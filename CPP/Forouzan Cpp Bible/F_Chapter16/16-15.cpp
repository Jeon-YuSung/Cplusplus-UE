//16-15. 이진파일에 데이터 쓰고 읽기 

#include <iostream>
#include<fstream>
#include<string>
#include<cassert>
using namespace std;

int main(void) {

    int a;
    a = 12345;
    double d;
    d = 45.78;
    ofstream strmOut("sample2", ios::out | ios::binary);
    if (!strmOut.is_open()) {
        cout << "파일에 쓸 수 없습니다 \n";
        assert(false);
    }
    strmOut.write(reinterpret_cast<char*>(&a), sizeof(int));
    strmOut.write(reinterpret_cast<char*>(&d), sizeof(double));
    strmOut.close();

    ifstream strIn("sample2", ios::in | ios::binary);
    if (!strIn.is_open()) {
        cout << "파일을 읽을수 없습니다 \n";
        assert(false);
    }
    strIn.read(reinterpret_cast<char*>(&a), sizeof(int));
    strIn.read(reinterpret_cast<char*>(&d), sizeof(double));
    strIn.close();

    cout << "a의 값 : " << a << endl;
    cout << "d의 값 : " << d << endl;

    return 0;
}
