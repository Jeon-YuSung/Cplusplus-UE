//15-9(14) 스택 애플리케이션 파일 
#include "stack.cpp"

int main(void)
{
	Stack<int> stack(10);
	stack.push(6);
	stack.push(2);
	stack.push(7);
	stack.push(3);

	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	return 0;
}
