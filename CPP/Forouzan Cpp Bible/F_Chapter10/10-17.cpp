/*
10-17. 문자열 객체 뒤집기 
문자열을 뒤집는 프로그램 
*/


#include <iostream>
#include <string>
using namespace std;

void reverse(string& strg) {

    string temp(strg);
    int size = strg.size();
    for (int i = 0; i < size; i++) {

        strg[i] = temp[size - 1 - i];
    }

}

int main(void) {
    
    string strg;

    cout << "문자열을 입력 : ";
    getline(cin, strg);
    cout << "원본 문자열 : " << strg << endl;

    reverse(strg);
    cout << "뒤집은 문자열: " << strg << endl;

    return 0;
}
