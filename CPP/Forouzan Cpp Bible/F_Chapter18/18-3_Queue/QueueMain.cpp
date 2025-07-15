//18-3. queue를 구현 해보기 
#include "queue.cpp"
#include <string>

int main(void) {


    Queue<string> queue;
    queue.push("Wonju");
    queue.push("Yonesei");
    queue.push("Seoul");
    queue.push("Osaka");
    queue.push("Tokyo");
    queue.push("Busan");

    //노드 상태 확인
    cout << "fornt와 back 확인하기 \n";
    cout << "fornt : " << queue.front() << endl;
    cout << "back : " << queue.back() << endl;
    cout << endl;

    //큐에서 노드 2개 제거
    queue.pop();
    queue.pop();

    //노드 제거후의 상태 확인
    cout << "노드 제거후의 front와 back의 상태 확인 \n";
    cout << "fornt : " << queue.front() << endl;
    cout << "back : " << queue.back() << endl;
    return 0;
}
