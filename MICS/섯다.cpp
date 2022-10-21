#include "����.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

void SetUpGame(Card cards[20])
{
	// ī�� ������ ����
	for (int i = 0; i < 10; i++)
	{
		cards[i].num = i + 1;
		cards[i].is_special = false;

		cards[i + 10].num = i + 1;
		cards[i + 10].is_special = true;
	}
	ShuffleCards(cards);

	// �ʱ�ȭ
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

	// �������� ����
	if (card_1.num > card_2.num)
	{
		Card temp = card_1;
		card_1 = card_2;
		card_2 = temp;
	}

	// ���� üũ
	if (card_1.is_special == true && card_2.is_special == true)
	{
		if (card_1.num == 3 && card_2.num == 8)
			user->ranking = ����38;
		if (card_1.num == 1 && card_2.num == 8)
			user->ranking = ����18; 
		if (card_1.num == 1 && card_2.num == 3)
			user->ranking = ����13;

		if (user->ranking != -1) return;
	}
	// �� üũ
	if (card_1.num == card_2.num)
	{
		user->ranking = �� + card_1.num;
		return;
	}
	// �߰�����
	if (card_1.num == 1)
	{
		if (card_2.num == 2)user->ranking = �˸�;
		if (card_2.num == 4)user->ranking = ����;
		if (card_2.num == 9)user->ranking = ����;
		if (card_2.num == 10)user->ranking = ���;
		if (user->ranking != -1) return;
	}

	if (card_1.num == 4)
	{
		if (card_2.num == 10)user->ranking = ���;
		if (card_2.num == 2)user->ranking = ����;
		if (user->ranking != -1) return;
	}
	//  Ư������
	{
		if(card_1.is_special==true&&card_2.is_special==true)
		{
			if (card_1.num == 4 && card_2.num == 7) user->ranking = ������;
			if (card_1.num == 3 && card_2.num == 7) user->ranking = ������;
			if (card_1.num == 4 && card_2.num == 9) user->ranking = ���ֱ�������;
		}
		else if (card_1.num == 4 && card_2.num == 9) user->ranking = ����;

		if (user->ranking != -1) return;
	}
	// ��
	user->ranking = (card_1.num + card_2.num) % 10;
}

void MainGame()
{
	// ���� ����
	Card cards[20];
	User users[2];
	int max_ranking = 0;

	SetUpGame(cards);

	users[0].cards[0] = cards[0];
	users[0].cards[1] = cards[1];

	users[1].cards[0] = cards[2];
	users[1].cards[1] = cards[3];

	// ���� üũ
	Calculation_Ranking(&users[0]);
	Calculation_Ranking(&users[1]);

	// Ư�� ����ó��
	Special(&users[0], &users[1]);
	Special(&users[1], &users[0]);

	// �¸� Ȥ�� ���� ó��
	{
		int winner = users[0].ranking > users[1].ranking ? 0 : 1;
		if (users[0].ranking == users[1].ranking) winner = -1;

		int wr = winner != -1 ? users[winner].ranking : -1;

		if (wr == ���ֱ������� || wr == ����)
			printf("����!!\n");
		else
			printf("%d��° ������ �¸�!\n", winner + 1);
	}

	// ���� ��ŷ �� ���
	printf("1�� :%d\n", users[0].ranking);
	printf("2�� :%d\n", users[1].ranking);

	system("pause");
}

void Special(User*my, User* other)
{
	if (my->ranking / Ư�� == 1)
	{
		int my_ranking = my->ranking;
		int other_ranking = other->ranking;

		if (my_ranking == ������)
			if (other_ranking == ����13 || ���� == ����18) {}
			else my->ranking = ��1;

		if (my_ranking == ������)
			if (other_ranking / �� == 1 && other_ranking != ��10) {}
			else my->ranking = ����;

		if (my_ranking == ���ֱ�������)
			if (other_ranking <= ��9 || other_ranking / Ư�� == 1) {}
			else my->ranking = ��3;

		if (my_ranking == ����)
			if (other_ranking <= �˸� || other_ranking / Ư�� == 1) {}
			else my-> ranking = ��3;
	}
}
