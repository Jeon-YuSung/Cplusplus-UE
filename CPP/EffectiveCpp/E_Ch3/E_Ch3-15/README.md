# 3-15 자원 관리 클래스에서 관리되는 자원은 외부에서 접근할 수 있도록 하자
자원 관리 클래스는 실수로 터질 수 있는 자원 누출을 튼튼히 막아주는 보호벽 역할을 하여 듬직하지만, 세상일은 계획대로 되지 않는 법, 즉, 클래스만 사용하고 실제 자원을 **직접** 조작하는 일이 없을거다. 그러나 현재 쓰이는 수 많은 API들이 **직접 참조**하도록 만들어져 있기 때문에 직접 조작하는일이 있다. 

```cpp
std::tr1::shared_ptr<Investment>pInv(createInvestment()); //항목 13의 예제

int daysHeld(const Investment* pi); // 투자금이 유입된 이후로 경과한 날
int days = daysHeld(pInv); // Error! 
```
위의 코드처럼 createInvestment로 자원을 만들고, pInv에 넘겨주는 경우를 생각해보자. 
그리고 정의문 처럼 작성을 하면 이 코드는 컴파일이 되지 않는다. daysHeld 함수는 Investment* 타입의 실제 포인터를 원하는데, 프로그래머가 std::tr1::shared_ptr<Investment> 타입의 객체로 넘겨졌기 때문이다. <br>
그럼 이 문제를 어떻게 해결해야할까? <br>
답은 RAII 클래스의 객체가 그 객체를 감싸고 있는 실제 자원으로 변환할 방법이다. 일반적으로 **명시적 변환(Explicit Conversion)과 암시적 변환(Implicit Conversion)** 이다. 

1. **명시적 변환(Explicit Conversion)**
   
std::tr1::shared_ptr은 명시적 변환을 수행하는 get 멤버 함수를 제공하는데, 이 get 함수를 통해 스마트 포인터 객체에 들어 있는 실제 포인터(의 사본)를 얻어낼 수 있다.

```cpp
int days = daysHeld(pInv.get()); // pInv에 들어 있는 실제 포인터를 daysHeld에 넘긴다. 
```

2. **암시적 변환(Implicit Conversion)**
   
제대로 만들어진 스마트 포인터 클래스라면 거의 모두, std::tr1::shared_ptr은 포인터 역참조 연산 (operator-> 및 operator*)도 오버로딩 하고 있기 때문에, 자신이 관리하는 실제 포인터에 대한 암시적 변환도 쉽게 할 수 있다. 

```cpp
// 여러 형태의 투자를 모델링한 투자 클래스의 최상위 클래스
class Investment{
public:
  bool isTaxFree() const;
  ...
};

Investment* createInvestment(); //팩토리 함수

std::tr1::shared_ptr<Investment>pInv(createInvestment()); //shared_ptr이 자원 관리를 맡도록한다.

bool taxable1 = !(pInv -> isTaxfree()); //operator ->를 써서 자원에 접근
//책에 auto_ptr이 나와있는데 현재 제거되어 있으므로 주석으로 처리
//std::auto_ptr<Investment>pi2(createInvestment());
bool taxable2 = !((*pInv).isTaxfree());
```

두 가지 변환에 대한 예시와 자원 접근을 제공하는 함수를 만들 때 조심해야할 점을 알아보자. 
다음 코드는 C API로 직접 조작이 가능한 폰트를 RAII클래스로 만든 것이다. 

```cpp
FontHandle getFot(); // C API 함수
void releaseFont(FontHandle fh);

class Font{
private:
  FontHandle f; //실제 폰트 자원

public:
  explicit Font(FontHandle fh) : f(fh) {} //자원을 획득한다, 여기서 call by value로 전달된다.
  ~Font() { releaseFont(f); } // C API로 자원을 해제한다. 
};
```

이제 명시적 변환으로 get 함수를 제공하는 경우와 암시적 변환으로 operator를 정의해서 변환하는걸 알아보자. 

1. **명시적 변환**
   
Font 객체를 FontHandle로 변환해주는 get 함수를 제공하는 코드를 보자

```cpp
class Font{
...
public:
  FontHandle get() const {return f}; //명시적 변환 함수 
...
};

void changeFontSize(FontHandle f, int newSize);
Font f(getFont());
int newFontSize;

changeFontSize(f.get(), newFontSize); //Font에서 FontHandle로 명시적으로 바꾼후 넘긴다. 
```

이러면 변환할 때마다 get함수를 호출 해야한다. 참고로 함수 호출도 cost가 든다. 

2. **암시적 변환**

operator()를 정의해서 암시적으로 Font를 FontHandle로 변환 함수를 제공하는 코드를 보자.

```cpp
class Font{
...
public:
  operator FontHandle() const {return f}; //암시적 변환 함수 
...
};

Font f1(getFont());
int newFontSize;
changeFontSize(f, newFontSize); //암시적 변환으로 Font에서 FontHandle로 변환. 
```

근데, 진짜 Font를 복사하려고 한 부분에서 원하지 않아도, FontHandle로 바뀌는 단점이 있다.

```cpp
Font f1(getFont());
FontHandle f2 = f1; //Font객체가 복사되는게 아니라, FontHandle로 바꾸고나서 복사 됨
```

f1이 관리하는 FontHandle를 f2에서도 직접 사용할 수 있는 상태가 되는데, 이는 좋지 않다 f1이 소멸되면, 폰트가 해제될테고, f2는 해제된 폰트(자원)을 갖게 된다 

RAII 클래스를 실제 자원으로 바꾸는 방법으로 명시적 변환 혹은 암시적 변환을 할건지는 RAII 클래스 만의 특정한 용도와 사용 환경에 따라 달라지고, 애초에 RAII클래스는 데이터를 은닉하는 목적이 아니기에 캡슐화에 위배되는 설계가 아니다. <br>
참고로, RAII 클래스 중에 자원의 엄격한 캡슐화, 느슨한 캡슐화를 동시에 지원하는 것이 있다 <br>
대표적으로 std::tr1::shared_ptr로, 참조 카운팅 매커니즘에 필요한 장치들은 모두 캡슐화되어 있지만, 동시에 자신이 관리하는 포인터를 쉽게 접근할 수 있는 통로를 제공하고 있다.

  - **3-15 정리**
    + 실제 자원을 직접 접근해야 하는 기존 API들도 많이 있기 때문에, RAII 클래스를 만들 때는 그 클래스가 관리하는 자원을 얻을 수 있는 방법을 열어주어야한다.
    + 자원 접근은 명시적 변환 또는 암시적 변환을 통해 가능하고, 안전성만 따지면 명시적 변환이 대체적으로 낫지만, 고객 편의성을 생각하면 암시적 변환이 괜찮다.
      
