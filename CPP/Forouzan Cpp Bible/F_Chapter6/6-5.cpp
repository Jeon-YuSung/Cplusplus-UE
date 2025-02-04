// 알파벳의 개수를 세고 소문자를 모두 대문자로 변환하는 프로그램. 

#include <iostream>
#include <cctype>
using namespace std;

int main (void){

  //변수 선언
  char ch;
  int count;
  count = 0;

  //글자를 입력 받고 처리 
  while (cin >> noskipws >> ch){
 if(isalpha(ch)){
   count++;
 }
    ch = toupper(ch);
    cout << ch; 
  }

  //글자 갯수 출력 
  cout << "알파벳의 문자의 갯수 : " << count << endl;
  return 0;
}
