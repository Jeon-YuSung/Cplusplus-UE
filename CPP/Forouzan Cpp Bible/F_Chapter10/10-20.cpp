/*
10-20. 함수를 이용하여 문자여을 비교하는 프로그램 
*/
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    

    //선언
    string strg1("hello my friends");
    string strg2 = "hello friends";
    
    cout << strg1 << "와 " << strg2 << "비교하기 : ";
    cout << strg1.compare(strg2) << endl;

    cout << "일부 비교 : " << endl;
    cout << strg1.compare(0, 5, strg2, 0, 5) << endl;
    cout << strg1.compare(0, 5, strg2) << endl;
    cout << strg2.compare(0, 3, "hello", 4);

    return 0;
}
