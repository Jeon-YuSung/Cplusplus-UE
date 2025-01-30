#include <iostream>
using namespace std;

int main (void){
//불 자료형에 boolalpha 조정자 사용 
  bool x = true;
  bool y = false;

  cout << "x와 y의 기본 출력 :" << x << y << endl;

  //조정자 사용
  cout << "조정자를 사용한 x의 값 : " << boolalpha << x <<endl;
  cout << "y의 값 : " << y;

  //oct는 8진수, hex는 16진수를 출력 showbase는 각각의 진법으로 출력
  int a;
  a = 1285;

     cout << "10진수 a의 값 : " << a <<endl;
     cout << "8진수 a의 값 : "<< oct << a <<endl;
     cout << "16진수 a의 값 : "<< hex<< a <<endl;
    
     cout << "10진수 showbase a의 값 : "<< showbase << dec << a <<endl;
     cout << "8진수 showbase a의 값 : " << showbase << oct << a <<endl;
     cout << "16진수 showbase a의 값 : " << showbase << hex << a <<endl;

  //fixed, showpoint, scientific 사용해서 표현

  double b = 1266;
  double c = 13124.31232134;

      cout << "b의 고정 소수점 형식 : "<< b <<endl;
     cout << "showpoint를 사용한 b의 고정 소수점 형식 : " << showpoint << b <<endl;
     cout << "과학 표기법을 사용한 c의 값 : " << c << scientific << endl;

  //출력 방식 조정 
  cout << fixed << setprecision(2) << showpos << setfill('*');
  cout << setw(15) << left << c << endl;
  cout << setw(15) << interal << c << endl;
  cout << setw(15) << right << c << endl;
  
    
  return 0;
}
