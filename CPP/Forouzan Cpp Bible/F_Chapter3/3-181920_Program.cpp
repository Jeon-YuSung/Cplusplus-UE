#include <iostream>
#include <limits>
using namespace std;

int main (void){

//부호 없는 정수 자료형의 오버플로우와 언더플로우 확인
  
// 부호 없는 정수의 최대값과 최소값 검색 
unsigned int n1 = numeric_limits<unsiged int>::max();
unsigned int n2 = numeric_limits<unsiged int>::min();

//최대값과 최소값 출력
cout << "최대값 : "<< n1 << endl; 
cout << "최소값 : << n2 << endl;

//강제로 오버플로우와 언더플로우 발생
n1 += 1;
n2 -= 1;

//오버플로우,언더플로우된 값 출력
  cout <<"n1+1의 값은 오버플로우가 발생 : " << n1 <<endl;
  cout << "n1-1의 값은 언더플로우가 발생 : " << n2 << endl;

//부호있는 자료형의 오버,언더플로우 확인
int n3 = numeric_limits<unsiged int>::max();
int n4 = numeric_limits<unsiged int>::min();

cout << "최대값 : "<< n3 << endl; 
cout << "최소값 : << n4 << endl;

//강제로 오버플로우와 언더플로우 발생
n3 += 1;
n4 -= 1;

//오버플로우,언더플로우된 값 출력
  cout <<"n3+1의 값은 오버플로우가 발생 : " << n3 <<endl;
  cout << "n4-1의 값은 언더플로우가 발생 : " << n4 << endl;
  
//부호있는 자료형의 오버,언더플로우 확인
double n5 = numeric_limits<unsiged int>::max();
double n6 = numeric_limits<unsiged int>::min();

cout << "double의 최대값 : "<< n5 << endl; 
cout << "더블의 최소값 : << n6 << endl;

//강제로 오버플로우와 언더플로우 발생
n5 = n5 * 1000.00;
n6 = n6 * 1000.00;

//오버플로우,언더플로우된 값 출력
  cout <<"오버플로우가 일어난 더블 n5의 값은 : " << n5 <<endl;
  cout << "언더 플로우가 일어난 더블 n6의 값은 : " << n6 << endl;
  
  return 0;
}
