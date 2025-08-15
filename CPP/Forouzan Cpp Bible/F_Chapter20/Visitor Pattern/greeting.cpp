// greeting의 구현 파일
#include  "greeting.h"

void Greeting::accept(Visitor* v) {
	v->visit();
}
