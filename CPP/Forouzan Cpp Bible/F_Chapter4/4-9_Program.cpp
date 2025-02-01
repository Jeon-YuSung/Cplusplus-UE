// 윤년 확인하기 
#include <iostream>
using namespace std;

int main (void){

  int year;
  bool divBy400, divBy40, divBy100;
  bool leapYear;

  //입력
  cout << "연도를 입력하세요 : " ;
  cin >> year;

  //조건 설정
  divBy400 = ((year%400) == 0);
  divBy4 = ((year%4) == 0);
  divBy410 = ((year%100) == 0);
  leapYear = (divBy400)||(divBy4 && !(divBy100));

  //윤년인지 아닌지 출력
  if(leapYear)
  {
cout << year << "년은 윤년입니다. " << endl; 
  }
  else{

    cout << year << "년은 윤년이 아닙니다. \n";
  }
  return 0;
}
