/*
9-11. 배열 요소를 거꾸로 만들기 
*/
 
#include<iostream>
using namespace std;

void reverse(int* a, int b) {

    int i, j;
    i = 0;
    j = b - 1;

    while (i < b / 2) {
        int temp;
        temp = *(a + i);
        *(a + i) = *(a + j);
        *(a + j) = temp;
        i++;
        j--;
    }
}

int main(void) {

    int arr[5] = {10,11,12,13,14};

    reverse(arr, 5);

    //배열을 거꾸로 만들고 출력
    cout << " 배열 거꾸로 출력 : ";
    for (int i = 0; i < 5; i++) {

        cout << *(arr + i) << " ";
    }
    return 0;
}
