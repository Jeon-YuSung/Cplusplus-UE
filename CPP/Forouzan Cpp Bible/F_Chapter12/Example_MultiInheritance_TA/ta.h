
#ifndef TA_H
#define TA_H
#include "student.h"
#include"professor.h"

class TA : public Professor, public Student { //다중 상속

public :
	TA(string name, double gpa, double sal);
	~TA();
	void print();
};

#endif // !1
