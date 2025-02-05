// 함수를 사용해서 정기 예금의 미래 가치를 찾는 프로그램2
// 6-25은 목돈을 한 번에 넣고, 만기 때에는 원금과 이자를 받는 정기 예금을 살펴봤음
//  6-26는 매 주기 특정일에 금액을 계속 넣고, 만기 때에 원금과 이자를 받는 정기 적금 예금 프로그램임. 

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//함수 선언 
void input(double &invest, double &rate, double &term);
void process(doube invest, double rate, double term, double &multiplier, double &futureValue);
void output(double invest, double rate, double term, double multiplier, double futureValue);
double getInput(string message);
double findMultiplier(double rate, double period);
void printData(double invest, double rate, double term);
void printResult(double multiplier, double futureValue);

//메인 함수 
int main (void){

  double invest, rate, term; // 입력 변수
  double multiplier, futureValue; // 출력 변수 

  input(invest, rate, term); 
  process(invest, rate, term, multiplier, futureValue);
  output(invest, rate, term, multiplier, futureValue);
  
  return 0;
}

// input 함수는 getInput 함수를 호출해서 3개의 입력을 받음. 
// call by reference로 값을 main에 전달
// 함수가 종료되면 입력들이 invest, rate ,term에 저장됨 
void input(double &invest, double &rate, double &term){
   invest = getInput("투자 금액 입력 : ");
  rate = getInput("1년 마다의 이율을 입력 : ");
  term = getInput("기간 선정 : ");
}

// process함수는 findMultiplier함수를 사용해서 승수를 계산하고 미래 가치를 계싼함
// call by reference로 받은 변수들로 값을 리턴 
void process(doube invest, double rate, double term, double &multiplier, double &futureValue){
  multiplier  = findMultiplier(rate, term);
  futureValue = multiplier * invest; 
}

// output 함수는 사용자로 부터 입력 받는 함수 
// parameter로 사용자에게 어떤 자료를 입력해달라고 요구할지, 메시지를 문자열 자료형의 객체로 전달 받고 입력이 양수인지를 확인 
// 최종적으로 입력받은 값을 input 함수로 리턴 
void output(double invest, double rate, double term, double multiplier, double futureValue){
printData(invest, rate, term);
printResult(multiplier, futureValue);  
}

double getInput(string message){
  doulbe input;
  do{
cout << message;
    cin >> input; 
  } while(input<0.0);
  return input;
}

// 이번에는 복리 적금 공식을 활용해서 승수를 계산 
// 최종적으로 처리한 값을 process함수로 리턴 
double findMultiplier(double rate, double term){
  double multiplier = 0; 
  double factor = 1 + rate/100;
  for (int i = term; i > 0; i--){
    
multiplier = multiplier + pow(factor, i);
  
  }
  
  return multiplier;
}

void printData(double invest, double rate, double term){
  cout << endl << "정기 적금 정보" << endl;
  cout << "정기 적금 투자 금액 : " << fixed << setprecision(2) << invest << endl;
  cout << "이율 : " << rate << fixed << setprecision(2) << "% 연 마다 " < endl;
cout << "기간 : " << term << "년" << endl << endl;
}

void printResult(double multiplier, double futureValue){
  cout << "투자 결과" << endl; 
cout << "투자의 승수 = " << fixed << setprecision(2) << multiplier << endl;
  cout << "미래 가치 = " <<fixed << setprecision(2) << futureValue << endl;
  
}
