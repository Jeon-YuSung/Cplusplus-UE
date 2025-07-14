//17-5. 문자열이 회문인지 확인하는 프로그램 

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str) {

    if (str.size() <= 1) {
        return true;
     }
    else if(str[0] != str[str.size() - 1]) {
        return false;
    }

    return isPalindrome(str.substr(1, str.size() - 2));
}
int main(void) {

    string strg1("");
    string strg2("rotor");
    string strg3("hello");

    cout << boolalpha;
    cout << " strg1('') = " << isPalindrome(strg1) << endl;
    cout << " strg2(rotor) = " << isPalindrome(strg2) << endl;
    cout << " strg3(hello) = " << isPalindrome(strg3) << endl;

    
    return 0;
}
