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
[10-1. 문자열 복사하기]()

null문자를 제외한 문자열의 문자 수는 C문자열의 크기로 strlen를 통해 길이를 구할 수 있음. <br>

```cpp
stze_t n = strlen(str); //str 문자열 길이 구하기
```
strlen는 매개변수로 C문자열을 받고, size_t로 리턴을 하는데, size_t는 라이브러리 내부에서 부호 없는 정수를 나타낸다. 

[10-2. 문자열과 멀티 바이트 문자의 크기]()

* ##### 입출력

[10-3. C문자열 사용하기]()

getline 함수는 공백을 포함하여 한줄을 모두 읽어 들이고 싶은 경우에 사용.

```cpp
cin.getline(str,n); // '\n'을 구분 문자로 사용
cin.get(str,n,'구분 문자'); // '구분 문자'를 구분 문자로 사용 
```

[10-4. C문자열 사용하기]()

* ##### 접근과 탐색
  
[10-5. C 문자열의 문자에 접근]()

strchr, strrchr를 통해 문자를 탐색할 수 있음. 

```cpp
char* ptr = strchr(str, 'c'); //정방향
char* ptr = shtrrchr(str, 'c'); //역방향 
```
[10-4. C문자열 내부에서 문자 찾고 변경]()

strstr는 문자열 내부의 문자열을 탐색할 수 있음. <br>

```cpp
char* ptr = strstr(str, substr); //서브 문자열 찾기
```
[10-7. 서브 문자열 탐색 ]()

strpbrk는 문자열 내부에서 어떤 문자들 중 특정 하나가 등장하는 위치를 찾아야하는 경우에 사용<br>

```cpp
char* p = strpbrk(str, set); //문자 집합 set에서 처음 등장하는 문자 찾기
```

[10-8. 문자들 중에 특정 문자의 위치 찾기]()

* ##### 비교와 결합
 
 strcmp, strncmp 사용해서 비교 가능 
 
 ```cpp
int a = strcmp(str1,str2); // str1, str2 전체 비교
int b = strncmp (str1,str2,n); // str1,str2 문자 일부 비교
```

[10-9. C문자열 비교하기]()

한 문자열 뒤에 다른 문자를 붙일 수 있음, 결합(Concatenation)은 두 문자열 중에 하나만 변경이 일어남 <br>
strcat, strncat를 사용 

```cpp
strcat(str1,str2); // str1 뒤에 str2 결합 (append)
strncat(str1,str2,n); //str1뒤에 str2의 문자 n개 결합 
```
[10-10. strcat과 strncat 사용]()

* ##### 토큰화
  string token은 문자열을 구분 기호(공백 등)으로 잘라 만들어진 작은 문자열임 <br>
  strtok 사용<br>
  
  strtok은 구분 기호가 아닌 문자 중에 처음 등장하는 문자를 찾아서 포인터를 리턴하고 만약에 찾을 수 없는 경우 아무 것도 하지 않는다. <br> 
  이어서 구분 기호를 찾아 해당 문자를 널 문자로 변경

  [10-11. C문자열 토큰화]()

---------------------------------------------
#### C++ 문자열 클래스.
