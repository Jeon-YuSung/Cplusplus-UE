//12-4. 다형성과 배열을 사용하는 예시
// 포인터 배열을 사횽해 다형성의 사용 예시를 확인하자. 

#include "student.h"

int main(void) {
	
	// 다형성 변수(포인터)의 배열 선언
	Person* ptr[4];
	ptr[0] = new Person("Jeon");
	ptr[1] = new Person("Vidan");
	ptr[2] = new Student("Lisa", 3.3);
	ptr[3] = new Student("Rin", 4.9);


// 객체의 가상 함수 호출
	for (int i = 0; i < 4; i++) {
		ptr[i]->print();
		cout << endl;
	}

	//힙의 객체 소멸시키기
	for (int i = 0; i < 4; i++) {
		delete ptr[i];
	}

	return 0;
}
