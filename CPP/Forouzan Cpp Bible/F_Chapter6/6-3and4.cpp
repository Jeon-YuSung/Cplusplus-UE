// 삼각 함수를 사용하는 법과 정다각형의 둘레와 넓이를 구하는 프로그램. 
/*
정다각형의 둘레 : n * s
넓이 : (n * s^2) / (4 * tan(PI/n))
*/

#include <iostream>
#include <cmath>
using namespace std;

int main (void){

  //변수 선언
  // 파이와 45도를 라디안 단위로 선언 
  const double PI =  3.141592653589793238462;
  double degree = PI / 4; 
  int n ; 
  double s, peri, area;

  // 45도의 sin, cos, tan의 값 구하기 
  cout <<< "사인 45도의 값은 : " << sin(degree) << endl;
  cout <<< "코사인 45도의 값은 : " << cos(degree) << endl;
  cout <<< "탄젠트 45도의 값은 : " << tan(degree) << endl;

  // 정다각형의 둘레와 넓이 구하기 
  // 변의 개수 입력 받기 
  do {
    cout << " 변의 개수를 입력하세요 (4 이상의 정수) : ";
    cin >> n;
  } while(n < 4);
  
  // 변의 길이 입력 받기 
  do {
    cout << "변의 길이를 입력하세요 : " ;
    cin >> s; 
  } while(s <= 0.0);
 
  //둘레와 넓이 구하기
  peri = n * s;
  area = (n * pow(s,2)) / (n * tan (PI/n));

  // 결과 출력하기 
  cout << " 둘레 : " << peri << "넓이 : " << area <<endl; 
  return 0;
}
