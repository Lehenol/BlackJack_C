#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <Windows.h>

#define ERROR_MSG SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); \
				printf("잘못된 입력입니다. 다시 입력해주세요.\n"); \
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  //에러메시지 매크로

char CARD[52][4] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", \
		"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", \
		"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", \
		"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" }; //스(0~12)다(13~25)하(26~38)클(39~51)

void start(), rule();
int rule_confirm(char YN);
int isBlackJack(int d, int p);
int hitOrStand();

int main()
{
	int n;
	printf("<----Black Jack---->\n\n");
	printf("1. 게임시작\n");
	printf("2. 게임방법\n");
	printf("3. 게임종료\n");
	printf("번호를 입력해주세요: ");
	scanf("%d", &n);

	do {
		if (n == 1) start();
		else if (n == 2) rule();
		else if (n == 3) exit(0);
		else ERROR_MSG;
	} while (n > 3 || n < 1);
}

void start()
{
	int sum_d = 0, sum_p = 0;
	int Round = 1, round_D = 1, round_P = 1, is_Stand = 0, result = 0;
	char dealCard[11][4], playCard[11][4];
	srand((unsigned)time(NULL));

	
}

void rule()  //규칙
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);  //텍스트색 노란색으로 변경

	printf("\n■ 플레이 방법\n");
	printf("1. 딜러와 플레이어 모두에게 먼저 2장씩 카드를 받는다.\n");
	printf("2. 자신이 갖고 있는 카드의 합이 21에 가까워지도록 카드를 추가하거나 카드 유지(스탠드:Stand)를 선택할 수 있다.\n");
	printf("3. 카드의 합이 21을 넘어버린 시점(버스트:Bust)에서 패배가 결정된다.\n");
	printf("4. 플레이어는 21을 초과하지 않는 한 원하는만큼 카드를 추가할 수 있다.\n");
	printf("5. 딜러는 카드의 합이 17을 초과할 때까지 카드를 추가한다.\n\n");
	printf("■ 카드의 숫자\n");
	printf("- A = 1\n");
	printf("- 2~10 = 2~10\n");
	printf("- J, Q, K = 11\n\n");
	printf("■ 용어\n");
	printf("- 히트(Hit) : 카드 한 장 추가\n");
	printf("- 스탠드(Stand) : 카드 유지 ( 현재의 수치로 딜러와 승부)\n");
	printf("- 서렌더(Surrender) : 항복\n");
	printf("- 버스트(Bust) : 카드의 합이 22 이상이 되는 것 (이 시점에서 패배 결정)\n");
	printf("- 푸쉬(Push) : 무승부\n");
	printf("- 블랙잭(BLACKJACK) : 받은 카드 2장의 합이 21이 되는 것. 승리의 배당 1.5배\n\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  //텍스트색 흰색으로 변경

	char YN;
	do {
		printf("게임을 시작하시겠습니까? ( Y / N ) ");
		scanf(" %c", &YN);
		if (YN == 'Y' || YN == 'y') start();
		else if (YN == 'N' || YN == 'n') exit(0);
	} while (YN != 'Y' && YN != 'N' || YN != 'y' && YN != 'n');
}