#ifndef INTEGER_H
#define INTEGER_H
#include "sp.h"

//Integer 클래스 정의 
class Integer {

private:
	SP sp;
public:
	Integer(int value);
	~Integer();
	int getValue();

};
#endif // !INTEGER_H
