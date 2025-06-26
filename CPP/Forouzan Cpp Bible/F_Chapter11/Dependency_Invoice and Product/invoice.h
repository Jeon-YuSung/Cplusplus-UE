#ifndef INVOICE_H
#define INVOICE_H
#include "product.h"

class Invoice {
private:
	int invoice_num;
	double invoice_total;
public:
	Invoice(int invoice_num);
	~Invoice();
	void add(int quantity, Product product);
	void print() const;

};

#endif
