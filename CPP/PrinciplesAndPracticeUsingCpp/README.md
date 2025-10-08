# Principles And Practice Using C++ Programming

이 책은 C++문법 책이 아니라, C++를 도구로 사용하면서 C++의 강점을 알려주고, C++아닌 어떤 언어를 사용하든 대부분의 엔지니어링 방식으로 문제에 접근하는 방식인 책이다. 그러니 컴파일러 설계나 다른 기타 CS지식이 필요할 수 있다.

**<목차>**
  + 0장. 독자에게 전하는 글
  + 1장. Computer, Human, Programming

### 1부 기본 다지기
  + 2장. Hello, World!
  + 3장. Object, Type, Value
  + 4장. 계산
  + 5장. 오류
  + 6장. 프로그램 작성
  + 7장. 프로그램 완성
  + 8장. 언어적 세부 사항1 p.s Function
  + 9장. 언어적 세부사항2 p.s Class

### 2부 입출력
  - 10장. Input/Output stream
  - 11장. 입출력 맞춤화(정규화)
  - 12장. Display Model(Graphics & GUI)
  - 13장. Graphics Class
  - 14장. Graphics Class 설계
  - 15장. 함수와 데이터의 그래프 그리기
  - 16장. Graphical User Interface
    
### 3부 데이터와 알고리즘 
  - 17장. 벡터와 자유 저장 영역
  - 18장. Vector and Array
  - 19장. Vector, Template, Exception
  - 20장. Container & Iterator
  - 21장. Algorithm & Map

### 4부 시야 넓히기 
  - 22장. 프로그래밍의 이상과 역사
  - 23장. Text Control
  - 24장. 수치계산
  - 25장. Embedded System Programming
  - 26장. Testing
  - 27장. C Language Programming

### 5부 부록 
  - 부록 A. 언어 요약
  - 부록 B. 표준 라이브러리 요약
  - 부록 C. Visual Studio Start
  - 부록 D. FLTK Download
  - 부록 E. GUI 구현

[비야네 스트롭스트룹 교수님 홈페이지](https://www.stroustrup.com/index.html)

[std_lib_facilities.h code](https://www.stroustrup.com/Programming/std_lib_facilities.h)

이 Repositories는 **Programming-Principles and Practice Using C++ 2nd Edition - Bjarne Stroustrup, 최광민 옮김 에이콘출판**을 기반으로 학습한 내용을 정리한 것입니다.
원 저작권은 해당 출판사/저자에게 있습니다.

--------------------------------------------------------------------------------
# 참고 사항
## std_lib_facilities.h
 이 책은 C++언어를 단계별로 배우는 것이 아니라 C++의 문법을 적당히 이해하고, 프로그램 자체를 잘 짜는 방법에 치중되어 있기에 std_lib_facilities.h파일을 사용해서 더 간편히 짤 수 있게 도와준다. 예를 들어 error함수는 c++에서 제공해주지않지만 이 헤더 파일에 구현되어 있어 에러 메시지를 출력해주고, keep_window_open라는 함수를 통해 입력이 없어도 화면 창이 종료되지 않도록 도와준다. <br> 
 즉, 기초 선언 iostream, string, vector, cmath등...을 선언해주지 않아도 혹은 throw runtime_error를 안해줘도 쉽게 프로그래밍을 할 수 있도록 도와준다. <br>
 더 자세한 내용을 알고 싶다면 구글에 std_lib_facilities.h를 검색해보자. 
