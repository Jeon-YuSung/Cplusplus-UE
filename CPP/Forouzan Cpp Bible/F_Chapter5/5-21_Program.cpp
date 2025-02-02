// 정수 리스트의 크기를 미리 알고 있을 때, 리스트의 내부의 최소 값과 최대 값을 구하는 프로그램 

#include <iostream>
#include <limits>
using namespace std;

int main (void){

  //변수 선언
  int size, n, smallest, largest; 
  
  // 초기화 
  smallest = numberic_limits<int>::max();
  largest = numberic_limits<int>::min();

  //입력 받기 
  do {
    cout << " 음수가 아닌 수로 리스트의 크기를 입력하세요 : " ;
    cin >> size; 
  }while(size <= 0);

  for(int i = 1; i <= size; i++){
  cout << " 다음 숫자를 입력하세요 : "; 
  cin >> n; 
    if(n < smallest){
      smallest = n;
    }
    if(n > largest){
      largest = n;
    }
  }

  // 출력
  cout << "최소 값 = " << smallest << " 최대 값 = " << largest << endl; 
  return 0;
}
