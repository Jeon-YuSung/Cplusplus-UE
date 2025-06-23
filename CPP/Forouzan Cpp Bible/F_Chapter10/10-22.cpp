/*
10-22. 회문 확인하기 
*/
#include <iostream>
#include <string>
using namespace std;

void reverse(string& strg);
bool isPalind(string& strg);

int main(void) {
    string strg;
    cout << "문자열 입력 : ";
    getline(cin, strg);
    //회문 확인
    if (isPalind(strg)) {
        cout << strg << "은 회문 입니다.";
    }
    else
    {
        cout << strg << "회문이 아닙니다.";
    }
    return 0;
}

//문자열을 뒤집는다. 
void reverse(string& strg) {
    string temp(strg);
    int size = strg.size();
    for (int i = 0; i < size; i++) {
        strg[i] = temp[size - 1 - i];
    }
}
// 문자열을 복사하고 뒤집은뒤에 원래 문자열이랑 같은지 확인하는 함수 
bool isPalind(string& strg) {

    string temp(strg);
    reverse(temp);
    return(temp == strg);
}
