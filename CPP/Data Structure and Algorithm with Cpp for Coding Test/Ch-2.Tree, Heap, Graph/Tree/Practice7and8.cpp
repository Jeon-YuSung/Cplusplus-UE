//연습문제 7. 트리를 이용하여 사내 조직도 구현해보기.
//연습문제 8 레벨 순회 트리도 같이 구현 
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

// 1명당 최대 2 명의 부하직원을 둘 수 있음.
struct node{
	string position;
	node* first;
	node* second;
};

struct org_tree{
	node* root;

	//뿌리 노드 정의, CEO를 나타내고, 새로운 트리를 만드는 정적 함수임
	static org_tree create_org_structure(const string& pos)
	{
		org_tree tree;
		tree.root = new node{ pos, NULL, NULL };
		return tree;
	}
	
	static node* find(node* root, const string& value){
		if (root == NULL)
			return NULL;

		if (root->position == value)
			return root;

		auto firstFound = org_tree::find(root->first, value);

		if (firstFound != NULL)
			return firstFound;

		return org_tree::find(root->second, value);
	}
	// 부하 직원을 삽임하는 함수 정의
	bool addSubordinate(const string& manager, const string& subordinate){
		auto managerNode = org_tree::find(root, manager);

		if (!managerNode){
			cout << manager << "을(를) 찾을 수 없습니다: \n";
			return false;
		}

		if (managerNode->first && managerNode->second){
			cout << manager << " 아래에 " << subordinate << "를 추가할 수 없습니다.\n";
			return false;
		}

		if (!managerNode->first)
			managerNode->first = new node{ subordinate, NULL, NULL };
		else
			managerNode->second = new node{ subordinate, NULL, NULL };

		cout << manager << " 아래에 " << subordinate << "를 추가했습니다.\n";

		return true;
	}
	//레벨 순서 순회
	static void levelOrder(node* start){
		if (!start)
			return;

		queue<node*> q;
		q.push(start);

		while (!q.empty()){
			int size = q.size();
			for (int i = 0; i < size; i++){
				auto current = q.front();
				q.pop();

				cout << current->position << ", ";
				if (current->first)
					q.push(current->first);
				if (current->second)
					q.push(current->second);
			}

			cout << endl;
		}
	}
};

int main(void){
	auto tree = org_tree::create_org_structure("CEO");

	tree.addSubordinate("CEO", "부사장");
	tree.addSubordinate("부사장", "IT부장");
	tree.addSubordinate("부사장", "마케팅부장");
	tree.addSubordinate("IT부장", "보안팀장");
	tree.addSubordinate("IT부장", "앱개발팀장");
	tree.addSubordinate("마케팅부장", "물류팀장");
	tree.addSubordinate("마케팅부장", "홍보팀장");
	tree.addSubordinate("부사장", "재무부장");

	//연습 8
	org_tree::levelOrder(tree.root);
}
