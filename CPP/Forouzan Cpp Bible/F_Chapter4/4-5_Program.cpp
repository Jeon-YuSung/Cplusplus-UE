#include <iostream>
using namespace std;

int main (void){

  int n1;
  int n2;

  //입력
  cout << " n1 숫자 입력 : " ;
  cin >> n1;
  cout << "n2 숫자 입력 : " ;
  cin >> n2;

  if(n1>=n2){

if(n1>n2){
cout << n1 << ">" << n2 << endl;
}
else{
  cout << n1 << " == " << n2 << endl; 
}
  }
  else{
cout << n1 << " < " << n2 << endl;
  }
  return 0;
}
