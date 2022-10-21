#pragma once

/*
	1. ī�带 ���´�.
	2. ī�带 ������ ���� ���� �� �̴´�.
	3. ���� ī����


	Ư�� ���� ó�� �Լ�
	�ʿ��Ѱ�
*/

struct Card
{
	int num;
	bool is_special;
};

struct User
{
	Card cards[2];
	int ranking;
};

void SetUpGame(Card cards[20]);
void ShuffleCards(Card cards[20]);
void Calculation_Ranking(User* user);
void MainGame();
void Special(User* my, User* other);

enum ranking
{
	// ����
	����=10000,
	����13,
	����18,
	����38,

	// ��
	�� =1000,
	��1,
	��2,
	��3,
	��4,
	��5,
	��6,
	��7,
	��8,
	��9,
	��10,

	// �߰�
	�߰� =100,
	����,
	���,
	���,
	����,
	����,
	�˸�,

	// ��

	�� = 0,
	����=0,
	��1,
	��2,
	��3,
	��4,
	��5,
	��6,
	��7,
	��8,
	��9,

	// Ư�� 
	Ư�� =100000,
	������,		// 13 18 ī����
	������,			// 1�� ~ 9�� ī����
	���ֱ�������,		// 9�� ����
	����				// �˸����� ����
};
