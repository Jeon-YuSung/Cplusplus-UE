/*
10-19. 문자열의 단어 추출하기 
한 줄의 문자열 내부에서 단어들을 찾아 출력하는 프로그램 
*/
#include <iostream>
#include <string>
using namespace std;

int main(void) {
    
    string text;
    string delimiter(" \t\n");
    string::size_type wStart, wEnd;
    string::size_type npos = -1; //오류가 발생하는 경우 뒤에 =-1 추가할 것
    

    //한 줄입력 받기
    cout << "한 줄 입력 : ";
        getline(cin, text);

    //문자 탐색하고 단어 추출
        cout << "추출한 단어 : " << endl;
    wStart = text.find_first_not_of(delimiter, 0);
    while (wStart != npos) { // wStart < npos로 나와있지만, nops는 최대값을 찾지 못했다는 의미로 !=가 더 적합 
    
        wEnd = text.find_first_of(delimiter, wStart);
        cout << text.substr(wStart, wEnd - wStart) << endl;
        wStart = text.find_first_not_of(delimiter, wEnd);
    }


    return 0;
}
