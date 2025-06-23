/*
10-12. 크기, 용적과 관련된 멤버 함수 사용하기 
문자열을 생성하고 용적 크기 관련 함수를 사용하는 프로그램 
*/


#include <iostream>
#include <string>
using namespace std;

int main(void) {
    
    string strg("Hello my friends");
    
    //크기와 용적 관련 함수 
    cout << "크기 : ";
    cout << strg.size() << endl;
    cout << "최대 크기 : " << strg.max_size() << "\n";
    cout << "용적 : " << strg.capacity() << "\n";
    cout << "빈 문자열 여부 : " << boolalpha << strg.empty() << "\n";
    cout << endl << endl;

    // 예약 후 크기와 용적 관련 함수 한번 더 사용 
    strg.reserve(20);
    cout << "크기 : ";
    cout << strg.size() << endl;
    cout << "최대 크기 : " << strg.max_size() << "\n";
    cout << "용적 : " << strg.capacity() << "\n";
    cout << "빈 문자열 여부 : " << boolalpha << strg.empty() << "\n";
  

    return 0;
}
