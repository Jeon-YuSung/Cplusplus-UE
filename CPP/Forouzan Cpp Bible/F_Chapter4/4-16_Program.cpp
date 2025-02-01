// 소득 범위에 따른 세금 구하기 
// 특정 소득을 기반으로 세금을 계산한 뒤, 출력하는 프로그램

#include <iostream>
using namespace std;

int main (void){
  //변수 선언
  double income, tax;
  bool bracket1, bracket2, bracket3, bracket4;
  double limit1, limit2, limit3;
  double rate1, rate2, rate3, rate4;
//상한 
  limit1 = 10000.00; 
  limit2 = 50000.00;
  limit3 = 100000.00;
//비율 
  rate1 = 0.05;
  rate2 = 0.10;
  rate3 = 0.15;
  rate4 = 0.20;

  //입력
  cout << "수입을 달러 입력하세요 : " ;
  cin >> income;

  //소득 범위 찾기 
  bracket1 = (income <= limit1) && (income >= 0);
  bracket2 = (income > limit1) && (income <= limit2);
  bracket3 = (income > limit2) && (income <= limit3);
  bracket4 = (income > limit3);

  //세금 계산 
  if(bracket1){
tax = income * rate1;  
  }
  else if (bracket2){
    tax = limit1 * rate1 + (income - limit1) * rate2; 
  }
  else if (bracket3){
    tax = limit1 * rate1 + (limit2 - limit1) * rate2 + (income * limit2) * rate3; 
  }
  else if (bracket4){
    tax = limit1 * rate1 + (limit2 - limit1) * rate2 + 
      (limit3 - limit2) * rate3 + (income * limit3) * rate4; 
  }
  else {
    cout <<"입력에 문제가 있습니다.\n";
    return 0;
  }
  //수입과 세금 출력
  cout << "수입 = " << income << endl;
  cout << "세금 = " << tax;
  
  return 0;
}

 
