// eof와 플래그를 사용해서 반복문 종료하기
// 100 200 300 400 500이라는 숫자가있는 numbers.dat 파일이 있다고 가정. 

#include <iostream>
#include <fstream>
using namespace std;

int main (void){

  ifstream infile;
  int n;
  bool flag;

  infile.open("numbers.dat");
flag = false;
  
  while(infile >> n && !flag){
 if(n >= 150){
  cout << " 찾는 숫자는 " << n; 
   flage = true;
 }
  }
  
  //플래그 확인 
  if(!flag){
    cout << " 찾는 숫자가 파일에 존재하지 않습니다 " ;
    
  }
  infile.close();
  return 0;
}

 
