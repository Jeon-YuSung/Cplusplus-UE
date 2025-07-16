//19-1. 벡터 반복자 사용하기
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;


int main(void) {

    //10개의 요소를 가진 벡터와 반복자 2개 생성
    vector<int> vec(10);
    vector<int>::iterator iter;
    vector<int>::reverse_iterator rIter;

    //요소의 값 변경
    for (int i = 0; i < 10; i++) {
        vec.at(i) = i * i;
    }

    cout << "기본 반복자를 이용해서 기본 탐색 :";
    for (iter = vec.begin(); iter != vec.end(); ++iter) {
    
        cout << setw(4) << *iter;
    }
    cout << endl;

    cout << "역 반복자를 이용한 역 탐색 : ";
    for (rIter = vec.rbegin(); rIter != vec.rend(); ++rIter){

        cout << setw(4) << *rIter;
    }
    cout << endl;

    return 0;
}
