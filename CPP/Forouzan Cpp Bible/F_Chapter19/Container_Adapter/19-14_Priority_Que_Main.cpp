//19-14. 우선순위 큐를 사용하는 프로그램 

#include <queue>
#include <iostream>
using namespace std;

int main(void) {

    priority_queue<int> line;
    //요소 추가
    line.push(4);
    line.push(2);
    line.push(7);
    line.push(4);
    line.push(5);
    line.push(8);
    line.push(1);
    line.push(6);
    line.push(9);

    while (!line.empty()) {
    
        cout << line.top() << " ";
        line.pop();
    }

    return 0;
}
