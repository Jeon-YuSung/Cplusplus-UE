//16-3. 각 단어의 첫 글자를 대문자로 만드는 프로그램 

#include <iostream>
using namespace std;

int main(void) {

	char c;
	cout << "여러 줄의 글자를 입력 하세요 (종료 : eof, ctrl+z) : \n";
	char pre = '\n';

	while (cin.get(c)) {

		if (pre == ' ' || pre == '\n') {
		
			cout.put(toupper(c));
		}
		else {
		
			cout.put(c);
		}
		pre = c; 
		}
	return 0;
}
