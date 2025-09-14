# 2장 Hello, World!

## 2.1 Program

프로그램과 프로그래밍의 차이는 뭘까? <br>
컴퓨터에게 어떤 일을 시키려면, 컴퓨터에게 어떤 일을 해야 하는지 시시콜콜할 정도로 자세히 알려줘야 함 <br>
여기서 프로그래램과 프로그램의 차이를 나눌 수 있다. <br> 

  - Program
    '어떤 일'에 대한 설명을 자세하고 명확하게 설명
  - Prgramming
    그런 프로그램을 작성하고 테스트 하는 활동

사람과 컴퓨터의 차이는 정확도에 있는데, 사람은 불충분한 설명으로 상식이나 추가적인 지식을 바탕으로 보강할 수 있지만, 컴퓨터는 **멍청 멍청**해서 **모든 사항을 자세하고 정확히 알려줘야 함** 

## 2.2 고전적인 첫 번째 프로그램 

```cpp
#include<iostream>

int main(void){
  std::cout << "Hello, World!\n";
  return 0;
}
```

가장 고전적이고 C++이나 어느 언어에서든 시작하는 출력 프로그램 <br>
std::cout << "Hello, World!\n";는 std::cout은 표준 출력 스트림(standard output stream)을 가르키고  <<는 'cout에 출력하라'라는 의미이며, Hello, World!라는 문자열을 출력하고 개행 문자(newline character)를 출력한다. <br>
참고로 cout은 character output stream의 줄임말이다. <br> 
문자열 리터럴(literal)은 큰따옴표(")로 구분 <br>
주석은 //나 /**/ 로 처리 가능하고, 프로그램은 이를 무시한다 주석은 코드를 읽는 프로그래머를 편의를 돕기위한 것임 <br>
include는 지시어(directive)로, 컴퓨터에 포함된 기능을 할 수 있게 한다. <br>
일반적인 확장자는 .h로 헤더나 헤더파일이라고 함. 
