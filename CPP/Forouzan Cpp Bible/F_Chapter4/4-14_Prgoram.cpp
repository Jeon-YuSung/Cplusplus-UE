// 조건부 표현식 

#include <iostream>
using namespace std;

int main (void){

  int n1, n2;
  int larger;

  //입력
  cout << "첫 번째 숫자 입력 : ";  
  cin >> n1;
  
  cout << "두 번째 숫자 입력 : ";  
  cin >> n2;

  //의사 결정
  larger = n1 >= n2 ? n1 : n2;

  cout << " 더 큰 숫자는 " << larger << "입니다\n";

  return 0;
}

 
