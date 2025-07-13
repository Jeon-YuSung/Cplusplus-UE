//16-20. Main 
#include "convert.h"

int main(void) {


    string strg = toString(12);
    cout << "문자열 : " << strg << endl;

    double data;
    data = toData<double>("15.687");
    cout << "데이터 : " << data << endl;

    return 0;
}
