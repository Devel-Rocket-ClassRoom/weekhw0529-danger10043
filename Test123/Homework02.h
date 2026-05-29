#pragma once
#include <string>

extern std::string cardList[52];

struct Card {
	int number;
	// 0 : 스페이드, 1 : 다이아몬드, 2 : 하트, 3 : 클로버
	int symbol;

	std::string printCard();
};

void Homework02_Run();