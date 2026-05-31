#pragma once
#include <string>

struct Card {
	int number;

	// 0 : 스페이드, 1 : 다이아몬드, 2 : 하트, 3 : 클로버
	int symbol;

	Card() {
		number = 0;
		symbol = 0;
	}

	Card(int newNumber, int newSymbol) {
		number = newNumber;
		symbol = newSymbol;
	}

	Card(int cardCode) {
		number = cardCode % 13 + 1;
		symbol = cardCode / 13;
	}

	Card(Card* card) {
		number = card->number;
		symbol = card->symbol;
	}

	std::string printCard();
};

void shuffle(Card* array, int length);

Card* drawCard(Card* initialCardList, int& cardIndex);

void drawCard(Card* userCardList, int& cardCount, Card* initialCardList, int& cardIndex);

void printGame(Card* playerCardList, int playerCardCount, Card* dealerCardList, int dealerCardCount, bool dealerReveal);

int getCardSum(Card* userCardList, int userCardCount);

bool isBlackJack(Card* userCardList);

void Homework02_Run();