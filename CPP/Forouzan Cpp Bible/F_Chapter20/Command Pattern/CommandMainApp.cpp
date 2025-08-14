//20-11 커맨드 패턴 예제 애플리케이션 파일 
#include "command.h"

int main(void) {

    //리시버 객체 인스턴스화 
    Receiver* receiver = new Receiver();

    //커맨드 객체 인스턴스화 
    Command* command = new Concrete(receiver);

    //Invoker 객체를 인스턴스화하고 멤버 함수 호출
    Invoker invoker;
    invoker.store(command);

    //포인터 제거
    delete receiver;
    delete command;

    return 0; 

}
