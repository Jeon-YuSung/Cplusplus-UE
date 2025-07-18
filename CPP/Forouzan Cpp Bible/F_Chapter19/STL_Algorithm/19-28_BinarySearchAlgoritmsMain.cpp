//19-28. 이진 탐색 알고리즘 

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;


int main(void) {
    
    vector<int> vec;
    vec.push_back(11);
    vec.push_back(17);
    vec.push_back(14);
    vec.push_back(22);
    vec.push_back(39);
    vec.push_back(26);
    vec.push_back(41);
    vec.push_back(91);
    vec.push_back(64);
    vec.push_back(40);

    sort(vec.begin(), vec.end());

    cout << "11의 탐색 결과 = " << boolalpha;
    cout << binary_search(vec.begin(), vec.end(), 11) << endl;
    cout << "32의 탐색 결과 = " << boolalpha;
    cout << binary_search(vec.begin(), vec.end(), 32) << endl;
    
    return 0; 

}
