//19-15. set으로 정수 정렬해보기

#include <set>
#include <iostream>
#include <iomanip>
using namespace std;

int main(void) {

    //빈 정수 set 생성
    set<int> st;

    //중복을 포함한 정수 셋트 넣기 
    st.insert(48);
    st.insert(18);
    st.insert(12);
    st.insert(25);
    st.insert(93);
    st.insert(33);
    st.insert(45);
    st.insert(22);
    st.insert(1);
    st.insert(87);
    st.insert(63);
    st.insert(56);
    st.insert(34);
    st.insert(20);
    st.insert(32);
    st.insert(48); //중복값을 넣어도 set은 중복이 안되기에 하나만 출력됨 


    cout << " 오름차순으로 set의 요소 출력 \n";
    set<int>::iterator iter;
    for (iter = st.begin(); iter != st.end(); iter++) {
        cout << setw(4) << *iter;
    }
    cout << endl << endl;

    cout << " 내리차순으로 set 요소 출력 \n";
    set<int>::reverse_iterator riter;
    for (riter = st.rbegin(); riter != st.rend(); riter++) {
    
        cout << setw(4) << *riter;
    }

    cout << endl << endl;

    //56 뒤의 요소 출력
    set<int>::iterator iter1 = st.find(56);
    iter1++;
    cout << "56 뒤의 요소 = " << *iter1 << endl;

    //22앞의 요소 출력
    set<int>::iterator iter2 = st.find(22);
    iter2--;
    cout << "22의 앞의 요소 = " << *iter2 << endl;

    return 0;
}
