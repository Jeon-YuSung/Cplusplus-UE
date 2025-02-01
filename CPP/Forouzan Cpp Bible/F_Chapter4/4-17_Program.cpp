//날짜 번호 구하기 
/*
한 해의 모든 날에 날짜 번호를 매기고, 
몇 월 며칠이 1년에서 몇 번째 날인지를 구하는 프로그램.
*/
#include <iostream>
using namespace std;

int main (void){

//변수 선언
  int month, day;
  int totalDays = 0;
  
  //입력 
  cout << "몇 월 인지 입력 : ";
  cin >> month;
  cout << "며칠인지 입력 : ";
  cin >> day;

  //각 월의 날짜 수 
  int m1 = 31;
  int m2 = 28;
  int m3 = 31;
  int m4 = 30;
  int m5 = 31;
  int m6 = 30;
  int m7 = 31;
  int m8 = 31;
  int m9 = 30;
  int m10 = 31;
  int m11 = 30;
//스위치문으로 특정 달까지의 날 수 계산 
switch(month){
  case 12:
  totalDays += m11;
    case 11:
  totalDays += m10;
    case 10:
  totalDays += m9;
    case 9:
  totalDays += m8;
  case 8:
  totalDays += m7;
    case 7:
  totalDays += m6;
    case 6:
  totalDays += m5;
    case 5:
  totalDays += m4;
  case 4:
  totalDays += m3;
    case 3:
  totalDays += m2;
    case 2:
  totalDays += m11;
    case 1:
  totalDays += 0;
}
//최종 결과 및 출력
totalDays = totalDays + day; 

  cout << "올해의 " << totalDays << "번째 날입니다 \n";
  
  return 0;
}

 
