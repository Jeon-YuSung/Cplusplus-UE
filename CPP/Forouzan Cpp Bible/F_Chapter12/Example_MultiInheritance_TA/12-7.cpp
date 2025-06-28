// 12-7. 사람, 교수, 학생, 조교 클래스를 확인하는 어플리케이션 파일 

#include "ta.h"

int main(void) {
	Person person("Jeon");
	person.print();

	Student student("Vidan", 3.2);
	student.print();

	Professor professor("Lusi", 80000.00);
	professor.print();

	TA ta("Mari", 3.3, 2000.00);
	ta.print();

	return 0;
