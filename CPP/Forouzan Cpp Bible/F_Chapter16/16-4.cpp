//16-4. getline 함수 사용하기 

#include <iostream>
using namespace std;

int main(void) {

	char c[100];
	cin.getline(c, 100, '\n');
	cout << c;

	return 0;
}
