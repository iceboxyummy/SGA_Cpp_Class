 // 01_stl_and_container.cpp

/*
	STL
	 - 珍砺戚格(Container), 鋼差切(iterator), 硝壱軒葬(algorithm)戚 匂敗鞠嬢赤陥.
	    * 珍砺戚格(Container) : 績税 展脊税 汽戚斗研 左淫拝 呪 赤陥.
	    * 鋼差切(iterator) : 珍砺戚格拭 左淫吉 据社拭 羨悦拝 凶 紫遂廃陥.
	    * 硝壱軒葬(algorithm) : 鋼差切級聖 亜走壱 析恵税 拙穣聖 呪楳廃陥.
	 - 奴巴鹸聖 紫遂馬食 嬢彊廃 展脊税 汽戚斗亀 是税 虞戚崎君軒 奄管聖 紫遂拝 呪 赤陥.
	  => 切戟莫聖 析鋼鉢馬食 坪球税 呪舛蒸戚 疑析廃 拙穣聖 呪楳拝 呪 赤惟 背層陥.

*/

/*
	珍砺戚格(Container) : 疑析廃 展脊税 食君 梓端研 煽舌馬澗 増杯, 煽舌社研 源廃陥.
	 - 奴巴鹸聖 紫遂背 煽舌馬澗 汽戚斗税 切戟莫拭 巷淫馬惟 巷譲戚窮 拝 呪赤惟 幻級嬢閃 赤陥.
	 - 3亜走 曽嫌税 珍砺戚格稽 戚欠嬢閃 赤陥.
*/

#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<string>
#include<stack>
#include<queue>
using namespace std;

void Sequence_Container();
void Associative_Container();
void Container_Adapter();

int main() { 
	Sequence_Container();
	Associative_Container();
	Container_Adapter();

	return  0;
}

void Sequence_Container()
{
	// SequenceContainer : 壕伸坦軍 汽戚斗研 識莫生稽 煽舌馬澗 珍砺戚格, 働紺廃 鋭帳戚蟹 薦鉦蒸戚 据社研 左淫廃陥.

	/*
		Vector : 亜痕 掩戚 壕伸, 疑旋 壕伸聖 奴巴鹸鉢廃 依
		 - 据社亜 叔薦 五乞軒拭 授託旋生稽 煽舌鞠嬢赤嬢 尻紗旋昔 汽戚斗研 坦軒馬奄拭 政軒馬陥.
		 - 績税 羨悦聖 薦因廃陥. [], at()
		 - 拝雁吉 因娃聖 陥 辰頗聖 井酔, 歯稽錘 笛 因娃聖 疑旋生稽 仙拝雁馬食 奄糎税 据社級聖 差紫廃陥.
		 - 固 及拭 据社研 諮脊, 肢薦拝凶澗 匙牽蟹. 
		   績税税 是帖拭 赤澗 据社研 諮脊, 肢薦馬澗 井酔, 益 及税 据社研 廃牒梢 戚疑獣佃爽嬢醤 馬奄 凶庚拭 汗軒陥.

		  * 紫遂馬奄 疏精 井酔
		   - 滴奄研 森著戚 亜管拝 凶
		   - 諮脊, 肢薦亜 紺稽 蒸聖 凶
		   - 尻紗旋昔 汽戚斗 坦軒亜 琶推拝 凶 
	*/

	{
		vector<int> vec; // template戚悟 template 適掘什稽 幻級嬢遭 梓端(壕伸坦軍 尻紗旋昔 五乞軒研 亜走壱 赤製)

		for (int i = 0; i < 10; i++)
			vec.push_back(i);

		for (const auto& ele : vec)
			cout << ele << ' ';
		cout << endl;
	}

	/*
		Dequeue : 拷斗人 搾汁馬蟹 据社亜 五乞軒 因娃拭 尻紗旋生稽 糎仙 馬走 省澗陥.
		 - 五乞軒研 仙拝雁拝 凶, 蓄亜稽 五乞軒 因娃聖 幻級嬢 轄軒旋生稽 戚嬢細昔陥. -> 汽戚斗拝雁戚 匙牽陥
		 - 辞稽 恭嬢閃赤澗 五乞軒 因娃税 舛左研 左淫馬奄 是背 困斗左陥 蓄亜旋昔 五乞軒亜 琶推馬陥.
		 - 績税税 是帖拭 赤澗 据社税 諮脊, 肢薦亜 困斗左陥 匙牽陥.
		 - 績税 羨悦聖 薦因廃陥. [], at()

		   * 紫遂馬奄 疏聖 凶
		    - 伍 蒋引 固 及税 据社研 諮脊, 肢薦馬澗 井酔亜 弦精 井酔
			- 困斗坦軍 紫遂馬壱 粛走幻 滴奄亜 森著戚 照鞠澗 井酔
	*/

	{
		deque<int> deq;

		for (int i = 0; i < 10; i++)
		{
			deq.push_back(i);
			deq.push_front(i);
		}

		for (const auto& ele : deq)
			cout << ele << ' ';
		cout << endl;
	}

	/*
		List : 丞号狽 尻衣軒什闘研 奴巴鹸鉢
		 - 軒什闘澗 獣拙 据社税 爽社人 原走厳 据社税 是帖幻聖 奄常廃陥.
		 - 唖唖税 据社亜 切重税 蒋引 及拭 神澗 据社研 亜軒徹壱 赤陥.
		 - 姥繕森獣 
		     ->, <- 澗 匂昔斗稽 蒋引 及税 据社税 爽社研 煽舌馬壱 赤陥.

				けけけ        けけけ        けけけ
				け据け   ->   け据け   ->   け据け  
				け社け        け社け        け社け
				け1 け   <-   け2 け   <-   け3 け 
				けけけ        けけけ        けけけ

		 - 是税 姥繕研 亜走壱赤嬢 績税税 是帖拭 赤澗 据社拭 郊稽 羨悦戚 照鞠壱 授託旋生稽 羨悦背醤廃陥.
		 - 据社税 諮脊 肢薦亜 析嬢劾 井酔 元滴幻 郊荷嬢爽檎 鞠奄拭 諮脊 肢薦亜 匙牽陥.

		   * 紫遂馬奄 疏聖��
		     - 据社税 諮脊, 肢薦亜 朔腰馬惟 戚欠嬢霜凶
			 - 据社級聖 授託旋生稽幻 羨悦拝��
	*/

	{
		list<int> list;

		for (int i = 0; i < 10; i++)
			list.push_back(i);


		for (const auto& ele : list)
			cout << ele << ' ';
		cout << endl;
	}
}

void Associative_Container()
{
	/*
		associactive container : 汽戚斗研 析舛廃 鋭帳拭 魚虞 煽舌馬壱 淫軒馬澗 珍砺戚格
		 - 煽舌廃 推社税 是帖研 走舛拝 呪 蒸壱 液莫 戚遭 闘軒蟹 背獣砺戚鷺聖 戚遂馬食 姥薄廃陥.
		 - 据社研 諮脊拝 井酔 切曽生稽 走舛背爽奄 凶庚拭 据馬澗 据社研 達澗 伊事 紗亀亜 匙牽陥.
		 - 徹(key) - 葵(value) 姥繕研 亜閃 働舛廃 徹葵聖 隔生檎 企誓馬澗 葵聖 宜形層陥.
	*/

	/*
		set引 multiset : 煽舌馬澗 汽戚斗葵 益 切端研 徹稽 紫遂廃陥.
		 - 砺戚斗税 糎仙政巷 幻 端滴馬澗井酔 紫遂廃陥.
	*/

	// set : 徹税 掻差聖 買遂馬走 省澗陥.
	{
		set<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");
		str_set.insert("World");

		// 砧 鯵亜 窒径吉陥.
		//  set精 掻差聖 買遂馬走 省奄 凶庚拭 掻差吉 汽戚斗研 諮脊拝 井酔 巷獣廃陥.
		cout << str_set.size() << endl;

		for (const auto& ele : str_set)
			cout << ele << ' ';
		cout << endl;
	}

	// multiset : 徹税 掻差聖 買遂廃陥
	{
		multiset<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");
		str_set.insert("World");

		cout << str_set.size() << endl;

		for (const auto& ele : str_set)
			cout << ele << ' ';
		cout << endl;		
	}

	/*
		map引 multimap : 徹人 葵生稽 汽戚斗研 淫軒廃陥.
		 - map精 掻差聖 買遂馬走 省走幻 multimap精 掻差聖 買遂背 馬蟹税 徹亜 食君 葵引 尻衣吃 呪 赤陥.
	*/

	// map : key / value - pair
	{
		map<char, int> map; // mapping : 企誓獣轍陥.
		map['c'] = 50;
		map['a'] = 10;
		map['d'] = 40;
		map['b'] = 20;

		cout << map['a'] << endl; // 徹葵拭 古芭吉 葵 10窒径

		map['a'] = 100;
		cout << map['a'] << endl; // 歯稽錘 葵生稽 段奄鉢 廃陥.

		for (const auto& ele : map)
			cout << ele.first << ' ' << ele.second << ' ';
		cout << endl;
	}

	// multimap
	{
		multimap<char, int>multimap;
		multimap.insert(pair<char, int>('a', 10));
		multimap.insert(pair<char, int>('b', 100));
		multimap.insert(pair<char, int>('a', 10000));
		// multimap.insert(pair('c', 500));  c++17拭辞澗 展脊 持繰亜管

		cout << multimap.count('a') << endl;

		for (const auto& ele : multimap)
			cout << ele.first << ' ' << ele.second << ' ';
		cout << endl;
	}

	/*
		unordered associative container : 舛慶鞠走 省精 尻淫 珍砺戚格
		- 是税 尻淫 珍砺戚格澗 闘軒研 紫遂馬走幻 舛慶鞠走 省精 据社研 煽舌拝 凶 背獣 砺戚鷺聖 紫遂廃陥.
		- 諮脊, 肢薦, 伊事 乞砧 匙牽陥.
		
		- unordered_set
		- unordered_multiset
		- unordered_map
		- unordered_multimap
	*/
}

void Container_Adapter()
{
	/*
		adapter container : 奄糎 珍砺戚格税 昔斗凪戚什研 薦廃馬食 幻級嬢 奄管戚 薦廃鞠暗蟹 痕莫吉 珍砺戚格
		 - 唖唖税 奄段亜 鞠澗 適掘什 昔斗凪戚什研 薦廃馬悟, 働舛莫殿税 疑拙幻聖 呪楳馬亀系廃陥.
		 - 鋼差切研 走据馬走 省焼 stl 硝壱軒葬 紫遂戚 照吉陥.
	*/

	/*
		Stack : 識莫生稽 汽戚斗研 煽舌馬壱 板脊識窒(LIFO)

		Last In First Out : 亜舌 原走厳拭 煽舌吉 汽戚斗亜 亜舌 胡煽 蟹紳陥.
	*/

	// Stack
	{
		cout << "Stack" << endl;

		stack<int>stack;

		stack.push(1);
		stack.push(2); // 差紫背辞 蓄亜
		stack.emplace(3); // 歯罫惟 持失馬食 汽戚斗研 蓄亜

		cout << stack.top() << endl; // 置雌舘拭 赤澗 汽戚斗拭 羨悦廃陥.
		stack.pop(); // 置雌舘拭 赤澗 汽戚斗研 薦暗廃陥
		cout << stack.top() << endl;
		cout << stack.top() << endl;
	}

	/*
		 Queue : 識莫生稽 汽戚斗研 煽舌馬壱 識脊識窒(FIFO)聖 魚献陥.

		 First In First Out : 亜舌 胡煽 煽舌吉 汽戚斗亜 亜舌 胡煽 蟹紳陥.
	*/

	// Queue
	{
		cout << "Queue" << endl;

		queue<int> queue;
		queue.push(1);
		queue.push(1);
		queue.push(1);

		// 1 2 3
		cout << queue.front() << ' ' << queue.back() << endl;
		queue.pop();

		// 2 3 
		cout << queue.front() << ' ' << queue.back() << endl;
	}

	/*
		Priority Queue (酔識授是 泥) : 酔識授是拭 魚虞 汽戚斗研 舛慶背層陥.
		 - 泥人澗 陥牽惟 亜舌 酔識 授是亜 株精 据社亜 薦析 胡煽 蟹神惟 吉陥.
	*/
	{
		cout << "Priotiry queue" << endl;

		//priority_queue<int> priority_queue;
		priority_queue<int, vector<int>, greater<int>> priority_queue;

		for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
			priority_queue.push(n);

		for (int i = 0; i < 10; i++)
		{
			cout << priority_queue.top() << endl;
			priority_queue.pop();
		}
	}
}