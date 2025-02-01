// 학생 성적 구하기 
// 시험 성적 3개에서 최대값과 최소값을 구하고, 이 두 값의 평균을 학생 성적으로 결정하는 프로그램 

#include <iostream>
using namespace std;

int main (void){

  //변수 선언 
  int score1, score2, score3;
  int max,min, score;

  //시험 성적 입력 
  cout << "첫 번째 시험 점수 입력 : ";
  cin >> score1;
  cout << "두 번째 시험 점수 입력 : ";
  cin >> score2;
  cout << "셋 번째 시험 점수 입력 : ";
  cin >> score3;

  // 가장 큰 점수 찾기
  if (score1 > score2 && score1 > score3)
  {
    max = score1;
  }
  else if(score2 > score1 && score2 > score3)
  {
    max = score2;
  }
  else 
  {
    max = score 3; 
  }

    // 가장 작은 점수 찾기
  if (score1 < score2 && score1 < score3)
  {
    min = score1;
  }
  else if(score2 < score1 && score2 < score3)
  {
    min = score2;
  }
  else 
  {
    min = score 3; 
  }

  //학생 성적을 구하고 올림하기 (홀수 일때 올림)
  int temp;
  temp = max + min;

  if(temp % 2 == 1)
  {
temp = temp + 1;
  }
  score = temp/2;
//결과 출력 
  cout << " 입력한 점수 = " << score1 << " " << score2 << " " << score3 << endl;
  cout << " 최소 점수와 최대 점수 = " << min << " " << max << endl; 
  cout << " 학생 성적 = " << score;
  return 0;
}

 
