//총합, 평균, 최소값, 최대값 찾기

#include <iostream>
#include <fstream>
using namespace std;

int main (void){
ifstream input;

  const int ca = 50;
  int num[ca];
  int size = 0; 
  int sum, small, large;
  double average;
  
  sum = 0;
  small = 1000000;
  large = -1000000;

  //유효성 검사하면서 파일 열기
  input.open("numFile.dat");
  if(!input){
    cout << " 입력 파일을 여는 동안 문제가 발생했습니다 \n";
    cout << "프로그램을 종료합니다 \n";
    return 0;
  }
//파일에서 숫자 읽어 들이기.
  while(input >> num[size]){
      size++;
    }
//입력 파일 닫기
  input.close();

  //합계, 평균, 최소값, 최대값 찾기 
  for (int i = 0; i < size; i++){
    sum += num[i];
    if(num[i] < small)
    {
      small = num[i];
    }
    if(num[i] > large){
      large = num[i];
    }
  }
  average = static_cast<double>(sum) / size;
  //결과 출력
  cout << " 목록에 숫자가 " << size << "개 있습니다 \n";
  cout << "합계 : " << sum << "\n";
  cout << "평균 : " << average << "\n";
  cout << "최소값 : " << small << "\n";
  cout << "최대값 : " << large << "\n";
  
  return 0;
}
