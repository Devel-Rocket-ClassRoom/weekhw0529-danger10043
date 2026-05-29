#include <iostream>
#include <string>
#include "Homework01.h"

int Date::maxDayCount(int currentMonth) {
	switch (currentMonth) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (isLeap(year)) {
			return 29;
		}
		else {
			return 28;
		}
		break;
	default:
		return 0;
	}
}

void Date::dateIncrease() {
	day++;
	if (this->day <= maxDayCount(month)) {
		return;
	}
	month++;
	day = 1;
	if (month <= 12) {
		return;
	}
	year++;
	month = 1;
	return;
}

bool isLeap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    }
    else {
        return false;
    }
}

std::string day2dayName(int day) {
	switch (day % 7) {
	case 0:
		return "월요일";
	case 1:
		return "화요일";
	case 2:
		return "수요일";
	case 3:
		return "목요일";
	case 4:
		return "금요일";
	case 5:
		return "토요일";
	case 6:
		return "일요일";
	default:
		return "?";
	}
}

void Homework01_Run() {
    printf("<< HOMEWORK 01 >>\n\n");
    printf("< 요일을 계산할 날짜의 연, 월, 일을 공백을 사이에 두고 입력하세요. >\n");
    printf("입력 : ");
    int year = 0, month = 0, day = 0;
    std::cin >> year >> month >> day;

	int dateCount = 0;
	Date initialDate(1, 1, 1);
	Date targetDate(year, month, day);

	while (!(initialDate == targetDate)) {
		initialDate.dateIncrease();
		dateCount++;
	}

	printf("\n%d년 %d월 %d일은 1월 1월 1일으로부터 %d일 이후의 날짜입니다.\n\n", year, month, day, dateCount);
	printf("%d년 %d월 %d일은 [%s] 입니다.", year, month, day, day2dayName(dateCount).c_str());

	printf("\n\n========================================\n\n");
}
