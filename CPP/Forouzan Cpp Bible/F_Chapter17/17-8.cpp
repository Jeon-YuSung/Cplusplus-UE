//17-8. 하노이 타워 

#include <iostream>
using namespace std;

void towers(int, char, char, char);
void moveOneDisk(char, char);

int main(void) {
    int n;
    do {
        cout << "디스크 수를 입력하세요 (1~4 범위): ";
        cin >> n;
    } while ((n < 1) || (n > 4));

    towers(n, 'A', 'C', 'B');
   
    return 0;
}
void towers(int num, char source, char dest, char aux) {
    if (num == 1) {
        moveOneDisk(source, dest);
    }
    else {
        towers(num - 1, source, aux, dest);
        moveOneDisk(source, dest);
        towers(num - 1, aux, dest, source);
    }
}

void moveOneDisk(char s, char e) {

    cout << "디스크를 " << s << "에서" << e << "로 이동했습니다\n";
}
