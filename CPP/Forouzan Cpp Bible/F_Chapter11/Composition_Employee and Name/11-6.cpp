/*
11-6. 메인 (애플리케이션 파일)
*/

#include "employee.h"

//메인 함수 
int main(void) {

    Employee employee1("Sung", "Y", "Jeon", 20023.00);
    Employee employee2("Vidan", "A", "Silk", 468883.00);
    Employee employee3("Ryan", "d", "Blue", 100992.00);
    employee1.print();
    employee2.print();
    employee3.print();

    return 0;
}
