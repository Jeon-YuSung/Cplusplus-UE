//17-6. Quick sort 
// 파티션 알고리즘을 재귀적으로 호출해서 배열을 정렬하는 퀵소트 프로그램

#include <iostream>
using namespace std;

// 함수 정의 
void swap(int& x, int& y);
void print(int array[], int size);
int partition(int arr[], int beg, int end);
void quickSort(int arr[], int beg, int end);

int main(void) {
    
    int array[10] = { 27,22,11,94,83,14,30,19,46,33 };

    cout << "정렬 전 배열 : "; 
    print(array, 10);

    quickSort(array, 0, 9);

    cout << "정렬 후 배열 : ";
    print(array, 10);
    
    return 0;
}

//스왑 함수
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

//배열 출력 함수 
void print(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// 파티션 함수 
int partition(int arr[], int beg, int end) {

    int p, i, j;
    p = beg; //피벗 초기화
    i = beg; // i초기화
    j = end; // j초기화

    while (i < j) {
    
        //j를 왼쪽으로 이동
        while (arr[j] > arr[p]) {
            j--;
        }
        swap(arr[j], arr[p]);
        p = j;
        
        //i를 오른쪽으로 이동
        while (arr[i] < arr[p]) {
            i++;
        }
        swap(arr[i], arr[p]);
        p = i;
    }
    return p;
}

void quickSort(int arr[], int beg, int end) {

    if (beg >= end || beg < 0) {
        return;
    }

    int pivot;
    pivot = partition(arr, beg, end);
    quickSort(arr, beg, pivot - 1);
    quickSort(arr, pivot + 1, end);
}
