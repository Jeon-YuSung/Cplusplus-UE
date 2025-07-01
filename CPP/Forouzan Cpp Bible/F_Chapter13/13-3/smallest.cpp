#include "smallest.h"

Smallest::Smallest() {
	curr = numeric_limits<int>::max();

}

//함수 호출 연산자 오버로드 
int Smallest::operator()(int next) {

	if (next < curr) {
		curr = next;
	}
	return curr;
}
