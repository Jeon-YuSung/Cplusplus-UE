//19-22. 사용자 정의 함수와 for_each 조합하기
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void print(int v) {
    cout << v << " ";

}

int main(void) {
    vector<int> vec;
    vec.push_back(25);
    vec.push_back(32);
    vec.push_back(77);

    for_each(vec.begin(), vec.end(), print);

    return 0; 

}
