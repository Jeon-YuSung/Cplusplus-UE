//19-30. accmulate 사용하기

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void print(int v) {
    cout << v << " ";
}


int main(void) {
    
    vector<int> f;
    f.push_back(11);
    f.push_back(10);
    f.push_back(19);
    f.push_back(11);
    f.push_back(22);
    f.push_back(30);
    f.push_back(77);
    f.push_back(163);
    f.push_back(23);
    f.push_back(82);

    for_each(f.begin(), f.end(), print);
    cout << endl << endl;

    int sum;
    sum = accumulate (f.begin(), f.end(), 0);

    cout << " 합계 = " << sum << endl;

    return 0; 

}
