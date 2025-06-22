/*
10-3. C 문자열을 만들고, 입출력 연산자를 사용하는 프로그램 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main(void) {

    //상수가 아닌 문자열과 상수 문자열 생성 
    char str1[] = { 'H','e','l','l','o','\0' };
    const char str2[] = {'H','e','l','l','o','\0'};
    //문자열 리터럴을 사용해서 상수 문자열 생성 
    const char* str3 = "Goodbye";
    const char* str4 = "Goodbye\0 my friend";

    //출력 
    cout << "str1 : " << str1 << "\n";
    cout << "str2 : " << str2 << "\n";
    cout << "str3 : " << str3 << "\n";
    cout << "str4 : " << str4;
    cout << endl << endl;

    char str5[20];
    cout << "str5의 값을 입력 : ";
    cin >> str5;
    cout << "str5 : " << str5;
    return 0;
}
