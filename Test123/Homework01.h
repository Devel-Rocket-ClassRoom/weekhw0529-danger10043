#pragma once
#include <string>

struct Date {
	int year = 1;
	int month = 1;
	int day = 1;

	Date(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}

	int maxDayCount(int CurrentMonth);

	void dateIncrease();

	bool operator==(const Date& otherDate) const {
		return ((this->day == otherDate.day) &&
			(this->month == otherDate.month) &&
			(this->year == otherDate.year));
	}
};

bool isLeap(int year);

std::string day2dayName(int day);

void Homework01_Run();