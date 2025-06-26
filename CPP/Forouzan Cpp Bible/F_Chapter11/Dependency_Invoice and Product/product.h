//11-7 product 헤더 파일 

#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
using namespace std;

class Product {

private:
	string name;
	double unit_price;
public:
	Product(string name, double unit_price);
	~Product();
	double getPrice() const;
};


#endif // !1
