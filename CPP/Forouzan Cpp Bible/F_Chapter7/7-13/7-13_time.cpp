#include <cmath>
#include <cassert>
#include "7-13_interface.h"

Time::Time(int hr, int mi, int se)
:hours(hr), minutes(mi), seconds(se){
  normalize();
}

Time::Time()
   :hours(0), minutes(0), seconds(0){}

Time::~Time(){}
    
void Time::print() const{
  coutg << hours << "시" << minutes << "분" << seconds << endl;
}

void Time::tick()
{
  seconds++;
  normalize();
}

void Time::normalize(){
//음수처리
  if((hours < 0) || (minutes < 0) || (seconds < 0)){
    cout << "유효하지 않은 숫자 입니다. 프로그램을 종료합니다." << endl;
    assert(false);
  }
  //범위 조정
  if (seconds > 59){
    int temp = seconds / 60;
    seconds = seconds % 60;
    minutes = minutes + temp;
  }
  if (minutes > 59){
    int temp = minutes / 60;
    minutes = minutes % 60;
    hours = hours + temp;
  }
  if(hours > 23){
    hours = hours % 24;
  }
}
