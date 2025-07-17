//19-19. 맵으로 학생의 이름과 점수 저장하기
#include <iostream>
#include <iomanip>
#include <map>
#include <utility>
using namespace std;

int main(void) {
    
    // map과 iteraotr 선언
    map<string, double> scores;
    map<string, double>::iterator iter;

    //맵에 학생 이름과 점수 저장
    scores["Vidan"] = 89.5;
    scores["Lusi"] = 72.3;
    scores["Den"] = 78.7;
    scores["Ruminus"] = 93.2;
    scores["Robert"] = 73.5;
    scores["Maria"] = 75.4;
    scores["Ari"] = 96.0;

    //출력
    cout << "학생의 이름과 점수  \n";
    for (iter = scores.begin(); iter != scores.end(); iter++) {
    
        cout << setw(10) << left << iter->first << " ";
        cout << setw(4) << iter->second << endl;

    }
    return 0; 

}
