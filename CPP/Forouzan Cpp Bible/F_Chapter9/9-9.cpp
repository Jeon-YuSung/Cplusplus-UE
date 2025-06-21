/*
9-9. 인덱스와 포인터를 사용해서 배열의 요소에 접근하기. 
인덱스와 포인터 모두 활용해서 배욜의 요소에 접근하는 방법을 보여주는 프로그램
*/
 
#include<iostream>
using namespace std;



int main(void) {

    int arr[5] = {10,11,12,13,14};
    
    // 인덱스를 사용해서 배열의 요소에 접근
    cout << "인덱스 사용 \n";
    for (int i = 0; i < 5; i++) {
    
        cout << arr[i] << " ";

    }
    cout << "\n";

    //포인터 사용해서 배열의 요소에 접근 
    cout << "포인터 사용 \n";
    for (int i = 0; i < 5; i++) {
        cout << *(arr + i) << " ";
    }
    return 0;
}
