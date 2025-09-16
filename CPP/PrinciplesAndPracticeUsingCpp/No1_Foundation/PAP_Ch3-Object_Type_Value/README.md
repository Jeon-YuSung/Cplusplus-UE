# Ch3- 객체, 타입, 값

## 3.1 입력(input)
앞에서 본 Hello, World! 프로그램은 화면에 쓰기만 한다. 즉, 출력을 생성할 뿐 아무것도 읽지 않고, 사용자의 입력을 받지 않음. <br>
실제 프로그램은 실행할 때마다 동일한 출력을 내보내지 않으며, 주어진 입력에 따라 다른 결과가 나옴. <br>
뭔가를 읽으려면, 어딘가 읽을 곳이 필요하다 → 읽을 내용을 컴퓨터 메모리의 어딘가에 저장해야 함. 그런 '장소'를 객체(object)라고 함. 

  - 객체
    저장하는 정보의 종류를 가리키는 **타입**과 연계된 메모리의 한 영역
    
  - 변수
    명명된 객체를 뜻 함, 문자열은 string 변수에, 정수는 int 변수에 저장

객체는 특정 타입의 객체를 저장하는 '상자'에 비유 가능.

<img src = https://github.com/Jeon-YuSung/Jeon-YuSung.github.io/blob/main/_img/intBoxGpt.png width = "300" height = "400"/>

```cpp
#include <iostream>
#include <string>
using namespace std;

int main(void){
  string firstName;
  cout << "firstName Input and Enter \n";
  cin >> firstName;
  cout << "hello, " << firstName << endl;
  return 0;
}

```

위의 코드에서 "firstName Input and Enter"는 사용자가 행동을 취하게 조언하는 의미로 프롬프트(prompt)라고 함 <br>
string 객체의 변수 firstName를 정의 → 메모리에 문자열을 저장할 메모리 영역을 할당 <br>
프로그램에서 새로운 이름을 선언하고, 변수를 저장할 메모리 영역을 할당하는 구문을 **정의문(Definition)** 이라고 함.<br>
cin은 cout 처럼 character input의 줄임말로, 표준 라이브러리에 정의된 표준 입력 스트림(standard input stream)을 가르키고, >> 연산자의 두 번째 피연산자(operand)는 입력을 받을 곳을 가리킴. <br>
참고로, 문자열 리터럴는 큰따옴표를 사용하고, 큰따옴표를 사용하지 않으면 그 이름이 가리키는 값을 참조하겠다는 의미임 <br>

-------------------------------------------------------------------------

## 3.2 변수(Variable)
입력 문자열을 저장하는 것처럼, 컴퓨터는 메모리에 데이터를 저장하지 않고는 일을 할 수 없음. <br>
데이터를 저장하는 장소는 객체(Object)라고 하고, 그 객체에 접근하려면 이름이 필요함 <br> 
이름이 있는(명명된) 객체를 변수(Variable)이고, 변수는 해당 객체에 넣을 수 있는 정보의 종류와 적용 가능한 연산의 종류를 지정하는 타입을 지님<br>
(int type에 123을, string type에 "Hello"를, 아니면 *로 곱셈을 하거나 <=을 적용해서 문자열을 비교) <br>
변수에 저장하는 데이터를 값(Value)라고 하고, 변수를 정의하는 구문은 말 그대로 **정의문**이라고 하고 정의문에서 초기 값을 지정할 수 있다 → (정의문에서 초기값을 지정 안해도 되는데, 지정하는게 권장 사항)

```cpp
string name = "Annemarie";
int number_of_steps = 42;
```
<img src = https://github.com/Jeon-YuSung/Jeon-YuSung.github.io/blob/main/_img/OutPutBoxWithGPT.png width = "600" height = "600"/>

이제 다음 코드를 보자

```cpp
string name = 42; // Error, 39는 문자열(string)아니다, 대신 "38", "4212321"같은 숫자를 문자형으로 바꾸는건 가능   
int number_of_steps = "Annemarie"; // Annemarie는 정수 int가 아니라 문자라 에러가 발생함
```

컴파일러는 각 변수의 타입을 기억해뒀다가, 변수 정의에서 지정한 타입을 사용하는지 확인함 <br>
C++에서 많은 종류의 타입을 제공하지만, 주로 다음 코드에 있는 타입들을 많이 사용.

```cpp
int num = 0; // int num (0);, int num; num 10; 이런식으로 초기화 가능, 4바이트
float realNum = 4.231; // float은 실수 표현 단정도 부동 소수점이라고도 함 4바이트
char singleChar = 'A' // 개별문자를 저장, 크기는 1바이트  'A'는 아스키 코드로 65
double realNum2 = 6.1232135; // double은 배정도 부동소수점, 크기는 8바이트
string name = "Vidan"; // 문자열을 저장하는 string, 크기는 객체가 차지하는 크기를 따라감
bool tapOn = true; // 논리 변수를 저장함 크기는 1바이트 
```
이외에도 unsigned char, unsigned int, short, long, long long... 등 다양한 기본 자료 타입들이 제공됨. 

-----------------------------------

## 3.3 입력과 타입(Input and Type)
입력 연산자 >>는 타입에 예민한 연산자로, 입력을 저장할 변수의 타입에 맞게 값을 읽어 들임. <br>


-----------------------------------------------------------------
