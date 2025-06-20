#include <iostream>
using namespace std;

#ifndef 7-10_INTERFACE_H
#define 7-10_INTERFACE_H
  
class Fraction{
  private:
int numer;
int denom;

//private 보조 멤버 함수
void normalize();
int gcd(int n, int m);

public:
  //생성자
Fraction(int num, int den);
Fraction();
Fraction(const Fraction &fract);
~Fraction();
//접근자
int getNumer() const;
int getDenom() const;
void print() const;
//설정자
void setNum(int num);
void setDenom(int den);


  };
#endif
