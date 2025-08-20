//연습문제10 중앙값 구하기
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
using namespace std;

//현재까지 받은 데이터를 저장할 컨테이너 정의
// 2개의 힙이 존재(최소힙과 최대힙)
struct median{
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	//새로 들어온 데이터를 저장하는 함수 정의
	void insert(int data){
		
		if (maxHeap.size() == 0){
			maxHeap.push(data);
			return;
		}

		if (maxHeap.size() == minHeap.size()){
			if (data <= get()) {
				maxHeap.push(data);
			}
			else {
				minHeap.push(data);
			}
			return;
		}

		if (maxHeap.size() < minHeap.size()){
			if (data > get()){
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(data);
			}
			else {
				maxHeap.push(data);
			}
			return;
		}

		if (data < get()){
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(data);
		}
		else {
			minHeap.push(data);
		}
	}

	//저장된 원소로 부터 중앙값을 구하여 반환하는 get 함수 정의
	double get(){
		if (maxHeap.size() == minHeap.size()) {
			return (maxHeap.top() + minHeap.top()) / 2.0;
		}

		if (maxHeap.size() < minHeap.size()) {
			return minHeap.top();
		}
		return maxHeap.top();
	}
};

int main(void){
	median med;

	med.insert(1);
	cout << "1 삽입 후 중앙값: " << med.get() << endl;

	med.insert(5);
	cout << "5 삽입 후 중앙값: " << med.get() << endl;

	med.insert(2);
	cout << "2 삽입 후 중앙값: " << med.get() << endl;

	med.insert(10);
	cout << "10 삽입 후 중앙값: " << med.get() << endl;

	med.insert(40);
	cout << "40 삽입 후 중앙값: " << med.get() << endl;
}
