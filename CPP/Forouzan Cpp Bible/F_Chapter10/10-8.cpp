/*
10-8 문자들 중 특정 문자의 위치 찾기 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    

    char str[] = "Hello friends of mine.";
    // 처음 등장하는 문자 e를 대문자로 변경
    char* sPtr= strpbrk(str, "pfmd");
    cout << "찾은 문자 : " << *sPtr << "\n";
    cout << "해당 문자의 인덱스 : " << sPtr - str;

    return 0;
}
