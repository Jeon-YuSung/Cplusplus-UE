//15-2 두 값중에 작은 값을 찾는 템플릿 함수를 사용하는 프로그램.
#include<iostream>
using namespace std;

template<typename T>
T smaller(T f1, T f2) {

	if (f1 < f2) {
	
		return f1;
	}
	return f2;
}
int main(void) {

	cout << "a와 B중 작은것 : " << smaller('a', 'B') << endl;
	cout << "34와 256중 작은것 : " << smaller(34, 256) << endl;
	cout << "23.45와 21.41중 작은것 : " << smaller(23.45, 21.41) << endl;

	return 0;
}
