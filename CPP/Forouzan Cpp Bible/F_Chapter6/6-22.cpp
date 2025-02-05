// 범위 해결 연산자를 사용하는 프로그램. 

#include <iostream>
using namespace std;

int num = 4; //전역 변수

int main (void){
int num = 25; //지역 변수 
  cout << "전역 변수 num의 값 = " << ::num << endl;
    cout << "지역 변수 num의 값 = " << num << endl;
  return 0;
}
