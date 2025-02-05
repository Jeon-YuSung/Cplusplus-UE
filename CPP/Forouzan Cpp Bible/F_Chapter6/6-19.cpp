// 함수 3개 오버로딩하기
// 서로 다른 시그니처를 갖는 함수 3개를 
// 오버로딩 하는 예를 보여주는 프로그램 

#include <iostream>
using namespace std;

int max(int n1, int n2);
int max(int n1, int n2, int n3);
int max(int n1, int n2, int n3, int n4);

int main (void){

  // 오버로딩 처리한 max 함수들을 호출 
  cout << "maxium(5,7) = " << max(5,7) << endl; 
  cout << "maxium(8,7,10) = " << max(8,7,10) << endl; 
  cout << "maxium(4,7,13,123) = " << max(4,7,13,123) << endl; 
  
  return 0;
}

// 매개변수 2개를 비교하여 더 큰 값을 리턴하는 함수 
int max(int n1, int n2){
int larger;
  if(n1>n2){
    larger = n1;
  }
  else {
 larger = n2;    
  }
  return larger; 
}

// 매개변수 3개를 정의한 함수
// 기존의 max 함수를 이용해서 n1,n2중 큰값을 찾은 이후 n3랑 비교해서 큰 값을 리턴
int max(int n1, int n2, int n3){
  return max(max(n1,n2),n3); 
}

//매개변수 3개를 정의한 max함수랑 동일한 원리
int max(int n1, int n2, int n3, int n4){
    return max(max(n1,n2,n3),n4); 
}
