#include<iostream>
#include"SmartPtr.h"
#include<list>

struct Data
{
	Data(const int year, const int month, const int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	int _year;
	int _month;
	int _day;
};

template<class T>
class ListNode
{
public:
	ListNode(const T& val = 0)
		:_val(val)
		, _next(nullptr)
		, _prev(nullptr)
	{}
public:
	T _val;
	my::share_ptr<ListNode<T>> _next;
	my::share_ptr<ListNode<T>> _prev;
};

int main()
{
	//my::auto_ptr<int> sp1(new int);
	//*sp1 = 10;
	//cout << *sp1 << endl;
	//my::auto_ptr<Data> sp1(new Data(1, 1, 1));
	//(*sp1)._day = 2;
	//sp1->_month = 2;
	//my::auto_ptr<int> sp1(new int(1));
	//my::auto_ptr<int> sp2(sp1);

	//my::auto_ptr<int> sp3(new int(3));
	//sp3 = sp2;

	//my::share_ptr<int> sp1(new int(1));
	//my::share_ptr<int> sp2(sp1);

	//my::share_ptr<int> sp3(new int(10));
	//sp3 = sp1;



	//int n = 10000;
	//my::share_ptr<int> sp = new int;
	//cout << sp.use_count() << endl;
	//thread t1([&]()
	//	{
	//		for (int i = 0; i < n; i++)
	//		{
	//			my::share_ptr<int> tmp(sp);
	//		}
	//	});

	//thread t2([&]()
	//	{
	//		for (int i = 0; i < n; i++)
	//		{
	//			my::share_ptr<int> tmp(sp);
	//		}
	//	});

	//t1.join();
	//t2.join();

	//cout << sp.use_count() << endl;



	my::share_ptr<ListNode<int>> sp1(new ListNode<int>);
	my::share_ptr<ListNode<int>> sp2(new ListNode<int>);

	//sp1->_next = sp2;
	//sp2->_prev = sp1;

	return 0;
}