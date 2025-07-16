//19-3. 2차원 벡터로 테이블을 만드는 프로그램 

#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;


int main(void) {


    //벡터 테이블 2차원 생성
    int rows = 10;
    int cols = 10; 
    vector<vector<int>> table (rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
    
        for (int j = 0; j < cols; j++) {
            table[i][j] = (i + 1) * (j + 1);
        }
    }

    //값 추출하여 출력
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << table[i][j] << " ";
        }
        cout << endl;
        
    }
    return 0;
}
