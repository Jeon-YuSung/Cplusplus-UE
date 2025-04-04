#include "7-13_interface.h"

int main() {
  Time time (4,5,27);
  //원래 시간 출력 
  cout << "원래 시간 : " << time.print() << endl;

  for(int i = 0; i < 143500; i++){
    time.tick();
  } 

  cout << "143500초가 지나면 : " << time.print() << endl;
  
  return 0;
}
