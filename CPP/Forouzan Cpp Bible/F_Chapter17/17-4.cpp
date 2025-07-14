//17-4. 재귀적으로 문자열 반전하기

#include <iostream>
#include <string>
using namespace std;

string reverse(string str) {

    if (str.length() <= 1) {
        return str;

    }
    else {
        return reverse(str.substr(1, str.length() - 1)) + str.substr(0, 1);
    }
}

int main(void) {

    cout << "ABCD 반전 = " << reverse("ABCD") << endl;

    cout << "wxyz 반전 = " << reverse("wxyz") << endl;

    cout << "Hello 반전 = " << reverse("Hello") << endl;

    
    return 0;
}
