/*
11-7. 메인 (애플리케이션 파일)
*/

#include "invoice.h"

//메인 함수 
int main(void) {

    Product product1("table", 150.00);
    Product product2("chair", 80.00);
    
    Invoice invoice(1001);
    invoice.add(2, product1);
    invoice.add(5, product2);
    invoice.print();
    return 0;
}
