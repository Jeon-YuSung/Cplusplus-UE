//8-8 배열 리턴을 유사적으로 구현
// 2개의 배열 매개변수로 받고 유사적으로 리턴하는 함수를 구현하는 프로그램 

#include <iostream>
using namespace std;

//함수 선언
void reverse(const int array1[], int array2[], int size);
void print(const int array[], int size);

//메인 함수
int main(void) {

	//배열 2개 선언
	int array1[5] = { 150, 120, 190, 110, 160 };
	int array2[5];

	//reverse 함수 호출
	reverse(array1, array2, 5);
	//배열 출력
	print(array1, 5);
	print(array2, 5);

	return 0;
}

//reverse 함수는 매개변수로 2개의 배열을 받아, 첫 번째 배열을 거꾸로 돌려서 두 번째 배열로 리턴하는 함수 
void reverse(const int array1[], int array2[], int size) {

	for (int i = 0, j = size - 1; i < size; i++, j--) {
		array2[j] = array1[i];
	}

	return;
}

//print 함수는 입력받고 이를 활용해서 배열의 내용을 출력, 배열 요소를 수정하지 않음. 
void print(const int array[], int size) {

	for (int i = 0; i < size; i++) {
	
		cout << array[i] << " ";
	}
	cout << endl;
	return;
}
