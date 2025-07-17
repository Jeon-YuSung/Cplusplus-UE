//19-25. 비변경 알고리즘 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool isEven(int value) {
    return(value % 2 == 0);
}

void timesTwo(int& value) {
    value = value * 2;
}

void print(int value) {
    cout << value << " ";
}

int main(void) {
    
    vector<int> vec;
    
    vec.push_back(25);
    vec.push_back(32);
    vec.push_back(77);
    vec.push_back(55);
    vec.push_back(12);
    
    vec.push_back(10);
    vec.push_back(7);
    vec.push_back(99);
    vec.push_back(43);
    vec.push_back(88);

    //원본 출력
    cout << "원본 벡터의 값 \n";
    for_each(vec.begin(), vec.end(), print);
    cout << endl << endl;

    // 벡터 내부의 10의 개수 세기
    cout << "벡터 내부에 있는 10의 개수 = ";
    cout << count(vec.begin(), vec.end(), 10);
    cout << endl << endl;

    cout << "벡터 내부에 있는 짝수 개수 = ";
    cout << count_if(vec.begin(), vec.end(), isEven);
    cout << endl << endl;

    cout << "벡터 내부의 요소에 곱하기 2 = ";
    for_each(vec.begin(), vec.end(), timesTwo);
    for_each(vec.begin(), vec.end(), print);
    cout << endl << endl;
    return 0; 

}
