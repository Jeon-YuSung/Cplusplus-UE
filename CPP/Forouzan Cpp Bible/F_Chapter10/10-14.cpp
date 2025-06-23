/*
10-14. 입출력 연산자 사용하기 
문자열 입출력 연산자를 사용하는 프로그램 
*/


#include <iostream>
#include <string>
using namespace std;

int main(void) {
    
    string strg;

    //한줄 입력
    cout << "한 줄 입력 : ";
    getline(cin, strg);
    cout << strg << endl;
    cout << endl;

    //여러줄 입력 
    cout << "여러 줄 입력 (종료 때는 $ 입력) : ";
    getline(cin, strg, '$');
    cout << strg << endl;
  

    return 0;
}
