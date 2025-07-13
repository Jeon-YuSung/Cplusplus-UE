//16-24. 사용자 정의 조정자 2개를 사용하는 프로그램 
// boolalpha와 noboolalpha를 구현하는 프로그램 
#include <iostream>
#include <iomanip>
using namespace std;

ostream& alpha(ostream& os) {

    os.setf(ios::boolalpha);
    return os;

}

ostream& noalpha(ostream& os) {
    os.unsetf(ios::boolalpha);
    return os;
}
int main(void) {

    bool a = false;
    bool b = true;

    cout << alpha << a << " " << b << endl;
    cout << noalpha << a << " " << b << endl;

    return 0;
}
