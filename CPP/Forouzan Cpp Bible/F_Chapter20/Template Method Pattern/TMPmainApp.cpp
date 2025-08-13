//20-9. 템플릿 메소드 패턴 예제의 애플리케이션 파일 
#include "meeting.h"

int main(void) {

    cout << "영어 인사 \n";
    EngMeeting eMt;
    eMt.meeting();
    cout << endl;

    cout << "불어 인사 \n";
    FrenMeeting freMt;
    freMt.meeting();
    cout << endl;

    return 0; 

}
