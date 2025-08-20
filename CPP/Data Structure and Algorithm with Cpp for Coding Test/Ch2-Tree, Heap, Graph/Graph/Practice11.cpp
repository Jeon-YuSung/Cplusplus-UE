//연습문제11 그래프를 구성하고 인접 행렬로 표현하기. 

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 클래스를 사용해서 도시 이름을 저장 
enum class city : int{
	MOSCOW,
	LONDON,
	SEOUL,
	SEATTLE,
	DUBAI,
	SYDNEY
};

// city enum에 대해 << 연산자 정의
ostream& operator<<(ostream& os, const city c){
	
	switch (c){
	case city::LONDON:
		os << "런던";
		return os;
	case city::MOSCOW:
		os << "모스크바";
		return os;
	case city::SEOUL:
		os << "서울";
		return os;
	case city::SEATTLE:
		os << "시애틀";
		return os;
	case city::DUBAI:
		os << "두바이";
		return os;
	case city::SYDNEY:
		os << "시드니";
		return os;
	default:
		return os;
	}

}
//데이터를 저장할 그래프를 정의 
struct graph{
	vector<vector<int>> data;

	// 그래플 구성하는 생성자를 추가 
	graph(int n) {
		data.reserve(n);
		vector<int> row(n);
		fill(row.begin(), row.end(), -1);

		for (int i = 0; i < n; i++){
			data.push_back(row);
		}
	}

	//엣지를 추가하는 함수로 가중치를 argument로 받음
	void addEdge(const city c1, const city c2, int dis){
		cout << "간선 추가: " << c1 << "-" << c2 << "=" << dis << endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		data[n1][n2] = dis;
		data[n2][n1] = dis;
	}

	//엣지를 제거하는 함수 정의
	void removeEdge(const city c1, const city c2){
		cout << "간선 삭제: " << c1 << "-" << c2 << endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		data[n1][n2] = -1;
		data[n2][n1] = -1;
	}
};

int main(void){
	graph g(6);
	g.addEdge(city::LONDON, city::MOSCOW, 2500);
	g.addEdge(city::LONDON, city::SEOUL, 9000);
	g.addEdge(city::LONDON, city::DUBAI, 5500);
	g.addEdge(city::SEOUL, city::MOSCOW, 6600);
	g.addEdge(city::SEOUL, city::SEATTLE, 8000);
	g.addEdge(city::SEOUL, city::DUBAI, 7000);
	g.addEdge(city::SEOUL, city::SYDNEY, 8000);
	g.addEdge(city::SEATTLE, city::MOSCOW, 8400);
	g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
	g.addEdge(city::DUBAI, city::SYDNEY, 1200);

	g.addEdge(city::SEATTLE, city::LONDON, 8000);
	g.removeEdge(city::SEATTLE, city::LONDON);

	return 0;
}
