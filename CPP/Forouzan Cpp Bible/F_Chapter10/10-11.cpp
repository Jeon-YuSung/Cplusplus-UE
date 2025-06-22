/*
10-11. 문자열 토큰화 
strtok 사용해서 날짜 형식 추출하는 형식 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    
    char str[] = "2025년 6월 22일";
    char* p;

    //단어 추출
    p = strtok(str, " "); //처음 호출 
    while(p) {
        cout << p << "\n";
        p = strtok(0, " "); //나머지 호출
    }


    return 0;
}
