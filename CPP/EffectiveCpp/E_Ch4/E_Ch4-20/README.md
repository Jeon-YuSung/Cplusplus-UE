# 4-20 값에 의한 전달(Call by Value / Pass by Value)보다는 상수객체 참조자에 의한 전달 방식(Pass-by-reference-to-const)을 택하는게 대개 낫다.

-참고로, Pass by Value와 Call by Value는 기능적으로 똑같은 역할을 하며, 단지 Pass by Value는 Argument에서의 단어이고, Call by Value는 Function에서의 단어이기 때문이다. <br>
그리하여 **Pass by Value == Call by Value** 이다. 

### 값의 의한 전달 (Pass by Value / Call by Value) 
기본적으로 C++는 함수로부터 객체를 전달 받거나, 객체를 함수로 전달할 때 **값의 의한 전달(Pass by Value)** 방식으로 사용하는데, 특별히 다른 방식을 정해주지 않는 이상, 기본적으로 함수 Parameter는 실제 Argument의 **사본**을 통해 초기화되며, 어떤 함수를 호출한 쪽은 그 함수가 반환한 값의 **사본**을 돌려받는다. 이 사본을 만들어내는 곳이 복사 생성자인데, 이러한 점 때문에, 값에 의한 전달의 Cost가 많이 들어가기도 한다. 

```cpp
class Person {
public:
  Person();
  virtual ~Person();
  ...

private:
  string name;
  string address;
};


class Student : public Person {
public:
  Student();
  ~Student();
  ...
private:
  string schoolName;
  string schoolAddress;
};

bool validateStudent(Student s);

Student plato;
bool platoIsOK =  validateStudent(plato);
```

plato를 인자로 전달하면 매개변수 s를 초기화하기 위해 Student의 복사 생성자를 호출하며, validateStudent 함수를 나갈 때 소멸자도 호출 될 것이다. 그리고 Person 클래스를 상속 받았기 때문에, Person의 생성자가 먼저 호출되고, 그 다음 Student의 생성자가 호출 각 클래스의 필드 또한 복사가 된다. <br>
즉, 위의 예시 코드는 총 생성자 6번을 호출하고, 소멸자 6번이 호출된 비용을 소모하고 있음을 알 수 있다. <br>

그럼 이러한 문제를 어찌 해결 할까? **상수 객체 참조자에 의한 방식(Pass by reference to const / Pass by constant reference)** 으로 해결이 가능하다. 

### 상수 객체 참조자에 의한 방식(Pass by reference to const)

```cpp
bool validateStudent(const Student& s);
```
상수 객체 참조자에 의한 전달 방식의 장점은 다음과 같다. 
1. 새로운 객체가 만들어지지 않아, 생성자와 소멸자가 호출되지 않는다 즉, 비용 소모가 없다.
2. const를 사용함으로 전달되는 객체가 변경되지 않음을 보장한다.
3. 복사 손실 문제가 없어지는 장점이 있다.

복사 손실 문제란?  보통 자식 클래스 객체가 부모 클래스 객체로서 전달되는 경우에 접할 수 있는데, 이때 이 객체가 값으로 전달되면 기본 클래스의 복사 생성자가 호출되고, 파생 클래스 객체의 특징들은 잘려나가게 된다는 문제를 뜻한다. 다음 예시 코드를 보자

```cpp
class Window{
public:
  string name() const;
  virtual void display() const;
};

class WindowWithScrollBars : public Window{
public:
  virtual void display() const;
};

// 1. 값에 의한 전달
void printNameAndDisplay(Window w){
  cout << w.name();
  w.display();
}

// 2. 상수 객체 참조자에 의한 전달. 
void printNameAndDisplay(const Window& w){
  cout << w.name();
  w.display();
}

WindowWithScrollBars wwsb;
printNameAndDisplay(wwsb);
```

printNameAndDisplay 함수의 Argument로 **값에 의한 전달**을 선택하면, Window 객체의 복사 생성자를 호출하기 때문에, WindowWithScrollBars를 넘기더라도, Window의 display만을 호출하게된다. 그럼 **상수 객체 참조자에 의한 전달**을 선택하는데, 이 방법으로 전달하면 어떤 종류의 Window가 넘겨지더라도 그 성질을 가지고 있게 된다. 

### 전달 방식으로 무엇을 선택하는게 좋을까? 
일단, 참조자는 보통 포인터를 써서 구현된다. 참조자를 전달한다는 것은 결국 **포인터**를 전달한다는 의미이다. 전달하는 객체의 타입이 기본 제공 타입(int, char, float)... 일 경우 참조자로 넘기는 것보다 Pass by Value가 좋은 선택이다. <br> 
즉, **값에 의한 전달** 방식은 일반적으로 **저비용**이라고 가정해도 괜찮은 타입들 **기본 제공 타입(int, char, float, long...), STL 반복자, 함수 객체 타입 정도이다.
여기서 주의할 점은 STL의 Iterator와 함수 객체는 **복사 효율을 높여야하고, 복사 손실 문제에 노출되지 않아야한다.**

참조자 전달을 선택하는 경우는 2가지 경우가 있다. 
1. 사용자 타입을 사용할 경우 - 보통 class, struct, enum, union이 대표적인 사용자 타입이다.
2. 위의 3가지 경우를 제외한 모든 경우 - 즉 Call by Value가 더 효율적이면 Call by Value를 사용하면 된다.

### 항목 20 정리
1. Call by Value보다는 Pass by reference to const방식을 선호하자, 대체적으로 효율적이며 복사 손실 문제까지 막아준다. 
2. 기본 제공 타입, STL Iterator, 함수 객체 타입은 Pass by reference to const보다 Call by Value가 더 적절하다.
