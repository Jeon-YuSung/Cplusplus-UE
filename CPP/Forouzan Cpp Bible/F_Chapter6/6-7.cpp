// 숫자 추측 게임 

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main (void){

  // 변수 선언 및 초기화 
  int low, high, tryLimit; guess;
  
  low = 5;
  high = 15;
  tryLimit = 5;

  //랜덤 숫자 생성
  srand(time(0));
  int temp = rand();
  int n = temp % (high - low + 1) + low;

  //추측을 위한 반복 
  int counter = 1;
  bool found = false;
  while(counter <= tryLimit && !found){

    do{
      cout << " 5 ~ 15 사이의 정수를 입력하세요 : "; 
      cin >> guess;
    }while(guess < 5 || guess > 15);

    if(guess == n)
    {
      found = true;
    }else if (guess > n){
      cout << "더 작은 숫자 입니다. " << endl;
    } else {  
      cout << "더 큰 숫자 입니다. " << endl; 
    }
    counter++;
  }
  //추측에 성공한 경우
  if(found){

    cout << "정답입니다, 추측에 성공하였습니다. ";
    cout << "답은 = " << n << endl;
  } else {
    cout << "오답입니다, 추측에 실패하였습니다  ";
    cout << "답은 = " << n << endl;
  }
  
  return 0;
}
