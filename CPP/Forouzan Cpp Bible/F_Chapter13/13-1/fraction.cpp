#include <iostream>
#include <cmath>
#include <cassert>
#include "fraction.h"
using namespace std;

//생성자
Fraction::Fraction(int num, int den = 1)
    : numer(num), denom(den) {
    normalize();
}

Fraction::Fraction()
    :numer(0), denom(1) {
}

Fraction::Fraction(const Fraction& fract)
    :numer(fract.numer), denom(fract.denom) {
}

Fraction::~Fraction() {}

//접근자
int Fraction::getNumer() const
{
    return numer;
}

int Fraction::getDenom() const
{
    return denom;
}

void Fraction::print() const
{
    cout << numer << "/" << denom << endl;
}

//설정자
void Fraction::setNum(int num)
{
    numer = num;
    normalize();
}

void Fraction::setDenom(int den)
{
    denom = den;
    normalize();
}

//private 보조 멤버 함수
void Fraction::normalize() {
    if (denom == 0) {
        cout << "잘못된 분모 값 입니다. 프로그램을 중단합니다\n";
        assert(false);
    }
    if (denom < 0) {
        denom = -denom;
        numer = -numer;
    }

    int divisor = gcd(abs(numer), abs(denom));
    numer = numer / divisor;
    denom = denom / divisor;
}

int Fraction::gcd(int n, int m) {

    int gcd = 1;
    for (int i = 1; i <= n && i <= m; i++) {

        if (n % i == 0 && m % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}
