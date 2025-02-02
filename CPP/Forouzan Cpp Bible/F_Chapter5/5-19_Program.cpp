// 리스트 내부의 숫자 곱을 활용해서 팩토리얼 n!을 구하는 프로그램 

#include <iostream>
using namespace std;

int main (void){

  int n;
  unsigned long long factorial;

  // 입력 받기 
do {
  cout << " 팩토리얼의 크기를 입력하세요 : ";
  cin >> n;
} while(n < 0);

  //초기화
  factorial = 1; 
  for (int i = 1; i < n + 1; i++){
factorial *= i;  
  }
  // 출력 
  cout << n << "! = " << factorial << endl;
  
  return 0;
}
