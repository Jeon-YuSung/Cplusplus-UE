//기본 parameter를 사용하는 프로그램 

#include <iostream>
using namespace std;

double calEarnings(double rate, dobuble hours = 40);

int main (void){

  cout << "직원 1의 임금 : " << calEarnings(22.0) << endl;
  cout << "직원 2의 임금 : " << calEarnings(12.50, 18) << endl;
  return 0;
}

double calEarnings(double rate, dobuble hours){

 double pay;
  pay = hours * rate;
  return pay; 
  
}
