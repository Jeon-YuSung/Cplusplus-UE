//18-2(8). 재귀가 아니라 스택을 사용해 문자열 반전해보기 
#include "stack.cpp"
#include <string>

int main(void) {

    Stack<char> stack;
    string origin;
    string reversed;

    cout << " 뒤집을 문자열 입력 : ";
    getline(cin, origin);

    for (int i = 0; i < origin.size(); i++) {
        stack.push(origin[i]);
    }

    //문자를 꺼내서 반전
    while (stack.size() > 0) {
    
        reversed.push_back(stack.top());
        stack.pop();
    }

    cout << "원본 문자열 :" << origin << endl;
    cout << "뒤집은 문자열 : " << reversed << endl;

    return 0;
}
