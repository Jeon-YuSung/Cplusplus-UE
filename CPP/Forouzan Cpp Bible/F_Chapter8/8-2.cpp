//어떤 파일을 읽고 배열을 사용해서, 정수 목록을 읽어 들이고, 거꾸로 돌려서 다른 파일로 출력하는 프로그램.

#include <iostream>
#include <fstream>

using namespace std;

int main (void){
  const int Ca = 50;
  int num[Ca];
  int size = 0;
  ifstream inputFile;
  ofstream outputFile;

  //입력 파일 열기
  inputFile.open("inFile.dat");
  if(!inputFile){
    cout << "파일을 열 수 없습니다 \n";
    cout << "프로그램을 종료합니다 \n";
    return 0;
  }

  //입력 파일에서 배열로 숫자 읽어 들이기
  while(inputFile >> num[size] && size <= 50){
    size++;
  }

  //입력 파일 닫기
  inputFile.close();

  //출력 파일 열기
  outputFile.open("outFile.dat");
   if(!outputFile){
    cout << "파일을 열 수 없습니다 \n";
    cout << "프로그램을 종료합니다 \n";
    return 0;
  }

  //배열의 내용을 거꾸로 출력 파일에 쓰기 
  for (int i = size - 1; i >= 0; i--){
    outputFile << num[i] << " ";
  }
  //출력 파일 닫기
   outputFile.close();
  return 0;
}
