#include "Homework02.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

// 카드 정보를 받아 텍스트로 출력하는 함수
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

// 카드 배열과 길이를 입력받고 배열을 섞는 함수
void shuffle(Card* array, int length) {
	for (int index = length - 1; index > 0; index--) {
		int swapTargetIndex = rand() % (index + 1);
		std::swap(array[index], array[swapTargetIndex]);
	}
}

// (섞은) 덱에서 카드 한 장을 뽑는 함수
Card* drawCard(Card* initialCardList, int& cardIndex) {
	cardIndex++;
	return &(initialCardList[cardIndex - 1]);
}

// 플레이어 및 딜러의 패로 카드 한 장을 뽑아 넣는 함수
void drawCard(Card* userCardList, int& cardCount, Card* initialCardList, int& cardIndex) {
	userCardList[cardCount] = Card(drawCard(initialCardList, cardIndex));
	cardCount++;
}

// 플레이어와 딜러의 손패를 출력하는 함수
void printGame(Card* playerCardList, int playerCardCount, Card* dealerCardList, int dealerCardCount, bool dealerReveal) {
	printf("플레이어의 패 : [ ");
	for (int i = 0; i < playerCardCount; i++) {
		printf("%s ", playerCardList[i].printCard().c_str());
	}
	printf(" ]\n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("딜러의 패 : [ ");
	for (int i = 0; i < dealerCardCount; i++) {
		if (i == 1 && !dealerReveal) {
			printf("??? ");
		}
		else {
			printf("%s ", dealerCardList[i].printCard().c_str());
		}
	}
	printf(" ]\n");
}

// 플레이어 또는 딜러의 손패를 입력받아 카드 번호의 합을 반환하는 함수
int getCardSum(Card* userCardList, int userCardCount) {
	int aceCount = 0;
	int result = 0;
	for (int i = 0; i < userCardCount; i++) {
		if (userCardList[i].number == 1) {
			aceCount++;
			result += 11;
		}
		else {
			result += std::min(userCardList[i].number, 10);
		}
	}

	while (result > 21 && aceCount > 0) {
		aceCount--;
		result -= 10;
	}
	return result;
}

// 플레이어 또는 딜러의 (초기) 손패를 입력받아 블랙잭인지 반환하는 함수 
bool isBlackJack(Card* userCardList) {
	bool hasAce = false;
	bool hasTen = false;

	for (int i = 0; i < 2; i++) {
		if (userCardList[i].number == 1) {
			hasAce = true;
		}
		else if (std::min(userCardList[i].number, 10) == 10) {
			hasTen;
		}
	}

	return (hasAce && hasTen);
}

void Homework02_Run() {
	srand(time(0));
	printf("<< HOMEWORK 02 >>\n\n");
	printf("< 블랙잭 게임 >\n\n");

	int gameCount = 1;
	Card cardList[52];
	for (int i = 0; i < 52; i++) {
		cardList[i] = Card(i);
	}

	while (true) {
		int playerCardCount = 0, dealerCardCount = 0;
		int cardIndex = 0;
		Card playerCardList[52];
		Card dealerCardList[52];
		printf("┏━━━━━━━━━━━━━━┓\n");
		printf("┃ %2d 회차 게임 ┃\n", gameCount);
		printf("┗━━━━━━━━━━━━━━┛\n");
		shuffle(cardList, 52);

		// 게임 시작 전 플레이어와 딜러 모두 카드 2장 드로우
		drawCard(playerCardList, playerCardCount, cardList, cardIndex);
		drawCard(playerCardList, playerCardCount, cardList, cardIndex);
		drawCard(dealerCardList, dealerCardCount, cardList, cardIndex);
		drawCard(dealerCardList, dealerCardCount, cardList, cardIndex);

		// 받은 카드가 블랙잭인지 저장
		bool isPlayerBlackJack = isBlackJack(playerCardList);
		bool isDealerBlackJack = isBlackJack(dealerCardList);

		printf("< 플레이어의 턴 >\n\n");
		int playerCardSum = 0;
		while (true) {
			printGame(playerCardList, playerCardCount, dealerCardList, dealerCardCount, false);
			printf("\n[1] Hit(카드 1장 뽑기) / [2] Stand(턴 넘기기)\n");
			printf("선택하세요 : ");
			int playerChoice = 0; std::cin >> playerChoice;
			if (playerChoice == 1) {
				drawCard(playerCardList, playerCardCount, cardList, cardIndex);
				printf("\n%s 카드를 뽑았습니다.\n\n", playerCardList[playerCardCount - 1].printCard().c_str());
			}
			playerCardSum = getCardSum(playerCardList, playerCardCount);
			if (playerChoice == 2 || playerCardSum > 21) {
				break;
			}
		}

		// 카드 총합이 21을 초과하는 경우 버스트, 패배
		if (playerCardSum > 21) {
			printf("<×> 당신의 카드 총합이 21을 초과(버스트)하였습니다. 패배하였습니다. <×>\n");
			printf("[1] 다음 게임 진행하기 / [2] 게임 종료\n");
			printf("선택하세요 : ");
			int playerChoice = 0; std::cin >> playerChoice;
			gameCount++;
			printf("\n\n");
			if (playerChoice == 1) {
				continue;
			}
			else {
				break;
			}
		}

		printf("< 딜러의 턴 >\n\n");
		printGame(playerCardList, playerCardCount, dealerCardList, dealerCardCount, true);
		int dealerCardSum = getCardSum(dealerCardList, dealerCardCount);
		while (dealerCardSum < 17) {
			drawCard(dealerCardList, dealerCardCount, cardList, cardIndex);
			dealerCardSum = getCardSum(dealerCardList, dealerCardCount);
			printf("딜러가 %s 카드를 뽑았습니다.\n\n", dealerCardList[dealerCardCount - 1].printCard().c_str());
			printGame(playerCardList, playerCardCount, dealerCardList, dealerCardCount, true);
		}

		// 카드 총합이 21을 초과하는 경우 버스트, 승리
		if (dealerCardSum > 21) {
			printf("<☆> 딜러의 카드 총합이 21을 초과(버스트)하였습니다. 승리하였습니다! <☆>\n");
			printf("[1] 다음 게임 진행하기 / [2] 게임 종료\n");
			printf("선택하세요 : ");
			int playerChoice = 0; std::cin >> playerChoice;
			gameCount++;
			printf("\n\n");
			if (playerChoice == 1) {
				continue;
			}
			else {
				break;
			}
		}

		if (playerCardSum == dealerCardSum) {
			// 카드 총합이 양쪽 모두 21인 경우, 블랙잭 여부로 승패 가르기
			if (playerCardSum == 21) {
				if (isPlayerBlackJack && isDealerBlackJack) {
					printf("<▣> 플레이어 블랙잭, 딜러 블랙잭 입니다. 무승부입니다. <▣>\n");
				}
				else if (isPlayerBlackJack) {
					printf("<☆> 플레이어의 블랙잭 입니다. 승리하였습니다! <☆>\n");
				}
				else if (isDealerBlackJack) {
					printf("<×> 딜러의 블랙잭 입니다. 패배하였습니다. <×>\n");
				}
			}
			printf("<▣> 플레이어와 딜러의 카드 총합이 같습니다. 무승부입니다. <▣>\n");
		}
		else if (playerCardSum > dealerCardSum) {
			printf("<☆> 플레이어의 점수 : [%d] / 딜러의 점수 : [%d] 입니다. 승리하였습니다! <☆>\n", playerCardSum, dealerCardSum);
		}
		else {
			printf("<×> 플레이어의 점수 : [%d] / 딜러의 점수 : [%d] 입니다. 패배했습니다. <×>\n", playerCardSum, dealerCardSum);
		}
		printf("[1] 다음 게임 진행하기 / [2] 게임 종료\n");
		printf("선택하세요 : ");
		int playerChoice = 0; std::cin >> playerChoice;
		gameCount++;
		printf("\n\n");
		if (playerChoice == 1) {
			continue;
		}
		else {
			break;
		}
	}
}

