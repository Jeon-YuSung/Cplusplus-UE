//정수의 첫 번째 자릿 수 출력 
#include <iostream>
using namespace std;

int main (void){
  unsigned int giveInt, firstDigit;

  //입력
  cout << "양의 정수 입력 : " ;
  cin >> giveInt;

  //처리
  firstDigit = giveInt % 10;
 
  // 출력 
  cout << "입력한 정수 : " << giveInt << endl;
  cout << "첫 번째 정수 자릿수 추출 : << firstDigit << endl; 

  return 0;
}
