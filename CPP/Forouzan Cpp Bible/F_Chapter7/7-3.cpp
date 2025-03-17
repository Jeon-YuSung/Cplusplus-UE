#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class randomInteger{

private:
//데이터 멤버 선언 
  int low;
  int high;
  int value;

public:
  randomInteger(int low, int high);
~ randomInteger();
// 합성 복사 생성자의 생성 막기 
 randomInteger(const  randomInteger &random) = delete; //복사 생성자를 선언하고, delete키워드를 할당하면 복사 생성자를 만들지 않는다. 
  void print() const;
};

//생성자   
randomInteger::randomInteger(int low, int high)

{
  srand(time(0));
  int temp = rand();
  value = temp % (high - low + 1) + low;
}
// 소멸자 
randomInteger::~randomInteger(){}

// 접근자 멤버 함수 
void randomInteger::print() const{
  cout << value << endl; 
}

int main (void){
  // 100 ~ 200 사이의 랜덤한 숫자 생성 
    randomInteger r1(100, 200);
  cout << "100 ~ 200 사이의 랜덤한 숫자 : " ;
  r1.print();
  // 500 ~ 700 사이의 랜덤한 숫자 생성 
    randomInteger r2(500, 700);
  cout << "500 ~ 700 사이의 랜덤한 숫자 : " ;
  r2.print();
  //1400~2000 사이의 랜덤한 숫자 생성 
      randomInteger r3(1400, 2000);
  cout << "1400 ~ 2000 사이의 랜덤한 숫자 : " ;
  r3.print();
  
  return 0;
}
