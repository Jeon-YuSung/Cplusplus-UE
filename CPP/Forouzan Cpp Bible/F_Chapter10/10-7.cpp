/*
10-7 서브 문자열 탐색하기
strstr 멤버 함수를 사용해서 문자열에서 서브 문자열의 위치를 찾는 프로그램 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    

    char str[] = "Hello friends of mine.";
    // 처음 등장하는 문자 e를 대문자로 변경
    char* sPtr= strstr(str, "friends");
    cout << "서브 문자열의 시작 인덱스 : " << sPtr - str;

    return 0;
}
