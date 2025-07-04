//15-5. 템플릿 함수를 사용하여 특수화하는 프로그램
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

template<typename T>
T smaller(const T& f1, const T& f2) {

	if (f1 < f2) {
		return f1;
	}
	return f2;
}

//템플릿 특수화
template<>
const char* smaller(const char* const& f1, const char* const& f2) {

	if (strcmp(f1, f2) < 0) {

		return f1;
	}
	return f2;
}

int main(void) {

	string str1 = "Hello";
	string str2 = "Hi";
	cout << "smaller(str1,str2) : " << smaller(str1, str2); 
	cout << endl;

	const char* s1 = "Bye";
	const char* s2 = "Bye Bye";
	cout << "smaller(s1,s2) : " << smaller(s1, s2) << endl;
	return 0;
}
