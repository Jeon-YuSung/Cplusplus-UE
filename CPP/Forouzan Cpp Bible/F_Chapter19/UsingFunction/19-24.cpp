//19-24. 단항 함수 객체 
//함수에 대한 포인터와 객체를 사용하는 프로그램

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void print(int v) {
    cout << v << " ";

}
int main(void) {

    vector<int> vec;
    vec.push_back(25);
    vec.push_back(32);
    vec.push_back(77);
    vec.push_back(55);
    //함수에 대한 포인터로 요소 출력
    for_each(vec.begin(), vec.end(), print);
    cout << endl << endl;

    //모든 요소의 부호를 반전하고 출력 
    transform(vec.begin(), vec.end(), vec.begin(), negate<int>());
    for_each(vec.begin(), vec.end(), print);

    return 0; 

}
