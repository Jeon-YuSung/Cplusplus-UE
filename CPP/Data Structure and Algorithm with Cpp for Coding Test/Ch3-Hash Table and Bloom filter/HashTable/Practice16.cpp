//연습문제16. STL에서 제공하는 해시 테이블. 

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//전역 함수 정의
void print(const unordered_set<int>& container);
void print(const unordered_map<int, int>& container);
void find(const unordered_set<int>& container, const int element);
void find(const unordered_map<int, int>& container, const int element);

//메인 함수 정의
int main(void){
	
	cout << "----std::unordered_set 예제-----\n";
	unordered_set<int> set1 = { 1, 2, 3, 4, 5 };

	cout << "set1 초깃값: "; print(set1);

	set1.insert(2);
	cout << "2 삽입: "; print(set1);

	set1.insert(10);
	set1.insert(300);
	cout << "10, 300 삽입: "; print(set1);

	find(set1, 4);
	find(set1, 100);

	set1.erase(2);
	cout << "2 삭제:"; print(set1);

	find(set1, 2);

	cout << "--------- std::unordered_map 예제 ----------------\n" ;
	unordered_map<int, int> squareMap;

	squareMap.insert({ 2, 4 });
	squareMap[3] = 9;
	cout << "2, 3의 제곱 삽입: "; print(squareMap);

	squareMap[20] = 400;
	squareMap[30] = 900;
	cout << "20, 30의 제곱 삽입: "; print(squareMap);

	find(squareMap, 10);
	find(squareMap, 20);
	cout << "squareMap[3] = " << squareMap[3] << endl;
	cout << "squareMap[100] = " << squareMap[100] << endl;
	print(squareMap);

	return 0;
}

//함수 구현
//print 함수는 컨테이너에 들어 있는 모드 원소를 출력
void print(const unordered_set<int>& container) {
	
	for (const auto& element : container) {
		cout << element << " ";
	}
	cout << endl;
}
void print(const unordered_map<int, int>& container) {

	for (const auto& element : container) {
		cout << element.first << " -> " << element.second << ", ";
	}
	cout << endl;

}
//검색을 효과적으로 하기 위한 find 함수 정의 
void find(const unordered_set<int>& container, const int element) {
	
	if (container.find(element) == container.end()) {
		cout << element << " 검색: 실패 \n";
	}
	else {
		cout << element << " 검색: 성공 \n";
	}
}
void find(const unordered_map<int, int>& container, const int element) {
	
	auto it = container.find(element);
	if (it == container.end()) {
		cout << element << " 검색: 실패 \n";
	}
	else {
		cout << element << " 검색: 성공, 값 = " << it->second << endl;
	}
}
