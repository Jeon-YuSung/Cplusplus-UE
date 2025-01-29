#include <iostream>
using namespace std;

int main (void){

  int bal = 0;
  int trans;

  cout << " 첫 번째 거래 금액 입력 : ";
  cint >> trans;
  bal = bal + trans;

  cout << " 두 번째 거래 금액 입력 : ";
  cint >> trans;
  bal = bal + trans;

  cout << " 셋 번째 거래 금액 입력 : ";
  cint >> trans;
  bal = bal + trans;

  cout << "계좌의 최종 잔액은 " << bal << "달러입니다." << endl;

  // 정수 자료형 크기 확인
  cout << "short int의 크기 : "<< sizeof(short int) << "입니다." <<endl;
  cout << "int의 크기 : "<< sizeof(int) << "입니다." <<endl;
  cout << "long int의 크기 : "<< sizeof(long int) << "입니다." <<endl;
  
  

  return 0;
}
