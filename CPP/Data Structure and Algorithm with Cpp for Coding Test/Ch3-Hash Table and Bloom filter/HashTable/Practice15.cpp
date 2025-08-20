//연습문제15. 뻐꾸기 해싱

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
using namespace std;

//해시 맵 클래스 정의 
class hash_map{

	// 두개의 해시 테이블 사용
	vector<int> data1;
	vector<int> data2;
	int size;

	int hash1(int key) const{
		return key % size;
	}

	int hash2(int key) const{
		return (key / size) % size;
	}

public:
	//생성자를 추가하고 해시 테이블 초기화
	//-1로 초기화 했으며, 이는 모든 테이블이 비어 있음을 나타냄.
	hash_map(int n) : size(n){
		data1 = vector<int>(size, -1);
		data2 = vector<int>(size, -1);
	}

	//룩업 함수 정의, 양쪽 해시 테이블에서 키를 검색하고, 해당 위치를 나타내는 반복자를 반환
	vector<int>::iterator lookup(int key){

		auto hash_value1 = hash1(key);
		
		if (data1[hash_value1] == key){
			std::cout << "1번 테이블에서 " << key << "을(를) 찾았습니다." << std::endl;
			return data1.begin() + hash_value1;
		}

		auto hash_value2 = hash2(key);
		if (data2[hash_value2] == key){
			cout << "2번 테이블에서 " << key << "을(를) 찾았습니다.\n";
			return data2.begin() + hash_value2;
		}

		return data2.end();
	}

	//삭제 함수 정의, 룩업 함수 호출이 담당함 
	//즉, 룩업 함수가 반환한 값을 조사하여, 실제 삭제 작업을 수행하거나 출력함
	void erase(int key){

		auto position = lookup(key);
		if (position != data2.end()){
			*position = -1;
			cout << key << "에 해당하는 원소를 삭제했습니다.\n";
		}
		else{
			cout << key << "키를 찾지 못했습니다.\n";
		}
	}

	//삽입 함수정의, 재귀적으로 동작해야 해하고, 순환 여부를 검사해야함. 
	void insert(int key){
		insert_impl(key, 0, 1);
	}

	void insert_impl(int key, int cnt, int table){

		if (cnt >= size){
			cout << key << " 삽입 시 사이클 발생, 재해싱이 필요합니다 \n";
			return;
		}

		if (table == 1){

			int hash = hash1(key);
			if (data1[hash] == -1){
				cout << table << "번 테이블에 " << key << " 삽입\n";
				data1[hash] = key;
			}
			else{
				int old = data1[hash];
				data1[hash] = key;
				cout << table << "번 테이블에 " << key << " 삽입: 기존의 " << old << " 이동 -> ";
				insert_impl(old, cnt + 1, 2);
			}
		}
		else{
			int hash = hash2(key);
			
			if (data2[hash] == -1){
				cout << table << "번 테이블에 " << key << " 삽입" << endl;
				data2[hash] = key;
			}
			else{
				int old = data2[hash];
				data2[hash] = key;
				std::cout << table << "번 테이블에 " << key << " 삽입: 기존의 " << old << " 이동 -> ";
				insert_impl(old, cnt + 1, 1);
			}
		}
	}

	//해시 테이블에 저장된 모든 데이터를 출력하는 함수 정의 
	void print(){
		
		cout << "Index: ";
		for (int i = 0; i < size; i++) {
			cout << i << '\t';
		} 
		cout << endl;

		cout << "Data1: ";
		for (auto i : data1) {
			cout << i << '\t';
		}
		cout << endl;

		cout << "Data2: ";
		for (auto i : data2) {
			cout << i << '\t';
		}
		cout << endl;
	}
};

//메인 함수 정의
int main(void){

	hash_map map(7);
	map.print();
	cout << endl;

	map.insert(10);
	map.insert(20);
	map.insert(30);
	cout << endl;

	map.insert(104);
	map.insert(2);
	map.insert(70);
	map.insert(9);
	map.insert(90);
	map.insert(2);
	map.insert(7);
	cout << endl;

	map.print();
	cout << endl;

	map.insert(14); // 사이클 발생!

	return 0;
}
