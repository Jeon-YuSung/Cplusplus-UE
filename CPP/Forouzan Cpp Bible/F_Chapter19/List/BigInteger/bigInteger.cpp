// 구현파일
#include <iostream>
#include <string>
#include <iomanip>
#include "bigInteger.h"
using namespace std;

//기본 생성자
Big_integer::Big_integer() :lst(list<int>()) {}

//매개변수가 있는 생성자
Big_integer::Big_integer(string str) : lst(list<int>()) {

	for (int i = 0; i < str.length(); i++) {
	
		int num;
		num = str[i] - 48;
		lst.push_back(num);
	}
}

//소멸자
Big_integer::~Big_integer() {}

//리스트를 문자열로 변환하는 함수
string Big_integer::toString() {
	string strg;
	list<int>::iterator iter;
	iter = lst.begin();
	while (iter != lst.end()) {
		strg.append(1, *iter + 48);
		iter++;
	}
	return strg;
}

//operator+friend 함수
Big_integer operator+(Big_integer first, Big_integer second) {
	list<int>::reverse_iterator iter1;
	list<int>::reverse_iterator iter2;
	Big_integer result;
	int n1, n2, sum, carry;
	carry = 0;

	iter1 = first.lst.rbegin();
	iter2 = second.lst.rbegin();

	while (iter1 != first.lst.rend() && (iter2 != second.lst.rend())) {
		n1 = *iter1;
		n2 = *iter2;
		sum = (n1 + n2 + carry) % 10;
		result.lst.push_front(sum);
		iter1++;
		iter2++;
	}

	while (iter1 != first.lst.rend()) {
		n1 = *iter1;
		sum = (n1 + carry) % 10;
		carry = (n1 + carry) / 10;
		result.lst.push_front(sum);
		iter1++;
	}

	while (iter2 != second.lst.rend()) {
		n2 = *iter2;
		sum = (n2 + carry) % 10;
		carry = (n2 + carry) / 10;
		result.lst.push_front(sum);
		iter2++;
	}
	if (carry == 1) {
		result.lst.push_front(carry);
	}
	return result;
}
