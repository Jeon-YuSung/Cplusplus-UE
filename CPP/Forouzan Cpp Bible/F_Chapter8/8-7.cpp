//배열의 요소에 접근해서 값을 변경하는 함수 프로그램
#include <iostream>
using namespace std;

//함수 선언
void multiTwo(int num[], int size); //매개 변수로 받은 배열을 배정, const 한정자 붙으면 안됨. 
void print(const int num[], int size); // 출력 함수 

//메인 함수
int main (void){

  int number[5] = {150, 170, 190, 110, 130};
  print(number, 5);
  multiTwo(number, 5);
  print(number, 5);
  return 0;
}

void multiTwo(int num[], int size){
    for(int i = 0; i < size; i++){
      num[i] *= 2;
    }
  return;
}

void print(const int num[], int size){
 for(int i = 0; i < size; i++){
    cout << num[i] << " ";
  }
  cout << endl;
  return;
}
