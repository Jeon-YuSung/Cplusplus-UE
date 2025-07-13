//16-22. 플래그, 필드, 변수를 이용해서 자료형 별로 형식화 하기. 

#include <iostream>
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
    cout << b << endl << endl;

    cout << "정수 자료형 형식화 \n";
    cout.setf(ios::showbase);
    cout.setf(ios::uppercase);
    cout.setf(ios::hex, ios::basefield);
    cout.setf(ios::right, ios::adjustfield);
    cout.width(16);
    cout.fill('*');
    cout << a << endl << endl;

    cout << "부동 소수점 자료형 형식화 \n";
    cout.setf(ios::showpoint);
    cout.setf(ios::right, ios::adjustfield);
    cout.setf(ios::fixed, ios::floatfield);
    cout.width(16);
    cout.fill('*');
    cout << d << endl;

    return 0;
}
