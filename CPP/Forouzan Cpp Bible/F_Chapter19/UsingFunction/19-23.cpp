//19-23. 함수 객체 사용하기 
#include <iostream>
using namespace std;

class Print {

public:
    void operator()(int v) {
        cout << v;
    }
};
int main(void) {

    Print print;
    print(45);

    return 0; 

}
