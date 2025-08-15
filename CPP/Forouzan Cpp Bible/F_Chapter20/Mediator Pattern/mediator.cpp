// 중재자 패턴 예제 구현 파일
#include  "mediator.h"

void Employee1::getMessage(std::string message) {
	std::cout << "직원1 객체가 메세지를 받았습니다 : " << message << "\n";

}

void Employee2::getMessage(std::string message) {
	std::cout << "직원2 객체가 메세지를 받았습니다 : " << message << "\n";

}
void Employee3::getMessage(std::string message) {
	std::cout << "직원3 객체가 메세지를 받았습니다 : " << message << "\n";

}
void Employee4::getMessage(std::string message) {
	std::cout << "직원4 객체가 메세지를 받았습니다 : " << message << "\n";

}

//중재자 클래스의 생성자
Mediator::Mediator() {
	employ.push_back(new Employee1());
	employ.push_back(new Employee2());
	employ.push_back(new Employee3());
	employ.push_back(new Employee4());
}
//중재자 클래스의 소멸자 
Mediator::~Mediator() {
	for (int i = 0; i < employ.size(); i++) {
		delete employ[i];
	}

}

//메시지를 브로드캐스트하는 sendMessage 함수
void Mediator::sendMesage(std::string message) {
	for (int i = 0; i < employ.size(); i++) {
		employ[i]->getMessage(message);
	}
}
