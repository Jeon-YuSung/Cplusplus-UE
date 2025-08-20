//연습문제14. 체이닝을 사용하는 해시 테이블

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
using namespace std;

//해시 맵 클래스 정의 
class hash_map{
	vector<list<int>> data;

public:
	// 생성자 정의, 해시 맵 또는 데이터 크기를 Argument로 받음
	hash_map(size_t n){
		data.resize(n);
	}

	//삽입 함수 정의
	//value값을 항상 해시 맵에 추가
	void insert(unsigned int value){
		int n = data.size();
		data[value % n].push_back(value);
		cout << value << "를 삽입했습니다.\n";
	}

	//특정원소가 맵에 있는지 확인하는 룩업 함수 정의 
	// 단순히 n값에 영향을 받는 것이 아니라 입력 데이터에 대해서도 영향을 받음. 
	bool find(unsigned int value){
		int n = data.size();
		auto& entries = data[value % n];
		return std::find(entries.begin(), entries.end(), value) != entries.end();
	}

	//삭제 함수 구현
	void erase(unsigned int value) {
		int n = data.size();
		auto& entries = data[value % n];
		auto iter = std::find(entries.begin(), entries.end(), value);

		if (iter != entries.end()){
			entries.erase(iter);
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

	map.insert(100);
	map.insert(55);

	print(100);
	print(2);
	print(3);

	map.erase(2);
	return 0;
}
