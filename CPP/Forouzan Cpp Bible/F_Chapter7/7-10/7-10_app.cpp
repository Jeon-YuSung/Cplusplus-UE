#include <iostream>
#include "7-10_interface.h"
using namespace std;

int main(void) {

   Fraction fract1;
   Fraction fract2(14,21);
   Fraction fract3(11, -8);
   Fraction fract4(fract3);

  cout << "생성한 분수 4개를 출력 " << endl; 
  cout << "fract1 : " << fract1.print() << endl;
  cout << "fract2 : " << fract2.print() << endl;
  cout << "fract3 : " << fract3.print() << endl;
  cout << "fract4 : " << fract4.print() << endl;

  //설정자 사용
  cout << "두 분수를 변경하고 출력 " << endl;
  fract1.setNumer(4);
  cout << "fract1 : " << fract1.print() << endl;
  fract2.setDenom(-5);
  cout << "fract1 : " << fract1.print() << endl;

  cout << "접근자로 분자와 분모 따로 확인 하기 : " << endl;
  cout << "fract1의 분자 : " << fract1.getNumer() <<endl;
  cout << "fract2의 분모 : " << fract2.getDenom() <<endl;

  return 0;
}
