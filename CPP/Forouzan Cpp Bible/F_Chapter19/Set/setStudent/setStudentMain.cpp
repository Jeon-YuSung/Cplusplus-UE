//19-16. setStudent 애플리케이션 파일
#include "setStudent.h"

int main(void) {

    Student student1(21, "Vidan", 3.47);
    Student student2(123, "John", 3.72);
    Student student3(47, "Lusi", 4.12);
    Student student4(92, "Erin", 3.65);
    Student student5(100, "Alex", 3.32);
    Student student6(76, "Ren", 3.15);
    Student student7(223, "Osiris", 3.47);

    //인스턴스를 set에 넣기
    set<Student> stdSet;
    stdSet.insert(student1);
    stdSet.insert(student2);
    stdSet.insert(student3);
    stdSet.insert(student4);
    stdSet.insert(student5);
    stdSet.insert(student6);
    stdSet.insert(student7);

    //출력
    set<Student>::iterator iter;
    for (iter = stdSet.begin(); iter != stdSet.end(); iter++) {
        iter->print();
    }

    return 0;
}
