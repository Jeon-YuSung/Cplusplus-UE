//연습문제24. 최단 작업 우선 스케줄링 SJF 구현해보기 
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

//전역 함수 정의 
template<typename T>
auto compute_waiting_times(vector<T>& service_times);
template<typename T>
void print_vector(vector<T>& V);
template<typename T>
void compute_and_print_waiting_times(vector<T>& service_times);

//메인 함수 정의
int main(void){
	vector<int> service_times{ 8, 1, 2, 4, 9, 2, 3, 5 };

	cout << "[처음 일 처리 시간 & 대기 시간]\n";

	compute_and_print_waiting_times<int>(service_times);

	// 일 처리 시간을 오름차순으로 정렬
	sort(service_times.begin(), service_times.end());
	cout << endl;
	
	cout << "[정렬 후 일 처리 시간 & 대기 시간] \n";
	compute_and_print_waiting_times<int>(service_times);

	return 0;
}

//선언한 함수를 구현하기
//평균 대기시간 계산 및 출력 함수 구현
template<typename T>
auto compute_waiting_times(vector<T>& service_times) {
	vector<T> W(service_times.size());
	W[0] = 0;

	for (auto i = 1; i < service_times.size(); i++)
		W[i] = W[i - 1] + service_times[i - 1];

	return W;
}

template<typename T>
void print_vector(vector<T>& V) {
	for (auto& i : V) {
		cout.width(2);
		cout << i << " ";
	}
	cout << endl;
}
template<typename T>
void compute_and_print_waiting_times(vector<T>& service_times) {
	auto waiting_times = compute_waiting_times<int>(service_times);

	cout << "- 처리 시간: ";
	print_vector<T>(service_times);

	cout << "- 대기 시간: ";
	print_vector<T>(waiting_times);

	auto ave_waiting_times = accumulate(waiting_times.begin(), waiting_times.end(), 0.0) / waiting_times.size();
	cout << "- 평균 대기 시간: " << ave_waiting_times;
	
	cout << endl;
}
