//1-1. array 예제 코드
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

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

    return 0; 

}
