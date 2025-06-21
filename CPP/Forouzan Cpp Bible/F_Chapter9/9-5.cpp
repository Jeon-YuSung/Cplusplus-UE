//9-5 직접 참조와 간접 참조 
// 데이터 변수의 값에 직접, 간접 접근해서 출력하는 프로그램 
#include<iostream>
using namespace std;

int main(void) {

    //데이터 변수 선언 
    int score = 92;
    int* pScore = &score;

    cout << "socre의 직접 접근 : " << score << "\n";
    cout << "score의 간접 접근 : " << *pScore << "\n";
    
    return 0;

}
