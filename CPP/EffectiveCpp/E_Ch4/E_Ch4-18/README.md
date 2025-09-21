# 4-18 인터페이스 설계는 제대로 쓰기 쉽게, 엉터리로 쓰기엔 어렵게 하자. 

C++에서 흔하고 계속 보는것이 인터페이스이다. 함수, 클래스 템플릿....등 <br>
아무튼 제대로 사용하면 쉽고, 엉터리로 사용하면 어려운 인터페이스를 개발하려면, 우선 사용자가 저지리를 만한 실수의 종류를 알고 있어야 한다. <br>

날짜를 나타내는 어떤 클래스에 넣을 생성자를 설계하는 과정의 코드를 보자.

```cpp
class Date{
public:
  Date(int month, int day, int year);
  ...
};
```

보기엔 별로 문제가 없어보이는 인터페이스이다. 그러나 사용자 입장에서 쉽게 저지를 수 있는 오류가 적어도 2개나 있다. 
1. parameter의 전달 순서가 잘못될 여지가 있다.
   
```cpp
Date d(21, 9, 2025); // day와 month를 바꿔서 입력하였다 
```

2. 월과 일에 해당하는 숫자가 잘못된 숫자일 수 도 있다.
```cpp
Date d(13,40,2025); //13월 40일은 존재하지 않는다. 
``` 

이에 대한 해결방안으로 
1. 새로운 타입을 들여와 인터페이스를 강화하여 사용자의 실수를 막는다.
```cpp
struct Day{
  int val;
  explicit Day(int d) : vad(d) {}
};

struct Month{
  int val;
  explicit Month(int m) : vad(m) {}
};

struct Year{
  int val;
  explicit Year(int y) : vad(y) {}
};

class Date{
public:
  Date(const Month& m, const Day& d, const Year& y);
};

Date d(40,3,2025); // 타입이 달라서 에러
Date d(Day(21), Month(8), Year(2025)); //이또한 타입이 틀려서 에러 발생
Date d(Month(9), Day(21),Year(2025)); //정상적으로 컴파일러 된다. 
```

2. 새로운 타입에 제약을 넣어서 오류를 방지한다.
```cpp
class Month{
private:
  explicit Month(int m);
public:
  static Month Jan() {return Month(1);}
  static Month Feb() {return Month(2);}
  ...
  static Month Dec() {return Month(12);}
};

Date d(Month::Dec(), Day(25), Year(2025));
```

위의 코드에서 정적 객체를 사용하지 않고 함수로 return하는 이유는 **비지역 정적 객체들의 초기화 순서는 정해지지 않는다**라는 특성 때문이다. 

또.. 예상되는 사용자 실수를 막는 다른 방법은 어떤 타입이 제약을 부여하여 그 타입을 통해 할 수있는 일들을 묶어 버리는 방법이 있다. <br>
흔히 **const**를 사용하는 방법이다. 항목3에서 설명했듯이, operator*의 반환 타입을 const로 한정함으로써 사용자가 사용자 정의 타입에 대해 실수를 저지르지 않도록 한다.
```cpp
if( a * b = c) // 비교하려고했으나, 대입이 되었다. 
```
일관성 있는 인터페이스를 제공하기 위해 별 다른 이유가 없다면 사용자 정의 타입은 기본 타입 제공처럼 동작해야 한다. <br>
**일관성**은 제대로 쓰기에 괜찮은 인터페이스를 만들어주는 중요한 요인이기 때문이다.

참고로, 사용자 쪽에서 뭔가를 외워야 제대로 쓸 수 있는 인터페이스는 잘 못 사용하기 쉽고, 언제든지 잊어버릴 수 있다. 

이제 **스마트 포인터를 활용한 인터페이스**에 대해 알아보자 <br> 
항목13에서 썼던 팩토리 함수를 생각해보자 <br>
```cpp
Investment* createInvestment();
```
이런식으로 사용하면 자원 누출을 피하기위해 createInvestment에서 얻은 포인터를 나중에라도 삭제(해제)해줘야 한다. 

그리고 문제점이 있는데,
1. 사용자가 포인터 삭제를 잊을 수 있다.
2. 똑같은 포인터에 대해 delete가 여러 번 적용될 수 있다.
3. 자원 관리를 위해 스마트 포인터에 createInvestment에서 얻은 포인터를 저장하려고 했지만 저장하는 것을 잊을 수 있다.

이제 이 스마트 포인터에 대한 문제점을 해결하는 방안을 알아보자 
```cpp
std::tr1::shared_ptr<Investment> createInvestment();
```
처음부터 팩토리 함수가 스마트 포인터를 반환하게 하자, 이러면 함수의 반환 값을 shared_ptr에 넣어둘 수 밖에 없고, 나중에 Investment 객체가 필요 없어졌을 때 객체를 삭제하는 것에 사용자가 신경 쓸 필요가 없어진다 <br>
또한, shared_ptr를 반환하는 구조는 자원 해제에 관련된 상당수의 사용자 실수를 사전에 봉쇄할 수 있고, 생성 시점에 자원 해제 함수를 직접 엮을 수 있는 기능을 가지고 있어서 인터페이스를 설계할 때 좋다. 

shared_ptr 삭제자 활용하는 법을 알아보자. 
createInvestment를 통해 얻은 Investment* 포인터를 직접 삭제하지 않게 하고, 다른 함수(getRidOfInvestment)에 포인터를 넘겨 삭제하는 기능을 만들어보자. 

```cpp
class Investment{
public:
  Investment* createInvestment() {return new Investment;}
  void getRidOfInvestment(Investment* obj) { delete obj;}
  void Func() {
      Investment* pInvest = createInvestment();
      ...
      getRidOfInvestment(pInvest);} 
};
```

이 코드 또한 문제점이 있는데, 
1. 사용자가 getRidOfInvestment를 사용하지 않고 직접 delete가 가능하다.
2. delete를 하고나서도, getRidOfInvestment가 호출하는 일이 발생할 수 있다.

다음 코드를 보자 
```cpp
std::tr1::shared_ptr<Investment> createInvestment{

  //방법 1 nullptr로 포인터를 초기화하고, 캐스트를 적용뒤, 나중에 대입 
  std::tr1::shared_ptr<Investment> retVal(static_cast<Investment*>(0), getRidOfInvestment);

  //방법2 실제 객체 포인터를 바로 생성자로 넘긴다. 
  std::tr1::shared_ptr<Investment> retVal(new Investment, getRidOfInvestment);

  retVal = ..;
  return retVal;
}
```

1. 포인터를 null ptr로 초기화하고 나중에 대입하는 방법
2. 실제 객체 포인터를 바로 생성자에게 넘기는 방법, 만약에 retVal로 관리할 실제 객체의 포인터를 결정하는 시점이 retVal을 생성하는 시점보다 앞설 수 있으면 이 방식을 추천한다.

마지막으로, **std::tr1::shared_ptr의 교차 DLL문제 방지**에 대해 알아보자 
std::tr1::shared_ptr는 포인터별(per-pointer) 삭제자를 자동으로 씀으로써, 사용자가 저지를 수 있는 **또 하나의 잘못을** 미연에 없애 준다는 점인데, 이 또 하나의 잘못은 **교차 DLL 문제(Cross-DLL prolbem)** 이다. <br>
이 문제가 언제 생기냐면, 객체 생성 시에 어떤 동적 링크 라이브러리(Dynamically linked library : DLL)의 new를 썼는데, 그 객체를 삭제할 때 이전의 DLL과 다른 DLL에 있는 delete를 사용한 경우이다. 원래 new/delete는 짝으로 실행되어야 하는데, 만약 DLL이 달라서 꼬이게 되면 런타임 에러가 발생한다. <br>
std::tr1::shared_ptr를 사용하면 이 문제를 방지할 수 있다. 그 이유는 std::tr1::shared_ptr의 클래스 기본 삭제자는 생성된 DLL과 동일한 DDL에서 delete를 사용하도록 만들어졌기 때문이다. 

참고로, 부스트(Boost Library)는 std::tr1::shared_ptr를 이용해서 구현한 것으로, 일단 부스트의 shared_ptr은 크기가 원시 포인터의 두 배이고, 내부 관리 데이터 및 삭제자 매커니즘을 돌릴 데이터를 위해 동적 할당 메모리를 사용하며, 다중 스레드로 돌아가는 프로그램을 지원할 경우에는 참조 카운트를 변경할 때 스레드 동기화 오버헤드를 일으킨다.(선행 처리자 기호를 정의해서, 다중 스레드 지원을 비활성화 할 수 있다).  이정도면 알고 나중에 항목55에서 좀 더 배울 부분이니 넘어가자.

  - **4-18 정리**
    + 좋은 인터페이스는 제대로 쓰기에 쉬우며, 엉터리로 쓰이기에는 어렵다. 인터페이스를 만들 때는 이 특성을 지닐 수 있도록 고민하자
    + 인터페이스의 올바른 사용을 이끄는 방법으로는 인터페이스 사이의 일관성 잡아주고, 기본제곱  타입과의 동작 호환성 유지하기가 있다.
    + 사용자의 실수를 방지하는 방법으로는 새로운 타입 만들기, 타입에 대한 연산을 제한하기, 객체의 값에 대해 제약 걸기, 자원 관리 작업을 사용자 책음으로 놓지 않기가 있다.
    + std::tr1::shared_ptr은 사용자 정의 삭제자를 지원한다. 이 특징 때문에 std::tr1::shared_ptr은 교차 DLL문제를 막아주고, 뮤텍스 등 자동으로 잠금 해제하는 데에도 사용할 수 있다.
    
