//18-1. Singly Linked List 구현하기
#include "list.cpp"
#include <string>

int main(void) {

    //리스트 객체 인스턴스화 
    List<string> list;

    //노드 추가
    list.insert(0, "Yonsei");
    list.insert(1, "Korea");
    list.insert(2, "Dongguk");
    list.insert(3, "Hongik");
    list.insert(4, "Vidan");
    list.insert(5, "Sejong");

    //리스트 노드 출력
    cout << "List 출력 \n";
    list.print();

    //노드 3개만 출력
    cout << "일부 노드만 출력\n";
    cout << list.get(0) << endl;
    cout << list.get(3) << endl;
    cout << list.get(5) << endl;

    //노드 2개 제거
    cout << "노드 일부 제거하고 노드 출력 \n";
    list.erase(0);
    list.erase(3);
    list.print();

    //노드를 제거한 후 리스트의 크기 출력
    cout << "리스트의 크기 확인 하기 \n";
    cout << "리스트의 크기 : " << list.size();

    return 0;
}
