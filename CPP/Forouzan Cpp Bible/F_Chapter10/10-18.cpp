/*
10-18. 서브 문자열 추출하기
문자열에서 서브 문자열을 추출해서 출력하는 프로그램.
*/


#include <iostream>
#include <string>
using namespace std;

int main(void) {
    
    string strg("The C++ language is fun to work with.");
    cout << strg.substr(8) << endl;
    cout << strg.substr(4, 12) << endl;


    return 0;
}
