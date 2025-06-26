/*
11-5. 메인 (애플리케이션 파일)

*/

#include "person.h"

//메인 함수 
int main(void) {

    Date date1(5, 6, 1993);
    Person person1(122133288, date1);
    Date date2(6, 26, 2025);
    Person person2(234223999, date2);
    
    person1.print();
    person2.print();

    return 0;
}

