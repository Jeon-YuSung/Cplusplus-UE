/*
10-16. 모든 단어를 대문자로 만들기
첨자 연산자를 사용해서 왼값, 오른값 추출해서 대문자로 바꾸는 프로그램
*/


#include <iostream>
#include <string>
using namespace std;

int main(void) {
    
    string line;

    cout << "한 줄 입력 : ";
    getline(cin, line);
    for (int i = 0; i < line.size(); i++) {
    
        line[i] = toupper(line[i]);
    }

    cout << line << endl;
    return 0;
}
