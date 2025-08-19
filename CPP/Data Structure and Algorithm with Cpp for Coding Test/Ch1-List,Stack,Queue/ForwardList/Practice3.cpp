// 연습문제 3: 연결 리스트에서 romve_if 함수를 사용해서 조건부로 값 삭제하기 
#include <iostream>
#include <algorithm>
#include <string>
#include <forward_list>
using namespace std;

// citizen 구조체 정의;
struct citizen
{
    string name;
    int age;
};

ostream& operator<<(ostream& os, const citizen& c) {
    return (os << "[" << c.name << "," << c.age << "]");
}

//메인 함수 
int main(void) {
    forward_list<citizen> people = {
        {"kim", 22}, { "Park",18 },{"Lee",21},{"John",12}, {"Vi",19 }
    };

    auto peopleCopy = people; //deep copy
    cout << "전체 시민들 : ";
    for (const auto& c : people) {
        cout << c << " ";
    } 
    cout << endl;

    // 나이를 이용하여 투표권이 없는 시민들을 리스트에서 제거
    people.remove_if([](const citizen& c) {
        return (c.age < 19);
        }
    );
    
    cout << "투표권이 있는 시민들 : ";
    for (const auto& c : people) {
        cout << c << " ";
    }  
    cout << endl;

    //내년에 투표권이 새로 생기는 사람들 
    peopleCopy.remove_if([](const citizen& c){
        return (c.age != 18);
        }
    );

    cout << "내년에 투표권이 생기는 사람들 : ";
    for (const auto& c : peopleCopy) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}
