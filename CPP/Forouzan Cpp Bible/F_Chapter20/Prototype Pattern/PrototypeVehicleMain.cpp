//20-4. 프로토타입 패턴을 활용하기 
#include "vehicle.h"

int main(void) {


    // 자동차 생성
    Vehicle* s1 = new Car("세단", "흰색");
    Vehicle* s2 = s1->clone(); //복제

    Vehicle* t1 = new Truck("1톤 봉고", "용달블루");
    Vehicle* t2 = t1->clone(); //복제

    //차량 파괴 
    delete s1;
    delete s2;
    delete t1;
    delete t2;

    return 0; 

}
