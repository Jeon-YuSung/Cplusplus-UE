// 3가지 종류의 변수를 초기화하지 않은 경우의 값
// 변수의 초기화를 확인하는 프로그램. 

#include <iostream>
using namespace std;

int global;

int main (void){
static int sLocal; //정적 지역 변수 
  int aLocal; //자동 지역 변수 

  //출력 
  cout << "전역 변수 = " << global << endl; 
  cout << "정적 지역 변수 = " << sLocal << endl;
  cout << "자동 지역 변수 = " << aLocal << endl; // 쓰레기 값 나옴. 
  
  return 0;
}
