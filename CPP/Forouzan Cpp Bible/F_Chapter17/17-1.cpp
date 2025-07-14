//17-1. 재귀를 이용한 팩토리얼과 합계를 구하기 

#include <iostream>
using namespace std;

//sum 함수의 재귀 정의 
int sum(int n) {
    if (n <= 0) {
        return 0;
    }
    return sum(n - 1) + n;
}

// 팩토리얼 함수의 재귀적 함수 정의
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return factorial(n - 1) * n;

}

int main(void) {

    cout << "sum(0) = " << sum(0) << endl;
    cout << "팩토리얼 (1) = " << factorial(1) << endl;
    
    cout << "sum(3) = " << sum(3) << endl;
    cout << "팩토리얼 (3) = " << factorial(3) << endl;
    
    cout << "sum(5) = " << sum(5) << endl;
    cout << "팩토리얼 (5) = " << factorial(5) << endl;
    
    cout << "sum(7) = " << sum(7) << endl;
    cout << "팩토리얼 (7) = " << factorial(7) << endl;

    return 0;
}
