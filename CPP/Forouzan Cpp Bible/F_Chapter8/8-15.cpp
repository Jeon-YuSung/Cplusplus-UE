/* 
8-15. 배열 선형 변환
2차원 배열을 열 방향과 행 방향으로 선형 변환해서 1차원 배열로 만든 뒤 출력하는 프로그램 
*/

#include <iostream>
#include <iomanip>
using namespace std;

//함수 선언
void rowTransform(const int originArray[][4], int rowSize, int rowArray[]);
void colTransform(const int originArray[][4], int rowSize, int colArray[]);
void printTwoDimensional(const int twoDimensional[][4], int rowSize);
void printOneDimensional(const int oneDimensional[], int size);


//메인함수 
int main(void) {
	//배열 선언 및 초기화
	int originArray[2][4] = { {0,1,2,3},{10,11,12,13} };
	int rowArray[8]; 
	int colArray[8];

	//2개의 함수를 호출하여 배열 반환
	rowTransform(originArray, 2, rowArray);
	colTransform(originArray, 2, colArray);

	//2차원 배열 출력
	cout << " 원본 배열 \n";
	printTwoDimensional(originArray, 2);

	//행 방향 선형 변환
	cout << " 행 방향으로 선형 변환한 결과 : ";
	printOneDimensional(rowArray, 8);

	//열 방향 선형 변환
	cout << " 열 방향으로 선형 변환한 결과 : ";
	printOneDimensional(colArray, 8);
	return 0; 
}

//함수 정의 
/*
rowtransform 함수는 2차원 배열을 행 방향으로 선형 변환해서 1차원 배열로 생성
첫 번째 매개변수는 변경하지 않게 const 한정자를 붙임 
*/
void rowTransform(const int originArray[][4], int rowSize, int rowArray[]) {

	int i = 0, j = 0;
	for (int k = 0; k < 8; k++) {

		rowArray[k] = originArray[i][j];
		j++;
		if (j > 3) {
			i++;
			j = 0;
		}
	}
}

/*
colTransfrom  함수는 2차원 배열을 열 방향으로 선형 변환해서 1차원 배열로 생성
첫 번째 매개변수는 변경하지 않게 const 한정자를 붙임 
*/
void colTransform(const int originArray[][4], int rowSize, int colArray[]) {
	int i = 0, j = 0;
	for (int k = 0; k < 8; k++) {
		colArray[k] = originArray[i][j];
		i++;
		if (i > 1) {
			j++;
			i = 0;
		}
	}
}

// 2차원 배열을 매개변수로 받아서 출력, 매개변수는 변경하지 않게 const한정자 사용 

void printTwoDimensional(const int twoDimensional[][4], int rowSize) {


	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < 4; j++) {
			cout << setw(4) << twoDimensional[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

// 1차원 배열을 매개변수로 받아 출력 
void printOneDimensional(const int oneDimensional[], int size){

	for (int i = 0; i < size; i++) {

		cout << setw(4) << oneDimensional[i];
	}
	cout << endl; 
}
