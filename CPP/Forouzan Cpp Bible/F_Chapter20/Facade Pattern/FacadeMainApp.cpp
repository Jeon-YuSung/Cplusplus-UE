//20-5. 퍼사드 패턴을 사용해보기 
#include "facade.h"

int main(void) {


    House house(1000); //퍼사드 객체 생성
    house.draw();

    return 0; 

}
