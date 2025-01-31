#include <iostream>
using namespace std;

int main (void){

  int score;
  char grade;

  cout<< "점수 입력 : " ;
  cin >> score; 

  if(score>= 90){
  grade = "A"; 
  
  }
  else if (score >= 80){
      grade = "B"; 
  
  }   else if (score >= 70){
      grade = "C"; 
  
  } 
    else if (score >= 60){
      grade = "D"; 
  } 
  else {
    grade = "F";
  }
  return 0;
}
