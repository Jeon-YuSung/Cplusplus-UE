// 은행 계좌 클래스를 선언, 정의,, 사용하는 프로그램. 
#include <iostream>
#include <cassert>
using namespace std;

//클래스 정의 (멤버 선언)
class Account{

  private:
 long accNumber;
  double balance;
  static int base;
public:
  Account(double bal); //생성자 
  ~Account(); //소멸자
void checkBalance() const; //접근자
void deposit(double amount); //설정자
void withdraw(double amount);//설정자 
};

// 정적 데이터 멤버 초기화 
int Account::base = 0;

// 모든 멤버 함수 정의
 Account::Account(double bal)
:balance(bal){

  if(bal < 0.0){
cout << "잔액은 음수가 될 수 없습니다. 프로그램 종료" << endl;
    assert(false);
  }
  base++;
  accNumber = 10000 +base;
  cout << "계좌_#" << accNumber <<"이 만들어졌습니다." <<endl;
  cout << "잔액_$" << balance << endl << endl; 
}

// 소멸자
 Account::~Account()
{
  cout << "계좌_#" << accNumber <<"가 닫혔습니다." <<endl;
  cout << "잔액_$" << balance << "를 고객에게 보냈습니다" << endl; 
}

//접근자
void Account::checkBalance() const
{
  cout << "계좌_#" << accNumber <<endl;
  cout << "트랙잭션 - 잔액 확인" << endl;
  cout << "잔액 : $" << balance << endl << endl; 
  
}

//설정자 
void  Account::deposit(double amount)
{
if (amount > 0.0)
{
  balance += amount;
}
  else {
    cout <<"트랙잭션이 중단되었습니다" <<endl;
  }
}

//설정자
void  Account::withdraw(double amount)
{
  if(amount > balance)
  {
    amount = balance;
  }
  balance -= amount;
  cout << "계좌_#" << accNumber <<endl;
  cout << "트랙잭션 - 인출 : $" << amount << endl;
  cout << "변경된 잔액 : $" << balance << endl << endl; 
}

//메인 함수
int main (void){
//계좌 생성
  Account acc1(2000);
   Account acc2(7000);
   Account acc3(4000);

  //트랙잭션 
  acc1.deposit(150);
  acc2.checkBalance();
  acc1.checkBalance();
  acc3.withdraw(800);
  acc1.withdraw(1000);
  acc2.deposit(120);
  return 0;
}
