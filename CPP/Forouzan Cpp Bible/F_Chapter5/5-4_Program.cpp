// while 반복문을 사용해서 수열의 합 구하기 
#include <iostream>
using namespace std;

int main (void){
//변수 선언
  int sum1, sum2, sum3;
  int n; 

//sum 변수 초기화
  sum1 = 0;
  sum2 = 0;
  sum3 = 0;

  //변수 n에 입력
  cout << " n의 값 입력 : " ;
  cin >> n;

  //while 반복문
  int counter = 1; 
  while(counter <= n){
    sum1 += counter;
    sum2 += counter * counter;
    sum3 +=   counter * counter * counter;
    counter ++;   
    }

  cout << " n의 값은 = " << n << endl;
  cout << "sum1의 값 : " << sum1 << endl;
  cout << "sum2의 값 : " << sum2 << endl;
  cout << "sum3의 값 : " << sum3 << endl;
  
  return 0;
}

 
