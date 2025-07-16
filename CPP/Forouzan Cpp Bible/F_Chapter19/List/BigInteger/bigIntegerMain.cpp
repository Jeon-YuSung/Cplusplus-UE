//19-10. Biginteger 애플리케이션 

#include <iomanip>
#include <iostream>
#include "bigInteger.h"
using namespace std;

int main(void) {


    //문자열 입력받기
    string strg1, strg2;
    cout << "첫 번째 큰 정수를 입력 : ";
    cin >> strg1;
    cout << "두 번째 큰 정수 입력 : ";
    cin >> strg2;

    //Biginteger 객체 2개생성
    Big_integer first(strg1);
    Big_integer second(strg2);
    
    // 두 정수를 더하고 result에 할당
    Big_integer result;
    result = first + second;

    //biginteger 객체를 문자열로 변경
    strg1 = first.toString();
    strg2 = second.toString();
    
    string strg3; 
    strg3 = result.toString();
    string dashes(strg3.length(), '-');

    //결과 출력 
    cout << "첫 번째 정수 : " << setw(strg3.length());
    cout << right << strg1 << " + \n";
    cout << "두 번째 정수 : " << setw(strg3.length()) << right << strg2 << endl;
    cout << "                " << dashes << endl;
    cout << "결과 :           " << setw(strg3.length()) << right << strg3 << endl;

    return 0;
}
