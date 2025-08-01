## Chpater 16. 입출력 스트림.

  스트림 객체 및 클래스에 대해 알아보는 챕터.
  
-----------------------------------------------

  * ### 16-1. 개요

      C++는 스트림이라는 라이브러리 클래스를 사용해서 입출력 처리함. <br>
      프로그램을 실행하려면 메모리 위에 데이터를 저장해야 하는데, 처리를 위해 메모리에 저장된 데이터는 external source로부터 들어와서 external sink로 나감 <br>
      data source는 데이터를 생성하거나 제공하는 원본을 의미하고, data sink는 데이터를 받아 저장하거나 처리하는 최종 목적지를 의미함 <br>
      source는 키보드, 파일, 문자열 등일 수도 있고 sink는 모니터, 파일, 문자열 등일 수 있음.  대부분 소스로 키보드를 사용하고, 싱크로 사용했는데, 키보드는 데이터의 임시적인 소스(temporary source), 모니터는 임시적인 싱크(temporary sink)라고도 부름. 프로그램을 실행할 때 마다 다시 입력하고, 새로 출력해야하기 때문에,
      반면 File은 데이터의 영구적인 소스(permanent source), 영구적인 싱크(permanet sink)라고 부르는데, 파일은 여러번 사용될 수 있기 때문임 <br>
      문자열은 데이터의 내부 소스(internal source), 내부 싱크(internal sink)라고도 하는데 이는 특수한 목적으로 설계되었기 때문임 <br>

    - 스트림이란

    데이터 소스와 싱크는 프로그램과 연결되어 있지 않아, 데이터 흐름을 제어하고 읽고 쓰려면 프로그램과 이들을 연결할 중간 다리가 있어야하는데 이를 **스트림(stream)** 이라고 부름. 스트림은 입력 스트림과 출력 스티림이 있고 입력 스트림은 데이터 소스와 프로그램 사이의 중간 다리를, 출력 스트림은 프로그램과 데이터 싱크 사이의 중간 다리 역할을 수행함 <br>
    즉, 스트림이라는 중간 다리를 타고서 data byte가 입출력 됨. <br>
    한 번에 입출력을 모두 해주는 양방향 스트림도 존재 <br>

    - 데이터 표현

    텍스트나 이진 형식으로 소스에서 데이터 입력을 받고, 싱크로 데이터를 출력할 수 있음. 소스와 싱크는 컴퓨터 시스템의 일부이기에, 모두 바이트열로 구성됨. 참고로 **바이트열만 스트림을 타고 이동할 수 있음** <br>

    - 스트림 클래스

    C++ 입출력 연산을 다루기 위해 여러 스트림을 제공하는데, 가장 최상위에는 ios 클래스가 있으며, ios 클래스는 모든 입출력 클래스의 부모 클래스이기에 입출력 스트림 클래스가 가져야하는 데이터 멤버와 멤버 함수들을 정의하고 인스턴스화할 수 없는 계층임.

istream, ostream, iostream등은 프로그램을 콘솔과 연결할 때 사용해서 콘솔 클래스라고 함. <br>
ifstream, ofstream, fstream은 프로그램과 파일을 연결할 때 사용하므로 파일 스트림이라고 함. <br>
istringstream, ostringstream, stringstream은 문자열 스트림이라고 함 <br>

스트림을 활용 하려면  스트림 객체를 만들고, 스트림 객체를 소스 또는 싱크와 연결하여 읽기 또는 쓰기를 하고 소스 또는 싱크와의 연결을 해제하여 스트림을 소멸 시켜야함 <br>
또한 모든 스트림 객체들은 복사 생성자와 할당 연산자를 제공하지 않는다는 특징이 있으며, 객체를 사용할 때 내부적으로 어떤 변화가 일어나서 
1. 복사 생성자가 없어, 스트림 객체를 함수로 전달할 때 pass by value를 사용할 수 없고, **call by reference**를 사용해야함
2. 함수에서 스트림 객체를 리턴할 때 return by value는 사용할 수 없어 **return by reference**를 사용해야 함
3. 무조건 상태 변화가 일어나기에, 스트림 객체를 매개변수 전달 또는 리턴할 때 **const 한정자를 붙이면 안됨**

-------------------------------------------------

  * ### 16-2. 콘솔 스트림

    - 콘솔 객체

      istream은 키보드에서 데이터를 읽어 들일 때 사용하기 때문에 개발자가 인스턴스화하지 못 함. <br>
      그래서 시스템이  **cin** 이라는 이름으로 인스턴스화 하고 키보드와 연갈하고나서 제공, 참고로 cin은 프로그램이 종료될 때 소멸되고 키보드와 자동으로 연결이 해제됨.

      ostream은 모니터로 데이터를 출력할 때 사용 istream과 마찬가지로 개발자가 인스턴스화할 수 없음 <br>
      iostream 헤더 파일은 이미 인스턴스화한 cout, cerr , clog라는 객체를 사용, 시스템이 **자동으로** 만들어주고, 연결해주고 프로그램이 종료될 때 연결 해제 및 소멸까지 해줌. <br>

    - 스트림 상태
   
      빈 버퍼에서 데이터를 읽어 들이려고 하거나, 이미 꽉찬 버퍼에 데이터를 쓰면 입출력에 실패하는 경우에는 스트림의 상태를 추적해야 함. <br>
      스트림의 객체 상태는 스트림 상태(stream state)라는 데이터 멤버에 저장되고, 스트림에는 스트림의 상태를 확인할 수 있는 멤버 함수도 있음 <br>
      이러한 데이터 멤버와 멤버 함수들은 ios 클래스에 정의되어 있고, **모든 스트림 클래스는 ios 클래스로부터 상속을 받기 때문에 모든 스트림 클래스에서 데이터 멤버 및 함수를 사용할 수 있음.** <br>

    - 상태 데이터 멤버
   
      ios 스트림에는 iostate라는 자료형이 정의되어 있음 (시스템에 따라 구현이 조금씩 다름), 기본적으로 eofbit, failbit, badbit라는 3가지 상수가 정의되어 있음 <br>
      ios::eofbit : 입력 스트림에서는 추출할 추가적인 문자가 없고 출력 스트림에는 적용할 수 없음, 즉 스트림 버퍼에 존재하지 않은 바이퍼를 추출하려고 할 때 <br>
      ios::failbit : 입출력 스트림에서 유효하지 않은 읽기 연산을 뜻 함, 즉 원하지 않은 바이트를 추출하려고할 때  <br>
      ios::badbit : 입출력 스트림에서의 스트림에 문제가 발생했다는 것을 뜻 함, eofbit, failbit가 설정되었을 때 자동으로 설정되며, 메모리 부족 또는 변환 문제 등의 예외가 발생해서 스트림의 무결성 손실된 경우 설정 됨<br>
      ios::goodbit : 입출력 스트림에서 모든 것이 정상적으로 동작함, **위의 세 비트가 아무것도 설정되어 있지 않을 때, 스트림은 정상적인 상태로 스트림을 활용해 읽고 쓰기 작업이 가능함.** <br>
      또한 상태와 관련된 멤버 함수가 있는데 operator void*()는 객체를 자료형으로 변환하는 자료형 변환 연산자 오버로드 함수임, operator!()는 논리 부정 연산자 오버로드 함수로 operator void*()에서 불로 변환되는 것읋 리턴하는 함수라고 생각하면 됨 <br>
      [16-1. cin 객체 상태 확인 하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-1.cpp)
      
    - 콘솔 입출력
      istream, osstream 객체의 버퍼가 char 자료형으로 해석될 수 있는 8bit로 구성된 byte 집합을 내부적으로 사용할 수 있음 <br>
      컴퓨터의 메모리는 데이터를 이진으로 저장하기 때문에, istream, ostream 객체의 멤버 함수는 내부적으로 문자 집합을 읽어 들이고, 이진으로 변환해서 사용함.
    
    - 문자 멤버 함수
      입출력 스트림 클래스들은 문자와 관련된 멤버 함수 연산자를 제공하기 때문에 문자를 키보드로부터 읽고 모니터에 출력 가능 <br>
      istream 클래스 : int get(), istream& get(char &c)
      ostream 클래스 : ostream& put (char& c)

      istream은 2가지 형태의 get 함수를 제공하는데, int get()함수는 버퍼에 있는 문자자의 ASCII 정수를 리턴해주는 형태이며, istream 객체에 대한 참조를 리턴하지 않기 때문에 함수 호출할 떄 스트림의 상태를 확인 할 수 없음, istream& get(char& c)는 매개변수에 지정한 문자를 읽어 들이는 형태 <br>
      ostream은 put 함수 하나의 형태만 있는데, 이는 매개변수로 전달한 문자를 복사해서 함수에 출력하는 역할을 함. <br>
      [16-2. int get 함수 사용하는 예제](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-2.cpp) <br>
      [16-3. get, put 함수를 사용하는 예제](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-3.cpp) <br>
      [16-4. getline 함수를 사용하는 예제](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-4.cpp)

    - 기본 자료형 읽고 쓰기
      istream, ostream은 기본적으로 문자 스트림 클래스라 내부적으로 모든 것들이 문자 입출력으로 이루어짐. 즉, 기본 자료형의 값을 입출력 스트림에 넣을 수 없지만 오버로되어 있는 형태의 추출 연산자와 삽입연산자로 기본 자료형으로 값을 추출하거나, 값을 출력할 수 있음. <br>
      type은 bool, char, shorty, int, long, float, double, long double, void* 를 나타냄 <br>
      istream& operator>>(type& x); -> 다음 데이터 아이템 추출 <br>
      ostream& operator<<(type& x); -> 다음 데이터 아이템 삽입

------------------------------------------------------------------------------------------
      
  * ### 16-3. 파일 스트림

    데이터 소스와 싱크는 프로그램이 종료되면 데이터가 증발해서 다시는 사용할 수 없는 일시적인 형태지만 File은 영구적인 데이터 소스, 데이터 싱크임 즉, 한 번 만들어지면 해당 프로그램에서 이후에도 활용할 수 있고, 다른 프로그램에서도 사용 가능 함 <br>
    fstream을 통해 파일을 사용 할 수 있음, 즉 파일 스트림 클래스를 활용하면 파일과 프로그램을 연결해서 파일을 읽고 쓸 수 있음 <br>
    ifstream, ofstream, fstream이 있는데 이 클래스들은 istream, ostream, iostream으로부터 상속되어 있기에, 부모 클래스에 있던 모든 멤버 함수를 상속 받고, 인스턴스화와 파일 열기위 한 몇가지 기능을 가짐

    - 파일 입출력
      
      [16-5 파일에 출력하는 5가지 단계](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-5.cpp) <br>
      [16-6. 기존에 있는 파일 읽어들이기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-6.cpp)

    - 열기 모드 (opening mode)
      일반적으로 입력을 목적으로 할 때 ios::in과 ios::in | ios :: ate를 사용 <br>
      ios::in은 파일을 열고 버퍼의 가장 앞부분에 마커를 놓기 때문에 앞부분부터 byte를 읽어 들이며 파일의 끝에 도달하면(eofbit가 설정되는 경우) 읽기를 종료 함 <br>
      ios::in | ios :: ate은 마커를 마지막 byte에 놓기 때문에 처음부터 eofbit가 설정되어 있어 파일을 읽을 수 없음. 주로 byte를 반대로 읽거나, 파일의 크기를 찾을 때 사용함 
      
    [16-7. ios::in를 사용해서 파일 읽어 들이기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-7.cpp) <br>
    [16-8. 입출력 모드를 사용해서 파일의 내용 복사](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-8.cpp) <br>
    [16-9. 기존의 파일뒤에 추가하기 ios::out | ios :: app 사용](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-9.cpp) <br>
    [16-10. 입출력 모두를 목적으로 파일 열기 ios:: in | ios :: out 사용](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-10.cpp)
    
    - 다른 멤버 함수
      
      int gcount() const 문자 수 세기, 마지막 입력에서 추출한 문자 수를 리턴 <br>
      istream& unget() 마지막에 추출한 문자 스트림에 다시 넣기, 마지막에 추출한 문자를 다시 스트림에 넣음 <br>
      istream& putback(char c) unget과 같은 기능 <br>
      int peek() 문자 제거하지 않고 확인만 하기 <br>
      istream& ignore(int n = 1, int d = eof) 문자를 추출하지 않고 건너 뛰기

      [16-11. unget 함수를 사용한 예제 프로그램](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-11.cpp)

    - 순차 접근과 임의 접근
   
      버퍼에 차근차근 접근 -> 순차 접근(sequential access), 특정 위치에 곧바로 접근 -> 임의 접근(random access)

      [16-12. 문자의 위치와 값 출력 하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-12.cpp) <br>
      [16-13. 띄어쓰기 문자를 줄바꿈 문자로 변경하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-13.cpp) <br>
      [16-14. 파일의 크기 찾기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-14.cpp)

    - 이진 입출력

      텍스트 파일이 아닌 데이터를 처리할 때는 이진 모드로 파일을 열어야 함<br>
      ifstream& read(char* s, int n), ofstream& readsome(char* s, int n) -> 입력 <br>
      ifstream& write(char* s, int n) -> 출력
   
      위의 함수들은 메모리에 저장된 바이트와 스트림 버퍼 사이에 자료형 변환 없이 모두 문자로 처리함 그렇기 떄문에 문자 배열로 변환하거나 반대로 변환하려면 자료형을 지정할 수 있는 장치가 필요함 <br>
      reinterpret_cast<자료형2*>(*자료형1) <br>
      일반적으로 이진 입출력에서는 자료형1이 기본 자료형이고 자료형2가 char 자료형임

      [16-15. 이진데이터 읽고 쓰기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-15.cpp)

    - 사용자 정의 자료형으로 변환

      [16-16. 인터페이스 파일](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-16)

    - 이진 파일의 임의 접근
   
      이진 파일도 임의 접근이 가능한데, seekg 함수와 seekp 함수를 사용 할 수 있음 단, 파일에 저장되어 있는 모든 객체의 크기가 동일 해야함 <br>
      기본 자료형의 데이터 멤버만을 가지는 객체의 경우, 모든 데잍 ㅓ멤버 크기의 합으로 저장되는 크기를 구할 수 있음 <br>

  -------------------------------------------------------
      
  * ### 16-4. 문자열 스트림
  
    문자열 스트림의 데이터 소스와 싱크는 프로그램 내부에 있는 문자열 <br>
    내부에 있기 떄문에 열고 닫는 과정이 없고, 프로그램 내부에서 생성하고 자동으로 소멸되기 때문에 문자열 스트림에서는 open()함수와 close() 함수가 없음

    - 인스턴스화
      
      [16-19. 문자열 스트림 클래스 사용하는 프로그램](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-19.cpp)

    - 어댑터 활용
        
        [20-20 기본자료형과 문자열을 서로 변환 하는 프로그램 예제](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-20)

------------------------------------------------------

  * ### 16-5. 데이터 형식화

     모든 스트림 클래스는 ios 클래스의 상속을 받기 때문에, 데이터 멤버와 멤버 함수를 가짐 <br>
     사용자 정의 조정자를 만들려면 플래그, 필드, 변수를 알아야함.

    - 플래그, 필드, 변수
      
      [16-22. 플래그, 필드, 변수를 사용하는 프로그램](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-22.cpp) 

    - 표준 조정자
      
      [16-23. 조정자 출력을 사용하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-23.cpp)

    - 조정자 정의

    [16-24. 사용자 정의 조정자 2개를 사용하는 프로그램](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-24.cpp) <br>
    [16-25. 조정자 만들고 테스트하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-25.cpp) <br>
    [16-26. 매개변수가 있는 조정자](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter16/16-26)
