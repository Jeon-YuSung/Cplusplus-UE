#include <iostream>
using namespace std;

int main (void){
const int ca = 10;
  int num[ca];
  int size;

  do{
    cout << " 크기 입력 (1 ~ 10) : ";
    cin >> size;
  }while(size < 1 || size > ca);

  cout << size << "개의 숫자를 입력 해주세요 :";
  for (int i = 0; i < size; i++){
    cin >> num[i];
  }
  cout << "입력한 숫자들을 거꾸로 출력 합니다 : "; 
for(int i = size -1; i>=0; i--){
  cout << num[i] << " ";

}
  return 0;
}
