/*
10-2. 문자열의 길이를 찾아서 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main(void) {

    
    const char* str1 = "This is the 1st string.";
    char str2[] = {'H','e','l','l','o','\0'};

    //문자열의 길이를 찾아서 출력 
    cout << "str1의 길이 : " << strlen(str1) << "\n";
    cout << "str2의 길이 : " << strlen(str2) << "\n";

    //한글 문자열 (멀티 바이트) 문자 출력
    const char* str3 = "안녕하세요";
    cout << "str3의 길이 : " << strlen(str3);

    return 0;
}
