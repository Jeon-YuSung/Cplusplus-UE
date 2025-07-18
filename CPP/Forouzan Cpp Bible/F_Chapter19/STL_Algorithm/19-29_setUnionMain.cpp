//19-29. 합집합을 구하는 프로그램 

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void print(int v) {
    cout << v << " ";
}


int main(void) {
    
    set<int> f;
    f.insert(10);
    f.insert(23);
    f.insert(5);
    f.insert(13);
    f.insert(114);

    cout << "첫 번째 집합 : " << endl;
    for_each(f.begin(), f.end(), print);
    cout << endl << endl;

    set<int> s;
    s.insert(20);
    s.insert(3);
    s.insert(5);
    s.insert(13);
    s.insert(92);

    cout << "두 번째 집합 : " << endl;
    for_each(s.begin(), s.end(), print);
    cout << endl << endl;

    //합집합 구하고 벡터에 저장 
    vector<int> temp(10);
    vector<int>::iterator iter;
    vector<int>::iterator enditer;
    enditer = set_union(f.begin(), f.end(), s.begin(), s.end(), temp.begin());

    //벡터에서의 결과를 세트로 복사
    set<int> result;
    for (iter = temp.begin(); iter != enditer; iter++) {
        result.insert(*iter);
    }
    
    cout << " 결과 " << endl;
    for_each(result.begin(), result.end(), print);
    cout << endl;
    return 0; 

}
