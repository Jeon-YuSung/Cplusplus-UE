//전역 스코프의 쉐도잉 

#include <iostream>
using namespace std;

int num = 5; //전역 변수

int main (void){
  cout << num << endl; //전역 변수 num
  int num; // 지역 변수 
  num = 24; // 지역변수 초기화 
    cout << num << endl; // 지역 변수 num이 전역변수 num을 가림 (쉐도잉)
  return 0;
}
