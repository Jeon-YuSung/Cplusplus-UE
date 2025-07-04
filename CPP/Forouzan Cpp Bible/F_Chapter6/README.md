## 6장 함수
-------------
함수의 기본 개념을 이해한다 

---------------
### 6.1 함수의 개요 

+ 함수는 어떤 작업을 하기위한 설계된 엔티티
  
큰 규모의 프로그램을 만들다 보면 세분화 작업이 필요 <br>
간단한 부분으로 나누지 않으면 이해하기 어렵고, 구현하기도 힘들기 때문임 <br>
-> 문제가 복잡해지고, 프로그램의 규모가 커질수록, 복잡한 문제를 작은 문제로 나누고 합치는 방법으로 효율을 높일수 있음 <br>

다른 프로그래밍 언어에서는 메소드(method) or 프로시저(procedure)라고도 부름 <br> 

+ **함수의 장점**
  
 * 분할 처리, 오류 확인(디버그), 재사용, 함수 라이브러리

+ **함수의 기본 사용법**

  함수를 사용하려면 정의, 선언, 호출이라는 엔티티가 필요함.

* 함수 정의 <br>
함수를 만드는 것을 의미 <br>

* 함수 선언 <br>
함수 선언 또는 함수 프로토타입은 함수의 헤더와 세미콜론만 조합된 구문 <br>
이때, 함수 헤더에서 매개변수의 이름을 입력하지 않아도 괜찮음 <br>
단, 자료형은 입력해야함
```cpp
int larger(int frist, int second); //매개변수에 이름을 넣은 경우 
int larger(int, int); //매개변수에 이름을 넣지 않은 경우
```
함수 선언은 함수의 호출 방법을 나타낼 때 사용 <br>
함수의 동작은 정의되어 있지 않지만, 함수에 무엇을 넣고, 함수에서 무엇을 나오는지를 알려줌.

* 함수 호출 <br>
Function call은 함수의 내용을 실행하기 위해서 함수를 호출하는 것 <br>
함수 호출은 side-effects와 return 값을 가질 수 있음. <br>
또한, 없을 수도 있고, 하나만 있거나, 둘 다 있을수 있음. <br>
side-effects만 있는 경우 표현식 구문으로 사용, 리턴값이 있는 경우 값이 필요한 아무곳에나 사용할 수 있음 

* argument와 parameter <br>
argument는 인수, parameter는 매개변수라고 함. 하지만 이를 구분하지 않은 경우가 많아 보통은 parameter (매개변수)로 통일하기도 함 <br>
parameter는 함수 정의에 있는 변수 선언을 뜻하고, argument는 함수를 호출할 때 매개변수를 초기화하는 값임 <br>
parameter의 초기화는 함수 호출할 때 내부적으로 일어남. <br> 
argument는 변수 또는 객체가 될 수 있음, 하지만 함수 호출 때는 내부의 값만 활용됨.

 예시 ex)  
 ```cpp
 int main(){ 
 ... 
  fun(5); // 함수 호출에서 5가 argument 
  ... 
 }
 
 void fun(int x) { //함수 정의에서 x가 parameter

 ....
 
 }
 ```
 ------------------------
 ### 6.3 사용자 정의 함수
 
 모든 함수가 라이브러리에 정의되어 있지않아, 필요한 함수를 직접 만들어야하는 경우가 있음.  
 보통 4가지 패턴이 있음 <br> 
 void 함수 이름 () { return; } // 매개 변수가 없는 void 함수  <br> 
 void 함수 이름 (자료형 매개변수, ... ) { return; } // 매개변수가 있는 void 함수 <br>
 자료형 함수 이름 () { return val; } // 매가 변수가 없지만 리턴값이 있는 함수 <br>
 자료형 함수 이름 (자료형 매개변수,....){ return val; } //매개 변수와 리턴 값이 자료형 함수  <br>

 * 매개변수가 없는 void 함수 <br>
   가장 기본적인 패턴. <br>
   함수 내부에서 side-effects를 일으키기 위해서만 사용 <br>
   만약에 side-effects를 일으키지 않는다면 함수에 의미가 없음, 이러한 함수는 값을 리턴하지 않으므로, 값이 필요한 위치에 활용할 수 없음.

* 매개변수가 있는 void 함수 <br>
 parameter로 값 argument를 전달해서 활용하는 함수 <br>
side-effects를 일으키지만 리턴 값을 리턴하지 않음, 함수가 side-effects를 일으키고, 이 side-effects에 추가적인 정보가 필요한 경우에 사용하는 패턴 <br>
일반적으로 매개변수가 있는 void 함수는 "입력-처리-출력" 이라는 설계에서 출력부분에 많이 사용됨 

* 매개변수가 없지만 리턴 값이 있는 함수 <br>
 리턴 값을 목적으로 사용하는 함수 <br>
 일반적으로 함수 내부에서 입력을 받고 이를 리턴, "입력-처리-출력"이라는 설계에서 입력 부분에 많이 사용됨. <br>

 * 매개변수와 리턴값이 있는 함수 <br>
   [코드6-11참고](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter6/6-11.cpp)

-----------------------------
### 6.4 자료 교환

호출되는 함수에 매개변수가 존재한다면, 함수 호출 때의 값(argument)이 호출되는 함수의 매개변수(parameter)로 전달 됨<br>
자료 전달은 <br> 
**값으로 전달(pass-by-value or call-By-Value)** <br>
**참조로 전달(pass-by-reference or call-By-Value)** <br>
**포인터로 전달(pass-by-pointer)** <br>

C++에서는 Pass by와 Call by~는 거의 동일한 의미로 사용 

+ **값으로 전달(pass-by-value or callByValue)** <br>
pass-by-value 매커니즘에서는 인수(argument)의 값이 복사되어서 매개변수(parameter)에 할당됨. <br>
값을 기반으로 자료가 전달되므로, 인수(argument)는 리터럴 또는 변수의 값이 됨 <br>
pass-by-value는 호출되는 함수 쪽에서 argument를 변경하지 않게 만들고 싶을 때 사용 <br>
즉, 이 매커니즘에서 호출되는 함수는 argument의 값을 **읽기**만 할 수 있다는 것임. <br>
이를 "읽기 전용 접근 (read-only access)라고도 표현함

[6-13.cpp 코드 참고](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter6/6-13.cpp)

pass-by-value의 매커니즘은 매우 간단하고, 호출되는 함수 쪽에서 argument를 조작하지 않게 차단을 함 <br>
하지만, argument의 값을 복사해서 parameter에 전달하므로 전달해야하는 값의 크기가 작다면 괜찮지만, 반대로 값의 크기가 크다면 복사하는 작업이 무거워질 수 있음. <br> 
즉, 객체지향 프로그래밍에서는 객체의 크기가 클 때, pass-by-value 매커니즘을 사용하지 않음 <br> 
(대신 pass-by-reference 또는 pass-by-pointer로 사용한다)


+ **참조로 전달(pass-by-reference or callByReference)** <br>
pass-by-reference는 argument와 parameter는 메모리 위치를 공유함. <br>
즉, 각각의 함수에서 변수의 이름은 다를 수 있지만, 양쪽 함수 모두에서 같은 메모리 위치에 접근해서 값을 읽거나 쓸 수 있음. <br>

[6-14.cpp코드 참고](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter6/6-14.cpp)

예를 들어 친구에게 편지를 검토해달라고 할 때, 종이에 작성한 편지를 전달하면 원본 편지를 공유하게 된다. 그리고 친구가 편지를 모두 검토하고 수정한 뒤 돌려주면, 본인이 최종적으로 갖는 편의 내용도 변경된다. <br>
또 다른 표현으로 "읽고 쓸 수 있는 접근 (read-write access)라고도 표현함. <br>
호출되는 함수에서 argument를 읽고 쓸 수 있음. <br> 
대표적인 예시가 swap임 <br> 
스왑은 정렬을 포함한 수많은 알고리즘에서 사용되고, 다양한 알고리즘에서 여러 번 활용하는 기능이기에 함수로 만들어서 사용할 가치가 있음 <br>
그런데 pass-by-value 매커니즘을 사용하면 원본(argument)에 접근할 수 없으므로 함수 호출로 스왑할 수 없음. <br>
따라서 paas-by-reference를 사용해서 원본 값을 조작해야함 <br>

pass-by-reference는 호출되는 함수쪽에서 매개변수를 변경해서, 호출한 함수 쪽의 원본(argument)를 변경할 수 있음. <br> 
즉, 스왑등을 구현할 때 가장 좋은 선택지임. <br>
또한 **복사가 필요하지 않다**는 장점이 있음 <br>
argument와 parameter의 이름은 다를 수 있지만 같은 메모리 위치를 나타냄 <br> 
따라서 큰 객체를 전달할 때에는 pass-by-reference를 사용 함. <br> 

+ **포인터로 전달(pass-by-pointer)** <br>

pass-by-pointer는 argument로 메모리 주소를 parameter로 전달하는 것 <br>
주소를 전달하므로, 매개변수를 사용해서 argument의 메모리 위치에 접근할 수 있음<br> 

<비고>
C언어에서는 pass-by-reference가 아예 존재하지 않아서, argumnet를 조작하려면 포인터로 pass-by-pointer를 무조건 사용해야 함. <br> 
C++에서는 pass-by-reference가 있어서, pass-by-pointer를 많이 사용하지 않지만, 일부 상황에서는 사용. <br>
pass-by-pointer는 pass-by-reference와 같은 장점을 가지고 있음 <br> 
일반적으로 C++에서는 많이 사용하지 않지만, 전달해야 하는 자료가 포인터의 특성(ex : C언어 문자열, 배열 등)을 갖고 있을 경우에는 pass-by-pointer를 사용함.

#### 자료 리턴
void 함수에 side-effects을 위해 사용. <br> 
void 함수는 아무것도 리턴하지 않음, 반면 void 함수가 아니라면, 어떤 값을 리턴해야함 <br>
리턴 값의 종류에 따라 <br>
**값으로 리턴 (return-by-value)** <br>
**참조로 리턴 (return-by-reference)** <br>
**포인터로 리턴 (return-by-pointer)** <br>
라고 3가지 매커니즘으로 나눌 수 있음. 

+ **값으로 리턴 (return-by-value)** <br>
가장 일반적으로 사용되는 매커니즘으로, 호출되는 함수 쪽에서 어떤 표현식을 생성하고, 이를 리턴함. <br>
함수를 호출하면 값이 리턴되므로, 값이 필요한 위치에 함수를 활용함 <br>

[6-16.cpp코드 참고](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter6/6-16.cpp)

+ **참조로 리턴 (return-by-reference)** <br>
C++를 절차 지향 매커니즘으로 사용할 때는 일반적으로 return-by-value를 함께 사용함 <br>
return-by-value는 쉬워, 이해하기 쉽지만 값을 복사해서 리턴함 <br>
일반적인 내장 자료형에서는 큰 문제가 없음. 하지만 객체지향 프로그래밍 매커니즘에서는 크키가 큰 객체를 리턴해야 하는 경우가 있음 <br>
**이때 복사로 인해서 발생하는 비용을 줄이려면, return-by-reference를 사용하는 것이 좋음** <br>
다만, 호출되는 함수에서 객체를 생성하면, 함수가 종료된 이후에 객체가 사라짐 <br>
그래서  return-by-reference를 사용할 때에는 여러 주의사항을 지켜야 함. 

+ **포인터로 리턴 (return-by-pointer)** <br>
return-by-reference와 효과가 같지만 거의 사용하지 않는다.

-----------------
### 6.5 parameter와 함수 오버로딩

#### Default Parameter

[6-18.cpp 코드 참고](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter6/6-18.cpp)

#### 함수 오버로딩 

Q. 이름을 같은 함수를 2개 정의 할 수 있을까? <br>
A. 매개변수(매개변수의 자료형, 개수, 순서)가 다르면 가능함 <br> 

이를 **함수 오버로딩(Function Overloading)** 이라고 함. <br>
프로그램이 같은 이름의 함수를 허용할 때, 함수들을 구분하기 위해 사용하는 기준을 **함수 시그니처(Function signature)** 라고 부름 <br>
함수 시그니처는 매개변수들의 자료형과 조합임. <br>
이름이 같은 함수라도 함수 시그니처가 다르다면, 호출 시점에 컴파일러가 자신이 어떤 함수를 호출해야 하는지 구분할 수 있음  <br>
다만, 함수 호출 시점에는 리턴값을 어떤 자료형으로 활용할지 컴파일러가 구분할 수 없으므로, 리턴 자료형은 함수 시그니처에 포함되지 않음. 

[6-19.cpp 코드 참고](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter6/6-19.cpp)


--------------------
### 6.6 함수의 사용 범위와 유지 기간

#### Scope

Scope는 소스 코드 내부에서 어떤 엔티티(상수, 변수, 객체, 함수 등)을 사용할 수 있는 범위(visible area)를 나타냄 <br> 
엔티티의 스코프를 정의하려면, 우선 스코프의 범위를 정의해야 함. <br>
엔티티를 선언할 때, 해당 엔티티에 대한 스코프가 만들어짐. <br> 
    
 **Function Shadowing**이란 내부 블록의 엔티티가 외부 블록의 엔티티를 그림자로 가르는 것처럼 가르는것을 의미함. <br>
즉, 내부 블록에서 외부 블록에서 있는 엔티티와 같은 이름으로 엔티티를 선언하면, 외부 블록에 있는 엔티티를 사용할 수 없음. <br>
외부 블록의 엔티티는 내부 블록이 종료된 이후에 사용할 수 있음. 

 [6-20 코드 참고](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter6/6-20.cpp)
 
* ##### 전역 스코프 (Global Scope)

모든 함수의 외부에 선언된 엔티티는 **Global Scope**를 가짐. <br>
전역 엔티티의 스코프는 프로램의 끝 부분까지라고 볼 수 있음.

```cpp
void pirnt();

int sum = 0; ///전역 스코프

int main(void){
sum++;
print();
}

void print(){
cout << sum << endl;
}
```

+ 전역 스코프의 쉐도잉 (Shadowing)

전역 스코프를 가장 넓은 스코프라고 보면, 쉐도잉이 전역 스코프에도 적용한다는 걸 쉽게 알 수 있음 <br> 

[6-21코드참고](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter6/6-21.cpp)

+ 범위 해결 연산자 (Scope Resolution Operator)

  지역 엔티티가 전역 객체를 가리는 쉐도잉을 무시하고, 전역 엔티티에 접근해야하는 경우도 있음. <br>
  C++는 이러한 떄를 위해 범위 해결 연산자 (::)를 제공함 <br>

  ::(객체) 이름 <br>
  스코프 ::(객체) 이름 <br>

 '       ::(객체) 이름'의 형태는 스코프가 프로그램의 Global Scope로 암묵적으로 지정됨 <br>
  '스코프 ::(객체) 이름'의 어떤 스코프의 엔티티인지를 나타냄 <br>

  [6-22 코드참고](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter6/6-22.cpp)
  

* #### 수명
  모든 프로그램은 태어나서 죽는 수명 (Lifetime)이 존재함<br>
여기서는 함수 내부에 있는 지역 변수의 수명만 살펴봄 <br> 
  함수 내부의 변수는 크게 자동 지역 변수와 정적 지연 변수로 구분할 수 있음. <br>

  + 자동 지역 변수 (automatic local variable)
 
    자동 지역 변수 (automatic local variable)는 함수가 호출될 때 생성되고, 함수가 종료될 때 소멸됨. <br>
    기본적으로 함수 내부의 모든 지역 변수들은 자동 지역 변수임 <br>
    
  + 정적 지역 변수 (static local variable)
 
C++은 정적(Static) 변경자를 3가지 상황에 사용할 수 있음. <br>
정적 지역 변수(static local variable)는 static 변경자를 앞에 붙여 만듦  <br>
정적 지역 변수는 프로그램이 종료되기 전까지 유지됨. <br>
**한 번만 초기화**되고 프로그램이 실행되고 있는동안, 프로그램은 메모리 위의 변수를 추적함.  <br>
따라서 함수를 여러 번 호출하면, 모든 함수들이 같은 변수를 공유함.

[6-23코드 참고](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter6/6-23.cpp)

    [6-24코드 참고](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter6/6-24.cpp)
   
