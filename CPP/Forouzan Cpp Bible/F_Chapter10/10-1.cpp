/*
10-1. strcpy와 strncpy를 사용해서 문자열 복사하는 프로그램 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main(void) {

    //str2 전체를 str1를 복사
    char str1[] = "This is the 1st string.";
    char str2[] = "This is the 2nd string.";
    strcpy(str1, str2);

    cout << "str1 : " << str1 << "\n";

    //str4의 일부를 str3으로 복사 
    char str3[] = "abcdefghijkln.";
    char str4[] = "ABCDEFGHIJKLN.";

    strncpy(str3, str4, 4); //앞에서부터 복사

    cout << "str3 : " << str3 << "\n";

    return 0;
}
