//8-9. 병렬 배열 사용하기
// 병렬 행열을 사용하여 5명의 이름 점수 학점을 저장하고 활용하는 프로그램 
#include <iostream>
#include <iomanip>
using namespace std;

//함수 선언

//findGrades 함수는 score 상수, grade 배열, 크기를 매개변수로 받고 첫 번째 배열을 활용해서 두번째 배열을 만듬
void findGrades(const int scores[], char grades[], int size) {

	char temp[] = { 'F','F','F','F','F','F','D','C','B','A','A' };
	for (int i = 0; i < size; i++) {
		grades[i] = temp[scores[i] / 10];
	}
	return;
}

//메인
int main(void) {

	//배열 3개 선언 및 2개 초기화 
	string names[4] = { "George", "John", "Maria" , "Luci" };
	int scores[4] = { 82,73,91,72 };
	char grades[4];

	findGrades(scores, grades, 4);
	
	//배열 3개의 값 출력
	for (int i = 0; i < 4; i++) {
	
		cout << setw(10) << left << names[i] << "       " << setw(2);
		cout << scores[i] << "   " << setw(2) << grades[i] << "\n";
	}

	return 0;
}
