## 항목 21 - 함수에서 객체를 반환해야 할 경우에 참조자를 반환하려고 들지말자. 

함수 수준에서 새로운 객체를 만드는 방법은 Stack에 만들거나, Heap에 만드는 것이다. 

**1. Stack**

스택에 객체를 만들려면 지역변수를 정의하면 된다. 

```cpp
const Rational& operator*(const Rational& lhs, const Rational& rhs){
  Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
  return result;
}
```
result는 다른 객체처럼 생성자를 통해 생성되고, 지역변수 이기때문에 operator*가 끝난 시점에 소멸된다. <br>
result는 이미 소멸된 메모리를 가르킨다. 

------------------------------------------------------------------------------------

**2. Heap**

함수가 반환할 객체를 힙에 생성해 뒀다가, 그 녀석의참조자를 반환하는 것은 어떨까? <br>
힙 기반 객체는 new 연산자를 통해 생성하고, delete 연산자를 통해 소멸시킨다

```cpp
// 어이 없는 코드2
const Rational& operator*(const Rational& lhs, const Rational& rhs){
  Rational* result = new Rational(lhs.n * rhs.n, lhs.d * rhs.d);
  return *result;
}
```

힙 또한, 생성자 호출 비용이 발생되고 동적 할당을 했기에 result 메모리를 해제해야 한다. 하지만 위의 코드에서는 해제하는 부분이 없기 때문에, 메모리 릭이 발생한다. 
위의 코드를 만든 상태로 밑의 func함수를 호출하면 어찌되는지 확인을 해보자. 

```cpp
void func(){
  Rational w,x,y,z;
  w = x* y * z; // operator*(operator*(x,y),z)
}
```

func함수를 호출하면, w = x* y * z; 문장에서 operator*가 2번 호출되어 new를 2번 실행했기에 delete를 2번해줘야한다. 하지만 객체에 접근할 방법이 없어 delete를 해줄 수 없다. <br>즉즉, 자원 누출이**보장**되는 코드이다.

------------------------------------------------------------------------------------

**3. 정적객체**

생성자 호출을 최소화하려면, 처음 한 번만 생성되는 정적 객체를 사용하면 되지 않을까? 

```cpp
const Rational& operator*(const Rational& lhs, const Rational& rhs){
  static Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
  return result;
}

bool operator==(const Rational&  lhs, const Rational& rh) {
  Rational a, b, c, d;
  // operator*은 정적 객체를 반환하기에 항상 같은 객체가 반환된다.
  if((a * b ) == (c * d)) return true;
  else return false;
}

```

처음 한 번만 생성하기에, 스레드 안정성 문제가 생겨 operator==연산자 오버로딩 시 항상 같은 참조자를 반환하기 때문에 ==연산시 항상 true로 반환하게된다.

-----------------------------------------------------------------------------------------------------

**4. 해결방법**

```cpp
inline const Rational operator* (const Rational& lhs, const Rational& rhs) {
  return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
}
```

위의 코드도 생성자와 소멸자를 호출하지만, 올바른 동작에 코스트가 적게 들어가는 비용이다. 
즉, 새로운 객체를 생성해서 리턴하는게 가장 옳은 방법이고, C++에서 컴파일러 구현자 들이 가시적인 동작 변경을 하지 않고도, 기존의 코드 수행 성능을 높이는 최적화를 적용할 수 있도록 배려한 것이다.
그렇기 때문에, 몇몇 조건하에서는 이 최적화 매커니즘에 의해 operator*의 반환 값에 대한 생성과 소멸 동작이 안전하게 제거 될 수 있다. 이를 **반환 값 최적화(return value optimization) RVO**라고 한다.

반환 값 최적화는 C++11 이후 표준이 되었으며, 컴파일러가 알아서 **복사 없이 최적화**를 한다.

**4장 21절 정리**

지역 스택 객체에 대한 포인터나 참조자를 반환하는 일, 혹은 힙에 할당된 객체에 대한 참조자를 반환하는 일, 또는 지역 정적 객체에 대한 포인터나 참조자를 반환하는 일은 그런 객체가 두 개 이상 필요해질 가능성이 있다면 절대로 하지 않는 것이 좋다. (1장 4절를 보면 지역 정적 객체에 대한 참조자를 반환하도록 설계된 올바른 코드 예제를 찾을 수 있고, 최소한 단일 환경 스레드 환경에서는 통한다)
