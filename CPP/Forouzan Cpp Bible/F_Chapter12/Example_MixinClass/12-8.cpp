// 12-8. 믹스인 클래스를 사용하는 프로그램 
#include "ta.h"
#include "student.h"
#include "professor.h"

int main(void) {

	Person person("Jeon");
	Student student("Vidan", 3.4);
	Professor professor("Lusi", 100000.00);
	TA ta("Mari", 3.7, 23500.00);

	//Person 정보 출력 
	cout << "Person 정보 : \n";
	person.print();
	cout << endl << endl;

	//student 정보 출력
	cout << "student 정보 출력 : \n";
	student.print();
	cout << endl << endl;

	//  교수 정보 출력
	cout << "Professor : \n";
		professor.print();
		cout << endl << endl;
		
		// TA 정보 출력
		cout << "TA : \n";
		ta.print();
		cout << endl << endl;
	return 0;
}
