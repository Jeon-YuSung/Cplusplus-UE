//16-16. 학생데이터를 파일에 출력하고 이진으로순차적으로 읽어 출력하는 프로그램.
#include "student.h"

int main(void) {

    fstream stdSt1;
    stdSt1.open("File.dat", ios::binary | ios::out);
    if (!stdSt1.is_open()) {
        cout << "file. dat을 열 수 없습니다, 프로그램 종료 \n";
        assert(false);
    }

    Student std1(1, "jon", 3.2);
    Student std2(2, "Vi", 3.5);
    Student std3(3, "Dan", 2.9);
    Student std4(4, "Lusi", 4.21);

    stdSt1.write(reinterpret_cast<char*>(&std1), sizeof(Student));
    stdSt1.write(reinterpret_cast<char*>(&std2), sizeof(Student));
    stdSt1.write(reinterpret_cast<char*>(&std3), sizeof(Student));
    stdSt1.write(reinterpret_cast<char*>(&std4), sizeof(Student));

    stdSt1.close();

    fstream stdSt2;
    stdSt2.open("File.dat", ios::binary | ios::in);
    if (!stdSt2.is_open()) {
        cout << "file. dat을 열 수 없습니다, 프로그램 종료 \n";
        assert(false);
    }

    cout << left << setw(4) << "ID" << " ";
    cout << setw(15) << left << "이름" << " ";
    cout << setw(4) << "학점" << endl;

    Student std;
    for (int i = 0; i < 4; i++) {
        stdSt2.read(reinterpret_cast<char*>(&std), sizeof(Student));
        cout << setw(4) << std.getId() << " ";
        cout << setw(15) << std.getName() << " ";
        cout << fixed << setw(4) << setprecision(2) << std.getGpa() << endl;
    }
    return 0;
}
