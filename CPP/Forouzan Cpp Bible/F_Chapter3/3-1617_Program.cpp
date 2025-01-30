#include <iostream>
using namespace std;

int main (void){
//우선 순위와 결합 방향을 모두 고려한 경우의 평가 순서
  cout << "표현식의 값 << 5-30 / 4 * 8 + 10;

//같은 우선 순위를 갖는 표현식들 
//오른쪾애서 왼쪽으로 결합 방향을 갖는 표현식

  int x = 10;
  int y = 20;

  y += x *= 40;

  cout << "x의 값 " << x << endl;
  cout << "y의 값 << y << endl;
    
  return 0;
}
