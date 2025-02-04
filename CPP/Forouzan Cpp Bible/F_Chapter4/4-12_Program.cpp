//스위치문을 활용하여 점수기반 학점 출력하는 프로그램 

#include <iostream>
using namespace std;

int main (void){

  int score;
  char grade;

  cout << "점수를 입력하세요 : ";
  cin >> score;

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
    grade  = 'F';    
    
  }

  //결과 출력
  cout << "점수 : " << score << endl;
  cout << "학점 : " << grade << endl;
  
  return 0;
}

 
