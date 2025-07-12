//16-14. 파일의 길이는 알아보자 

#include <iostream>
#include<fstream>
#include<cassert>
using namespace std;

int main(void) {
    ifstream fstr;
    fstr.open("TestFile1.txt", ios::in | ios::ate);

    cout << "전체 크기 :" << fstr.tellg();

    fstr.close();
    return 0;
}
