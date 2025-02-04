//CallbyValue확인하는 프로그램 

#include <iostream>
using namespace std;

// 함수 선언 
void fun(int y);

int main (void){
 //변수 선언
  int x = 10;
  // x를 argument로 fun함수 호출
  fun(x);

  //x의 값이 변했는지 확인 (변화 x)
  cout << "main 함수 내부의 x = " << x << endl;
  return 0;
}

/*
fun 함수는 x 값을 전달받고 이를 y에 저장
이때 x와 y는 서로 다른 메모리 위치를 가짐.
따라서 fun 함수의 y를 증가시켜도 main함수의 x에는 영향 없음 
*/

void fun(int y){

  y++;
  cout << "fun 함수 내부의 y = " << y << endl;
  return; 
}
