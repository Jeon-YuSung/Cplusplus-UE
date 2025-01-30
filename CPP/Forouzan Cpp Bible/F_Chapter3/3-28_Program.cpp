//부동 소수점이 주어졌을댸 정수와 소수점 아래 부분을 추출하는 프로그램. 

#include <iostream>
#include <iomanip>
using namespace std;

int main (void){
  
  int intPart;
  double number;
  double fractPart;

  //입력 
  cout << " 부동소수점 입력 : " ;
  cin >> number;

  intPart = static_cast<int>(number);
  fractPart = number - intPart;

  //출력 
  cout << fixed << showpoint << setprecision(2);
  cout << "원래 값 : " << number << endl;
  cout << "정수 값 : " << intPart << endl;
  cout << "소수점 아랫 부분 : " << fractPart << Endl;
  
  return 0;
}
