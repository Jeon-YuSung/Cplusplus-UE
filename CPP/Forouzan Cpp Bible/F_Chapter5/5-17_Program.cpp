/*
소수를 찾았을 때 return 구문을 실행하는 프로그램
어떤 숫자가 1인지 또는 복합수 인지 또는 소수인지 확인하면 곧바로 main 함수를 벗어남. 
*/

#include <iostream>
using namespace std;

int main (void){

// 변수 선언 
int n;
  
// 유효성 검사하면서 입력받기   
  do{
  cout << "양의 정수를 입력 하세요 : ";
    cin >> n;  
  }while(n <= 0);

  // 1인지 확인
  if(n==1){
cout << "1은 소수도 합성수도 아닙니다. ";
    return 0; 
  }

  // 복합수 확인
  for (int i = 2; i < n; i++){
 if(n % i == 0){
 cout << n << "은/는 합성수 입니다. " << endl;
   cout << i << "로/으로 나누어집니다. " << endl;
   return 0;
 }
  }

  //결과 출력 
  couit << n << "은/는 소수입니다. " << endl;
  return 0;
}
