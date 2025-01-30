//평균과 편차를 구하기 

#include <iostream>
#include <iomanip>
using namespace std;

int main (void){

//변수 선언
int n1,n2,n3;
int sum;

double dev1,dev2, dev3;
double average;

//입력 
cout << "첫 번째 숫자 입력 : " ;
cin >> n1;
cout << "두 번째 숫자 입력 : " ;
cin >> n2;
cout << "셋 번째 숫자 입력 : " ;
cin >> n3;

//처리 
 sum = n1 + n2 + n3;
average = static_cast<double>(sum)/3;
dev1= n1 - average;
dev2= n2 - average;
dev3= n3 - average;

//출력 
cout << fixed << setprecision(2);
cout << "셋 수자의 합 : " << sum << endl;
cout << "평균 : " << setw(9) << average << endl;
cout << "첫 번째 숫자의 편차" << setw(9) << dev1 <<endl;
cout << "두 번째 숫자의 편차" << setw(9) << dev2 <<endl;
cout << "셋 번째 숫자의 편차" << setw(9) << dev3 <<endl;
  return 0;
}
