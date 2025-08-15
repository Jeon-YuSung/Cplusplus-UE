//20-17 방문자 패턴 예제 파일 
#include "greeting.h"
using namespace std;

int main(void) {
    
    Greeting gree;
    Visitor* v1 = new EngVisitor;
    gree.accept(v1);
    Visitor* v2 = new FrenchVisitor;
    gree.accept(v2);
    Visitor* v3 = new KoreanVisitor;
    gree.accept(v3);

    return 0; 

}
