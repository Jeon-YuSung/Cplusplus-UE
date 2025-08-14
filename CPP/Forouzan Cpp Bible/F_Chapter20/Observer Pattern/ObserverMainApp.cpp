//20-12 옵저버 패턴 예제 코드 
#include "observer.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main(void) {

    //클래스 인스턴스화
    Subject subject;
    Observer1 ob1(&subject);
    Observer2 ob2(&subject);

    subject.subscribe(&ob1);
    subject.subscribe(&ob2);

    //이벤트 모방
    bool flag = true;
    while(flag) {
        srand(time(0));
        int temp = rand();
        int price = temp % (100 - 10 + 1) + 10;
        if (price < 40)
        {
        
            subject.notify(price);
            flag = false;
        }
    }

    //구독 해제 
    subject.unsubscribe(&ob1);
    subject.unsubscribe(&ob2);
    return 0; 

}

