## Chapter19 STL

  - ### 19-1. STL의 구성 요소 

  표준 템플릿 라이브러리 (STL- Standard Template Library)는 SW 재사용성과 기능 분리라는 2가지 문제를 해결하기위해 개발됨. 

  - Container
    
    컨테이너는 STL의 **핵심**으로 목적에 따라 Sequence Container, Container Adapter, Associate Container, Pseudo Contatiner로 구분 가능

  - Algorithm
    
    컨테이너 요소에 적용할 연산을 의미, 크게 4가지로 구분 가능 <br>
    1. non-mutating algorithm(비변경 알고리즘)은 container 구조를 변경하지 않음
    2. mutating algorithm(변경 알고리즘)은 container 구조를 변경함.
    3. sorting algorithm(정렬 알고리즘)은 container의 요소를 정렬함.
    4. numeric algorithm(수치 알고리즘)은 숫자 요소에 대한 수학 처리를 함.

  - 반복자
    
    container와 container 내부의 요소는 서로 자료형에 영향을 주지 않음 <br>
    STL는 반복자(iterator)를 사용해 요소 하나하나에 접근해서 처리함, 반복자는 컨테이너의 자료형 또는 요소의 자료형과 상관없이 모두 사용 가능, 또한 컨테이너가 반복자를 지원하기만 한다면 어떤 것을 활용해도 알고리즘을 적용할 수 있음
     
  - 함수와 개체
    
    STL 에는 여러 범용 알고리즘이 존재하고 필요한 경우에는 함수 또는 함수 객체를 사용해 사용자 정의 알고리즘을 정의할 수 있음
    함수를 활용할 때는 정해진 형태의 함수를 만들어야하고, 함수 객체를 활용할 때는 operator() 연산자 오버로드가 정의된 클래스를 만들어야함

----------------------------------------------------------------------------

  - ### 19-2. 반복자

  -  반복자의 구조
    
     포인터를 추상화 한 것, 데이터 멤버로 포인터를 가지고 이를 활용하는 여러 멤버 함수를 가짐 또한 객체로 포인터를 추상화하면 추가적인 제한을 걸거나 기능을 추가할 수 있음 <br>
     컨테이너의 내부 구조를 사용자에게 숨기고 사용만 할 수 있게 만들 수 있고, 사용자는 외부 반복자라는 것을 사용해서 컨테이너 내부의 요소에 접근할 수 있음 <br>
     내부 반복자는 외부 반복자를 처리할 때 사용

  - 종류
    
    입력 반복자, 출력반복자, 전방 반복자, 양바향 반복자, 임의 접근 반복자가 존재 <br>
    1. 입력 반복자 (input iterator) - 요소를 읽을 때 사용, **읽기만 가능** 
    2. 출력 반복자 (output iterator) - 요소를 쓸 때 사용, **쓰기만 가능**
    3. 전방 반복자 (forward iterator) - 요소를 읽고 쓸 때 사용, 즉 입력 반복자 + 출력반복자
    4. 양방향 반복자 (bidirectional iterator) - 양방향으로 움직일수 있는 반복자
    5. 임의 접근 반복자(random-access iterator) - 양방향 접근자에 [],+,-,<,<=,>,>= 연산자를 추가한 반복자로 이런 연산자를 사용해서 **한 번에 원하는 위치의 요소에 접근 할 수 있음**
       
  - 이동방향
    
    컨테이너는 기본적으로 **기본 반복자(iterator)와 역 반복자 (reverse_iterator)** 라는 2가지 종류로 정의 <br>
    기본 반복자의 ++와 +는 뒤로 이동, --와 -는 앞으로 이동을 나타냄, 역 반복자의 ++와 +는 앞으로 이동, --와 -는 뒤로 이동을 나타냄
    
  - 상수성
    
    데이터를 변경할 수 있는지 없는지를 상수성(constantness)라고 함 <br>
    컨테이너에는 const iterator와 const_iterator가 정의되어 있음 <br>
      
      + 자료형 const iterator
        한 번 어떤 요소를 가리키면, 다른 요소를 가리킬 수 없음. 즉, 고정된 곳을 가르킴.
        
      + 자료형 const_iterator
        요소를 rvalue로 역 참조하기에 요소를 변경할 수 없음. 즉, 값을 변경할 수 없는 상수로 배열을 선언한 것과 비슷함.
   
---------------------------------------------------------------------------

  - ### 19-3. Sequence Container

    프로그래머가 요소를 저장하고 요소를 찾는 순서를 제어할 수 있는 컬렉션으로 Vector, deque, list라는 3가지 Sequence Container를 제공

      - Vector
        
        벡터는 빠른 임의 접근을 할 수 있으며, 컨테이너의 뒤에 빠른 삽입과 삭제를 함. <br>
        그리하여 컨테이너의 앞과 중간에 요소를 추가하거나 제거하는 경우에는 적합 하지 않음. <br>
        힙 메모리에 할당된 배열을 활용해서 구현했기에 다양한 연산을 제공해주고, 배열처럼 인덱스를 사용해 요소에 접근 가능. 또한 배열은 고정 크기로 크기 변경을 못 하지만, 벡터는 필요한 경우 크기를 변경할 수 있음 <br>
        또한 배열 대신 아무때나 사용 가능함 

        [19-1. 벡터의 반복자 사용해보는 예제](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/Vector/19-1.cpp) <br>
        [19-2. 반복자를 사용한 양방향 임의 접근 예제](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/Vector/19-2.cpp) <br>
        [19-3. 벡터의 테이블](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/Vector/19-3.cpp) <br>
        [19-4. 래기드 백터를 사용해서 파스칼의 삼각형 만들기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/Vector/19-4.cpp) <br>

      - Deque
        
        덱은 백터와 비슷하지만 **양쪽으로 요소를 추가할 수 있음** <br>
        Deque는 double-ended queue의 약자로, 앞과 뒤로 요소를 추가하고 제거할 수 있다는 의미임. <br>
        앞과 뒤로 빠르게 추가하고 제거할 수 있기에 벡터와 다르게 메모리를 많이 차지함 <br>

         [19-5. 덱으로 요소의 순서 회전하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/Deque/19-5.cpp) <br>
   
      - List
        
        리스트는 빠른 삽입과 삭제가 가능 <br>
        목록의 원하는 위치에 요소를 삽입 및 삭제할 수 있지만, Doubly Linked List로 구현되어 있어서, Index 또는 at 멤버 함수로 특정 요소로 바로 접근 불가 <br>
        원하는 요소에 접근하려면 반복자를 사용해서 원하는 요소까지 이동한 뒤에 접근해야함 <br>
        양방향 반복자만 제공하기에, 임의 접근 반복자가 없어 임의 접근 반복자에 정의되어 있는 +, -, [], at 멤버 함수 사용 불가 <br>
        용적이 따로 없기에 원하는 위치에 요소를 추가할 수 있어 capacity, reserve 함수가 없고, 요소에 접근하려면 반복자를 명시적으로 사용 해야함
        
         [19-6. 리스트의 요소 출력하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/List/19-6.cpp) <br>
         [19-7. 리스트의 요소 일부 출력하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/List/19-7.cpp) <br>
         [19-8. biginterger 클래스](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/List/BigInteger) <br>

---------------------------------------------------------------------------

  - ### 19-4. Container Adapter

    - 공용 인터페이스
      
      Container Adapter는 Sequence Container보다 가벼운 인터페이스며 사용하기 쉬운 stack, queue, priority_queue를 제공함 <br>
      하지만 begin, end처럼 반복자를 만드는 멤버함수를 제공하지 않아 알고리즘을 적용할 수 없음 <br>

        - Stack
          
          스택은 삽입(push), 삭제(pop), 탑(top)이라는 간단한 기능을 가지고, 한 쪽 끝(탑)으로만 요소를 삽입 및 제거가 가능 <br>
          마지막에 추가한 요소가 가장 먼저 제거가 되는 **후입 선출 LIFO(last in first out) 구조임**

          [19-11. 10진수를 16진수로 변환하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/Container_Adapter/19-11_Stack_dec_hex.cpp) <br>
          [19-12. 괄호안 짝 확인하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/Container_Adapter/19-12_Paired.cpp)

        - Queue
          
          큐는 한 쪽 끝으로 요소를 삽입하고, 다른 쪽 끝으로만 제거 가능 <br>
          처음 삽입한 요소가 가장 먼제 삭제되는 **선입 선출 FIFO(first in first out) 구조임**

          [19-13. 기부 금액 분류하기 ](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/Container_Adapter/19-13_queue_donation.cpp)
          
        - Priority_queue
          
          우선 순위 큐는 요소를 삽입했을 때, 어떤 순위에 따라서 요소를 꺼낼 수 있음 

          [19-14. 우선 순위 큐 사용하기.](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/Container_Adapter/19-14_Priority_Que_Main.cpp)
    
-----------------------------------------------------------------------------

  - ### 19-5. Associative Container
      
      - 공용 인터페이스
        
        연관 컨테이너는 key를 기반으로 값을 저장하고 접근 <br>
        일반적으로 이진 탐색 트리로 구현되어 있음.
        
      - set class
        
        key와 값이 동일한 연관 컨테이너로, **key 라는 하나의 템플릿 자료형만 지정** <br>
        오름차순으로만 정렬되고 중복 불가능 <br>
        index를 사용해서, 요소에 접근할 수 있는 첨자 연산자와 at함수가 없어 key를 사용해서 접근 해야함

        [19-15. 정수 set 다루기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/Set/19-15_SetMain.cpp) <br>
        [19-16.student set을 만들고 정렬하는 예시](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/Set/setStudent)
        
      - map class
        
        key와 값이 다른 연관 컨테이너, table, dictionary, associate array이라고도 불리는 객체 <br>
        key와 값을 쌍으로 갖는 요소를 여러 개 저장하는 컨테이너로 key를 기반으로 오름차순 정렬 <br>
        set과 비슷하지만, 맵은 요소에 접근할때 []연산자를 사용함 또한 index로 정수가 아닌 문자열을 사용 <br>
        하지만 []연산자가 벡터나 덱처럼 작용하지 않고 단순하게 key - value 쌍을 나타내기위한 표현임 그렇기 때문에, + 또는 -를 사용해서 요소들을 뛰어다닐 수 없고 양방향 반복자을 사용해서 반복을 돌 수 있음
        
        [19-19. map을 이용해서 학생의 이름과 점수 저장하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/Map/19-19_map_StudentMain.cpp) <br>
        [19-20. map을 이용해서 단어 개수 세기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/Map/19-20_map_WordsCountMain.cpp)        

--------------------------------------------------------------------------------
  - ### 19-6. 함수 사용

      - 함수에 대한 포인터

        알고리즘은 컨테이너의 요소들에 어떤 처리를 할 때 사용 <br>
        직접 만들거나 라이브러리에서 제공한 것을 사용할 수 있음 <br>
        메모리에 저장되는 모든 엔티티는 주소를 갖는데, 함수의 정의도 메모리 위에 저장되기 때문에 함수도 어떤 주소를 가짐. 즉, 배열의 이름이 배열의 첫 번째 요소에 대한 포인터 인것 처럼, 함수의 이름도 함수가 저장된 위치의 첫 번째 바이트를 가리키는 포인터임.

        [19-21. 함수에 대한 포인터 사용하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/UsingFunction/19-21.cpp) <br>
        [19-22. for_each함수 조합해서 사용하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/UsingFunction/19-22.cpp)

      - 함수 객체

        [19-13 함수 객체 사용하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/UsingFunction/19-23.cpp)

        - STL 알고리즘의 함수 객체
            
          STL 내부적으로 여러 함수 객체를 정의하고 있음 functional 헤더 파일에 존재

           [19-24. 단항 함수 객체](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/UsingFunction/19-24.cpp)

-------------------------------------------------------------------------------
        
  - ### 19-7. Algorithm

    Algorithm은 각각의 컨테이너 내부에 어떤 연산을 따로 정의하지 않고, 반복자를 사용해서 연산을 처리할 수 있게 해주는 함수로써 모든 컨테이너에 적용할 수 있는 전역 함수 <br>
    컨테이너가 적절한 반복자를 지원하지 않으면, 알고리즘을 적용할 수 없음

    - Non-mutating algorithm
      
      비변경 알고리즘은 컨테이너의 순서를 변경하지 않음, 요소를 변경할 수도, 변경하지 않을 수도 있음
      
      [19-25. 비변경 알고리즘 사용하는 프로그램](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/STL_Algorithm/19-25_nonMutating_Algorithm.cpp)
    
    - Mutating algorithm

      컨테이너의 구조를 변경하는 알고리즘
      
      [19-26. 변경 알고리즘 사용하는 프로그램](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/STL_Algorithm/19-26_Mutating_AlgorithmsMain.cpp)
      
    - Sorting algorithm
      정렬 또는 정렬과 관련된 알고리즘을 제공

      [19-27. 정렬 알고리즘 사용하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/STL_Algorithm/19-27_SortingAlgorithmsMain.cpp)<br>
      [19-28. 이진 탐색 알고리즘 사용하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/STL_Algorithm/19-28_BinarySearchAlgoritmsMain.cpp) <br>
      [19-29. 두 집합의 합집합 구하기](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/STL_Algorithm/19-29_setUnionMain.cpp) <br>
      
    - Numeric algorithm
      
      수치 알고리즘은 컨테이너의 요소 또는 컨테이너에 간단한 수학 연산을 적용 해주는 알고리즘임

      [19-30. accmulate 수치 함수를 사용하는 프로그램](https://github.com/Jeon-YuSung/Cplusplus-UE/blob/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter19/STL_Algorithm/19-30_UsingAccumulateMain.cpp) <br>
