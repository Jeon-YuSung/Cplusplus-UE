//퍼사드 패턴 헤더파일 구현
#include "facade.h"

//리빙룸 생성자
LivingRoom::LivingRoom(double s) :size(s) {}

//리빙룸의 draw 멤버 함수
void LivingRoom::draw() {

	cout << "거실의 크기는 : " << size << "평방 피트로 그립니다 \n";

}

// 베드룸의 생성자
BedRoom::BedRoom(double s) : size(s) {}

// 베드룸의 draw 
void BedRoom::draw() {

	cout << "침실의 크기는 : " << size << "평방 피트로 그립니다 \n";

}

// 키친 생성자
Kitchen::Kitchen(double s) : size(s) {}

// 키친의 draw
void Kitchen::draw() {

	cout << "부엌의 크기는 : " << size << "평방 피트로 그립니다 \n";

}

// 베쓰룸의 생성자
BathRoom::BathRoom(double s) : size(s) {}

//베쓰룸의 draw
void BathRoom::draw() {

	cout << "욕실의 크기는 : " << size << "평방 피트로 그립니다 \n";

}

// 하우스 생성자
House::House(double s) :size(s) {}

//하우스의 draw
void House::draw() {

	LivingRoom livingrm(size * 0.35);
	livingrm.draw();
	BedRoom bedrm(size * 0.25);
	bedrm.draw();
	Kitchen kitchen(size * 0.25);
	kitchen.draw();
	BathRoom bathrm(size * 0.15);
	bathrm.draw();

}
