#include "command.h"

//액션 멤버 함수
void Receiver::action() {

	cout << "명령을 실행 합니다 \n";
}

//concrete 생성자
Concrete::Concrete(Receiver* recv) 
: receiver(recv) {}

//exeute 멤버 함수
void Concrete::execute() {

	receiver->action();

}

//storeCommand 멤버함수
void Invoker::store(Command* com) {

	command = com;
	bool rightTime = false;
	while (!rightTime) {
	
		cout << "적절한 시점에 1을 입력하고 이외의 경우에는 0을 입력하세요 : ";
		cin >> rightTime;
		if (rightTime) {
			command->execute();
		}
	}

}
