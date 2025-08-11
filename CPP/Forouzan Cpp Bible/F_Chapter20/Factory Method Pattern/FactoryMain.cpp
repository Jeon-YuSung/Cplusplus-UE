//20-2. 팩토리 메소드 패턴 사용하는 예제
#include "factory.h"

int main(void) {

    Shape* shape;
    
    // 사각형 객체를 생성하고 사용 
    shape = Shape::factory("square");
    shape->draw();

    //써클 객체를 생성하고 사용 
    shape = Shape::factory("circle");
    shape->draw();

    return 0; 

}
