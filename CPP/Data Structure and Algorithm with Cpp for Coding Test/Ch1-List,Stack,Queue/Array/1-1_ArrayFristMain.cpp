//1-1. array 예제 코드
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

void print(array<int, 5> arr);

template<size_t N>
void print2(const array<int, N>& arr);

int main(void) {
    
    array<int, 10> arr1;
    arr1[0] = 1;
    
    cout << "arr1의 첫 번째 원소 : " << arr1[0] << "\n";
    
    array<int, 4> arr2 = { 1,2,3,4 };
    cout << "arr2의 모든 요소 : ";
    
    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    //예외 처리하는 경우 
    array<int, 6> arr3 = { 1,2,3,4,5,6 };
    try {
        cout << "arr3의 3번째 데이터 값은 : " << arr3.at(3) << endl;
        cout <<  arr3.at(6) << endl; // out_ofrange 예외 발생
    }
    catch (const out_of_range& ex) {
        cerr << ex.what() << endl;
    }
    cout << endl;

    array<int, 5> arr4 = { 1,2,3,4,5};
    print(arr4);
    cout << endl; 

    array<int, 7> arr5 = { 1,2,3,4,5,6,7 };
    print2(arr5);
    cout << endl;

    array<int, 9> arr6 = { 1,2,3,4,5,6,7,8,9 };
    for (auto iter = arr6.begin(); iter != arr6.end(); iter++) {
        auto el = (*iter);
        cout << el << ' ';
    }
    cout << endl;

    array<int, 8> arr7 = { 1,2,3,4,5,6,7,8 };
    cout << "arr7을 사용해서 array에 대한 원소 접근 함수 \n";
    cout << arr7.front() << endl;
    cout << arr7.back() << endl;
    cout << *(arr7.data() + 1) << endl;

    return 0;
}

void print(array<int, 5> arr) {
    for (auto ele : arr) {
        cout << ele << ",";
    }
}

template<size_t N>
void print2(const array<int, N>& arr) {

    for (auto element : arr) {
        cout << element << ' ';
    }
}
