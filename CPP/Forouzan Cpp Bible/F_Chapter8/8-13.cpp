//8-13 배열 3개 사용하기
//학생의 시험 성적들과 그 평균을 2차원 배열로 만들어서 활용하는 프로그램 
#include <iostream>
#include <iomanip>
using namespace std;

//함수 선언
void findStudentAverage(int const scores[][3], double stdAver[], int rowSize, int colSize);
void findTestAverage(int const score[][3], double tstAver[], int rowSize, int colSize);

//메인 함수
int main(void) {

	//배열과 변수 선언
	const int rowSize = 5;
	const int colSize = 3;
	int scores[rowSize][colSize] = { {82, 65, 72},
									 {73, 70, 80},
									 {91, 67, 40},
									 {72, 72, 67},
									 {65, 90, 80} };
	double stdAver[rowSize];
	double tstAver[colSize];

	//배열을 수정하는 함수 2개 호출
	findStudentAverage(scores, stdAver, rowSize, colSize);
	findTestAverage(scores, tstAver, rowSize, colSize);

	//헤더 출력 
	cout << "            시험 점수             평균 \n";
	cout << "-----------------------------  ---------\n";

	//시험 점수와 학생의 평균 출력 
	for (int i = 0; i < rowSize; i++) {
		for (int j = 0; j < colSize; j++)
		{
			cout << setw(12) << scores[i][j];
		}
		cout << fixed << setprecision(2) << " " << stdAver[i] << "  \n";
	}

	//평균 출력
	cout << "===============================================\n";
	cout << "최종 점수 : ";
	
	for (int j = 0; j < colSize; j++)
	{
		cout << fixed << setprecision(2) << "  " << stdAver[j] << "  ";
	}

	cout << "\n";
	return 0;
}

//첫 번째 매개변수로 학생의 성적을, 2차원 배열을 매개변수로 입력받고
//두 번째 매개변수로 시험의 성적 평균을 구해서 유사 리턴 
void findStudentAverage(int const scores[][3], double stdAver[], int rowSize, int colSize) {

	for (int i = 0; i < rowSize; i++) {
		int sum = 0; 
		for (int j = 0; j < colSize; j++) {
			sum += scores[i][j];
		}
		double average = static_cast<double>(sum) / colSize;
		stdAver[i] = average;
	}
	return; 
}

//학생의 성적 평균을 구해서 유사 리턴 
void findTestAverage(int const score[][3], double tstAver[], int rowSize, int colSize) {

	for (int j = 0; j < colSize; j++) {
		int sum = 0; 
		for (int i = 0; i < rowSize; i++) {
			sum += score[i][j];
		}
		double average = static_cast<double>(sum) / rowSize;
		tstAver[j] = average;
	}
}
