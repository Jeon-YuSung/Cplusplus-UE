//20-6. 프록시 패턴 사용하기 
#include "proxy.h"

int main(void) {

    
    Proxy p;
    for (int i = 0; i < 5; i++) {
        p.draw(i, i);
        p.erase();
    }

    return 0; 

}
