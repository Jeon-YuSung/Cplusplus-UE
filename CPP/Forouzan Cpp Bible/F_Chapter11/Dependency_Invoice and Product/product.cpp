/*
11-7. 구현파일
product.h 클래스의 구현 파일.
*/
#include "product.h"

Product::Product(string nm, double up) : name(nm), unit_price(up) {
}
Product::~Product() {}
double Product::getPrice() const {
	return unit_price;
}
