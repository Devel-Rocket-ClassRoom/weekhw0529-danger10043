#include "Homework02.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

std::string Card::printCard() {
	std::string result;
	if (number >= 2 && number <= 10) {
		result = std::to_string(number);
	}
	else if (number == 1) {
		result = "A";
	}
	else if (number == 11) {
		result = "J";
	}
	else if (number == 12) {
		result = "Q";
	}
	else if (number == 13) {
		result = "K";
	}
	else {
		result = "?";
	}

	if (symbol == 0) {
		result += "♠";
	}
	else if (symbol == 1) {
		result += "◇";
	}
	else if (symbol == 2) {
		result += "♡";
	}
	else if (symbol == 3) {
		result += "♣";
	}
	else {
		result += "?";
	}

	return result;
}

void shuffle(Card* array, int length) {
	for (int index = length - 1; index > 0; index--) {
		int swapTargetIndex = rand() % (index + 1);
		std::swap(array[index], array[swapTargetIndex]);
	}
}

void Homework02_Run() {
	srand(time(0));
	printf("<< HOMEWORK 02 >>\n\n");
	printf("< 블랙잭 게임 >\n\n");
	Card cardList[52];
	for (int i = 0; i < 52; i++) {
		cardList[i] = Card(i);
	}
	shuffle(cardList, 52);

	printf("< 플레이어의 턴 >\n\n");
	Card playerCardList[52];
}

