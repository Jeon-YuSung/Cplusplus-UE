// 5개의 요소를 갖는 배열을 만들고 기본 반복자와 역 반복자로 출력하기 

#include <list>
#include <iostream>
using namespace std;

int main(void) {

    list<int> lst;
    int value;

    for (int i = 0; i < 5; i++) {
        
        cout << "정수 입력 : ";
        cin >> value;
        lst.push_back(value);
    }

    //기본 방향으로 출력
    cout << "기본 방향 \n";
    list<int>::iterator iter1;
    for (iter1 = lst.begin(); iter1 != lst.end(); iter1++) {
        cout << *iter1 << " ";
    }
    cout << endl;

    //역 방향으로 출력
    cout << "역 방향 \n";
    list<int>::reverse_iterator iter2;
    for (iter2 = lst.rbegin(); iter2 != lst.rend(); iter2++) {
        cout << *iter2 << " ";
    }
    cout << endl;


    return 0;
}
