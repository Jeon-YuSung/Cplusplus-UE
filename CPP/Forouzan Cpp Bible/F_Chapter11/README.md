## Ch11. 클래스간의 관계

---------------------------------
### 11-1. 상속(inheritance)

  C++에서 범용적인 클래스를 Base class 또는 Super Class라고 함 (혹은 부모 클래스) <br> 
  구체적인 클래스를 Derived Class 또는 Sub Class라고 부름 (혹은 자식 클래스). <br> 
  Sub class는 Super Class에서 확장(Extend)한 것이라고 표현. <br>  

  파생 클래스를 만들 때 public, protected, private 3가지 방식으로 만듬 <br>
  상속의 종류를 따로 지정하지 않으면 private 상속. <br>
  명시적으로 상속할 때 접근 제한자의 종류를 지정해주는 것이 일반적 <br>

[11-1.Public상속](https://github.com/ysungJ/Cplusplus-UE/edit/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter11/11-1.cpp)

[11-3. 사람의 객체정보를 상속하여 학생의 객체 정보와 학점을 출력하는 프로그램](https://github.com/ysungJ/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter11/person_and_student)


* 상속 막기
  설계자 입장에서 추가적인 클래스 상속을 막고 싶을 때 **final 한정자**를 사용<br>
  final 한정자는 클래스 계층 구조의 어떤 위치이든 사용 할 수 있음.

  * 상속 트리
    
    [11-4. 객체를 통해 사람, 학생, 노동자의 정보를 출력하는 프로그램](https://github.com/ysungJ/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter11/Class_Employee)
    
-------------------------------------

### 11-2. 연관(Association)
  
  클래스들의 관계를 상속만으로 표현할 수 없음 <br>
  **다중성**은 연관과 관련된 객체를 나타냄 <br>

  * 소유 (aggregation)

    has-a 관계로 표현하는 객체의 소유와 관련된 특별한 종류의 Association <br>
    aggregation는 **단방향** 관계, 양방향 관계가 되면 무한한 관계가 될 수 있어, 사용하지 않는다. <br>

    [11-5. date클래스를 이용하여 사람의 생일 정보를 확인하는 프로그램](https://github.com/ysungJ/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter11/Aggregation-Date%20and%20Person)

  * 구성 (composition)
 컨테이너의 존재에 따라서 내부에 있는 내용물의 존재가 달라지는 특별한 종류의 Association <br>
aggregation와 composition의 관계를 정하는 것은 설계자의 주관 <br>
composition 관계는 내용물을 데이터 멤버로 갖는 컨테이너 형태로 설계되고, 내부에 직접적으로 내용물을 가진다.
그리고 컨테이너가 소멸할 때 내용물도 함께 소멸된다

[11.6 노동자의 급여와 풀 네임을 알아보는 프로그램](https://github.com/ysungJ/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter11/Composition_Employee%20and%20Name)

 -------------------------------------
 ### 11-3. 의존(dependency)
dependency는 inheritance와 Association의 관계 보다는 약한 관계로 굉장히 다양한 정의가 있음 <br>
의존 관계는 **사용 관계 (uses-a)** 라고 표현함 <br>
 클래스A가 클래스B를 내부적으로 사용한다면, 클래스A가 클래스B를 의조하는 것임. <br>
 즉 클래스B가 없으면 A가 정상적으로 작동하지 않음 
 
1. A의 멤버 함수에서 매개변수로 B 자료형을 사용하는 경우 <br>
2. A의 멤버 함수에서 리턴값으로 B 자료형을 사용하는 경우 <br>
3. A의 멤버 함수에서 지역 변수로 B 자료형을 사용하는 경우 <br>
등으로 정리 할 수 있음 <br>

* UML 다이어 그램
  
 의존 관계에서는 UML 클래스 다이어그램과 시퀀스 다이어 그램을 사용.

 [의존 관계을 보여주는 예시 프로그램](https://github.com/ysungJ/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter11/Dependency_Invoice%20and%20Product)

------------------------------
### 11-4 [LAB] 응용 프로젝트

#### Tokenizer 클래스 설계하기 
