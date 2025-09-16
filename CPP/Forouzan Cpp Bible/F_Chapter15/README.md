## Ch 15. 제네릭 프로그래밍 : 탬플릿 

 * ### 15-1. 개요
   일반화(Generalization) : 여러 상황에 적용할수 있는 프로그램을 하나 만들 때 사용하는 방법 <br>
   이를 Template Programming 또는 Generic Programming이라고도함 <br>

------------------------------------------------------------
 
 * ### 15-2. Function Template
   함수 템플릿을 사용하면 프로그램을 작성할 때는 처리만 작성하고, 컴파일할 때는 알아서 자료형이 세부적으로 지정되게 만들 수 있음<br>
   함수를 하나만 작성해도 여러 자료형에 적용되는 함수를 여러 개를 자동으로 만들 수 있음 <br>

     * 필요성
       
       Template Programming를 하지 않는다면, 여러 개의 함수를 정의 해야함 <br>
       그럼 코드의 유지보수나 가독성이 떨어짐 <br>

       [15-1. 여러 개의 함수 오버로드하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter15/15-1.cpp)
       
     * 사용
       
       템플릿 함수를 만들 때는 템플릿 자료형 위치에 PlaceHolder를 사용 <br> 
       템플릿 헤더는 template 키워드와 <>로 구성되고, <>에는 함수 내부에서 사용할 자료형 목록의 심볼을 지정함 <br>
       여러 개의 템플릿 자료형 심볼을 만들 수 있지만, 2개 이상의 템플릿 자료형 사용하는 경우는 매우 드묾 <br>
       오래된 코드에서 typename 대신에 class가 사용하는 경우가 있지만 현재 표준 라이브러리들은 내부적으로 typename 키워드를 사용함 <br>

       [15-2. 함수 템플릿 사용하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter15/15-2.cpp) <br>
       [15-3. 템플릿 함수를 이용한 변수 스왑](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter15/15-3.cpp)
  
       15-3코드처럼 pass by value가 아니라 pass by reference를 하고 싶으면 T를 T&로 변경 

         - 템플릿 인스턴스화
           
           개별적인 자료형에 대한 함수의 정의 생성이 컴파일 시점까지 이루어지지 않고, 컴파일되는 때에 컴파일러가 함수 호출에 필요한 만큼들의 함수들을 만들어 냄. 이러한 과정을 템플릿 인스턴스화(Template Instantiation)라고 함 <br>
           참고로 템플릿 인스턴스화와 클래스 인스턴스화는 완전히 다른 개념 <br>
           
     * 변형 
         - 자료형이 아닌 템플릿 매개변수
           
           함수 템플릿으로 자료형이 아닌 값을 정의 할 수 있음. 이럴 경우 매개변수를 전달하는 것과 비슷한 역할을 하고 자료형이 아니라 값을 정의하는거라 자료형이 고정 됨 <br>
           [15-4. 템플릿 함수 사용해서 배열 출력하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter15/15-4.cpp)
         
         - 명시적 자료 결정
           
           만약에 서로 다른 자료형을 모두 넣으면 오류가 발생 됨, 즉 T에 대한 자료형이 다르면 오류가 발생 <br>
           T라는 자료형은 하나의 템플릿 자료형이라 값은 반드시 **같은 자료형** 이여야 함.

           ```cpp
              smaller(23, 67.2); // 오류 발생
              smaller<double>(23, 67.2); // int 23이 23.0으로 변환되어서 실행 
           ```

         - 미리 정의된 연산
           
           int, double, char는 < 연산자가 정의되어 있어 활용이 가능함 즉, <연산자가 오버로드 되어 있는 모든 자료형은 사용할 수 있음, string 클래스도 < 연산자를 오버로드 하기 때문에 T를 string으로 교체해서 사용 가능.

           ```cpp
           smaller("Hello,"Bi"); //"Bi" 출력
           ```
  
           하지만 C문자열 같은 자료형은 연산자 오버로드가 되어있지 않음. 이러한 경우 특수화를 사용해야함. 
       
         - 특수화
           
           C 문자열은 < 연산자가 정의되어 있지 않아 템플릿 함수를 정의해도 C문자열을 매개변수로 전달해서 비교할 수 없음. 그리하여 템플릿 자료형이 아니라 특정 자료형으로 다른 함수를 정의해서 활용 해야함
  
           [15-5. 특수화 예시](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter15/15-5.cpp)
  
           참고로, 이미 정의되어 있는 템플릿 함수의 특수화라는 것을 나타내려면 함수 앞에 template<>를 사용해야하고, 특수화 하려면 모든 T를 같은 자료형으로 변경 해야함. <br>
           C 스타일 문자열은 const char* 이기에 모든 T 위치에 해당하는 자료형을 const char*로 입력해야함 <br>
           
         - 템플릿의 오버로딩
           함수 템플릿을 오버로딩하면 이름을 같지만, 시그니처가 다른 여러 개의 함수를 만들 수 있음<br>
           일반적으로 탬플릿 자료형은 같지만 매개변수의 수가 다른 함수를 만들어 낼 때 활용.

           [15-6 템플릿 오버로딩](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter15/15-6.cpp)

     * 활용
       인터페이스 파일에 넣고, 헤더는 애플리케이션 파일에서 읽어들이게 구성하면 템플릿 함수를 다른 애플리케이션에서도 사용할 수 있음
       
       [15-7. 애플리케이션 활용 예시](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter15/15-7)
       
---------------------------------------------

 * ### 15-3 Class Template

   템플릿 함수와 마찬가지로 다른 자료형에 같은 처리를 하는 클래스를 만들 때 사용함 <br>
   클래스 템플릿을 만들 때는 데이터 멤버와 멤버 함수를 모두 템플릿으로 만들어야 함 <br>

      * 클래스 템플릿 사용
        클래스에는 인터페이스와 구현이 있음, 클래스 템플릿 만들 때도 **인터페이스와 구현 모두에 템플릿 매개변수가 있어야함.**
           
           - 인터페이스

             클래스의 인터페이스는 데이터 멤버와 멤버함수에서 사용할 typename를 정의 해야함
             
           - 구현

             템플릿 자료형을 사용하는 **모든 멤버 함수 앞에<typename 이름>** 를 지정해야함. <br>
             그리고 클래스 ::연산자 앞에 클래스 이름에 <T>를 꼭 붙여줘야 함 <br>
             보통 <>안에 typename T라고 함 <br>
             
             [15-8. 클래스 템플릿 사용하는 예시](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter15/15-8)
             
             참고로, 비템플릿 클래스 구현과 템플릿 클래스 구현에서 차이는 컴파일러가 애플리케이션 파일을 컴파일할 때 템플릿 함수의 매개변수화가 이루어진 형태를 미리 인지하고 있다는 점임 <br>
             그래서 애플리케이션 파일에서 구현 파일을 헤더파일로 포함해야하고, 구현 파일은 ifndefm define, endif 매크로가 있어야 함.

      * 분산된 템플릿의 컴파일
        여러 파일에 분산되어 함수 템플릿과 클래스 템플릿을 가지는 경우, 여러 파일들을 컴파일하고 링크할 수 있음
        
           - 포함 방법
             
             inclusion approach라고 함, 선언과 정의를 모두 헤더 파일에 넣고, 헤더 파일을 읽어 들이는 형태. <br>
             물론, 선언은 .h, 정의(구현) 파일을 .cpp파일에 넣어 구분하는 것이 좋음 <br>
             파일을 구분하면 빠르게 전환할 수 있기 때문임 <br>
             기본적으로, 애플리케이션 파일에서 구현(정의) 파일을 읽어 들이고, 구현 파일에서 인터페이스(헤더) 파일을 읽어 들이는 형태로 사용 함 <br>
             
           - 분할 컴파일
             
             객체 지향 프로그래밍은 프로그램을 구분해서 작성하고 컴파일함, 구현을 사용자에게 숨길수 있도록 캡슐화 하는 방법도 있음<br>
             그런데 템플릿 함수와 템플릿 클래스를 사용할 경우 기존의 형태로 사용할 수 있음<br>
             컴파일러가 템플릿 함수와 템플릿 클래스의 내부 내용을 컴파일에 활용하기 때문에, 구현 파일을 독립적으로 컴파일할 수 없다는 문제가 있기 때문<br>
             C++표준에 **export 키워드**가 추가되면서 이러한 문제를 해결 할 수 되었는데, 템플릿 선언 또는 정의 앞에 export 키워들 붙이면 됨, 모든 템플릿 멤버 함수 앞에 붙여야 함 <br>

             ```cpp
             export template<typename T>  
             ```
             
             컴파일러가 export를 지원하지 못하는 경우에는 포함 방법을 사용해야 함<br>
             
             [15-9 스택 구현 예시](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter15/15-9)
             
      * friend와 typedef
           - friend
             
             템플릿 클래스 선언 때 freind 함수를 포함할 수 있음 <br>
             1. 템플릿 클래스는 비템플릿 함수를 friend로 가질 수 있고,
             2. 템플릿 클래스는 템플릿 함수를 friend로 가질 수 있음
             3. 또한 특수화된 함수를 friend로 가질 수 있음.
                
           - 별칭
             
             **typedef를 사용해서 템플랫 클래스의 별칭을 정의해서 사용하는 경우도 있는데 이럴 경우 별칭으로 일반적인 클래스 처럼 사용이 가능함** <br>
             
             ```cpp
             typedef stack<int> iStack;
             typedef stack<double> dStack;
             typedef stack<string, int> siStack;

             iStack s1;
             dStack s2;
             siStack s3;
             ```
             
      * 템플릿 클래스의 상속
        
        템플릿 클래스를 부모 클래스나 자식(템플릿, 비템플릿 둘 다 가능)으로 사용할 수 있음<br>
        상속은 가능하지만 거의 사용하지 않는다<br>
        
      * 기존에 사용한 템플릿 클래스
        
           - 문자열 클래스
             string 클래스는 basic_string이라는 클래스를 특수화한 클래스임
             
             ```cpp
             template<typename charT>
             class basic_string{.....};

             //라이브러리를 보면 string 클래스를 기반으로 2가지 특수화한 클래스가 있다
             typedef basic_string<char> string;
             typedef basic_string<wchar_t> wstring;
             ```
             
           - 입출력 클래스
             
             istream 클래스는 basic_istream 클래스를 char 자료형으로 특수화한 클래스임
             
             ```cpp
             typedef basic_istream<char> istream;
             typedef basic_istream<wchar_t> wistream;
             ```
