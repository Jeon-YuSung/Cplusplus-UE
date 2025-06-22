/*
10-10. strcat과 strncat 사용하기 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    

    char str1[20] = "This is";
    const char* str2 = "a String";
    strcat(str1, str2);
    cout << "str1 : " << str1 << "\n";

    char str3[20] = "abcdefghijklmn";
    const char* str4 = "ABCDEFGHIJKLMN";
    strncat(str3, str4,4);
    cout << "str3 : " << str3 << "\n";

    return 0;
}
