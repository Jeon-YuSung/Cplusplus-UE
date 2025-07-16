//19-12 괄호 짝 확인하기
//표현식의 괄호짝이 맞는지 확인하는 프로그램 

#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main(void) {


    stack<char> stk;
    string exp;
    bool paired = true;

    cout << "표현식 입력 : ";
    getline(cin, exp);
    int i = 0;
    while (i < exp.size() && paired) {
    
        char next = exp[i];
        if (next == '(') {
            stk.push(next);
        }
        else if (next == ')') {
            if (stk.empty()) {
                paired = false; // 스택이 여기에서 비어버리면 짝이 안맞는다. 
            }
            else {
                stk.pop();
            }
        }
        i++;
    }
    //스택이 비어 있지 않으면 짝이 안맞다는 의미
    if (!stk.empty()) {
        paired = false;
    }

    //결과 
    if (paired) {
        cout << "괄호 짝은 정상적인 표현입니다. \n";
    }
    else {
        cout << " 괄호 짝이 맞지않습니다. \n";
    }
    return 0;
}
