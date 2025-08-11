//20-3. 빌더 패턴 사용하는 애플리케이션 파일 
#include "builder.h"

int main(void) {

    //여행 유형 선택
    int type;
    do {
        cout << "여행 유형을 입력하세요 (1,2,3) : ";
        cin >> type;
    } while (type < 1 || type>3);

    //여행 계획 확인
    Director::book(type);
    return 0; 

}
