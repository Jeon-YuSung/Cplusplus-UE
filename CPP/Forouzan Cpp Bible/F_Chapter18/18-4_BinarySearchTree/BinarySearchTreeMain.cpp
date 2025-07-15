//18-4. 이진 탐색 트리 구현
#include "binarysearchtree.cpp"

int main(void) {

    Binary_search_tree<string> bct;

    //노드 6개 추가
    bct.insert("Korea");
    bct.insert("Japan");
    bct.insert("UK");
    bct.insert("Canada");
    bct.insert("USA");
    bct.insert("Spain");

    //전위 순회로 출력
    cout << " pre order 출력 \n";
    bct.pre_order();
    cout << endl << endl;

    //중위 순회로 출력 
    cout << "in order 출력 \n";
    bct.inorder();
    cout << endl << endl;

    //후위 순회로 출력
    cout << "post order 출력 \n";
    bct.post_order();
    cout << endl << endl;

    //값 탐색
    cout << "탐색 : \n";
    cout << "search(UK) : " << boolalpha;
    cout << bct.search("UK") << endl;
    cout << "search (Korea) : " << boolalpha;
    cout << bct.search("Korea") << endl;
    cout << "search (French) : " << boolalpha;
    cout << bct.search("French") << endl;


    return 0;
}
