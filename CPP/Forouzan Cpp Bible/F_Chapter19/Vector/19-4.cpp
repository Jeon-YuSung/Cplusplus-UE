//19-4. 래기드 벡터를 사용해서 파스칼 삼각형 만들기 
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;


int main(void) {

    int power = 5;
    vector<vector<int>> pascal(power + 1, vector<int>());

    //레기드 벡터 생성
    // push_back 대신에 resize, assign, vector(새 벡터 사용) 
    for (int i = 0; i <= power; i++) {
        for (int j = 0; j < i + 1; j++) {
            pascal[i]= vector<int>(i + 1, 0); //push_back(0) 사용시 컴파일 오류 or  런타임 오류(UB)발생.
        }
    }

    //레기드 벡터를 파스칼의 삼각형으로 채우기
    for (int i = 0; i <= power; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || i == j) {
            
                pascal[i][j] = 1;
            }
            else {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i- 1][j];
            }
        }
    }

    //출력 
    for (int i = 0; i <= power; i++) {
        cout << "(X+Y)^" << i << "의 계수 ==>";
        for (int j = 0; j < i + 1; j++) {
            cout << setw(4) << pascal[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
