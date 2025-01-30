#include <iostream>
using namespace std;

int main (void){
  //불자료형을 false와 true 입력 받기 

  bool flag;
  cout << "불 자료형을 true or false로 입력 : ";
  cin >> boolalpha >> flag;
  cout << flag;

  //여러 진법의 정수 입력 
  int n1, n2, n3;
  
 //10진수 입력 
  cout << 1번 숫자는 10진수로 입력 : " ;
  cin >> n1;
  //8진수 입력
  cout << 2번 숫자는 8진수로 입력 : " ;
  cin >> oct >> n2;
  //16진수 입력  
  cout << 3번 숫자는 16진수로 입력 : " ;
  cin >> hex >>n3;

 cout << n1 <<endl;
 cout << n2 << endl;
 cout << n3 << endl;
  
  return 0;
}
