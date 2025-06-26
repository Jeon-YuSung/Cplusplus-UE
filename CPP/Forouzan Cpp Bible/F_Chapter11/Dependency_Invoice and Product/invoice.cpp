//11-7. invoice 구현 파일

#include"invoice.h"

Invoice::Invoice(int invNum) : invoice_num(invNum), invoice_total(0.0) {}
Invoice::~Invoice() {}

void Invoice::add(int quantity, Product product) {
	invoice_total += quantity * product.getPrice();
}
void Invoice::print() const {
	cout << "청구 번호 : " << invoice_num << endl;
	cout << "청구 금액 : " << invoice_total << endl;

}
