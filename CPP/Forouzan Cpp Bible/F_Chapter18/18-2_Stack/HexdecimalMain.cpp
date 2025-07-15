//18-2(7). 10진수를 16진수로 변환해보기 
#include "stack.cpp"

int main(void) {

    Stack<char> stack;

    //문자열 객체 2개와 변수 2개생성
    string converter("0123456789ABCDEF");
    string hexadecimal;
    int decimal, index;

    // 10진수 입력
    do
    {
        cout << " 양의 정수 입력 : ";
        cin >> decimal;

    } while (decimal <= 0);

    cout << "입력한 10진수의 값 : " << decimal << endl;

    //16진수 문자로 변환해서 스택에 넣기
    while (decimal != 0) {
    
        stack.push(converter[decimal % 16]);
        decimal = decimal / 16;
    }

    //스택에서 꺼내서 문자열 조합
    while (stack.size() > 0) {
    
        hexadecimal.push_back(stack.top());
        stack.pop();
    }

    cout << " 변환한 16진수의 값 : " << hexadecimal << endl;

    return 0;
}
