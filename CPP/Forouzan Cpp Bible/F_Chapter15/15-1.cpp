//작은 것을 찾는 smaller 함수를 자료형 별로 구현
#include<iostream>
using namespace std;

char smaller(char c1, char c2) {

	if (c1 < c2) {
		return c1;
	}
	return c2;
}

int smaller(int f1, int f2) {

	if (f1 < f2) {

		return f1;
	}
	return f2;
}


double smaller(double d1, double d2) {
	if (d1 < d2) {

		return d1;
	}
	return d2;
}
int main(void) {

	cout << "a와 B중 작은것 : " << smaller('a', 'B') << endl;
	cout << "34와 256중 작은것 : " << smaller(34, 256) << endl;
	cout << "23.45와 21.41중 작은것 : " << smaller(23.45, 21.41) << endl;

	return 0;
}
