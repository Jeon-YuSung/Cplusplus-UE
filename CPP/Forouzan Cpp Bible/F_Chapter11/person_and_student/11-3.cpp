/*
11-3. 메인 (애플리케이션 파일)
person 클래스와 student 클래스를 사용하는 애플리케이션 파일. 
*/

#include "student.h"

//메인 함수 
int main(void) {

    Person person(111111111);
    cout << "person의 객체 정보 : " << endl;
    person.print();
    cout << endl;

    Student student(222222222, 3.7);
    cout << "학생의 객체 정보 : " << endl;
    student.print();
    cout << endl;



    return 0;
}
