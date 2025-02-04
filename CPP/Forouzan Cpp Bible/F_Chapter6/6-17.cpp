// 점수 기반으로 등급 계산하는 프로그램
// 입력, 처리, 출력 함수들을 사용 

#include <iostream>
using namespace std;

//함수 선언 
int getScore();
char findGrade(int score);
void printResult(int score, char grade);

//메인 함수 
int main (void){
  //변수 선언
  int score;
  char grade;

  //함수 호출
  score = getScore();
  grade = findGrade(score);
  printResult(score, grade);
  return 0;
}

/*
side-effects를 갖는 입력 함수
사용자로부터 점수를 입력 받고, 이를 메인 함수에 값으로 리턴
지역변수 score를 리턴하는 형태 
함수 내부에서는 0~100 사이의 점수인지 확인하는 유효성 검사도 하고있음 
*/

int getScore(){
  int score;
  do {
    cout << "점수 입력 : " ;
    cin >> score;
  } while(score < 0 || score > 100);
  return score;
}
/*
Call by Value인 함수로  
전달된 매개변수 score의 값을 기반으로 학점을 계산하고
학점을 값으로 리턴하는 함수
if-else문 또는 switch문으로 구현 가능 
*/

char findGrade(int score){
char grade; 
  switch(score/10){
  case 10 :    
  case 9 :
    grade = 'A'; 
    break;
    
  case 8 :
    grade = 'B'; 
    break;
  
  case 7 :
    grade = 'C'; 
    break;
      
  case 6 :
    grade = 'D'; 
    break;
    default :
        grade = 'F';
  }
  return grade;
}

// 점수와 학점을 출력하는 함수 
void printResult(int score, char grade) {

  cout << endl << " 시험 결과" << endl;
  cout << "점수 = " << score << "/100 " << "학점 = " << grade << endl; 

}
