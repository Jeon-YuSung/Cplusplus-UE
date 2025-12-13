# 항목 21 - 함수에서 객체를 반환해야 할 경우에 참조자를 반환하려고 들지말자. 

함수 수준에서 새로운 객체를 만드는 방법은 Stack에 만들거나, Heap에 만드는 것이다. 

**1. Stack**

```cpp
const Rational& operator*(const Rational* lhs, const Rational& rhs){
  Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
  return result;
}
```
result는 다른 객체처럼 생성자를 통해 생성되고, 지역변수 이기때문에 operator*가 끝난 시점에 소멸된다. <br>
result는 이미 소멸된 메모리를 가르킨다. 

**2. Heap**

```cpp
const Rational& operator*(const Rational* lhs, const Rational& rhs){
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

func함수를 호출하면, w = x* y * z; 문장에서 operator*가 2번 호출되어 new를 2번 실행했기에 delete를 2번해줘야한다. 하지만 객체에 접근할 방법이 없어 delete를 해줄 수 없다. <br>

**3. 정적객체**

생성자 호출을 최소화하려면, 처음 한 번만 생성되는 정적 객체

```cpp

```

