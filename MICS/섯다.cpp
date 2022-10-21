#include "¼¸´Ù.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

void SetUpGame(Card cards[20])
{
	// Ä«µå µ¥ÀÌÅÍ ¼¼ÆÃ
	for (int i = 0; i < 10; i++)
	{
		cards[i].num = i + 1;
		cards[i].is_special = false;

		cards[i + 10].num = i + 1;
		cards[i + 10].is_special = true;
	}
	ShuffleCards(cards);

	// ÃÊ±âÈ­
	srand((unsigned int)time(NULL));
	system("cls");
}

void ShuffleCards(Card cards[20])
{
	for (int i = 0; i < 100; i++)
	{
		int a, b;
		a = rand() % 20;
		b = rand() % 20;

		Card temp = cards[a];
		cards[a] = cards[b];
		cards[b] = temp;
	}
}

void Calculation_Ranking(User* user)
{
	Card card_1 = user->cards[0];
	Card card_2 = user->cards[1];
	user->ranking = -1;

	// ¿À¸§Â÷¼ø Á¤·Ä
	if (card_1.num > card_2.num)
	{
		Card temp = card_1;
		card_1 = card_2;
		card_2 = temp;
	}

	// ±¤¶¯ Ã¼Å©
	if (card_1.is_special == true && card_2.is_special == true)
	{
		if (card_1.num == 3 && card_2.num == 8)
			user->ranking = ±¤¶¯38;
		if (card_1.num == 1 && card_2.num == 8)
			user->ranking = ±¤¶¯18; 
		if (card_1.num == 1 && card_2.num == 3)
			user->ranking = ±¤¶¯13;

		if (user->ranking != -1) return;
	}
	// ¶¯ Ã¼Å©
	if (card_1.num == card_2.num)
	{
		user->ranking = ¶¯ + card_1.num;
		return;
	}
	// Áß°£Á·º¸
	if (card_1.num == 1)
	{
		if (card_2.num == 2)user->ranking = ¾Ë¸®;
		if (card_2.num == 4)user->ranking = µ¶»ç;
		if (card_2.num == 9)user->ranking = ±¸»æ;
		if (card_2.num == 10)user->ranking = Àå»æ;
		if (user->ranking != -1) return;
	}

	if (card_1.num == 4)
	{
		if (card_2.num == 10)user->ranking = Àå»ç;
		if (card_2.num == 2)user->ranking = ¼¼·ú;
		if (user->ranking != -1) return;
	}
	//  Æ¯¼öÁ·º¸
	{
		if(card_1.is_special==true&&card_2.is_special==true)
		{
			if (card_1.num == 4 && card_2.num == 7) user->ranking = ¾ÏÇà¾î»ç;
			if (card_1.num == 3 && card_2.num == 7) user->ranking = ¶¯ÀâÀÌ;
			if (card_1.num == 4 && card_2.num == 9) user->ranking = ¸ÛÅÖ±¸¸®±¸»ç;
		}
		else if (card_1.num == 4 && card_2.num == 9) user->ranking = ±¸»ç;

		if (user->ranking != -1) return;
	}
	// ²ı
	user->ranking = (card_1.num + card_2.num) % 10;
}

void MainGame()
{
	// °ÔÀÓ ¼¼ÆÃ
	Card cards[20];
	User users[2];
	int max_ranking = 0;

	SetUpGame(cards);

	users[0].cards[0] = cards[0];
	users[0].cards[1] = cards[1];

	users[1].cards[0] = cards[2];
	users[1].cards[1] = cards[3];

	// Á·º¸ Ã¼Å©
	Calculation_Ranking(&users[0]);
	Calculation_Ranking(&users[1]);

	// Æ¯¼ö Á·º¸Ã³¸®
	Special(&users[0], &users[1]);
	Special(&users[1], &users[0]);

	// ½Â¸® È¤Àº Àç´ë°á Ã³¸®
	{
		int winner = users[0].ranking > users[1].ranking ? 0 : 1;
		if (users[0].ranking == users[1].ranking) winner = -1;

		int wr = winner != -1 ? users[winner].ranking : -1;

		if (wr == ¸ÛÅÖ±¸¸®±¸»ç || wr == ±¸»ç)
			printf("Àç´ë°á!!\n");
		else
			printf("%d¹øÂ° À¯Àú°¡ ½Â¸®!\n", winner + 1);
	}

	// À¯Àú ·©Å· °ª Ãâ·Â
	printf("1¹ø :%d\n", users[0].ranking);
	printf("2¹ø :%d\n", users[1].ranking);

	system("pause");
}

void Special(User*my, User* other)
{
	if (my->ranking / Æ¯¼ö == 1)
	{
		int my_ranking = my->ranking;
		int other_ranking = other->ranking;

		if (my_ranking == ¾ÏÇà¾î»ç)
			if (other_ranking == ±¤¶¯13 || ±¤¶¯ == ±¤¶¯18) {}
			else my->ranking = ²ı1;

		if (my_ranking == ¶¯ÀâÀÌ)
			if (other_ranking / ¶¯ == 1 && other_ranking != ¶¯10) {}
			else my->ranking = ¸ÁÅë;

		if (my_ranking == ¸ÛÅÖ±¸¸®±¸»ç)
			if (other_ranking <= ¶¯9 || other_ranking / Æ¯¼ö == 1) {}
			else my->ranking = ²ı3;

		if (my_ranking == ±¸»ç)
			if (other_ranking <= ¾Ë¸® || other_ranking / Æ¯¼ö == 1) {}
			else my-> ranking = ²ı3;
	}
}
