//vehicle 멤버 함수 구현하는 파일 
#include "vehicle.h"

//car의 생성자
Car::Car(string m, string c) : model(m), color(c) {
	cout << color << " " << model << " 자동차를 만들었습니다.\n";
}

//car의 복사 생성자
Car::Car(const Car& car) : model(car.model), color(car.color) {
	cout << color << " " << model << " 자동차를 만들었습니다 \n";
}

// car의 clone 멤버함수 
Car* Car::clone() const {
	return new Car(*this);
}

//트럭의 생성자
Truck::Truck(string s, string c) : size(s), color(c) {
	cout << color << " " << size << " 트럭을 만들었습니다.\n";
}

//트럭의 복사 생성자 
Truck::Truck(const Truck& truck) : size(truck.size), color(truck.color) {
	cout << color << " " << size << " 트럭을 만들었습니다.\n";
}

//트럭의 clone 멤버 함수 
Truck* Truck::clone() const {
	return new Truck(*this);
}
