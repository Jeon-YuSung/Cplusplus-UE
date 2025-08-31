//연습문제36. 전수 조사 방식으로 부분집합의 합 문제 풀기. 
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

// 매크로 정의, 부가적인 기능으로 디버그라는 전처리 상수와 프린트라는 매크로 함수 정의 
//디버그가 0이 아닌 경우에만 stderr 출력을 수행. 
#define DEBUG 1
#if DEBUG 
#define PRINT(x) cerr << x
#else
#define PRINT(x)
#endif

using namespace std;

//함수 선언
void GetAllSubsets(vector<int> set, vector<int> subset, int index, vector<vector<vector<int>>>& allSubsets);
bool SubsetSum_BruteForce(vector<int> set, int target);

//메인 함수 정의 
int main(void) {
	vector<int> set = { 13, 79, 45, 29 };
	//타겟을 구할수 있는 정수 값
	int target = 58; 
	// 타겟을 구할 수 없는 정수값
	// int target = 100000;

	bool found = SubsetSum_BruteForce(set, target);

	if (found) {
		cout << "원소 합이 " << target << "인 부분집합이 있습니다.\n";
	}
	else {
		cout << "원소 합이 " << target << "인 부분집합이 없습니다.\n";
	}
}

//함수 구현 
// 집합의 모든 부분집합을 구하는 함수 정의 
void GetAllSubsets(vector<int> set, vector<int> subset, int index, vector<vector<vector<int>>>& allSubsets) {
	// 집합 set의 끝에 도달한 경우
	if (index == set.size()) {
		// 부분집합 크기를 인덱스로 사용하여 부분집합을 allSubsets에 추가
		allSubsets[subset.size()].push_back(subset);
		return;
	}

	// 원소를 추가하지 않고 재귀 호출
	GetAllSubsets(set, subset, index + 1, allSubsets);

	// 원소를 부분집합에 추가한 후 재귀 호출
	subset.push_back(set[index]);
	GetAllSubsets(set, subset, index + 1, allSubsets);
}
// 입력 집합을 표현하는 정수 벡터 set과 부분 집합의 합을 나타내는 정수 target을 인자로 받고, 불 값으로 반환
bool SubsetSum_BruteForce(vector<int> set, int target) {
	vector<vector<vector<int>>> allSubsets(set.size() + 1);

	GetAllSubsets(set, {}, 0, allSubsets);

	for (int size = 0; size <= set.size(); size++) {
		PRINT("부분집합의 원소 개수: " << size << endl);

		for (auto subset : allSubsets[size]) {
			PRINT("\t{ ");

			int sum = 0;
			for (auto number : subset) {
				sum += number;
				PRINT(number << " ");
			}

			PRINT("} = " << sum << endl);

			if (sum == target)
				return true;
		}
	}

	return false;
}
