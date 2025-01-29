#include <iostream>
using namespace std;

int main (void){

  //상수 정의 
  const unsigned int peenyValue = 1; 
  const unsigned int nickelValue = 5; 
  const unsigned int dimeValue = 10; 
  const unsigned int quarterValue = 25;
  const unsigned int dollarValue = 100;

  //변수 정의 
  unsigned int peenies;
  unsigned int nickels;
  unsigned int dimes; 
  unsigned int quarters;
  unsigned int dollars;
  unsigned long totalValue;

  // 코인 입력 
  cout << "페니의 수 : ";
  cin >> peenies;
  cout << "니켈의 수 : ";
  cin >> nickels;
   cout << "다임의 수 : ";
  cin >> dimes;
   cout << "쿼터의 수 : ";
  cin >> quarters;
   cout << "달러의 수 : ";
  cin >> dollars;


  //전체 금액 계산 
  totalValue = peenies * peenyValue + nickels * nickelValue +
    dimes * dimeValue +  quarters * quarterValue +  dollars *  dollarValue;

 //결과 출력
  cout << "전체의 값은" << totalValue << "페니입니다" << endl;

  return 0;
}
