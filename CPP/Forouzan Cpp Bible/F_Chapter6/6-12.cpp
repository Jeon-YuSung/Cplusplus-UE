// 함수를 사용하여 윤년을 확인하는 프로그램 
#include <iostream>
using namespace std;

//함수 선언;
int input();
bool process(int year);
void output(int year, bool result);

// 메인 함수 
int main (void){

  // input, processing, output
  int year = input();
  bool result = process(year);
  output(year, result);
  return 0;
}

// input 함수 정의 
int input(){
  int year;
  do{
    cout << " 1582년 이후의 연도를 입력하세요 : ";
    cin >> year; 
  }while(year<= 1582);
  return year;
}

// process함수 정의 
bool process(int year) {

  bool cr1, cr2;
  cr1 = (year % 4 == 0);
  cr2 = (year % 100 != 0) || (year % 400 == 0);
  return (cr1) && (cr2);
}
// output 함수 정의 
void output(int year, bool result){

  if (result){
    cout << year << "년은 윤년입니다. " << endl; 
  } else {
cout << year << "년은 윤년이 아닙니다. " << endl;
  }
  return; 
}
 
