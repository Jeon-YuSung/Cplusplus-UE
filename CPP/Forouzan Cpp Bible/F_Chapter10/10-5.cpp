/*
10-5. 첨자 연산자를 사용해서 문자열의 문자에 접근하는 프로그램
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    

    const char* str1 = "Hello my friends.";
    char str2[] = "This is the 2nd string";

    //특정 위치의 문자 출력
    cout << "str1의 인덱스 6에 위치하는 문자 " << str1[6] << "\n";
    //특정 위치 문자 변경
    str2[0] = 't';
    cout << "변경 후의 str2 : " << str2;

    return 0;
}
