#include <string>
#include <iostream>
#include <iomanip>
#include <deque>

using namespace std;


void print(deque<string> deq) {
    for (int i = 0; i < deq.size(); i++) {
        cout << deq.at(i) << " ";
    }
    cout << endl;
}


int main(void) {

    //덱 생성하고 요소 5개 초기화 
    deque<string> deq(7);
    string arr[5] = { "Korea","Yonsei","Vidan", "Park", "Kim" };
    for (int i = 0; i < 5; i++) {
        deq[i] = arr[i];
    }
    print(deq);

    //시계 방향으로 회전
    deq.push_back(deq.front());
    deq.pop_front();
    print(deq);

    //시계 반대방향
    deq.push_front(deq.back());
    deq.pop_back();
    print(deq);

    return 0;
}
