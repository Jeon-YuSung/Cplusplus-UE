## Chapter 18. Data Structure

  객체가 모여서 여러 객체를 이룬 것 -> Collection <br>
  일반적으로 프로그래밍에서 객체의 관계는 **선형(Linear), 비선형(Nonlinear)** 로 구분 <br>
  비선형 구조는 일렬로 연결된 관계가 아니기에, 여러개의 요소가 트리나 그래프 형태로 나타냄 <br> 
  선형 구조는 선형 리스트, 연결 리스트, 스택, 큐, 데크 형태로 나타낼 수 있음 

--------------------------------------------

  - #### Singly Liked List
  
  단일 연결 리스트는 선형 구조로, 리스트의 각각의 요소를 노드(Node)라고하고, 각각의 노드는 데이터와 포인터라는 두 부분으로 구성됨. <br>
  데이터는 값을 저장하고 포인터 부분은 다음 노드를 가르킴, 모든 노드는 다음 노드로 이동할 수 있지만, 이전 노드로 이동할 수 없음 <br>

[18-1. Singly Linked List](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter18/18-1_List)

  이중 연결 리스트 (Doubly Linked List) 또는 양방향 연결 리스트는 이전 노드, 다음노드 양쪽 모두 자유롭게 이동할 수 있음. 

  - #### STACK

    스택은 모든 추가와 제거를 한쪽으로만 할 수 있는 제한된 선형 리스트 컨테이너로 후입선출(Last In, First Out)구조 <br>
    입력연산은 PUSH, 출력 연산은 POP이라고 하며 조회 연산은 PEEK라고 하는데, 탑 포인터가 가리키는 데이터를 조회(확인)만 함 <br>

    접시를 쌓아놓거나, 책을 쌓아놓거나 등의 예시가 있음

[18-2. STACK](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter18/18-2_Stack)

  - #### QUEUE

    큐는 데이터를 뒤로 삽입하고, 앞으로 제거할 수 있는 선형 리스트 구조로, 데이터를 입력한 순서대로 꺼낼 수 있어 선입선출(First in, First out) 구조 흔히 버스 정류장을 생각하면 됨. <br>
    데이터가 가장 먼저 들어오는 위치를 뒤(Rear or Back)이라고 하고, 데이터를 나가는 위치를 가장 앞(Front)라고 함 <br>
    입력 동작은 Enqueue, 출력 동작은 Dequeue라고 함 <br>
    참고로 큐는 OS나 Networks system등 다양한 영역에서 내부적으로 큐를 활용함 <br>
    고객 요청 처리, 주문 같은 비즈니스 대기열 구현이나 인쇄 대기열 등에도 큐를 활용 <br>

[18-3. QUEUE](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter18/18-3_Queue)

  
  - #### 이진 탐색 트리

    연결 리스트, 스택, 큐는 모두 선형 구조이고, 비선형 구조에는 트리, 그래프가 있음 <br>
    트리에 있는 각각의 노드는 둘 이상의 노드와 연결됨. 또한 트리는 다양한 종류가 있지만, 컴퓨터 과학에서는 최대 2개의 노드와 연결되는 이진 트리(Binary Tree)를 많이 활용하고 Binary tree 중에서 노드와 연결된 왼쪽(첫 번째 노드)의 값이 오른쪽(두 번째 노드)의 값보다 작은 형태로 정렬된 트리를 이진 탐색 트리(Binary Search Tree)라고 함

    이진 탐색 트리는 노드에 어떤 처리를 한 번 씩하기 위해 순회(Traversal)하는 과정이 있는데, 순회 순서를 전위 순회(pre-order), 중위 순회(in-order), 후위 순회 (post-orde)로 나뉨. <br>
    뿌리를 기준으로 순회를 구분하면 쉬움<br>
    전위 순회는 뿌리(Root), 왼쪽, 오른쪽 순서로, 중위 순회는 왼쪽, 뿌리, 오른쪽 순서로, 후위 순회는 왼쪽, 오른쪽, 뿌리 순으로 순회함 <br>

[18-4. BinarySearchTree](https://github.com/Jeon-YuSung/Cplusplus-UE/tree/main/CPP/Forouzan%20Cpp%20Bible/F_Chapter18/18-4_BinarySearchTree)
