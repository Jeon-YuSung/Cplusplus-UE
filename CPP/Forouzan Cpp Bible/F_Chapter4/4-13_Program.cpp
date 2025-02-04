// 학점을 기반으로 PASS/ Non-pass 출력하기 

#include <iostream>
using namespace std;

int main (void){

  char grade;

  cout << "학점을 입력하세요 : ";
  cin >> grade;

  switch(grade){
    
    case 'A' : 
  case 'B' : 
  case 'C' : 
      cout << " pass 입니다 " << endl;
  case 'D' : 
  case 'F' : 
      cout << "non-pass (fail) 입니다 " << endl;
  default :
    cout << "입력 오류, 시도 하세요 " << endl;
  }

  return 0;
}
