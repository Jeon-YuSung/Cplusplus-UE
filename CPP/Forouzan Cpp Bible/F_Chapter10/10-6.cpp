/*
10-6 가장 처음에 등장하는 문자와 마지막에 등장하는 문자를 찾아서 출력하는 프로그램 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    

    char str[] = "Hello frineds.";
    // 처음 등장하는 문자 e를 대문자로 변경
    char* cPtr;
    cPtr = strchr(str, 'e');
    *cPtr = 'E';
    cout << "첫 번째 변경후의 str : " << str << endl;
    
    //마지막으로 등하는 문자 e를 대문자로 변경 
    cPtr = strrchr(str, 'e');
    *cPtr = 'E';
    cout << "두 번째 변경후의 str : " << str << endl;

    return 0;
}
