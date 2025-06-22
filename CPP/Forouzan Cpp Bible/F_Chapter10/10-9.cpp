/*
10-9. 두 문자열을 비교하는 프로그램 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    

   const char* str1 = "Hello Alice";
   const char* str2 = "Hello John.";
   const char* str3 = "Hello Betsy.";

   //문자열 전체 비교
   cout << "str1, str2 비교하기 : " << strcmp(str1, str2) << "\n";
   cout << "str2, strr3 비교하기 " << strcmp(str2, str3) << "\n";
   
  //앞의 5문자만 비교
   cout << "str1과 str2의 앞 5문자만 비교하기 : " << strncmp(str1, str2, 5);

    return 0;
}
