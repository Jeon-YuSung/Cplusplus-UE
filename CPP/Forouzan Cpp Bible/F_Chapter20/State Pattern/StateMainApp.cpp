//20-13 상태 패턴 예제 코드 
#include "state.h"
using namespace std;

int main(void) {

    Light* light = new Light;
    State* state = new OffState;
    light->setState(state);

    light->turnSwitch();
    light->turnSwitch();
    light->turnSwitch();

    // delete state; -> state를 2번 해제하기 되어 _CrtIsValidHeapPointer로 에러 발생 즉, double delete임   
    light->delState(); 
    delete light;
    return 0; 

}
