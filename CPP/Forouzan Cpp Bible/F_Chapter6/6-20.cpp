// 지역 스코프의 쉐도잉 
// 내부 블록과 외부 블록에 선언되어 있는 지역 변수에서 일어나는 쉐도잉을 확인하는 프로그램. 

#include <iostream>
using namespace std;

int main (void){
 int sum = 5;
  cout << sum << endl;
{
int sum = 3;
  cout << sum << endl;
} //내부 블록의 sum 사용 
   cout << sum << endl; // 외부 블록의 sum 사용
  return 0;
}
