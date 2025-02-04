// 두 값을 스왑하는 프로그램 
#include <iostream>
using namespace std;

void swap(int &first, int &second);

int main (void){

  int fst = 10;
  int snd = 20;
  swap(fst,snd);

  //스왑 확인 
  cout << " 메인 함수의 first 값 : " << fst << endl;
  cout << " 메인 함수의 second 값 : " << snd << endl;
  
  return 0;
}
/*
swap함수는 call by reference로 
2개의 매개변수를 받음
temp라는 임시 변수를 사용해서 값을 스왑 
call by reference로 받은 매개변수를 변경했으므로 argument에도 영향을 미친다 
여기서 argument는 메인함수의 fst와 snd이다. 
*/

void swap(int &fir, int &sec){

  int temp;
  temp = fir;
  fir = sec;
  sec = temp;
  return;
}
