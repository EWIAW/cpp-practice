#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;

void set_test1()
{
	set<int> s;
	s.insert(10);
	s.insert(2);
	s.insert(87);
	s.insert(56);
	s.insert(2);

	s.erase(2);
	set<int>::iterator a = s.find(56);
	if (a != s.end())
	{
		s.erase(a);
	}

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void map_test1()
{
	map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(pair<int, int>(2, 2));
	m.insert(pair<int, int>(3, 3));

	map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ":" << it->second << endl;;
		it++;
	}
	cout << endl;

	for (auto& e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void map_test2()
{
	map<string, string> m;
	m.insert(make_pair("sort", "排序"));
	m.insert(make_pair("first", "第一个"));
	m.insert(make_pair("rjk", "阮靖凯"));

	for (auto& e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void map_test3()
{
	map<string, int> Count;
	string str[] = { "西瓜","苹果","香蕉","西瓜", "西瓜", "西瓜", "西瓜","苹果","苹果","苹果" };
	for (auto& e : str)
	{
		map<string, int>::iterator it = Count.find(e);
		if (it == Count.end())
		{
			Count.insert(make_pair(e, 1));
		}
		else
		{
			it->second++;
		}
	}

	for (auto& e : Count)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void map_test4()
{
	string str[] = { "西瓜","苹果","香蕉","西瓜", "西瓜", "西瓜", "西瓜","苹果","苹果","苹果" };
	map<string, int> m;
	for (auto& e : str)
	{
		m[e]++;
	}

	for (auto& e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void map_test5()
{
	//oprerator[]
	//通过key值查找对应的val，
	//如果没有，则插入，并返回对应val的引用
	//如果有，则直接返回对应val的引用
	//其底层实现是通过insert来完成的
	//(*((this->insert(make_pair(k,mapped_type()))).first)).second	其底层实现
	//所以operator[]有一下的功能
	//1.可以插入（如果对应的key存在，则插入新可以）
	//2.可以修改（可以修改对应key映射的val）
	//3.可以插入+修改
	//4.可以查找（不推荐）（因为如果不存在，就会进行插入）

	//insert
	//insert是通过给一个pair来进行插入数据
	//返回值也是一个pair，其pair的内容为iterator，bool
	//如果map中没有，则进行插入，返回的pair中，iterator指向新插入的结点，bool为true
	//如果map中有，则不插入，返回的pair中，iterator指向已存在的结点，bool为false
	string str[] = { "西瓜","苹果","香蕉","西瓜", "西瓜", "西瓜", "西瓜","苹果","苹果","苹果" };
	map<string, int> m;
	for (auto& e : str)
	{
		m[e]++;
	}
}

int main()
{
	//set_test1();
	//map_test1();
	//map_test2();
	map_test3();
	return 0;
}