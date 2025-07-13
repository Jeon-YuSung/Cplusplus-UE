#include"length.h"

length::length(int n1) : n(n1)
{
}

//연산자 오버로드
ostream& operator<< (ostream& stream, const length& len) {

	stream.width(len.n);
	return stream;
}
