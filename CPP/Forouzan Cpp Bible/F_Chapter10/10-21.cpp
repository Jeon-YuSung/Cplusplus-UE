/*
10-21. 비교 연산자를 사용해서 문자열을 비교하기 
*/
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    

    //선언
    string strg1;
    string strg2(5, 'a');
    string strg3("Hello Friends");
    string strg4("hi people", 4);

    cout << "strg1 < strg2 : " << boolalpha << (strg1 < strg2) << endl;
    cout << "strg2 >= strg3 : " << boolalpha << (strg2 >= strg3) << endl;
    cout << "strg1 == strg2 : " << boolalpha << (strg1 == strg2) << endl;
    cout << "hi p != strg4 : " << boolalpha << ("hi p" != strg4) << endl;

    return 0;
}
