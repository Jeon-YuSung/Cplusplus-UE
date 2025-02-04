//현재 시간 찾는 프로그램
#include <iostream>
#include <ctime>
using namespace std;

int main (void){

  //경과한 초 단위 시간과 현재 초를 찾기 
  long elapsedSeconds = time(0);
  int currentSeconds =  elapsedSeconds % 60; 
  
    //경과한 분 단위 시간과 현재 분을 찾기 
  long elapsedMinutes = elapsedSeconds / 60;
  int currentMinutes =  elapsedMinutes % 60; 
  
    //경과한 시간 단위 시간과 현재 시간을 찾기 
  long elapsedHours = elapsedHours / 60;
  int currentHours =  elapsedHours % 24; 

  //현재 시간을 출력
  cout << " 현재 시간 =" << currentHours << "시" << currentMinutes << "분" << currentSeconds << endl;
  return 0;
}
