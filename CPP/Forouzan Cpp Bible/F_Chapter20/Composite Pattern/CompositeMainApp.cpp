//20-8. 컴포짓 패턴 사용하는 애플리케이션 파일. 
#include "composite.h"

int main(void) {

    // 포인트 객체 (leaf)만 만들고 출력
    cout << "Point 객체 만들고 출력하기 \n";
    Point point(7.77, 2.24);
    point.show();
    cout << endl;

    //멀티 포인트 객체(컴포짓)을 만들고 출력
    cout << "멀티포인트 객체 만들고 출력하기 \n";
    Multipoint multipoint;
    multipoint.addPoint(new Point(3.22, 4.51));
    multipoint.addPoint(new Point(5.22, 9.17));
    multipoint.addPoint(new Point(1.56, 7.53));
    multipoint.show(); 
    cout << endl;

    return 0; 

}
