# Chapter 10 문자열 
-----------------------------------

#### C문자열과 C++문자열 

C문자열은 문자 배열을 만들고, 마지막 요소에 NULL("\0")를 설정하면됨 <br>
그리고 상수가 아닌 문자열(Nonconstant string)과 상수 문자열(Constant string)으로 구분할 수 있음. <br>
Nonconstant string은 문자의 값을 생성한 후에 변경할 수 있지만 Constant string은 문자의 값을 변경 할 수 없음 <br>

```cpp
char str[] ={'a','b','c','d','\0'}; // Nonconstant string
char str[] = "ABCD"; //Nonconstant string + compact form
const char str[] = {'a','b','c','d','\0'}; // Constant string
const char str[] = "ABCD"; //Constant string + compact form 
```
compact form에서 문자열을 큰따옴표를 감싸, 널 문자를 따로 입력하지않아도 알아서 마지막 요소에 널 문자가 들어가는 배여을 만들어줌 <br>

```cpp
char str[] = "ABCD";
char* p = str;
```

```cpp
const char str[] = "ABCD";
const char* p = str;
```
문자열 이름은 변수가 아니라 rvalue 포인터이기에 변수를 선언하고 문자열의 이름을 할당해야 함. <br>
C문자열은 마지막 문자가 널 문자로 크기를 간접적으로 알 수 있어, 포인터 변수를 리턴해도 문제 없음 <br>

* ##### 문자열 리터럴
  큰 따옴표로 감싸는 글자를 생성하는 것 <br>
  문자열 리터럴은 상수 엔티티이므로 한 번 생성된 이후에는 변경할 수 없음.

* ##### 문자열 리터럴을 사용해서 문자열 생성

  ```cpp
  char* str = "Hello"; // 오류 - 리터럴은 상수이기 때문에 
  const char* str = "Hello"; // 정상 작동 
  ```
 문자열 리터럴은 상수 포인터가 아닌 포인터에 할당하면 컴파일 오류가 발생.  <br>

 * ##### 간단한 형태의 초기화와 문자열 리터럴

   ```cpp
   char str1[] = "Hello";
   const char str2[] = "Hello";
   const char* str3 = "Hello";
   ```
* ##### 힙 메모리 생성
  배열 이기에 힙 메모리 위에도 생성 할 수 있는데, 문자열의 이름은 char 자료형에 대한 포인터로 간단한 형태로는 불가능. 즉, 상수 문자열이 아니라면 문자 하나하나 초기화 해줘야 함 <br>
  문자열이 상수 문자열 -> 문자열 리터럴 사용해서 초기화 가능

```cpp
char* str = new char[3]; //두 문자를 가질 수 있는 상수가 아닌 문자열
const char* str - new char[3]; //두 문자를 가질 수 있는 상수 문자열
```
* ##### 파괴 및 복사
 
 C문자열은 스택 메모리에 올라가면 함수가 종료될 때 자동 삭제, 힙 메모리에 올라 갔으면 delete 구문을 사용해야 함 <br>

```cpp
const char* str = new char[3]; // 생성
delete[] str; //파괴
```

C문자열은 복사 생성자가 없어 strcpy 또는 strncpy를 사용해서 C문자열을 복사할 수 있음. 

```cpp
strcpy(str1,str2); //str2 전체 복사
strncpy(str1, str2, n); // str2의 일부 복사
```
str1에 str2의 내용을 복사해서 붙이는 느낌임 
[10-1. 문자열 복사하기](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter10/10-1.cpp)

null문자를 제외한 문자열의 문자 수는 C문자열의 크기로 strlen를 통해 길이를 구할 수 있음. <br>

```cpp
stze_t n = strlen(str); //str 문자열 길이 구하기
```
strlen는 매개변수로 C문자열을 받고, size_t로 리턴을 하는데, size_t는 라이브러리 내부에서 부호 없는 정수를 나타낸다. 

[10-2. 문자열과 멀티 바이트 문자의 크기](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter10/10-2.cpp)

* ##### 입출력

[10-3. C문자열 사용하기](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter10/10-3.cpp)

getline 함수는 공백을 포함하여 한줄을 모두 읽어 들이고 싶은 경우에 사용.

```cpp
cin.getline(str,n); // '\n'을 구분 문자로 사용
cin.get(str,n,'구분 문자'); // '구분 문자'를 구분 문자로 사용 
```

[10-4. C문자열 사용하기](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter10/10-4.cpp)

* ##### 접근과 탐색
  
[10-5. C 문자열의 문자에 접근](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter10/10-5.cpp)

strchr, strrchr를 통해 문자를 탐색할 수 있음. 

```cpp
char* ptr = strchr(str, 'c'); //정방향
char* ptr = shtrrchr(str, 'c'); //역방향 
```
[10-6. C문자열 내부에서 문자 찾고 변경](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter10/10-6.cpp)

strstr는 문자열 내부의 문자열을 탐색할 수 있음. <br>

```cpp
char* ptr = strstr(str, substr); //서브 문자열 찾기
```
[10-7. 서브 문자열 탐색 ](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter10/10-7.cpp)

strpbrk는 문자열 내부에서 어떤 문자들 중 특정 하나가 등장하는 위치를 찾아야하는 경우에 사용<br>

```cpp
char* p = strpbrk(str, set); //문자 집합 set에서 처음 등장하는 문자 찾기
```

[10-8. 문자들 중에 특정 문자의 위치 찾기](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter10/10-8.cpp)

* ##### 비교와 결합
 
 strcmp, strncmp 사용해서 비교 가능 
 
 ```cpp
int a = strcmp(str1,str2); // str1, str2 전체 비교
int b = strncmp (str1,str2,n); // str1,str2 문자 일부 비교
```

[10-9. C문자열 비교하기](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter10/10-9.cpp)

한 문자열 뒤에 다른 문자를 붙일 수 있음, 결합(Concatenation)은 두 문자열 중에 하나만 변경이 일어남 <br>
strcat, strncat를 사용 

```cpp
strcat(str1,str2); // str1 뒤에 str2 결합 (append)
strncat(str1,str2,n); //str1뒤에 str2의 문자 n개 결합 
```
[10-10. strcat과 strncat 사용](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter10/10-10.cpp)

* ##### 토큰화
  string token은 문자열을 구분 기호(공백 등)으로 잘라 만들어진 작은 문자열임 <br>
  strtok 사용<br>
  
  strtok은 구분 기호가 아닌 문자 중에 처음 등장하는 문자를 찾아서 포인터를 리턴하고 만약에 찾을 수 없는 경우 아무 것도 하지 않는다. <br> 
  이어서 구분 기호를 찾아 해당 문자를 널 문자로 변경

  [10-11. C문자열 토큰화](https://github.com/ysungJ/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter10/10-11.cpp)

---------------------------------------------
#### C++ 문자열 클래스

C++라이브러리는 string이라는 클래스 제공. <br>
C 문자열과 다르게 **NULL 문자**로 끝나지 않음 <br>

* ##### C++ 문자열의 연산
 
 + 생성자
  C++ 문자열은 기본 생성자 1개, 매개변수가 있는 생성자 3개, 복사 생성자 2개를 갖고 있음. <br>

  기본 생성자 : string strg; <br>
  매개변수가 있는 생성자 : 
  
  ```cpp
  string strg1(5,'a'); //aaaaa
  string strg2("hello"); // hello 
  string strg3("hello",3); // "hel
```

복사 생성자 : 

```cpp
string strg1(oldStrg); //전체 복사
string strg2(oldstrg1, index, length); // 일부 복사
```

+ 소멸자
 힙에 생성된 문자 배열을 모두 제거하고, 스택에 할당된 모든 데이터 멤버도 제거 <br>
 delete연산자를 호출하는것으로 메모리 누수를 막을 수 있음

+ 크기와 용적

  크기를 늘리거나 줄이는 경우가 많으면 오버헤드가 발생할 수 있음. <br>
  이를 방지하고자, 시스템이 사용자가 사용할 문자열의 크기를 문자열의 크기보다 크게 예약할 수 있게 해줌 <br>

  + 크기와 최대 크기  :

```cpp
size_type n = strg.size(); // 크기 구하기 
size_type n = strg.max_size(); // 최대 크기 구하기 
```

주의점 : 멀티 바이트 문자를 사용할 때 size 함수의 결과를 주의 해야함 시스템에 따라 크기가 다르기 때문에. <br>

+ 크기 변경 (리사이징) :

 resize 함수 사용, 문자열의 크기를 변경 할 수 있음 <br>
n < size라면 문자열의 뒷 부분이 삭제, n > size라면 추가되는 부분이 다음 코드에서 채워져서 크기를 맞춤 <br>

```cpp
strg.resize(n,'c'); //문자열의 크기를 변경하고 남는 부분을 'c'로 채운다
```

  + 용적과 예약 : 
  
  capacity 함수를 사용해서 문자열의 현재 용적을 리턴. <br>
  추가적인 예약이 없으면 용적은 크기와 동일하고, reserce 함수를 사용해 용적을 추가로 예약할 수 있음 <br>

```cpp
size_type n = strg.capacity(); //용적 구하기
strg.reserve(n); //용적 예약
```

reserve 함수의 매개변수가 현재 문자열의 크기보다 작으면 아무 일도 일어나지않고, 문자열의 용적을 늘릴 수 만 있음 <br>

  + 빈 문자열 확인하기 :

  empty 함수는 문자열의 크기가 0이면 true를 리턴, 이외의 경우 false를 리턴 

  [10-12. 크기, 용적과 관련된 멤버함수 사용하기]()

 + 입출력 : 
  
   [10-13. 입출력 연산자 사용하기]()

   + Getline 함수 : 
   '\n'까지 읽거나 구분 기호를 사용자가 지정해서 읽음  

```cpp
getline(cin, strg); // '\n'까지만 읽어들임.
getline(cin, strg, 'c'); //'c'까지 읽어들임.
```
   
   [10-14. getline 함수로 입력받기]()

  + 접근과 출력 : 
   
   C++문자열의 문자에 단순한 배열처럼 접근 가능, at 함수도 있음
   
```cpp
char c = strg[pos]; // 문자 c 수정 가능
const char c = strg[pos]; // 수정 불가능
char c= strg.at(pos); // 수정가능
const char c = strg.at(pos); //수정 불가
```

  [10-15. 문자열 내부의 문자 추출하기]()

  [10-16. 모든 단어를 대문자로 만들기]()

  [10-17. 문자열 객체 뒤집기]()
 
 + 서브 문자열 추출 :

   substr 함수 사용, 첫 번째 매개변수로 인덱스, 두 번째 매개변수로 추출할 문자수를 지정 <br>
  
```cpp
string result =strg. substr(pos, n); //pos 위추부터 n개의 서브 문자열 추출
```

   [10-18. 서브 문자열 추출하기]()
 
 + 문자 탐색 :

   find 함수와 rfind 함수를 사용해서 찾을 수 있음.

   [10-19 문자열의 단어 추출하기]()

+ 문자열 비교 :

  compare 함수를 사용.
  
     [10-20. getline 함수로 입력받기]()

  + 연산자를 사용한 비교 :

     [10-21. getline 함수로 입력받기]()

    [10-22. getline 함수로 입력받기]()

    + 추가 연산 제거

      ```cpp
      strg.append(temp); // 뒤에 추가
      strg.insert(pos1, temp); // 중간에 삽입
      strg.replace(pos1,n1,temp); // 대체하기
      strg.assign(temp); //할당하기

      strg.clear(); //문자열 전체 제거
      strg.erase(pos,n); // 문자열의 일부 제거
      ```

    +  연산자 오버로드와 변환 :

  ```cpp
  string strg = temp; //문자열 할당
  string strg += temp; //문자열 복합할당
  string strg = temp1 + temp2; //문자열 결합
  ```

  [10-23. getline 함수로 입력받기]()

  [10-24. getline 함수로 입력받기]()

  ```cpp
  const char* arr =strg.data(); // 문자 배열로 변환
  const char* str =strg.c_str(); // C 문자열로 변환
  ```
  
위의 코드처럼 C++ 문자열 객체를 문자 배열 또는 C 문자열로 변환 할 수 있음. 

---------------------------------------------------

#### 10-3 [Lab] 응용 프로젝트 

##### 문자열과 관련된 사용자 정의 함수 만들기 

##### 진번 변환 시스템 만들기 
