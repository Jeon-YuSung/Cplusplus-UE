//연습문제13. 정수 값을 저장하는 간단한 사전 구현해보기. 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//해시 맵 클래스 정의 
class hash_map{
	vector<int> data;

public:
	//해시맵 생성자에서 벡터의 모든 원소를 -1로 초기화 
	// -1은 해당 위치에 저장된 원소가 없음을 나타냄. 
	hash_map(size_t n){
		data = vector<int>(n, -1);
	}
	//삽입 함수 정의
	//해시 값 위치에 다른 값이 존재하는지 확인 안함, 즉, 이미 값이 존재해도 그위에 덮어씀
	void insert(unsigned int value){
		int n = data.size();
		data[value % n] = value;
		cout << value << "을(를) 삽입했습니다.\n";
	}
	//특정원소가 맵에 있는지 확인하는 룩업 함수 정의 
	bool find(unsigned int value){
		int n = data.size();
		return (data[value % n] == value);
	}
	//삭제 함수 구현
	void erase(unsigned int value){
		int n = data.size();
		if (data[value % n] == value){
			data[value % n] = -1;
			cout << value << "을(를) 삭제했습니다.\n";
		}
	}
};

//메인 함수 정의
int main(void){

	hash_map map(7);

	auto print = [&](int value) {
		if (map.find(value)) {
			cout << "해시 맵에서 " << value << "을(를) 찾았습니다.";
		}
		else {
			cout << "해시 맵에서 " << value << "을(를) 찾지 못했습니다.";
		}
			cout << endl;
		};

	map.insert(2);
	map.insert(25);
	map.insert(10);
	print(25);

	map.insert(100);
	print(100);
	print(2);

	map.erase(25);
	return 0;
}
