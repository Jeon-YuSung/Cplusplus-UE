// 정적 변수를 확인하는 프로그램. 
#include <iostream>
using namespace std;

void fun();

int main (void){

  fun();
  fun();
  fun();
  
  return 0;
}

// 정적 지역 변수 count를 갖는 함수
// count는 처음 호출할 때, 초기화 되며 이후에는 초기화되지 않고 값이 유지됨.
void fun(){

  static int count = 0;
  count++;
  cout << "count = " << count << endl;
  
}

/*
함수를 처음 호출 할 때, count변수가 초기화 되고, 이후에는 초기화가 실행되지 않아
값을 계속 유지함. 
정적 변수는 다양한 경우에 활용됨
*/
