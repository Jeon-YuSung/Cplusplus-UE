//11-5. date 구현 파일

#include "date.h"

Date::Date(int m, int d, int y) : month(m), day(d), year(y){

	if ((month < 1) || (month > 12)) {

		cout << "월의 범위가 벗어났습니다.\n";
		assert(false);
	}
	int days_in_months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((day < 1) || (day > days_in_months[month])) {
		cout << "일의 범위가 벗어 났습니다.\n";
		assert(false);
	}
	if ((year < 0) || (year > 9999)) {
		cout << "년의 범위가 벗어 났습니다" << endl; 
			assert(false);
	}
}
Date::~Date() {}
void Date::print() const {
	cout << year << "년 " << month << "월 " << day << "일\n";
}
