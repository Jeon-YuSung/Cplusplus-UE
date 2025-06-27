//12-3 다형성을 기반으로 Persong 클래스에 대한 포인터를 사용해
// student 클래스의 멤버 함수를 호출하는 프로그램 

#include "student.h"

int main(void) {
	
	Person* ptr;
	ptr = new Person("Jeon");
	cout << " 사람의 정보 : \n";
	ptr->print();
	cout << endl << endl;
	delete ptr;

	ptr = new Student("Vidan", 3.7);
	cout << "학생의 정보 : \n";
	ptr->print();
	cout << endl;
	delete ptr;

	return 0;
}
