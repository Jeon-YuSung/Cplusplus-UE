/*
10-4 getline함수를 사용해서 한 줄을 모두 읽어 들이고 출력하는 프로그램 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main(void) {
    
    char lines[3][80];

    for (int i = 0; i < 3; i++) {

        cout << "한 줄을 입력하세요 : ";
        cin.getline(lines[i],80);
    }

    cout << endl;
    cout << "출력 : " << endl;
    for (int i = 0; i < 3; i++) {

        cout << lines[i] << "\n";
    }

    return 0;
}
