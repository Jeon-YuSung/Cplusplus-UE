//19-21. 함수에 대한 포인터 사용하기. 
#include <iostream>
using namespace std;

void print(int v) {
    cout << v << endl;

}

void fun(int x, void(*f)(int)) {
    f(x);
}

int main(void) {
    
    fun(24, print);
    fun(88, print);

    return 0; 

}
