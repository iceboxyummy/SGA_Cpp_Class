#pragma once

/*
	1. 墨靛甫 集绰促.
	2. 墨靛甫 蜡历啊 阿阿 滴厘 究 惶绰促.
	3. 惶篮 墨靛狼


	漂荐 练焊 贸府 窃荐
	鞘夸茄巴
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
	// 堡动
	堡动=10000,
	堡动13,
	堡动18,
	堡动38,

	// 嫰
	动 =1000,
	动1,
	动2,
	动3,
	动4,
	动5,
	动6,
	动7,
	动8,
	动9,
	动10,

	// 吝埃
	吝埃 =100,
	技氟,
	厘荤,
	厘绘,
	备绘,
	刀荤,
	舅府,

	// 昌

	昌 = 0,
	噶烹=0,
	昌1,
	昌2,
	昌3,
	昌4,
	昌5,
	昌6,
	昌7,
	昌8,
	昌9,

	// 漂荐 
	漂荐 =100000,
	鞠青绢荤,		// 13 18 墨款磐
	动棱捞,			// 1动 ~ 9动 墨款磐
	港胖备府备荤,		// 9动 犁版扁
	备荤				// 舅府捞窍 犁版扁
};
