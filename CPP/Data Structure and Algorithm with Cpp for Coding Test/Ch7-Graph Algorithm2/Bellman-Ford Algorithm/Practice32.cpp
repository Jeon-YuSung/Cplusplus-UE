//연습문제32 벨만포드 알고리즘 구현하기 
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>

using namespace std;

//무한을 표현하기 위한 상수 정의 정수 최대값을 표현
const int UNKNOWN = INT_MAX;

//간선을 표현할 구조체 정의
//출발 정점, 목적 정점, 가중치를 저장
struct Edge{

	int src;
	int dst;
	int weight;
};

vector<int> BellmanFord(vector<Edge> edges, int V, int start) {
	vector<int> distance(V, UNKNOWN);
	distance[start] = 0;

	// (V - 1)번 반복
	for (int i = 0; i < V - 1; i++) {
		// 전체 에지에 대해 반복
		for (auto& e : edges) {
			// 에지의 시작 정점의 거리 값이 UNKNOWN이면 스킵
			if (distance[e.src] == UNKNOWN) {
				continue;
			}

			// 인접한 정점의 거리 값이 새로운 경로에 의한 거리 값보다 크면
			// 거리 값을 업데이트함.
			if (distance[e.dst] > distance[e.src] + e.weight) {
				distance[e.dst] = distance[e.src] + e.weight;
			}
		}
	}

	return distance;
}

int main(void){
	int V = 5;              // 정점 개수
	vector<Edge> edges;     // 에지 포인터의 벡터

	vector<vector<int>> edge_map{ // {시작 정점, 목표 정점, 가중치}
		{0, 1, 3},
		{1, 2, 5},
		{1, 3, 10},
		{3, 2, -7},
		{2, 4, 2}
	};

	for (auto& e : edge_map){
		edges.emplace_back(Edge{ e[0], e[1], e[2] });
	}

	int start = 0;
	vector<int> distance = BellmanFord(edges, V, start);

	cout << "[" << start << "번 정점으로부터 최소 거리]" << endl;

	for (int i = 0; i < distance.size(); i++){
		if (distance[i] == UNKNOWN)
			cout << i << "번 정점: 방문하지 않음!" << endl;
		else
			cout << i << "번 정점: " << distance[i] << endl;
	}
	
	return 0;

}
