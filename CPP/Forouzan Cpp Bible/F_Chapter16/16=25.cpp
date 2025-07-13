//16-25. 사용자 정의 조정자를 만들고 사용하는 프로그램 

#include <iostream>
#include <iomanip>
using namespace std;

ostream& currency(ostream& stream) {

    cout << '$';
    stream.precision(2);
    stream.fill('*');
    stream.setf(ios::fixed, ios::floatfield);
    return stream;
}

int main(void) {

    cout << currency << setw(12) << 12341.23 << endl;
    cout << currency << setw(12) << 0.34 << endl;

    return 0;
}
