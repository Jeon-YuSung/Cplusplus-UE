// 연습문제 4. 다양한 반복자에서 이동하기. 
#include <iostream>
#include <algorithm>
#include <string>
#include <forward_list>
#include <vector>
using namespace std;

//메인 함수 
int main(void) {
    vector<string> vec = {
        "Vidan", "Korean", "Yonsei", "Mirae", "Seoul", "Busan",
        "Incheon", "Dongguk", "Hina", "Tabi"
    };

    auto it = vec.begin();
    cout << "가장 최근 데이터 : " << *it << endl;
    it += 8;
    cout << "여덟 칸 뒤의 데이터 : " << *it << endl;
    advance(it, -3);
    cout << "그 이후 3칸 앞 데이터 : " << *it << endl;

    forward_list<string> fwd(vec.begin(), vec.end());
    auto it1 = fwd.begin();
    cout << "가장 최근 데이터 : " << *it1 << endl;
    advance(it1, 4);
    cout << "넷 칸 뒤의 데이터 : " << *it1 << endl;

    // forward_list는 순방향만 이동하기 때문에 역방향 이동인 advance(it1,-3);은 에러 발생
    //it+=2;하는 경우 에러가 발생함. 

    return 0;
}
