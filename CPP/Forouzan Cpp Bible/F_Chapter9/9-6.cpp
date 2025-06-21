/*
9-6. 포인터로 전달을 사용해서 함수로 전달한 2개의 값을 스왑하는 프로그램
*/
 
#include<iostream>
using namespace std;

void swap(int* a, int* b) {

    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {

    int x = 10;
    int y = 20;

    cout << " 스왑하기전의 x, y의 값 : " << " x : " << x << " y : " << y << "\n";
    swap(&x, &y);

    //스왑한 결과 출력 

    cout << " 스왑 후의 x, y의 값 : " << " x : " << x << " y : " << y << "\n";
    return 0;

}
