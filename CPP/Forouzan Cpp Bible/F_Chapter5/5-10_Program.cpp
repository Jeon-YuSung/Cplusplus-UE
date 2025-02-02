// 7로 나눌 수 있는 숫자 출력하기 
// 1~300 범위에 있는 8로 나눌 수 있는 정수를 
// 10개의 열을 가진 표 형식으로 출력하는 프로그램

#include <iostream>
#include <iomanip>
using namespace std;

int main (void){

  // 변수 선언 및 초기화
  int lower, higher, divisor, col;

  lower = 1; 
  higher = 300;
  divisor = 7;
  col = 1;

  //for문
  for (int i = lower; i < higher; i++){
if( i % divisor == 0){
  cout << setw(4) << i; 
  col++;
  if(col>10){
    cout << endl;
    col = 1;
    }
  }   
}
  return 0;
}

 
