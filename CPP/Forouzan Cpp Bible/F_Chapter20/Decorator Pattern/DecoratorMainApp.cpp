//20-7.데코레이터 패턴 사용하기 
#include "decorator.h"

int main(void) {

    Decorator decor1(Component("안녕하세요!"));
    decor1.draw();

    
    Decorator decor2(Component("반갑습니다"));
    decor2.draw();
    
    Decorator decor3(Component("데코레이터 패턴 예제 입니다"));
    decor3.draw();

    return 0; 

}
