/*
반복문을 중첩해서 2~10단의 곱셈 표를 출력하는 프로그램 
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main (void){

  //변수 size 선언 
  int size;

  //입력 받고 유효성 검사 
  do {
  cout << "표의 크기를 입력하세요 (2~10) : " ;
    cin >> size;
  } while(size < 2 || size > 10);

  // 중첩 반복문으로 표 출력
  for (int i = 1; i <= size; i++){
    for (int j = 1; j <= size; j++){
      cout << setw(4) << i * j;
    }
    cout << endl;
  }
  return 0;
}
