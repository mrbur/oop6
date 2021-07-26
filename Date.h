#pragma once
#include <ostream>
#include <cassert>

using namespace std;

class Date {
	private:
		int day;
		int month;
		int year;

	public:
		Date(int day, int month, int year) : day(day), month(month), year(year) {
			assert(day > 0 && day < 32);
			assert(month > 0 && month < 13);
		}

		int getDay() const {
			return this->day;
		}
		int getMonth() const {
			return this->month;
		}
		int getYear() const {
			return this->year;
		}
};

bool operator>(const Date& date1, const Date& date2) {
	return date1.getYear() > date2.getYear() ||
		date1.getYear() == date2.getYear() && (date1.getMonth() > date2.getMonth()) ||
		date1.getYear() == date2.getYear() && (date1.getMonth() == date2.getMonth()) && (date1.getDay() > date2.getDay());
}

ostream& operator<< (std::ostream& out, const Date& date) {
	return out << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << endl;
}
