//연습문제38. 메모이제이션으로 부분집합 문제 풀기. 
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <time.h>
#include <iomanip>

// 매크로 정의, 부가적인 기능으로 디버그라는 전처리 상수와 프린트라는 매크로 함수 정의 
//디버그가 0이 아닌 경우에만 stderr 출력을 수행. 
#define DEBUG 0
#if DEBUG 
#define PRINT(x) cerr << x
#else
#define PRINT(x)
#endif

using namespace std;

//또는 -1로 설정 가능 
const int UNKNOWN = INT_MAX; 

//문자열 배열 정의, 화면출력 용도로 사용 
vector<string> types =
{
	"BRUTE FORCE",
	"BACKTRACKING",
	"MEMOIZATION",
	"TABULATION"
};

//함수 선언
void GetAllSubsets(vector<int> set, vector<int> subset, int index, vector<vector<vector<int>>>& allSubsets);
bool SubsetSum_BruteForce(vector<int> set, int target);
bool SubsetSum_Backtracking(vector<int> set, int sum, int i);
void GetTime(clock_t& timer, string type);
bool SubsetSum_Memoization(vector<int>& set, int sum, int i, vector<vector<int>>& memo);

//메인 함수 정의 
int main(void) {
	vector<int> set = { 16, 1058, 22, 13, 46, 55, 3, 92, 47, 7,
					   98, 367, 807, 106, 333, 85, 577, 9, 3059 };
	int target = 6799;
	int tests = 3;

	sort(set.begin(), set.end());

	for (int i = 0; i < tests; i++)
	{
		bool found = false;

		clock_t timer = clock();

		switch (i)
		{
		case 0:
			found = SubsetSum_BruteForce(set, target);
			break;
		case 1:
			found = SubsetSum_Backtracking(set, target, 0);
			break;
		case 2:
		{
			// 메모이제이션 테이블 초기화
			vector<vector<int>> memo(set.size(), vector<int>(7000, UNKNOWN));

			found = SubsetSum_Memoization(set, target, 0, memo);
			break;
		}
		}

		if (found)
		{
			cout << "원소 합이 " << target << "인 부분집합이 있습니다." << endl;
		}
		else
		{
			cout << "원소 합이 " << target << "인 부분집합이 없습니다." << endl;
		}

		GetTime(timer, types[i]);
		cout << endl;
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

// 뺵트레킹 함수 정의
bool SubsetSum_Backtracking(vector<int> set, int sum, int i) {
	// 만약 현재 부분집합의 합이 target과 같다면
	if (sum == 0){
		return true;
	}

	// 만약 현재 부분집합의 합이 target보다 크거나, 집합의 끝에 도달했다면
	if (i == set.size() || set[i] > sum){
		return false;
	}

	// Case 1: sum에서 set[i]을 빼서 재귀 호출 (i번째 원소를 부분집합에 추가)
	// Case 2: sum을 그대로 전달하여 재귀 호출 (i번째 원소를 부분집합에 추가하지 않음)

	return SubsetSum_Backtracking(set, sum - set[i], i + 1) || SubsetSum_Backtracking(set, sum, i + 1);
}

//경과 시간을 출력하는 함수 정의 
void GetTime(clock_t& timer, string type) {
	// 현재 시간에서 timer를 빼서 경과 시간을 계산
	timer = clock() - timer;

	// 화면에 경과 시간 출력
	cout << type << " 방법 경과 시간: ";
	cout << fixed << setprecision(5) << (float)timer / CLOCKS_PER_SEC << endl;

	timer = clock(); // timer를 현재 시간으로 초기화
}

//백트레킹 함수의 아규먼트 구성과 거의 같지만, 메모라는 이름의 2차원 정수 벡터의 참조를 추가로 가짐
bool SubsetSum_Memoization(vector<int>& set, int sum, int i,vector<vector<int>>& memo) {
	// 만약 현재 부분집합의 합이 target과 같다면
	if (sum == 0)
	{
		return true;
	}

	// 만약 현재 부분집합의 합이 target보다 크거나, 집합의 끝에 도달했다면
	if (i == set.size() || set[i] > sum)
	{
		return false;
	}

	// 현재 상태가 캐시에 있는지 확인
	if (memo[i][sum] == UNKNOWN)
	{
		// 현재 상태에 대한 솔루션을 구하여 캐시에 저장
		bool append = SubsetSum_Memoization(set, sum - set[i], i + 1, memo);
		bool ignore = SubsetSum_Memoization(set, sum, i + 1, memo);

		memo[i][sum] = append || ignore;
	}

	// 캐시에 저장된 값을 반환
	return memo[i][sum];
}
