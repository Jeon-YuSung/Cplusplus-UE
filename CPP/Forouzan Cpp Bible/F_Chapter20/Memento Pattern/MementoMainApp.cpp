//20-14. 메멘토 패턴 예제 파일 
#include "memento.h"
using namespace std;

int main(void) {

    Originator originator;
    originator.setState("안녕하세요"); //첫번째 상태 설정
    cout << originator.getState() << "\n"; // 첫 번째 상태 출력
    originator.setState("안녕!"); // 2번째 상태 설정
    cout << originator.getState() << "\n"; //2번째 상태 출력 
    originator.restoreState(); //상태 복원
    cout << originator.getState() << "\n"; // 복원한 상태 출력 
    return 0; 

}
