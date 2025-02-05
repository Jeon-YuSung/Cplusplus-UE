// 함수를 사용해서 정기 예금의 미래 가치를 찾는 프로그램
#include <iostream>
#include <iomanip>
#include <cmath>
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

double findMultiplier(double rate, double period){
  double factor = 1 + rate/100;
  return pow(factor, term);
}

void printData(double invest, double rate, double term){
  cout << endl << "투자 정보" << endl;
  cout << "투자 금액 : " << fixed << setprecision(2) << invest << endl;
  cout << "이율 : " << rate << fixed << setprecision(2) << "% 연 마다 " < endl;
cout << "기간 : " << term << "년" << endl << endl;
}

void printResult(double multiplier, double futureValue){
cout << "투자의 승수 = " << fixed << setprecision(2) << multiplier << endl;
  cout << "미래 갗이 = " <<fixed << setprecision(2) << futureValue << endl;
  
}
