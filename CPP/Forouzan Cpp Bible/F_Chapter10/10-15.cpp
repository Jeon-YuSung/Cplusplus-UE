/*
10-15. 문자열 내부의 문자 출력하기
문자열에서 문자 하나를 추출해서 출력하는 프로그램
*/


#include <iostream>
#include <string>
using namespace std;

int main(void) {
    
    string strg("A short string");

    //5, 8번째 인덱스 위치 문자 추출
    cout << "인덱스 5번의 문자 : " << strg[5] << endl;
    cout << "인덱스 8번의 문자 : " << strg.at(8) << endl;

    return 0;
}
