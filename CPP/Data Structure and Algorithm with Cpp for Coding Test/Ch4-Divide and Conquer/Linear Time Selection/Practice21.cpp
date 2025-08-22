//연습문제21 선형 시간 선택. 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//전역 함수 정의 
template <typename T>
vector<T> merge(vector<T>& arr1, vector<T>& arr2);
template <typename T>
vector<T> merge_sort(vector<T> arr);
template <typename T>
auto partition(typename vector<T>::iterator begin, typename vector<T>::iterator end);
template <typename T>
void quick_sort(typename vector<T>::iterator begin, typename vector<T>::iterator last);
template<typename T>
auto find_median(typename vector<T>::iterator begin,typename vector<T>::iterator last);
template <typename T>
auto partition_using_given_pivot(typename vector<T>::iterator begin, typename vector<T>::iterator end, typename vector<T>::iterator pivot);
template<typename T>
typename vector<T>::iterator linear_time_select(typename vector<T>::iterator begin,typename vector<T>::iterator last,size_t i);
template <typename T>
void print_vector(vector<T> arr);
void run_linear_select_test();

//메인 함수 정의
int main(void){
	run_linear_select_test();
	
	return 0;
}

template <typename T>
vector<T> merge(vector<T>& arr1, vector<T>& arr2) {
	vector<T> merged;

	auto iter1 = arr1.begin();
	auto iter2 = arr2.begin();

	while (iter1 != arr1.end() && iter2 != arr2.end()){
		if (*iter1 < *iter2){
			merged.emplace_back(*iter1);
			iter1++;
		}
		else{
			merged.emplace_back(*iter2);
			iter2++;
		}
	}

	if (iter1 != arr1.end()) {
		for (; iter1 != arr1.end(); iter1++) {
		merged.emplace_back(*iter1);
		}
	}
	else{
		for (; iter2 != arr2.end(); iter2++) {
			merged.emplace_back(*iter2);
		}
	}

	return merged;
}


template <typename T>
vector<T> merge_sort(vector<T> arr) {
	if (arr.size() > 1){
		auto mid = size_t(arr.size() / 2);
		auto left_half = merge_sort(vector<T>(arr.begin(), arr.begin() + mid));
		auto right_half = merge_sort(vector<T>(arr.begin() + mid, arr.end()));

		return merge<T>(left_half, right_half);
	}

	return arr;
}
template <typename T>
auto partition(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
	auto pivot_val = *begin;
	auto left_iter = begin + 1;
	auto right_iter = end;

	while (true){
		while (*left_iter <= pivot_val && left_iter != right_iter) {
			left_iter++;
		}
		while (*right_iter >= pivot_val && left_iter != right_iter) {
			right_iter--;
		}


		if (left_iter == right_iter) {
			break;
		}
		else {
			iter_swap(left_iter, right_iter);
		}
	}

	if (pivot_val > *right_iter) {
		iter_swap(begin, right_iter);
	}

	return right_iter;
}
template <typename T>
void quick_sort(typename vector<T>::iterator begin, typename vector<T>::iterator last) {
	if (distance(begin, last) >= 1){
		auto partition_iter = partition<T>(begin, last);

		quick_sort<T>(begin, partition_iter - 1);
		quick_sort<T>(partition_iter, last);
	}
}

template<typename T>
auto find_median(typename vector<T>::iterator begin, typename vector<T>::iterator last) {
	// 정렬
	quick_sort<T>(begin, last);

	// 가운데(median) 원소 반복자를 반환
	return begin + (std::distance(begin, last) / 2);
}
template <typename T>
auto partition_using_given_pivot(typename vector<T>::iterator begin, typename vector<T>::iterator end, typename vector<T>::iterator pivot) {
	// 피벗 위치는 함수 Argument로 주어지므로, 
	// 벡터의 시작과 마지막 원소를 가리키는 반복자를 정의.
	auto left_iter = begin;
	auto right_iter = end;

	while (true){
		// 벡터의 첫 번째 원소부터 시작하여 피벗보다 큰 원소를 찾습니다.
		while (*left_iter < *pivot && left_iter != right_iter) {
			left_iter++;
		}

		// 벡터의 마지막 원소부터 시작하여 역순으로 피벗보다 작은 원소를 찾습니다.
		while (*right_iter >= *pivot && left_iter != right_iter) {
			right_iter--;
		}

		// 만약 left_iter와 right_iter가 같다면 교환할 원소가 없음을 의미합니다.
		// 그렇지 않으면 left_iter와 right_iter가 가리키는 원소를 서로 교환합니다.
		if (left_iter == right_iter) {
			break;
		}
		else {
			iter_swap(left_iter, right_iter);
		}
	}

	if (*pivot > *right_iter) {
		iter_swap(pivot, right_iter);
	}
	return right_iter;
}

template<typename T>
typename vector<T>::iterator linear_time_select(typename vector<T>::iterator begin, typename vector<T>::iterator last, size_t i) {
	auto size = distance(begin, last);

	if (size > 0 && i < size){
		// 5개 원소로 구분하여 만들 부분 벡터 Vi의 개수 계산
		auto num_Vi = (size + 4) / 5;
		size_t j = 0;

		// 각각의 Vi에서 중앙값을 찾아 벡터 M에 저장
		vector<T> M;
		for (; j < size / 5; j++){
			auto b = begin + (j * 5);
			auto l = begin + (j * 5) + 5;

			M.push_back(*find_median<T>(b, l));
		}

		if (j * 5 < size){
			auto b = begin + (j * 5);
			auto l = begin + (j * 5) + (size % 5);

			M.push_back(*find_median<T>(b, l));
		}

		// Vi의 중앙값으로 구성된 벡터 M에서 다시 중앙값 q를 찾음
		auto median_of_medians = (M.size() == 1) ? M.begin() : linear_time_select<T>(M.begin(), M.end() - 1, M.size() / 2);

		// 분할 연산을 적용하고 피벗 q의 위치 k를 찾음
		auto partition_iter = partition_using_given_pivot<T>(begin, last, median_of_medians);
		auto k = distance(begin, partition_iter) + 1;

		if (i == k) {
			return partition_iter;
		}
		else if (i < k) {
			return linear_time_select<T>(begin, partition_iter - 1, i);
		}
		else if (i > k) {
			return linear_time_select<T>(partition_iter + 1, last, i - k);
		}
	}
	else {
		return begin;
	}
}
template <typename T>
void print_vector(vector<T> arr) {
	for (auto i : arr) {
		std::cout << i << " ";
	}
	cout << endl;
}

void run_linear_select_test() {
	vector<int> S1{ 45, 1, 3, 1, 2, 3, 45, 5, 1, 2, 44, 5, 7 };

	cout << "입력 벡터: \n";
	print_vector<int>(S1);

	cout << "정렬된 벡터: \n";
	print_vector<int>(merge_sort<int>(S1));

	cout << "3번째 원소: " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 3) << endl;
	cout << "5번재 원소: " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 5) << endl;
	cout << "11번째 원소: " << *linear_time_select<int>(S1.begin(), S1.end() - 1, 11) << endl;
}
