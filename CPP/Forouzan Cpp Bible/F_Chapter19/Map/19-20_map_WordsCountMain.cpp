//19-20. 단어 개수 세기 
#include <iostream>
#include <iomanip>
#include <map>
#include <utility>
#include <string>
using namespace std;

int main(void) {
    
    // map과 iteraotr 선언
    map<string, int> freq;
    map<string, int>::iterator iter;
    string word;

    cout << "문장 입력 : \n";
    while (cin >> word) {
        ++freq[word];
    }
    for (iter = freq.begin(); iter != freq.end(); iter++) {
    
        cout << left << setw(10) << iter->first << iter->second << endl;
    }
    return 0; 

}
