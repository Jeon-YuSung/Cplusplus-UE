//17-2. 최대 공약수를 구하는 프로그램.

#include <iostream>
using namespace std;

int gcd(int f, int s) {

    if (s == 0) {
        return f;
    }
    else {
        return gcd(s, f % s);
    }
}

int main(void) {

    cout << "gcd (8,6) = " << gcd(8, 6) << endl;
    cout << "gcd (9,12) = " << gcd(9, 12) << endl;
    cout << "gcd (7,11) = " << gcd(7, 11) << endl;
    cout << "gcd (3,19) = " << gcd(3, 19) << endl;
    cout << "gcd (21,35) = " << gcd(21, 35) << endl;
    cout << "gcd (140,12) = " << gcd(140, 12) << endl;

    return 0;
}
