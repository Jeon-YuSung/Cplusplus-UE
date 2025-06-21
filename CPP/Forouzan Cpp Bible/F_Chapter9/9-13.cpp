/*
9-13. 정적 메모리 사용하기 
프로그램이 존재하는 동안 계속해서 메모리에 존재하는 전역 변수, 정적 변수를 사용하는 프로그램 
*/
 
#include<iostream>
using namespace std;

//전역 변수 선언
int first = 20;
static int second = 30; // 전역 정적 변수 

int main(void) {

    static int third = 50; // 정적메모리 위에 올라가는 정적 변수 

    cout << " 전역 변수의 값 : " << first << "\n";
    cout << " 전역 정적 변수의 값 : " << second << "\n";
    cout << " 지역 정적 변수의 값 " << third;

    return 0;
}
