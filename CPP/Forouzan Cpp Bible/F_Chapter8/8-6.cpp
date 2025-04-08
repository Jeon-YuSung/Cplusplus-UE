//배열의 이름과 크기를 매개변수로 입력 받아서 출력하는 함수를 사용하는 프로그램

#include <iostream>
using namespace std;
//print 함수는 매개변수로 배열의 이름과 크기를 입력 받고 이를 활용해서 배열의 내용을 출력 
void print(const int num[], int size);

int main (void){

  int number[15] ={5, 7, 9, 11, 13};
  print(number, 5);
  
  return 0;
}

void print(const int num[], int size){
  for(int i = 0; i < size; i++){
    cout << num[i] << " ";
  }
  return;
}
