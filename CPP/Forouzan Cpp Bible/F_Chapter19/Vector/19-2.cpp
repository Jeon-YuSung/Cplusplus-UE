//19-2. 반복자를 이용한 양방향 임의 접근, 임의 접근 기본 반복자와 역 반복자를 살펴보는 프로그램

#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;


int main(void) {

    //10개의 요소를 가진 벡터와 반복자 2개 생성
    vector<int> vec;
    vector<int>::iterator iter;
    vector<int>::reverse_iterator rIter;

    //요소의 값 채우기
    for (int i = 0; i < 10; i++) {
        vec.push_back(i * 10);
    }

    // 기본 반복자로 40과 20출력
    cout << "40 출력 후에, 20 출력하기 \n";
    iter = vec.begin();
    iter += 4;
    cout << *iter << " ";
    iter -= 2;
    cout << *iter << endl;

    //역 반복자로 50, 70 출력
    cout << "50 출력 후에, 70 출력하기 \n";
    rIter = vec.rbegin();
    rIter += 4;
    cout << *rIter << " ";
    rIter -= 2;
    cout << *rIter << endl;

    return 0;
}
