#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void print_list(const list<int>& l)
{
	list<int>::const_iterator cit = l.begin();
	while (cit != l.end())
	{
		cout << *cit << " ";
		cit++;
	}
	cout << endl;
}

//构造函数	赋值=重载
void Test1()
{
	list<int> l1;//构造函数
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);

	print_list(l1);

	const list<int> l2(l1);//拷贝构造
	print_list(l2);

	list<int> l3;
	l3 = l2;//赋值=重载
	print_list(l3);
}

//迭代器
void Test2()
{
	//四种迭代器		正向、反向、const、非const
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	cout << l1.size() << endl;

	//正向非const
	list<int>::iterator it = l1.begin();
	while (it != l1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//反向非const
	list<int>::reverse_iterator rit = l1.rbegin();
	while (rit != l1.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	//正向const
	list<int>::const_iterator cit = l1.begin();
	while (cit != l1.end())
	{
		cout << *cit << " ";
		cit++;
	}
	cout << endl;

	//反向const
	list<int>::const_reverse_iterator crit = l1.rbegin();
	while (crit != l1.rend())
	{
		cout << *crit << " ";
		crit++;
	}
	cout << endl;
}

//插入
void Test3()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_front(0);
	l1.push_front(-1);
	l1.push_front(-2);
	l1.insert(l1.end(), 5);//-2 -1 0 1 2 3 4 5

	list<int>::iterator pos = find(l1.begin(), l1.end(), 3);

	l1.insert(pos, 100);

	cout << *pos << endl;

	print_list(l1);
}

//删除
void Test4()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);

	list<int>::iterator pos = find(l1.begin(), l1.end(), 3);
	l1.erase(pos);;

	print_list(l1);
}

class Date
{
	friend ostream& operator<<(ostream& out, Date& d);
public:
	explicit Date(int year = 0, int month = 0, int day = 0)
		:_year(year)
		, _month(month)
		, _day(day)
	{

	}

//private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day;
	return out;
}

void Test5()
{
	list<Date> l1;
	Date(2024, 1, 1);
	l1.push_back(Date(2024, 4, 11));
	l1.push_back(Date(2024, 4, 12));
	l1.push_back(Date(2024, 4, 13));
	l1.push_back(Date(2024, 4, 14));

	list<Date>::iterator it = l1.begin();
	while (it != l1.end())
	{
		cout << (*it) << endl;
		it++;
	}
	cout << endl;
}

int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	Test5();
	return 0;
}