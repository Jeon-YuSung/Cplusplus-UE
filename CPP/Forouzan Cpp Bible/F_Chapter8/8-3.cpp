//어떤 달의 날짜 수를 배열을 사용해서 출력하는 프로그램 
#include <iostream>
using namespace std;

int main (void){
  int numOfDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
  int month;

    do{
      cout << "월을 입력 해주세요 : (1~12) "; 
      cin >> month;
    }
      while(month < 1 || month > 12);
  
  //출력 
  cout << "해 당 월에는 " << numOfDays[month] << "개의 일이 있습니다\n";
  
  return 0;
}
