//19-11. 10진수를 16진수로 변환하기 

#include <stack>
#include <iostream>

using namespace std;

int main(void) {


    stack<char> stk;
    string converter("0123456789ABCDEF");
    string hex;
    int dec;

    //10 진수 입력 받기
    do {
        cout << "정수 입력 :";
        cin >> dec;
    } while (dec <= 0);

    //16진수로 변환하고 스택에 입력
    while (dec != 0) {
    
        stk.push(converter[dec % 16]);
        dec = dec / 16;
    }

    //스택에서 요소를 꺼내서 문자열에 붙임
    while (!stk.empty())
    {
        hex.push_back(stk.top());
        stk.pop();
    }
    cout << "16진수 변환 결과 = " << hex;

    return 0;
}
