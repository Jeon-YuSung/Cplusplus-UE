/*
11-4. 메인 (애플리케이션 파일)
person 클래스와 student 클래스를 그리고 Employee 사용하는 애플리케이션 파일. 
*/

#include "student.h"
#include "employee.h"

//메인 함수 
int main(void) {

    Person person("Jeon");
    cout << "person의 객체 정보 : " << endl;
    person.print();
    cout << endl << endl; 

    Student student("Vidan", 3.22);
    cout << "학생의 객체 정보 : " << endl;
    student.print();
    cout << endl;

    cout << "노동자의 객체 정보: " << endl;
    Employee employee("Mari", 8000.00);
    employee.print();
    cout << endl;

    return 0;
}
