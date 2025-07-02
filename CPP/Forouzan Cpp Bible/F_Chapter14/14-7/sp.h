//14-7 integer 클래스를 사용한 간단한 예시 프로그램

#ifndef SP_H
#define SP_H
#include<iostream>
using namespace std;

class SP {

private:
	int* ptr;
public:
	SP(int* ptr);
	~SP();
	int& operator*()const;
	int* operator->() const;
};

#endif // !SP_H
