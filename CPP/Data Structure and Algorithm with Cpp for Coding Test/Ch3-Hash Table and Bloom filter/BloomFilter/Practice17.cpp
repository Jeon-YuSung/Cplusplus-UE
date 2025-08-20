//연습문제17. 블룸필터 만들기

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//블룸 필터 구현 클래스 정의 
class bloomFilter{
	
	vector<bool> data;
	int nBits;

	//해시 함수를 단순하게 구현
	// num은 내부에서 어떤 해시 함수를 사용할지 결정하는 역할을 함. 
	int hash(int num, int key){
		switch (num){
		case 0: return key % nBits;
		case 1: return (key / 7) % nBits;
		case 2: return (key / 11) % nBits;
		}

		return 0;
	}

public:
	//블룸 필터 생성자 정의
	bloomFilter(int n) : nBits(n){
		data = vector<bool>(nBits, false);
	}

	//룩업 함수 정의, 모든 비트가 1로 설정되어있는지 검사
	void lookup(int key){

		bool result = data[hash(0, key)] && data[hash(1, key)] && data[hash(2, key)];

		if (result){
			cout << key << ": 있을 수 있음 \n";
		}
		else{
			cout << key << ": 절대 없음 (거짓-부정 보장) \n";
		}
	}

	//삽입 함수 구현
	void insert(int key)
	{
		data[hash(0, key)] = true;
		data[hash(1, key)] = true;
		data[hash(2, key)] = true;
		cout << key << "을(를) 삽입: ";

		for (auto a : data) {
			std::cout << a << " ";
		}
		cout << endl;
	}
};

//메인 함수 정의
int main(void){
	
	bloomFilter bf(7);
	bf.insert(100);
	bf.insert(54);
	bf.insert(82);

	bf.lookup(5);
	bf.lookup(50);
	bf.lookup(20);
	bf.lookup(54);

	return 0;
}

