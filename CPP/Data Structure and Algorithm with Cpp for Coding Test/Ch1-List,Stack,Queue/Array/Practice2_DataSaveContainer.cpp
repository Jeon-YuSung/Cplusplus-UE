// 1장 연습문제 2, 빠르고 범용적인 데이터 저장 컨테이너 만들기
#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <type_traits>
using namespace std;

//buildarray 함수를 선언, 이 함수는 빠른 원소 순회를 보장하는 array를 반환 및 가변 템플릿 사용
//반환된 컨테이너는 빠르게 순회할 수 있는 조건이 있으니 배열 또는 벡터를 사용

template<typename ... Args>
auto buildArray(Args&&... args) -> array<typename common_type <Args...>::type, sizeof...(args)> {
    using commonType = typename common_type<Args...>::type;
    return { forward<commonType>((Args&&)args)... };
}

//메인 함수 
int main(void) {
       
    auto data = buildArray(1, 0u, 'a', 3.2f, 'A', true, false);
    for (auto i : data) {
        cout << i << " ";
        cout << endl;
    }

    // auto data2 = buildArray(1, "Packt", 2.0); 
    // → 이경우 모든 데이터 타입이 하나의 공통 타입으로 반환할수 없어 에러 발생 
    // 문자열과 숫자를 모두 표현할수 있는 공통의 자료형이 존재하지 않기 때문임. 
    

    return 0;
}
