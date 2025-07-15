//18-3(12). queue를 이용해서 대기열을 구현하고 통계를 출력해보기.

#include "queue.cpp"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <utility>

//randNUM 함수 정의
int randNum(int low, int high) {

    int temp, num;
    temp = rand();
    num = temp % (high - low + 1) + low;
    return num;
}

int main(void) {

    //변수 선언
    int size = 15;
    int arriveDelay, serveTime;
    int arrive = 0;
    int start = 0;
    int leave = 0;
    int wait = 0;
    int toTalServeTime = 0;
    int totalWait = 0;

    //큐 인스턴스화 
    Queue<pair<int, int>> line;

    //랜덤한 고객 행동 설정
    srand(time(0));
    for (int i = 0; i < size; i++) {
        pair<int, int> p(randNum(1, 6), randNum(5, 10));
        line.push(p);
    }

    //통계 헤더 출력
    cout << left << setw(10) << "Arrive " << setw(10) << "Start";
    cout << left << setw(10) << "Delay " << setw(10) << "Leave";
    cout << left << setw(10) << "Serve Time \n";

    //통계 계산하고 출력
    while (line.size() > 0) {
    
        arriveDelay = line.front().first;
        serveTime = line.front().second;
        arrive = arrive + arriveDelay;
        if (arrive >= leave) {
            start = arrive;
        }
        else {
            start = leave;
        }
        leave = start + line.front().second;
        wait = start - arrive;
        cout << left << setw(10) << arrive << setw(10) << start;
        cout << left << setw(10) << wait;
        cout << setw(10) << leave;
        cout << left << setw(12) << serveTime << endl;
        toTalServeTime += serveTime;
        totalWait += wait;
        line.pop();
    }

    //통계 정리
    double averageWait;
    averageWait = static_cast<double>(totalWait) / size;
    cout << "---------------------------------------------------------\n";
    cout << "전체 서비스 시간 = " << toTalServeTime << endl;
    cout << "고객 평균 대기 시간 = " << averageWait << endl;

    return 0;
}
