//연습문제19. 병합 정렬 구현. 

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
void print_vector(vector<T> arr);
void run_merge_sort_test();

//메인 함수 정의
int main(void){
	run_merge_sort_test();
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

	if (iter1 != arr1.end()){
		for (; iter1 != arr1.end(); iter1++)
			merged.emplace_back(*iter1);
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
		auto left_half = merge_sort<T>(vector<T>(arr.begin(), arr.begin() + mid));
		auto right_half = merge_sort<T>(vector<T>(arr.begin() + mid,arr.end()));

		return merge<T>(left_half, right_half);
	}

	return arr;
}

template <typename T>
void print_vector(vector<T> arr) {
	for (auto i : arr) {
		cout << i << " ";
	}
	cout << endl;
}

void run_merge_sort_test() {
	vector<int>    S1{ 45, 1, 3, 1, 2, 3, 45, 5, 1, 2, 44, 5, 7 };
	vector<float>  S2{ 45.6f, 1.0f, 3.8f, 1.01f, 2.2f, 3.9f, 45.3f, 5.5f, 1.0f, 2.0f, 44.0f, 5.0f, 7.0f };
	vector<double> S3{ 45.6, 1.0, 3.8 , 1.01, 2.2, 3.9, 45.3, 5.5, 1.0, 2.0, 44.0, 5.0, 7.0 };
	vector<char>   C{ 'b', 'z', 'a', 'e', 'f', 't', 'q', 'u', 'y' };

	cout << "정렬되지 않은 입력 벡터: \n";
	print_vector<int>(S1);
	print_vector<float>(S2);
	print_vector<double>(S3);
	print_vector<char>(C);
	cout << endl;

	auto sorted_S1 = merge_sort<int>(S1);
	auto sorted_S2 = merge_sort<float>(S2);
	auto sorted_S3 = merge_sort<double>(S3);
	auto sorted_C = merge_sort<char>(C);

	cout << "병합 정렬에 의해 정렬된 벡터: \n";
	print_vector<int>(sorted_S1);
	print_vector<float>(sorted_S2);
	print_vector<double>(sorted_S3);
	print_vector<char>(sorted_C);
	cout << endl;
}
