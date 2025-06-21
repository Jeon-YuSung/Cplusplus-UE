/*
9-14. 힙 메모리에 크기가 유동적인 배열 만들기
*/
 
#include<iostream>
using namespace std;

int main(void) {

    // 스택 배열에 대한 크기와 포인터 선언 
    int size;
    int* pArr;

    // 0보다 큰 배열의 크기 입력 받기 do-while문 사용
    do {
        cout << " 0보다 큰 배열의 크기를 입력하세여 : ";
        cin >> size; 
    } while (size <= 0);

    //힙에 배열 생성
    pArr = new int[size];
    //배열에 값 입력 받기
    for (int i = 0; i < size; i++) {
        cout << i << "번째 요소의 값을 입력하세요 : ";
        cin >> *(pArr + i);
    }
    //배열 요소 출력
    cout << "배열 요소 출력하기 : "; 
    for (int i = 0; i < size; i++) {
        cout << *(pArr + i) << "  ";
    }

    //힙에서 배열 제거
    delete[] pArr;

    return 0;
}
