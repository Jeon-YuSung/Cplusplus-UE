//15-4. 템플릿 함수를 사용하여 모든 자료형과 크기의 배열을 출력
#include<iostream>
using namespace std;

template<typename T, int N>
void print(T(&array)[N]) {

	for (int i = 0; i < N; i++) {
	
		cout << array[i] << " ";
	}
	cout << endl;
}

int main(void) {

	//배열 생성
	int arr1[4] = { 7,3,5,2 };
	double arr2[3] = { 7.8, 1.5, 2.2 };

	//템플릿 함수 호출 
	print(arr1);
	print(arr2);

	return 0;
}
