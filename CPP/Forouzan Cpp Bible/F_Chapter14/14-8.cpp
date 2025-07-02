//14-8 invalid_argument 클래스 사용하는 프로그램
// invalid_argument 객체를 사용해서 0으로 나눌 경우, 예외를 발생시키고 처리하는 프로그램. 

#include<iostream>
#include<stdexcept>
using namespace std;

int quotient(int f, int s) {
	if (s == 0) {

		throw invalid_argument("오류 : 0으로 나눌수 없습니다. \n");
	}
	return (f / s);
}

int main(void) {
	
	int n1, n2, result;
	for (int i = 0; i < 5; i++) {

		cout << "정수 입력 : ";
		cin >> n1;
		cout << "다른 정수도 입력 : ";
		cin >> n2;

		try {

			cout << "결과 : " << quotient(n1, n2) << endl;
		}
		catch (invalid_argument ex) {
			cout << ex.what() << endl;
		}
	}

}
