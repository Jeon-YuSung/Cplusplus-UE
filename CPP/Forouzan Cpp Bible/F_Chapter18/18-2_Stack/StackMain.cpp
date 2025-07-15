//18-2. 스택 구현해보기
#include "stack.cpp"

int main(void) {

    Stack<string> stack;

    //스택에 노드 추가 
    stack.push("Korea");
    stack.push("Yonsei");
    stack.push("Dongguk");
    stack.push("Konkuk");
    stack.push("Sejong");

    // 스택 크기 확인
    cout << "스택의 크기 : " << stack.size() << endl;

    // top 멤버 함수를 호출해서 위의 노드 확인 후 pop 멤버 함수를 호출해서 제거 
    while (stack.size() > 0) {
    
        cout << "Stack.top = " << stack.top() << endl;
        stack.pop();
    }

    cout << " 스택의 크기 다시 확인 : " << stack.size() << endl;

    return 0;
}
