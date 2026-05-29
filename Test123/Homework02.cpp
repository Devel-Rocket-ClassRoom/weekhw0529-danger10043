#include "Homework02.h"
#include <iostream>
#include <string>

std::string cardList[52];

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

void Homework02_Run() {

}
