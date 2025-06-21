//9-4 변수의 크기, 값 주소 출력하기 
// 3개의 변수를 선언하고 값과 주소를 출력하는 프로그램 
#include<iostream>
using namespace std;

int main(void) {

    //데이터 변수 선언 
    bool flag = true;
    int score = 92;
    double average = 82.56;

    cout << "bool 자료형의 변수 \n";
    cout << "크기 : " << sizeof(flag) << "\t" << "값 : "
        << flag << "\t" << "주소 : " << &flag << endl << endl;

    cout << "int 자료형의 변수 \n";
    cout << "크기 : " << sizeof(score) << "\t" << "값 : "
        << score << "\t" << "주소 : " << &score << endl << endl;

    cout << "bool 자료형의 변수 \n";
    cout << "크기 : " << sizeof(average) << "\t" << "값 : "
        << average << "\t" << "주소 : " << &average << endl << endl;
    
    return 0;

}
