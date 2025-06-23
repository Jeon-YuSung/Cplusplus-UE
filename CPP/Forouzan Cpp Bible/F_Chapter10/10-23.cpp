/*
10-23. 전체 이름 출력하기 
*/
#include <iostream>
#include <string>
using namespace std;


int main(void) {

    string first, last;
    char init;

    cout << "Frist Name을 입력 하세요 : ";
    cin >> first;
    cout << " Last Name을 입력 : ";
    cin >> last;
    cout << "이니셜을 입력하세요 : ";
    cin >> init;

    cout << endl;
    cout << "첫 번째 형식의 Full name : ";
    cout << first + " " + init + "." + " " + last << endl;
    cout << "두 번째 형식의 Full name : ";
    cout << last + "," + first + " " + init + "." << endl;

    return 0;
}
