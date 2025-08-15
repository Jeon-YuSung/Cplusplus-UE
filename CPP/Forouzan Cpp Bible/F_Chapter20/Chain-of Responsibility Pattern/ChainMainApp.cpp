//20-15. 책임 연쇄 패턴 예제 파일
#include "chain.h"
using namespace std;

int main(void) {

    cout << "대출자 1 : \n";
    Loan lo1(82000);
    cout << endl;

    cout << "대출자 2 : \n";
    Loan lo2(700);
    cout << endl;

    cout << "대출자 3 : \n";
    Loan lo3(146000);
    cout << endl;

    cout << "대출자 4 : \n";
    Loan lo4(3200000);
    cout << endl;

    return 0; 

}
