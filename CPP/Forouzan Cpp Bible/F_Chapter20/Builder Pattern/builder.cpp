//빌더 패턴의 구현 파일 
#include "builder.h"

//정적 데이터 멤버 정의
Vacation* Director::vacation = 0;

//클라이언트가 호출할 정적 멤버 함수 정의
void Director::book(int packageType) {

	if (packageType == 1) {
		vacation = new Package1();
	}
	else if (packageType == 2) {
		vacation = new Package2();
	}
	else if (packageType == 3) {
		vacation = new Package3();
	}

	cout << "여행 계획에 대한 정보 : \n";
	vacation->bookHotels();
	vacation->bookFlights();
	vacation->bookTours();
	cout << endl;
}

//패키지1의 멤버 함수 정의
void Package1::bookHotels() {
	cout << "호텔 예약 \n";
}

void Package1::bookFlights() {
	cout << "항공권 예약 \n";
}
void Package1::bookTours() { }

//패키지2의 멤버 함수 정의
void Package2::bookHotels() {
	cout << "호텔 예약 \n";
}

void Package2::bookFlights() {

}
void Package2::bookTours() {

	cout << "투어 예약 \n";
}

//패키지3의 멤버 함수 정의
void Package3::bookHotels() {
	cout << "호텔 예약 \n";
}

void Package3::bookFlights() {
	cout << "항공권 예약 \n";
}
void Package3::bookTours() {
	cout << "투어 예약 \n";
 }
