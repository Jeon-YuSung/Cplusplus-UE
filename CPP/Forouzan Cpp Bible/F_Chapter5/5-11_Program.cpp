// 한 달의 날짜 수와 첫 날의 요일을 입력 받고
// 달력 형태로 한 달을 출력하는 프로그램. 

#include <iostream>
#include <iomanip>
using namespace std;

int main (void){

  // 변수 선언 및 초기화
  int startDay;
  int daysInMonth;
  int col = 1;

  // 한 달의 날짜 유효성 검사 
  do{
    cout << "한 달의 날짜 수를 입력 하세요 (28, 29, 30, 31): ";
    cin >> daysInMonth;
  } while(daysInMonth < 28 || daysInMonth > 31);
  
  //요일 유효성 검사 
  do {
  cout << "첫 날의 요일을 입력하세요 (0~6) : ";
    cin >> startDay;
  } while(startDay < 0 || startDay > 6);
  
  //제목 출력
  cout << endl;
  cout << "Sun Mon Tue Wed Thr Fri Sat" << endl;
  cout << "--- --- --- --- --- --- ---" << endl; 

  //달력의 앞쪽에 여백 출력 
  for (int i = 0;  i < startDay; i++){
  cout << "    ";
    col++;
  }

  //달력 출력
  for (int day =1; day <= daysInMonth; day++){
cout <<setw(3) <<< day << " ";
    col++;
    if(col > 7){
      cout << endl;
      col = 1; 
    }
  }
  return 0;
}

 
