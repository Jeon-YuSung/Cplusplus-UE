#include <iostream>
using namespace std;

int main (void){

  //변수 선언
  int base, exponet;
  unsigned long int power, temp;
  bool overflow;

  // 유효성 검사화면서 입력받기
  do {
cout << "밑을 음수가 아닌 정수로 입력하세요 : ";
    cin >> base;
  } while(base < 0);

  do {
cout << "지수를 음수가 아닌 정수로 입력하세요 : ";
    cin >> exponet;
  } while(exponet < 0);

  // 초기화
  power = 1; 
  temp = power;
  overflow = false;

  //처리 
  for (int i = 1; (i <= exponet) && (!overflow); i++){
    power *= base; 
    if(power / base != temp){
    overflow = true; // 반복문 종료 
    }
    temp = power; 
  }

  //출력 
  if(overflow){
  cout << "오버플로우가 발생했습니다, 작은 값으로 다시 시도하세요. ";
  } else {
cout << base << "^" << exponet << " = " << power << endl;  
  }
  return 0;
}
