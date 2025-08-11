#include "president.h"

President* President::ptr = 0;

// 생성자 정의 
President::President(string nm) : name(nm) {
	cout << "대표가 선택 되었습니다.\n";
}

// create 정적 함수 정의
President* President::create(string name) {

	if (!ptr) {
		ptr = new President(name);
	}
	else {
		cout << "대표가 이미 뽑혀서 존재합니다! \n";
	}
	return ptr;
}

//접근자 함수 
string President::getName() const {
	return name;
}