//19-26. 변경 알고리즘 

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <random>
using namespace std;

void print(int v) {
    cout << v << " ";
}

int main(void) {
    
    vector<int> vec;
    vec.push_back(11);
    vec.push_back(17);
    vec.push_back(14);
    vec.push_back(22);
    vec.push_back(39);
    vec.push_back(26);
    vec.push_back(41);
    vec.push_back(91);
    vec.push_back(64);
    vec.push_back(40);

    cout << "원본 출력 \n";
    for_each(vec.begin(), vec.end(), print);
    cout << endl << endl;

    cout << "반전된 벡터 출력 \n";
    reverse(vec.begin(), vec.end());
    for_each(vec.begin(), vec.end(), print);
    cout << endl << endl; 

    cout << "회전한 벡터 출력 \n";
    rotate(vec.begin(), vec.begin() + 2, vec.end());
    for_each(vec.begin(), vec.end(), print);
    cout << endl << endl;
    
    //난수 생성기 준비 
    random_device a;  // 시드 공급 
    mt19937 b(a()); // 메르센 트위스터 엔진을 a가 준 시드로 초기화

    cout << "셔플한 벡터 출력 \n";
    //random_shuffle(vec.begin(), vec.end()); c++17부턴 완전 제거됨 
    shuffle(vec.begin(), vec.end(), b);
    for_each(vec.begin(), vec.end(), print);
    cout << endl << endl;

    return 0; 

}
