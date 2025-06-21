/*
9-10. 배열 요소의 합 구하기 
*/
 
#include<iostream>
using namespace std;

int getSum(const int* a, int b) {
    int sum;
        sum = 0;
    for (int i = 0; i < b; i++) {
        sum += *(a++);
    }
    return sum;
}

int main(void) {

    int arr[5] = {10,11,12,13,14};
    
    cout << "요소의 합 : " << getSum(arr, 5);

    return 0;
}
