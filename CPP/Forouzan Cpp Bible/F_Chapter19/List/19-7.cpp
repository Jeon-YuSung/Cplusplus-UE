//19-7 리스트의 요소를 일부 출력하기 
// 19-2 벡터를 이용한 것을 리스트로  작성해보기 
#include <list>
#include <iostream>
using namespace std;

int main(void) {

    list<int> lst;
    list<int>::iterator iter1;
    list<int>::reverse_iterator iter2;

    //리스트 요소에 10개 입력
    for (int i = 0; i < 10; i++) {
        lst.push_back(i * 10);
    }

    //iter1로 출력
    cout << " 40 출력 후 20 출력 하기 \n";
    iter1 = lst.begin();
    iter1++;
    iter1++;
    iter1++;
    iter1++;
    cout << *iter1 << " ";
    iter1--;
    iter1--;
    cout << *iter1 << "\n";

    //iter2로 출력
    cout << " 50 출력 후 70 출력하기 \n";
    iter2 = lst.rbegin();
    iter2++;
    iter2++;
    iter2++;
    iter2++;
    cout << *iter2 << " ";
    iter2--;
    iter2--;
    cout << *iter2 << "\n";

    return 0;
}
