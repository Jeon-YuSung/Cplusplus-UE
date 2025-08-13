//20-10. 전략 패턴, 오름차순과 내림차순으로 정렬하는 프로그램 
#include <iostream>
#include <string> 
#include <cassert>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;

void print(string m, vector<int> v);

int main(void) {

    //벡터 선언 및 요소 넣고 출력
    vector<int> vec;
    vec.push_back(18);
    vec.push_back(10);
    vec.push_back(13);
    vec.push_back(16);
    vec.push_back(19);
    vec.push_back(12);
    vec.push_back(15);

    print("원본 벡터 : ", vec);

    //오름차순 정렬 
    sort(vec.begin(), vec.end(), less<int>());
    print("오름차순 : ", vec);

    //내림차순 정렬
    sort(vec.begin(), vec.end(), greater<int>());
    print("내림차순 : ", vec);
    return 0; 

}

void print(string m, vector<int> v) {

    cout << m;
    for (int i = 0; i < v.size(); i++) {
        cout << setw(4) << left << v[i];
    }
    cout << endl;
}
