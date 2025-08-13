//템플릿 메소드 패턴 예제 구현 파일 

#include "meeting.h"

//템플릿 메소드 구현
void Meeting::meeting() {

	greeting();
	farewell();

}

void EngMeeting::greeting() {
	cout << "Hello My friends! \n";
}

void EngMeeting::farewell() {
	cout << "Bye My Friends! \n";
}

void FrenMeeting::greeting() {

	cout << "Bonjour mes amis \n";
}

void FrenMeeting::farewell() {

	cout << "Au revoir mes amis \n";

}
