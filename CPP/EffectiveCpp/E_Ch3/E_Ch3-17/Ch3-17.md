# 3-17 new 생성한 객체를 스마트 포인터에 저장하는 코드는 별도의 한 문장으로 만들자

자원 관리 객체를 사용하고 있더라도, 잘못 사용한다면 자원이 누수될 가능성이 있다. 이번 챕터는 어떻게 사용하면 자원을 더 안전하게 사용할 수 있는지 알아보자.

다음 코드를 보자

```cpp
int priority();
void processWidget(std::tr1::shared_ptr<Widget> pw, int priority);
```
이 코드는 처리 우선 순위를 알려주는 함수가 있고, 동적 할당한 Widget 객체에 어떤 우선순위에 따라 처리를 적용하는 함수이다. 
자원 관리에는 객체를 사용하는게 좋다는 것을 바탕으로, processWidget 함수에는 std::tr1::shared_ptr라는 스마트 포인터를 사용하도록 만들어 졌다.

이제 다음과 같이 함수를 호출 해보자. 

```cpp
processWidget(new Widget, priority());
```
포인터를 받는 std::tr1::shared_ptr의 생성자는 explicit으로 선언되어 있기 때문에 
new Widget 표현식에 의해 만들어진 포인터가 std::tr1::shared_ptr 타입의 객체로 바꾸는 암시적 변환이 있을리가 없기 때문에, 컴파일이 되지 않는다. <br>
processWidget는 std::tr1::shared_ptr가 필요해도 컴파일이 되지 않는다. 

반면 다음 코드는 컴파일 되는 코드이다. 

```cpp
processWidget(std::tr1::shared_ptr<Widget>(new Widget), priority());
```

하지만 위의 코드도, 자원 누수가 발생할 가능성이 있는 코드이다. 왜 그런지 하나씩 파악해보자. <br>
우선, 컴파일러는 processWidget가 호출 코드를 만들기 전에, 우선 이 함수의 매개변수로 넘겨지는 argument를 평가(evaluate)하는 순서를 가진다. <br>
2번째 인자인 priority는 호출문 밖에 없지만, std::tr1::shared_ptr<Widget>(new Widget)는 다음 2가지로 나눌 수 있다.
  - new Widget 표현식을 실행하는 부분
  - std::tr1::shared_ptr 생성자를 호출하는 부분
그렇기 때문에, processWidget 함수 호출이 이루어기 전에 컴파일러는 3 가지 연산을 위한 코드를 만들어야한다 <br>
  - priority를 호출
  - new Widget 실행
  - std::tr1::shared_ptr 생성자 호출
그리고 C++에서 이 연산의 순서는 컴파일러마다 다르다.
물론 new Widget은 std::tr1::shared_ptr 생성자가 실행될 수 있기 전에 호출되어야 한다. 그러나 priority의 호출은 어디서든 호출이 될 수 있다. <br>
만약에 new Widget → priority() → std::tr1::shared_ptr순으로 호출되고, priority()에서 예외가 발생했다면 new Widget으로 만들어진 포인터는 유실될 수 있다.
즉, 자원이 생성되는 시점과, 그 자원이 자원 관리 객체로 넘어가는 시점 사이에 예외가 끼어들면 자원은 유실될 수 있다. 

그럼 어찌 해결해야할까? <br>
Widget을 생성해서 스마트 포인터에 저장하는 코드를 별도의 문장 하나로 만들고, 그 스마트 포인터를  processWidget에 넘기는 방법으로 해결할 수 있다. <br>

```cpp
std::tr1::shared_ptr<Widget> pw(new Widget); //new로 생성한 객체를 스마트 포인터로 담는 하나의 독립된 문장.

processWidget(pw, priority());
```

한 문장 안에 있는 연산들 보다 문장과 문장 사이에 있는 연산들이 컴파일러의 재조정을 받을 여지가 적어지기 때문에, 자원 누출 가능성이 없어진다. 

  - **3-17 정리**
    + new로 생성한 객체를 스마트 포인터로 넣는 코드는 별도의 한 문장으로 만들자, 이것이 안 되어 있으면, 예외가 발생될 때 디버깅하기 힘든 자원 누출을 초래될 수 있다. 
