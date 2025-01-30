#include <iostream>
#include <typeinfo>
using namespace std;

int main (void){

int x;
double y;

x = 23.72;
y= 130;

//데이터의 값과 자료형 확인 
cout <<"x의 23.72의 자료형 : " << typeid(x=23.72).name() << endl;
cout <<"할당 후 의 x의 값 : " << x <<endl;
cout << "y의 130의 자료형 : " <<typeid(y=130).name() << endl;
cout << "할당 후 y의 값 " << y << endl;

//암묵적 자료형 변환 활용 
cout << " 캐스팅 하지 않을 경우 " << x + y << endl;
//명시적 자료형 변환 
cout << "캐스팅 " << static_cast<int>(x)+y << endl; 

  return 0;
}
