//19-27. 정렬 알고리즘 

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
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

    cout << "오름차순으로 정렬한 벡터 출력 \n";
    sort(vec.begin(), vec.end());
    for_each(vec.begin(), vec.end(), print);
    cout << endl << endl; 

    cout << "내리차순으로 벡터 출력 \n";
    sort(vec.begin(), vec.end(), greater<int>());
    for_each(vec.begin(), vec.end(), print);
    cout << endl << endl;
    
    return 0; 

}
