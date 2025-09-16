## Ch.20 디자인패턴

정보처리기사 대비용으로 공부하는 단원. 

----------------------------------

  ### 20-1. 개요 
  
  * 객체 지향 프로그래밍 에서 가장 중요한 것은 **재사용**인데, 단순하게 코드 재사용이 아닌 문재를 해결하는 방법이나 패턴 자체도 재사용할 수 있어야 함 <br>
  * 객체 지향의 특징인 **캡슐화, 상속, 추상화, 다형성**과 설계 원칙인 **SOLID** 기반으로 구현됨 <br>
  *  SOLID 원칙은 5가지로 나눌 수 있으며 다음과 같다.
     1. 단일 책임 원칙 (Single Responsibility Principle), (SRP)  : 한 클래스는 하나의 책임만 가져야 한다.
     2. 개방-폐쇄 원칙 (Open-closed Principle), (OCP) : 소프트웨어 요소는 확장에는 열려 있으나 변경에는 닫혀 있어야 한다. 즉, 기존의 코드를 변경하지 않고 기능을 수정하거나 추가할 수 있도록 해야한다. 
     3. 리스코프 치환 원칙 (Liskov Substitution Principle), (LSP) : 프로그램의 객체는 프로그램의 정확성을 깨뜨리지 않으면서 하위 타입의 인스턴스로 바꿀 수 있어야 한다 계약에 의한 설계를 참고하라. 즉, 하위 타입 객체는 상위 타입 객체에서 가능한 행위를 수행할 수 있어야함 -> 상위 타입 객체를 하위 타입객체로 치환해도 정상적으로 동작해야함. 상속 관계에서는 일반화 관계 IS-A가 성립해야 함.  
     4. 인터페이스 분리 원칙 (Interface Segregation Principle), (ISP) : 특정 클라이언트를 위한 인터페이스 여러 개가 범용 인터페이스 하나보다 낫다. 즉, 자신이 사용하는 메소드에만 의존해야하며, 클래스는 자신이 사용하지 않는 인터페이스는 구현하지 않아야함 -> 하나의 통상적인 인터페이스보다는 여러 개의 세부적이고 구체적인 인터페이스가 낫다. 
     5. 의존관계 역전 원칙 (Dependency Inversion Principle), (DIP) : 프로그래머는 추상화에 의존해야지, 구체화에 의존하면 안된다. 의존성 주입은 이 원칙을 따르는 방법 중 하나다. 즉, 의존 관계를 맺을 때, **변하기 쉬운 구체적인 것** 보다는 **변하기 어려운 추상적인 것에** 의존 해야함 
    
  * 디자인 패턴 GoF(Gang of Four) 기준으로 3가지 패턴으로 나눌 수 있음 **생성(Creational Pattern), 구조 (Structural Pattern), 행동 (Behavior Pattern)** 임

  * 디자인 패턴의 장점
    1. 재사용성 : 반복적인 문제에 대한 일반적인 해결책을 제공하여, 유사한 상황에서 코드를 더 쉽게 작성할 수 있음
    2. 가독성 : 일정한 구조로 정리하고, 명확하게 작성하여 개발자가 코드를 이해하고 유지보수하기 쉽게 만듬
    3. 유지보수성 : 코드를 쉽게 모듈화할 수 있으며, 변경이 필요한 경우에 해당 모듈만 수정하여 유지보수가 쉬워짐
    4. 확장성 : 새로운 기능을 추가하거나 변경할 때 디자인 패턴을 사용하면, 기존 코드를 변경하지 않고도 새로운 기능을 통합할 수 있음.
    5. 안정성과 신뢰성 : 검증된 해결책을 제공해줌
    
-----------------------------------

  ### 20-2. 생성 패턴 (Creational Pattern)
   * 전통적인 방법으로, 인스턴스화하면 안되는 상황에서, 어떤 형태로 객체를 인스턴스화해야 하는지에 대한 방법 <br>
   * 객체 지향 프로그래밍은 객체의 설계와 생성을 분리(분할 컴파일)이 목적 <br>
   * 싱글턴, 팩토리 메소드, 빌더, 프로토 타입이 있음

   * **싱글턴 패턴 (Singleton Patton)**
      - **사용자가 클래스의 인스턴스를 하나만 생성도록 강제하는 방법**으로 시스템에서 컨트롤러 또는 관리자 역할을 하는 객체를 만들 때 사용함
      - 클래스의 생성자가 한 번만 호출되게 강제 해야하지만 C++에서는 생성자를 포함한 함수의 호출 횟수를 제한할 수 없다.
      - create함수를 통해 만들 수 있고, create함수가 싱글턴 객체에 포함될 경우, 정적(Static) 함수로 만들어야 함
      - 생성자를 private로 선언하여 사용자가 직접적으로 접근할 수 없도록 만들어야함.

      [20-1. 싱글턴 패턴 예제 코드](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter20/Singleton%20Pattern)

   * **팩토리 메소드 패턴 (Factory Method Patten)**
      - 객체를 생성하는 것은 전통적으로 사용자의 책임이기에, 객체를 만들 때 사용자는 객체와 관련된 세부적인 내용을 알고 있어야 함. 팩토리 메소드 패턴은 사용자의 이러한 점을 쉽게 만들어 주는 패턴
      - **팩토리 메소드 패턴을 사용하면 사용자는 최소의 정보만 제공하면, 적합한 객체를 인스턴스화 할 수 있음**
     
     [20-2. 팩토리 메소드 패턴 예제 코드](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter20/Factory%20Method%20Pattern)

  * **빌더 패턴 (Builder Pattern)**
     - 객체의 생성과 객체의 표현 형태를 분리해서 사용자가 쉽게 사용할 수 있도록 해주는 방법
     - GUI 프로그램에서 복잡한 그래픽 객체를 만들 때 사용 함. 

    [20-3. 빌더 패턴 예제 코드](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter20/Builder%20Pattern)
  
  * **프로토타입 패턴 (Prototype Pattern)**
    - 사용자가 객체를 많이 만들어야 할 때 사용
    - clone 함수를 사용하면, clone함수 내부에서 복사 생성자를 호출하므로, 별도의 인스터스화와 초기화 없이 객체를 만들어 낼 수 있음.
    - 복제는 원본 대상이 있어야 하므로, 일단 첫 번째 객체는 생성자를 호출해서 만들어야 함.

     [20-4. 프로토 타입 예제 코드](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter20/Prototype%20Pattern)
    
----------------------------------

  ### 20-3. 구조 패턴 (Structural Pattern)
  * 간단한 객체의 조합으로 복잡한 새로운 객체 구조를 만들어 문제를 해결하는 방법 
  * 적절한 자료형이 없는 상태에서 문제를 해결해야 하는 경우가 있는데, 이러한 경우에는 이미 존재하는 인터페이스와 구현을 결합해서 새로운 자료형을 만들어내 문제를 해결할 수 있음 
  * 구조 패턴은 **상속과 구성을 결합해서 사용하는 방법을 정리한 것**으로 브리지 패턴, 어댑터 패턴, 퍼사드 패턴, 프록시 패턴, 데코레이터 패턴, 컴포짓 패턴이 있음.

  * **브리지 패턴 (Bridge Pattern)**
    - 객체 지향은 인터페이스와 구현을 분리함, 일반적으로 구현은 사용자가 볼 수 없지만 인터페이스는 공용 인터페이스라는 형태로 모두가 확인 가능.
    - 인터페이스와 구현을 분리하면, 인터페이스를 동일하게 유지한 상태로 구현을 바꿀 수 있음. 하지만 반대로 구현은 유지하되, 인터페이스를 바꾸고 싶다면 브리지 패턴을 사용하여 바꿀 수 있음
    - 즉, 브리지 패턴은 **새로운 인터페이스를 만들 때, 이전의 구현을 변경하지 않고 간단하게 구현할 수 있게 해주는 패턴.**
   
  * **어댑터 패턴 (Adapter Pattern)**
    - **기존의 인터페이스를 사용자가 원하는 인터페이스로 변경하게 해주는 어댑터를 끼워주는 패턴**
    - 예를들어, 전원플로그는는 국가별로 모양이 달라 사용할 수 없음 이때 전원 플러그의 모양을 변경하는 어댑터를 사용해서 전기를 사용할 수 있도록 함. 
      
  * **퍼사드 패턴 (Facade Pattern)**
    - 어댑터 패턴처럼 인터페이스와 관련된 패턴으로, **서브 시스템에 하나의 통합된 인터페이스를 제공하는 패턴**
   
      [20-5. 퍼사드 패턴 예제 코드](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter20/Facade%20Pattern)

  * **프록시 패턴 (Proxy Pattern)**
    - 프록시란 대리인이라는 뜻으로, 컴퓨터 프로그래밍에서도 **실제 객체의 일을 다른 객체가 하도록 하는 프록시 객체를 사용하는 패턴임**

      [20-6. 프록시 패턴 예제 코드](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter20/Proxy%20Pattern)

  * **데코레이터 패턴 (Decorator Pattern)**
    - 데코레이터 패턴을 사용하면 런타임 때 객체를 데코레이션을 할 수 있음
    - 데코레이션은 꾸민다는 뜻으로 추가적인 특징을 부여한다는 의미로, 여러 개의 다른 특징을 가진 객체를 만드는 것이 아니라, **하나의 객체를 여러 객체로 꾸며서 특징을 추가한다는 것임**
    - 일반적으로 GUI 애플리케이션에서 많이 사용됨.
   
      [20-7. 데코레이터 패턴 예제 코드](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter20/Decorator%20Pattern)

    - 데코레이터 패턴은 패턴을 사용한 것인지도 모르는 결과가 나올 수 있음. 하지만 사용하기 전에 어떤 원리가 있는지 알아 두면, 더 잘 활용할 수 있음. 
  
  * **컴포짓 패턴 (Composite Pattern)**
    - **여러 객체로 구성된 객체를 하나의 간단한 객체처럼 취급해야 할 때 사용**
    - 컴포짓 패턴도 GUI 프로그래밍에서 많이 사용됨.

      [20-8. 컴포짓 패턴 예제 코드](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter20/Composite%20Pattern)
      
-----------------------------------

  ### 20-4. 행동 패턴 (Behavior Pattern)
  * 어떤 객체가 혼자 처리할 수 없는 문제를 여러 개의 객체로 분할해서 문제를 해결하는 방법
  * 복잡한 행동을 여러 객체가 서로 통신하면 효율적으로 처리 할 수 있음. 예를 들어서 상속을 사용해서 행동을 여러 클래스에 분할하거나, 구성을 사용해서 책임을 분산할 수 있음.
  * 행동 패턴에는 **반복자 패턴, 템플릿 메소드 패턴, 스트래티지 패턴(전략 패턴), 커맨드 패턴(명령 패턴), 옵저버 패턴(관찰자 패턴), 상태 패턴, 메멘토 패턴, 책임-연쇄 패턴, 중재자 패턴, 방문자 패턴**이 있음.

  * **반복자 패턴(Iterator Pattern)**
    - 컨테이너의 구현과 상관없이, **컨테이너의 구현을 숨기고, 컨테이너의 요소에 접근할 수 있게 해주는 반복자를 사용하는 패턴**
      
  * **템플릿 메소드 패턴(Template Method Pattern)**
    - 어떤 처리를 세부적인 부분으로 나누고 부모 클래스에서 순서를 정의한 뒤에, 일반적인 부분을 구현한 뒤 자식 클래스에서 수부적인 부분을 정의해서 사용하는 패턴
    - 즉, **불변 속성은 부모 클래스에서 정의하고, 변할 수 있는 부분은 자식 클래스에서 정의하는 패턴**
      
      [20-9. 템플릿 메소드 패턴 예제](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter20/Template%20Method%20Pattern)
      
  * **스트래티지 패턴 or 전략 패턴(Strategy Pattern)**
    - **함수 객체를 사용하는 패턴**

    [20-10. 전략 패턴을 사용하는 예제](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter20/Strategy%20Pattern)
    
  * **커맨드 패턴 or 명령 패턴(Command Pattern)**
    - 초기의 객체 지향 프로그래밍에서 사용하던 **콜백 함수를 객체 지향적으로 어떻게 확장할 수 있을까?** 에서 시작한 패턴으로 함수끼리 통신하게 하지 말고, 객체끼리 통신하게 함.
    - 다형성을 기반으로 계층 구조를 갖는 여러 개의 명령을 만들 수 있음.
    - 모든 명령에는 execute 함수가 있음.
    - 커맨드 패턴과 콜백 매커니즘을 사용하는 것과 비교해보면 다음과 같은 특징이 있음.
      1. 모든 함수가 클래스의 메소드로 구현
      2. 함수 포인터를 사용하지 않아도 됨
      3. Receiver 객체에 여러 명령 객체를 전달하게 구성해서, 쉽게 패턴을 확장할 수 있음.
      4. 다형성을 사용해서 여러 종류의 Receiver 객체를 사용할 수 있음.

    - 일반적으로 GUI 애플리케이션에서 사용됨.
       
         [20-11. 커맨드 패턴 사용 예제](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter20/Command%20Pattern)
      
  * **옵저버 패턴 or 관찰자 패턴(Observer Pattern)**
    - 상태가 변경될 때 이를 알려주는 객체가 필요하면 옵저버 패턴을 사용
    - 옵저버 패턴에는 Subject 객체와 Observer 객체가 있는데, 일단 Observer 객체가 Subject 객체를 구독(Subscribe)하게 함, 구독을 하면 Subject 객체는 자신의 상태가 변경될 때, Observer 객체에 메시지를 보내 이를 통지함, 구독은 이후에 구독 해제(Unsubscribe)할 수 있으며, 구독 해제시 Subject 객체가 변경되어도 Observer 객체에 이를 통지 하지 않음.
    - 구독과 구독 해제는 유니캐스트로 이루어져, 옵저버 객체는 필요할 때 1대1로 구독을 함. 반복 통지는 구하고 있는 모든 대상에 멀티캐스트로 이루어지기 때문에 Subject 객체는 구독하고 있는 모든 옵저버 객체에게 1대N으로 통지함.
   
      [20-12. 옵저버 패턴 예제](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter20/Observer%20Pattern)
      
  * **상태 패턴(State Pattern)**
    - 상태가 변경되면, 행동이 달라지는 대상이 있음. On/Off하는 전등이나 자판기 등등
    - On/off 같은 상태를 객체로 정의하는 것이 상태 패턴임

      [20-13. 상태 패턴 예제](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter20/State%20Pattern)
      
  * **메멘토 패턴(Memento Pattern)**
    - 객체를 변경했는데, 어떠한 이유로 이전 상태로 복구해야 할 때, **객체를 이전 상태로 복구하는 메멘토 패턴**을 사용함.
    - 메멘토 패턴은 이전 상태를 유지하는 메멘토 객체라는 별도의 객체를 사용, 그렇기 때문에 상태를 변경 하는 객체(Originator 클래스의 객체)와 이전 상태를 저장하기 위한 객체(Memento 클래스의 객체)라는 2개의 객체가 필요함.
   
      [20-14 메멘토 패턴 예제](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter20/Memento%20Pattern)
      
  * **책임-연쇄 패턴(Chain-of Responsibility Pattern)**
    - 책임 연쇄 패턴에서는 **일련의 처리를 가진 객체가 있는데, 첫 번째 객체에 요청을 처리할 수 있는 기회를 제공하고, 만약 첫 번째 객체에서 모든 요청을 처리할 수 없다면, 다음 객체로 전달... 또 다른 다음 객체로 전달... 이런 과정을 마지막 객체까지 계속 반복하는 패턴임.**
    - 만약에 마지막 객체도 요청을 처리할 수 없다면, 요청이 취소(drop)됨
    - 일반적으로 GUI 프로그래미엥서 사용함.
   
      [20-15. 책임 연쇄 패턴 예제](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter20/Chain-of%20Responsibility%20Pattern)

      
  * **중재자 패턴(Mediator Pattern)**
    - **중재자를 사용해서 n개의 객체 사이의 커뮤니케이션(통신)을 단순화 하는 패턴.**
    - 만약에 중재자가 없이 n개의 객체가 커뮤니케이션을 하라면, 모든 객체는 (n-1)개의 객체를 구성(composition)해야 하기 때문에 n(n-1)개의 포인터가 필요함.
    - 하지만 중재자 패턴을 사용하면, 각각의 객체에 대한 포인터를 하나씩, 모두 n개의 포인터를 갖고 다른 객체들은 포인터를 따로 가질 필요가 없으며, 다른 객체와 커뮤니케이션할 때는 중재자 객체를 사용함
    - 그룹에 새로운 객체를 추가할 때도 편함. 중재자가 없으면 모든 객체에 포인터를 하나하나 추가하기 때문에 불편하고 중재자를 사용하면 중재자가 객체에 포인터하나만 추가하면 됨.

      [20-16. 중재자 패턴 예제](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter20/Mediator%20Pattern)
      
  * **방문자 패턴(Visitor Pattern)**
    - 일부 연산을 사용자가 구현해야 하지만, 사용자가 캡슐화의 원칙과 다형성의 원칙을 위반하고 싶지 않아 **객체의 구현을 바꾸지 못하게 하고 싶을 때**가 있을 수도 있음.
    - 이 때, 사용자가 객체를 건드리지 못하고, 방문자로 추가적인 구현만 제공하게 하면 됨.
    - 일반적으로 컴파일러 설계 소프트웨어 또는 GUI 애플리케이션에서 많이 사용함.

      [20-17. 방문자 패턴 예제](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter20/Visitor%20Pattern)
