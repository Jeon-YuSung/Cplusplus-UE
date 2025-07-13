//16-23. 조정자로 출력 형식 조정하기 
// 표준 조정자를 사용해서 이전과 같은 결과를 출력하는 프로그램 

#include <iostream>
#include <iomanip>
using namespace std;

int main(void) {

    bool b = true;
    int a = 12000;
    double d = 1234.456;

     //형식화 없이 단순하게 출력
    cout << "형식화 없이 출력하기 \n"; 
    cout << "bool b의 값 : " << b << endl;
    cout << "int a의 값 : " << a << endl;
    cout << "double d의 값 : " << d << endl << endl;

    cout << "불 자료형 형식화 \n";
    cout.setf(ios::boolalpha);
    cout << boolalpha <<  b << endl << endl;

    cout << "정수 자료형 형식화 \n";
    cout << showbase << uppercase <<  hex << right << setw(16)
        << setfill('*') << a << endl << endl;

    cout << "부동 소수점 자료형 형식화 \n";
    cout << showpoint << right << fixed<< setw(16) <<
        setprecision(2) << setfill('*') << d << endl;

    return 0;
}
