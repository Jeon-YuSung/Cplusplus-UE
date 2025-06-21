/*
9-8. 배열 요소들의 주소를 확인하는 프로그램 
시스템이 배열에 있는 요소를 포인터로 다룬다는 것을 확인하기 위한 프로그램
*/
 
#include<iostream>
using namespace std;



int main(void) {

    int arr[5];
    // 포인터 연산과 *연산자로 주소 출력
    for (int i = 0; i < 5; i++) {
    
        cout << "포인터 연산을 사용한 주소 : " << i;
        cout << arr + i << "\n";
        cout << " & 연산자를 사용한 주소 : " << i;
        cout << &arr[i] << endl << endl;

    }
    return 0;
}
