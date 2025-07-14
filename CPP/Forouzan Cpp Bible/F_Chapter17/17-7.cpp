//17-7. 재귀를 이용한 이진 탐색
// 재귀적 이진 탐색으로 배열에서 특정 값을 찾는 프로그램 

#include <iostream>
using namespace std;

// 이진탐색 함수 선언 - 비재귀, 재귀 
int binarySearch(const int arr[], int size, int value);
int binarySearch(const int arr[], int low,int high, int value);

//탐색 대상 배열 선언 
const int SIZE = 10;
//array 변수이름이  using namespace std; 때문에 표준 라이브러리의 std::array 템플릿과 충돌해서 발생함
int dataArr[SIZE] = { 6,14,22,27,35,49,65,72,88,92 };

int main(void) {
    
    int value;
    cout << "찾을 값을 입력하세요 : ";
    cin >> value;

    //비재귀 이진 탐색 호출
    int index;
    index = binarySearch(dataArr, SIZE, value);
    
    if (index == -1) {
        cout << "배열에서 값을 찾을수 없습니다. \n";
    }
    else {
        cout << " 해당 값을 찾았습니다 : " << index << endl;
    }

    
    return 0;
}

// 비재귀 이진탐색 함수 정의
int binarySearch(const int arr[], int size, int value) {
    int low = 0;
    int high = size - 1;
    return binarySearch(arr, low, high, value);
}

// 재귀적 이진 탐색 함수 정의
int binarySearch(const int arr[], int low, int high, int value) {

    int mid;
    mid = (low + high) / 2;
    if (low > high) {
        return -1;
    }
    else if (value == arr[mid]) {
        return mid;

    }
    else if (value < arr[mid]) {
        return binarySearch(arr, low, mid - 1, value);
    }
    else {
        return binarySearch(arr, mid + 1, high, value);
    }
}
