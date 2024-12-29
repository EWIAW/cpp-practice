//#include<iostream>
//#include"SmartPtr.h"
//#include<list>
//#include<mutex>
//#include<memory>
//using namespace std;
//
//struct Data
//{
//	Data(const int year, const int month, const int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	~Data()
//	{
//		cout << "delete" << endl;
//	}
//
//	int _year;
//	int _month;
//	int _day;
//};
//
//template<class T>
//class ListNode
//{
//public:
//	ListNode(const T& val = 0)
//		:_val(val)
//		, _next(nullptr)
//		, _prev(nullptr)
//	{}
//
//	~ListNode()
//	{
//		cout << "delete" << endl;
//	}
//public:
//	T _val;
//	my::weak_ptr<ListNode<T>> _next;
//	my::weak_ptr<ListNode<T>> _prev;
//};
//
//template<class T>
//struct DeleteArray
//{
//	void operator()(T* ptr)
//	{
//		delete[] ptr;
//	}
//};
//
//template<class T>
//struct Free
//{
//	void operator()(T* ptr)
//	{
//		cout << "free" << endl;
//		free(ptr);
//	}
//};
//
//class A
//{
//public:
//	A(const int val = 0)
//		:_val(val)
//	{}
//
//	~A()
//	{
//		cout << "delete" << endl;
//	}
//private:
//	int _val;
//};
//
//class LockGuard
//{
//public:
//	LockGuard(mutex& mtx)
//		:_mtx(mtx)
//	{
//		_mtx.lock();
//	}
//
//	~LockGuard()
//	{
//		_mtx.unlock();
//	}
//private:
//	mutex& _mtx;
//};

/*
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



	//int n = 1000000;
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



	//my::weak_ptr<ListNode<int>> sp1(new ListNode<int>);
	//my::weak_ptr<ListNode<int>> sp2(new ListNode<int>);

	//sp1->_next = sp2;
	//sp2->_prev = sp1;



	//shared_ptr<A> sp1(new A);
	//shared_ptr<A> sp2(new A[10],DeleteArray<A>());
	//shared_ptr<A> sp3((A*)malloc(sizeof(A)), [](A* ptr) {
	//	free(ptr);
	//	});

	mutex mtx;
	LockGuard lock(mtx);

	return 0;
}
*/

#include <iostream>
#include "Blog_SmartPtr.h"
using namespace blog_smartptr;

//void Div()
//{
//	int x, y;
//	cin >> x >> y;
//	if (y == 0)
//		throw invalid_argument("除数为0");
//	else
//		cout << x / y << endl;
//}
//
//void Func()
//{
//	SmartPtr<int> sp(new int(10));
//	Div();
//}
//
//void Test1()
//{
//	try
//	{
//		Func();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//}

template<class T>
class SmartPtr
{
public:
	//构造函数
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}
	//析构函数
	~SmartPtr()
	{
		delete _ptr;
		std::cout << "资源已被释放" << std::endl;
	}

	//实现可以模拟指针的原生行为
	//重载operator*
	T& operator*()
	{
		return *_ptr;
	}
	//重载operator->
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};

struct Data
{
	Data(int year,int month,int day)
		:_year(year)
		,_month(month)
		,_day(day)
	{}
	int _year;
	int _month;
	int _day;
};

void test1()
{
	SmartPtr<Data> sp(new Data(2024, 12, 28));
	SmartPtr<Data> sp1(sp);
	std::cout << (*sp)._year << std::endl;
	std::cout << sp->_month << std::endl;
}

void test2()
{
	auto_ptr<Data> sp(new Data(2024, 12, 29));
	auto_ptr<Data> sp1(sp);

	auto_ptr<Data> sp2(new Data(1111, 11, 11));
	sp1 = sp2;
}

void test3()
{
	unique_ptr<int> up(new int(10));
	//unique_ptr<int> up1(up);
}

int main()
{
	//test1();
	//test2();
	//test3();
	return 0;
}