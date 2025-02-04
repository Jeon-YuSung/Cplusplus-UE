//매개변수와 리턴값이 있는 함수 

#include <iostream>
using namespace std;

/*
larger 함수는 두 값을 매개변수로 받고,
둘 중에 더 큰수를 찾아서 값을 리턴하는 함수 
별도의 side-effects는 없음 
*/

int larger(int fst, int snd){
 int max;
  if(fst>snd){
    max =fst;
  }else{
    max= snd;
  }
  return(max);
}

int main (void){

  //변수 선언 및 입력
  int first, second;

  cout << " 첫 번째 숫자 입력 : "; 
  cin >> first; 
  cout << " 두 번째 숫자 입력 : "; 
  cin >> second; 

  // 함수 호출
  cout << "두 수 중에 큰 것 = " << larger(first, second) << endl;
  
  return 0;
}
