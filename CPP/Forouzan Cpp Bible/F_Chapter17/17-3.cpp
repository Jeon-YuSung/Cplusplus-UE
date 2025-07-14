//17-3. 피보나치 수열 구하기 

#include <iostream>
using namespace std;

long long fib(int n) {

    if (n == 0 || n == 1) {
        return n;
    }
    else {
        return(fib(n - 1) + fib(n - 2));
    }
}

int main(void) {

    cout << "0~10 범위의 피노나치 수 테스트 \n";
    for (int i = 0; i <= 10; i++) {
        cout << "fib(" << i << ") = " << fib(i) << endl;
    }
    cout << endl << endl;

    cout << "35와 36 피보나치 수 테스트 \n";
    cout << "fib 35 = " << fib(35) << endl;
    cout << "fib 36 = " << fib(36) << endl;

    return 0;
}
