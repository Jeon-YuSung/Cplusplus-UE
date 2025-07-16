//19-13. 기부 금액 분류하기
// 큐를 이용하여 기부 내역을 구분 하는 프로그램 

#include <queue>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//print 함수 정의 
void print(queue<int> queue) {

    while (!queue.empty()) {
    
        cout << queue.front() << " ";
        queue.pop();
    }

    cout << endl;
}
int main(void) {

      // 5개의 큐와 변수 선언
    queue<int> q1, q2, q3, q4, q5;
    int n;
    int donation;

    //기부 내역을 랜덤하게 생성하고 구분 
    srand(time(0)); 
    for (int i = 0; i < 50; i++) {
        n = rand();
        donation = n % (50 - 0 + 0) + 0;
        switch (donation / 10) {
        case 0: q1.push(donation);
            break;
        case 1: q2.push(donation);
            break;
        case 2: q3.push(donation);
            break;
        case 3: q4.push(donation);
            break;
        case 4: q5.push(donation);
            break;
 
        }
    }
 //결과 출력

    cout << " 기부 금액 범위 $0 ~ 9 : ";
    print(q1);
    cout << " 기부 금액 범위 $10 ~ 19 : ";
    print(q2);
    cout << " 기부 금액 범위 $20 ~ 29 : ";
    print(q3);
    cout << " 기부 금액 범위 $30 ~ 39 : ";
    print(q4);
    cout << " 기부 금액 범위 $40 ~ 49 : ";
    print(q5);
    return 0;
}
