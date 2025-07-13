//16-19. 문자열 스트림 클래스를 테스트하기

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void) {

    istringstream iss("hello Friends!");
    cout << iss.str() << endl;
    iss.str("hello, world!");
    cout << iss.str() << endl << endl;

    ostringstream oss("bye friends!");
    cout << oss.str() << endl;
    oss.str("Bye,world");
    cout << oss.str() << endl;

    return 0;
