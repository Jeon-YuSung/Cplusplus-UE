//20-1. 싱글톤 패턴, 대표자 뽑는 프로그램 
#include "president.h"

int main(void) {

    President* ptr;
    //첫 번째 대표 객체 생성하기.
    ptr = President::create("Mary");
    cout << "대표자의 이름 : " << ptr->getName() << endl;
    //두 번째 대표 객체 생성 시도 
    ptr = President::create("John");
    cout << "대표자의 이름 : " << ptr->getName() << endl;
    return 0; 

}
