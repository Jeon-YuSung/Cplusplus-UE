/*
callByReference확인 
매개변수의 변경이 arugment에 영향을 준다는 것을 확인하는 프로그램 
*/

#include <iostream>
using namespace std;

/*
fun 함수는 y로 참조를 전달 받음
따라서  y는 함수 호출 때 argument의 별칭이 됨 
매개변수를 변경하면 argumnet가 함께 변함
*/
void fun(int &y){

  y++;
  cout << "fun 함수 내부의 y = " << y << endl; 
  return;
}

//메인 함수 
int main (void){
  int x = 10;
  fun(x);
cout << " 메인 함수 내부의 x = " << x << endl;
  return 0;
}
