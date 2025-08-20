//연습문제12. 그래프를 인접리스트로 표현하기 

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
	vector<vector<pair<int,int>>> data;

	// 인접리스트를 사용하는 그래프의 구조체 생성자 
	graph(int n) {
		data = vector<vector<pair<int, int>>> (n, vector<pair<int, int>>());
	}

	//엣지를 추가하는 함수 정의 
	void addEdge(const city c1, const city c2, int dis){
		cout << "간선 추가: " << c1 << "-" << c2 << "=" << dis << endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		data[n1].push_back({ n2,dis });
		data[n2].push_back({ n1,dis });
	}

	//엣지를 제거하는 함수 정의
	void removeEdge(const city c1, const city c2){
		cout << "간선 삭제: " << c1 << "-" << c2 << endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		remove_if(data[n1].begin(), data[n1].end(), [n2](const auto& pair){
			return pair.first == n2;
			});
		remove_if(data[n2].begin(), data[n2].end(), [n1](const auto& pair) {
			return pair.first == n1;
			});

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
