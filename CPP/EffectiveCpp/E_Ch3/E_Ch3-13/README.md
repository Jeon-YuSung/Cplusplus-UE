# 3-13. 자원 관리에는 객체가 그만! 

우린 동적 할당한 객체를 사용할 일이 없으면 해제를 해줘야한다. 

```cpp
class Investment {....}; //여러 형태의 투자를 모델링한 클래스 계통의 최상위 클래스

Investment*  createInvestment(); //Investment 클래스 계통에 속한 클래스의 객체를 동적 할당 및 그 포인터를 반환
                                 //이 객체의 해제는 호출자 쪽에서 직접해줘야한다. 

void f(){

  Investment* pInv = createInvestment(); //팩토리 함수 호출, pInv 사용
  ...
  delete pInv; //객체 해제 
}

```
위의 코드를 보면, f()함수를 벗어날 때, Investment객체를 해제하기 때문에 문제가 없어 보이지만, 
중간에 예외가  발생하거나 return 되는 경우에 대한 고려점이 없는걸 알수 있다. 
뭐...이러든 저러든 delete문이 실행되지 않으면, Investment 객체를 담고 있는 메모리가 누출되고, 동시에 그 객체가 갖고 있던 자원까지 모두 메모리 누수가 된다. 
이러한 문제를 해결하는 방법은 자원을 객체에 넣고 그 자원을 해제하는 것은 소멸자가 맡고, 소멸자의 실행이 f()함수가 끝날 때, 호출하도록 만들면 된다
이것을 템플릿 클래스로 만든 것이 **Smart Pointer** 이다. 

## Smart Pointer  

포인터처럼 동작하는 클래스 템플릿으로, 사용이 끝난 메모리를 자동으로 해제해준다. 즉, 가리키고 있는 대상에 대해 소멸자가 자동으로 delete를 불러주도록 설계되었다. <br>
다음 코드를 보자 

```cpp
f() {
  std::auto_ptr<Investrment> pInv(createInvestment()); //팩토리 함수를 호출하여, 예전처럼 pInv 사용
                                                       //그리고 auto_ptr의 소멸자를 통해 pInv를 삭제.
}
```

아주 간단한 예제이지만 이를 통해, 자원 관리에 객체를 사용하는 방법에 대한 아주 중요한 2가지 특징을 알 수 있다. 

1. **자원을 획득한 후에 자원 관리 객체에게 넘긴다.** <br>
예제 코드를 보면 createInvestment 함수가 만들어 준 자원은 그 자원을 관리할 auto_ptr 객체를 초기화하는데 쓰인다.
즉, **자원 획득 즉 초기화(Resource Acquisition is initialization, RAII)** 이라고 하는데,
쉽게 자원 획득과 자원 관리 객체의 초기화가 바로 한 문장에서 이루어지는 것이 당연한 것이기 때문이다.
획득된 자원으로 자원 관리 객체를 초기화하지 않고,
그 자원을 그 객체에 대입하는 경우도 있지만 **자원을 획득하고 나서 바로 자원 관리 객체에 넘겨 준다**라는 점은 같다.

2. **자원 관리 객체는 자신의 소멸자를 사용해서 자원이 확실히 해제되도록 한다.** <br>
소멸자는 어떤 객체가 소멸될 때, 자동적으로 호출되기 때문에, 실행 제어가 어떤 경위로 블록을 떠나는가에 상관없이 자원 해제가 제대로 이루어진다.
물론 객체를 해제하다가 예외가 발생될 수 있는 상황이 일어나면 많이 복잡하겠지만... 그건 항목 2-8를 보면 해결되는 문제이다.

auto_ptr은 자신이 소멸될 때, 자신이 가리키고 있는 대상에 대해 자동으로 delete 연산를 해주기 때문에 **어떤 객체를 가리키는 auto_ptr의 개수가 둘 이상이면 절대 안된다**
만약에 이런 상황이 생기는 경우, 자원이 두 번 삭제되는 결과를 얻고, 프로그램은 미정의 동작을 하게 된다. 이걸 막겠다고, auto_ptr의 유별한 특징이 있는데,
auto_ptr 객체를 복사하면(복사 생성자/복사 대입 연산자를 통해) 원복 객체는 null로 만든다. 복사하는(copying) 객체만이 그 자원의 유일한 소유권(ownership)을 갖는다고 가정하기 때문이다. 

```cpp
std::auto_ptr<Investment> pInv1 (createInvestment()); //pInv1이 가리키는 대상은 createInvestment함수에서 반횐된 객체

std::auto_ptr<Investment> pInv2(pInv1); //pInv2는 현재 그 객체를 가리키고 있는 반면, 이제 pInv1는 null이다.

pInv1 = PInv2; // 지금 pInv1은 그 객체를 가리키고 있고, pInv2는 null이다. 
```

auto_ptr이 관리하는 객체는 2개 이상의 객체를 물고 있으면 안 된다는 요구 사항과, 동적으로 할당되는 모든 자원에 대한 관리 객체로 auto_ptr을 사용하는것은 최선의 방법이 아니다. 
왜냐하면, STL 컨테이너의 경우엔 원소들이 '정상적인' 복사 동작을 가져야해서, autor_ptr은 원소를 허용하지 않는다. <br>
그럼, auto_ptr을 쓸 수 없는 상황이라면, 그 대안이 있을까? → 있다 <br>
바로, **참조 카운팅 방식 스마트 포인터(Reference-Counting Smart Pointer, RCSP)** 라는 괜찮은 선택지가 있다. <br>
RCSP는 특정한 어떤 자원을 가리키는(참조하는) 외부 객체의 개수를 유지하고 있다가, 그 개수가 0이 되면 해당 자원을 자동으로 삭제하는 스마트 포인터 <br>
RCSP의 동작만 보면 가비지 컬렉션(Garbage Collection)과 매우 흡사하다, 하지만 참조 상태가 고리를 이루는 경우(예를 들어 다른 두 객체가 서로를 가리키고 있는 상황)를 없앨 수 없다는 점은 가비지 컬렉션과의 차이점이다. 

TR1에서 제공되는 tr1::shared_ptr이 대표적인 RCSP로 다음 코드를 보자

```cpp
void f(){
  ...
  std::tr1::shared_ptr<Investment> pInv(createInvestment()); //팩토리 함수 호출, pInv 사용
  ...                                                        // shared_ptr의 소멸자를 통해 pInv를 자동 삭제 
}

```

auto_ptr랑 비슷해보이지만, shared_ptr의 복사가 훨씬 더 자연스럽다.

```cpp
void f(){
  ...
  std::tr1::shared_ptr<Investment> pInv1(createInvestment()); //pInv1이 가리키는 대상은 createInvest 함수에서 반환된 객체

  std::tr1::shared_ptr<Investment> pInv2(pInv1); //pInv1 및 pInv2가 동시에 그 객체를 가리키고 있음. 

  pInv1 = pInv2; //마찬가지로 변한 것은 하나도 없으며, pInv1 및 pInv2는 소멸되어 이들이 가리키는 객체도 자동으로 삭제됨. 
  ....
}
```

복사 동작이 '예상대로' 이루어지기 때문에 tr1::shared_ptr은 괴상한 복사 동작을 하는 auto_ptr을 쓸 수 없는 STL 컨테이너 등의 환경에서 사용할 수 있다. <br>
또한 auto_ptr과 tr1::shared_ptr은 소멸자 내부에서 delete[]연산자가 아닌 **delete 연산자**를 사용한다. <br>
즉, 동적으로 할당한 배열에 auto_ptr 혹은 tr1::shared_ptr를 사용하면 곤란해지는 경우가 있다. 왜냐면 동적 배열을 썼을 때 컴파일 에러가 발생하지 않기 때문이다.

```cpp
  std::auto_ptr<std::string> aps(new std::string[10]); // 좋지않은 문법으로 잘못된 delete를 사용
  std::tr1::shared_ptr<int> spi(new int [1024]); //이 또한 잘못된 delete를 사용
```

참고로, C++ 표준 라이브러리에서는 동적 할당된 배열을 위해 준비된 autor_ptr 또는 tr1::shared_ptr같은 클래스가 제공되지 않는다. TR1도 마찬가지로 제공하지 않는다. <br>
그 이유는 동적으로 할당된 배열은 vector나 string으로 거의 대체할 수 있기 때문이다. 그리고 나중에 배울 부스트(boost) 라이브러리에서 boost::scoped_array나 boost::shared_array를 제공해줘서 이걸로 대체할 수 있다. 
auto_ptr이나 tr1::shared_ptr로 활용하여 자원을 잘 관리할 수 있으나, **이 클래스를 사용해도 제대로 관리 할수 없는 자원이 있다** <br>
이럴 경우 직접 구현해야한다. 

마지막으로, createInvestment 함수 반환 타입이 포인터로 되어 있는데, 이 부분에서 문제가 생길 수 있다. 반환된 포인터에 대한 delete 호출을 호출자쪽에서 해야하는데, 그것을 안하고 넘어가기 쉽기 때문이다. <br>
(autor_ptr 또는 tr1::shared_ptr를 써서 delete를 수행한다고 해도, createInvestment의 반환 값을 스마트 포인터에 저장해야한다) <br>
이 문제를 해결하는건 4-18을 참고하자 → 인터페이스를 고쳐야하기 때문임. 

  - **3-13 정리**
    + 자원 누출을 막기 위해, 생성자 안에서 자원을 획득하고, 소멸자에서 그것을 해제하는 RAII객체를 사용하자
    + 일반적으로 널리 쓰이는 RAII클래스는 autor_ptr이나 tr1::shared_ptr이고, auto_ptr은 복사되는 객체(원본 객체)를 null 만든다. 반면에 tr1::shared_ptr는 복사 시의 동작이 더 직관적이기 때문에 대체적으로 좋은 편이다.  
    
