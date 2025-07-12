//16-13. 단어 뒤에 줄 바꿈 문자를 넣는 프로그램 

#include <iostream>
#include<fstream>
#include<cassert>
using namespace std;

int main(void) {
  fstream fstr;
  fstr.open("16-13_file.txt", ios::in | ios::out);
  char ch;

  while(fstr.get(ch)){
        
    if(isspace(ch)){

        fstr.seekp(-1, ios::cur);
        fstr.put('\r');
      }
  }

  fstr.close();
	return 0;
}
