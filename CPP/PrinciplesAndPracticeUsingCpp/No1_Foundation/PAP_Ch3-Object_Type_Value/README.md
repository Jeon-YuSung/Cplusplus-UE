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

## 3.2 변수 
