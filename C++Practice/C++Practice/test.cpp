﻿//#include<iostream>

//using namespace std;
//
//int main()
//{
//	cout << "hehe\n" << endl;
//
//	int a = 10;
//	double b = 3.1415926;
//	char ch = 'c';
//
//	char arr[] = "haha";
//
//	cout << a << " " << b << " " << ch << " " << arr << endl;
//
//	return 0;
//}

//using std::cout;
//using std::endl;
//
//int main()
//{
//	cout << "hehe" << endl;
//
//	return 0;
//}

//int main()
//{
//	std::cout << "hehe" << std::endl;
//	return 0;
//}

//#include<iostream>
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//double Add(double x, double y)
//{
//	return x + y;
//}
//
//
//
//int main()
//{
//	Add(1, 2);
//	Add(3.1, 2.5);
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//namespace aaa
//{
//	int a = 10;
//	int b = 20;
//	int Add(int x, int y)
//	{
//		return x + y;
//	}
//}
//
//using namespace aaa;
//
//int main()
//{
//	aaa::a;
//
//	cout << a << endl;
//	return 0;
//}

//#include<iostream>
//
//int main()
//{
//	std::cout << "hello world" << std::endl;
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int endl = 10;
//
//int main()
//{
//	cout << endl << std::endl;
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//namespace calculator
//{
//	int a = 10;
//	int Add(int x, int y)
//	{
//		return x + y;
//	}
//}
//
//using namespace calculator;
//
//int main()
//{
//	int sum = Add(10, 20);
//
//	cout << sum << " " << a << endl;
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int Add(int x = 0, int y = 0, int z = 0)
//{
//	return x + y + z;
//}
//
//int main()
//{
//	int sum = Add();
//	cout << sum << endl;
//
//	int sum1 = Add(1, 3);
//	cout << sum1 << endl;
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int Add(int x , int y=0, int z=0)
//{
//	return x + y + z;
//}
//
//int main()
//{
//	int sum = Add(10, , 3);
//	cout<<sum<<endl;
//	return 0;
//}

//#include<iostream>
//
//int Add(int x, int y)
//{
//	return x + y;
//}
//
//int Add(double x, double y)//类型不同
//{
//	return x + y;
//}
//
//int Add(double x, double y, double z)//个数不同
//{
//	return x + y + z;
//}
//
//
//void Add(int i, char a)
//{
//	;
//}
//
//void Add(char a, int i)//顺序不同
//{
//	;
//}
//
//int main()
//{
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int a = 10;
//	int& ra = a;
//
//	cout << &a << endl;
//	cout << &ra << endl;
//
//	return 0;
//}

//#include<iostream>
//
//int main()
//{
//	const int a = 10;
//	int& ra = a;//编译不能通过，因为const 修饰的变量a只能读不能写，而ra可读可写，权限放大了
//
//	const int b = 20;
//	const int& rb = 20;//编译能通过
//
//	int c = 30;
//	const int& rc = c;//编译能通过，因为c可读可写，rc只可读，权限缩小
//
//	//总结，权限可以缩小，但不能放大
//
//	return 0;
//}

//#include<iostream>
//
//int main()
//{
//	int i = 0;
//	double aaa = i;
//	double& bd = i;
//
//	int a = 1;
//	const double& pa = a;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//
//int Count1()
//{
//	static int a = 0;
//	a++;
//	return a;
//}
//
////int& Count2()
////{
////	a++;
////	return a;
////}
//
//int main()
//{
//	int tmp = Count1();	
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
////C语言交换两个数的写法
//void Swap_C(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
////C++使用引用交换两个数
//void Swap_CPP(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	int x = 10;
//	int y = 20;
//
//	Swap_C(&x, &y);
//
//	cout << x << " " << y << endl;
//
//	Swap_CPP(x, y);
//
//	cout << x << " " << y << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int a = 0;//全局变量a
//
//int& Count1()
//{
//	a++;
//	return a;
//}
//
//int main()
//{
//	int& tmp = Count1();
//	cout << a << endl;
//	tmp++;
//	cout << a << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//inline void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	int x = 10;
//	int y = 20;
//	Swap(x, y);
//	cout << x << " " << y << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//
//	for (auto& e : arr)
//	{
//		e *= 2;
//		cout << e;
//	}
//	cout << endl;
//
//
//	return 0;
//}

//#include"game.h"
//
//int main()
//{
//
//
//	GameStart();
//	GameRun();
//	GameEnd();
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	char arr[10];
//	cin >> arr;
//	cout << arr << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int Count(int x, int y)
//{
//	return x + y;
//}
//
//double Count(double x, double y)
//{
//	return x + y;
//}
//
//int main()
//{
//	Count(1, 2);
//	Count(1.2, 3.5);
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//
//class A
//{
//private:
//	int a;
//	char b;
//	char c;
//	char d;
//	char e;
//	char g;
//};
//
//class B
//{
//	;
//};
//
//int main()
//{
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//////用struct定义类
////struct Date
////{
////	void Show()
////	{
////		cout << _year << "-" << _month << "-" << _day << endl;
////	}
////
////	int _year;
////	int _month;
////	int _day;
////};
//
////用class定义类
//class date
//{
//	void Show()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.Show();
//
//	date d2;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Data
//{
//public:
//	void Show();
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void Data::Show()
//{
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//
//int main()
//{
//	Data d1;
//	cout << sizeof(d1) << endl;
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//
//class Data
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Show()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Data d1;
//	Data d2;
//	d1.Init(2024, 3, 5);
//	d2.Init(2024, 3, 6);
//
//	d1.Show();
//	d2.Show();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	bool operator>(Date& d)
//	{
//		if (_year > d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month > d._month)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day > d._day)
//		{
//			return true;
//		}
//		return false;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2024, 3, 7);
//	Date d2(2024, 3, 7);
//
//	bool ret = d1.operator>(d2);
//	cout << ret << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	//void Init(int year,int month,int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	//Date(int year = 0,int month = 1,int day = 1)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	Date()
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}
//
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Show()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{	
//
//	//Date d1(2024, 3, 9);
//	//Date d2;
//	Date d1;
//	Date d2(2024, 3, 8);
//
//	d1.Show();
//	d2.Show();
//
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Time
//{
//public:
//	Time()
//	{
//		_hour = 0;
//		_min = 1;
//		_second = 1;
//		cout << "Time" << endl;
//		cout << _hour << "-" << _min << "-" << _second << endl;
//	}
//private:
//	int _hour;
//	int _min;
//	int _second;
//};
//
//class Date
//{
//public:
//	void Show()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	Time _t;
//};
//
//int main()
//{
//	Date d1;
//	d1.Show();
//
//	return 0;
//}




//#include<iostream>
//using namespace std;
//
//class Time
//{
//public:
//	Time(int hour = 24, int min = 0, int second = 0)
//	{
//		_hour = hour;
//		_min = min;
//		_second = second;
//	}
//
//	void Show()
//	{
//		cout << _hour << "-" << _min << "-" << _second << endl;
//	}
//
//	~Time()
//	{
//		cout << "Time类 析构完成" << endl;
//	}
//private:
//	int _hour;
//	int _min;
//	int _second;
//};
//
//class Date
//{
//public:
//	void Show()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	~Date()
//	{
//		cout << "Date类 析构完成" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	Time _t;
//};
//
//int main()
//{
//	Date d1(2024, 3, 8);
//
//	d1.Show();
//
//	return 0;
//}

//#include<iostream>
//#include<assert.h>
//using namespace std;
//
//class Stack
//{
//public:
//	//构造函数
//	Stack(int n = 10)//栈的初始化
//	{
//		int* tmp = (int*)malloc(sizeof(int) * n);
//		if (tmp == nullptr)
//		{
//			cout << "开辟失败" << endl;
//			exit(-1);
//		}
//		_a = tmp;
//		_size = 0;
//		_capacity = n;
//	}
//
//	//栈的扩容
//	void CheckCapacity()
//	{
//		if (_size == _capacity)
//		{
//			int* tmp = (int*)realloc(_a, sizeof(int) * (_capacity * 2));
//			if (tmp == nullptr)
//			{
//				cout << "扩容失败" << endl;
//				exit(-1);
//			}
//			_a = tmp;
//			_capacity *= 2;
//		}
//	}
//
//	//入栈
//	void Push(int x)
//	{
//		CheckCapacity();
//		_a[_size] = x;
//		_size++;
//	}
//
//	//出栈
//	void Pop()
//	{
//		assert(_size > 0);
//		_size--;
//	}
//
//	//遍历栈
//	void Print()
//	{
//		int i = 0;
//		while (i < _size)
//		{
//			cout << _a[i] << " ";
//			i++;
//		}
//	}
//
//	//析构函数
//	~Stack()
//	{
//		free(_a);
//		_size = 0;
//		_capacity = 0;
//		_a == nullptr;
//	}
//
//private:
//	int* _a;//栈数组
//	int _size;//栈中现有元素个数
//	int _capacity;//栈的容量
//};
//
//int main()
//{
//	Stack s1;
//
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//	s1.Push(5);
//
//	s1.Pop();
//	s1.Pop();
//	s1.Pop();
//
//	s1.Print();
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Show()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2024, 3, 9);
//	d1.Show();
//
//	Date d2(d1);
//	d2.Show();
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Time
//{
//public:
//	Time(int hour = 24, int min = 0, int second = 0)
//	{
//		_hour = hour;
//		_min = min;
//		_second = second;
//	}
//
//private:
//	int _hour;
//	int _min;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	bool operator==(const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1(2024, 3, 9);
//	Date d2(2024, 3, 9);
//
//	//bool ret = d1.operator==(d2);
//	bool ret = d1 == d2;
//
//	cout << ret << endl;
//
//	return 0;
//}




//时间类完整的实现
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	//获取当月的天数
//	int GetMonthDay(int year, int month)
//	{
//		int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		//判断是否闰年
//		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//		{
//			arr[2]++;//二月份天数++
//		}
//		return arr[month];
//	}
//
//	//构造函数
//	Date(int year = 0, int month = 0, int day = 0)
//	{
//		if (year >= 0 
//			&& month >= 1 && month <= 12 
//			&& day >= 1 && day <= GetMonthDay(year, month))
//		{
//			_year = year;
//			_month = month;
//			_day = day;
//		}
//		else
//		{
//			/*cout << "非法日期" << endl;*/
//			_year = -1;
//			_month = -1;
//			_day = -1;
//		}
//	}
//
//	//拷贝构造
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	//日期比较
//	bool operator==(const Date& d)//判断日期是否相等
//	{
//		if (_year == d._year
//			&& _month == d._month
//			&& _day == d._day)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//
//	bool operator>(const Date& d)//判读日期是否大于日期
//	{
//		if (_year > d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month > d._month)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day > d._day)
//		{
//			return true;
//		}
//		return false;
//	}
//
//	bool operator>=(const Date& d)//判读日期是否大于等于日期
//	{
//		return (*this == d) || (*this > d);
//	}
//
//	bool operator<(const Date& d)//判断日期是否小于日期
//	{
//		return !(*this >= d);
//	}
//
//	bool operator!=(const Date& d)//判断日期是否不相等
//	{
//		return !(*this == d);
//	}
//
//	bool operator<=(const Date& d)//判断日期是否小于等于日期
//	{
//		return !(*this >= d);
//	}
//
//	//日期+或+=天数
//	Date operator+(int day)//日期+天数
//	{
//		Date ret(*this);
//
//		ret._day += day;
//
//		while (ret._day > GetMonthDay(ret._year, ret._month))
//		{
//			ret._day -= GetMonthDay(ret._year, ret._month);
//			ret._month++;
//
//			if (ret._month > 12)
//			{
//				ret._year++;
//				ret._month -= 12;
//			}
//		}
//		return ret;
//	}
//
//	Date& operator+=(int day)//日期+=天数
//	{
//		_day += day;
//
//		while (_day > GetMonthDay(_year, _month))
//		{
//			_day -= GetMonthDay(_year, _month);
//			_month++;
//
//			if (_month > 12)
//			{
//				_year++;
//				_month -= 12;
//			}
//		}
//		return (*this);
//	}
//
//	//日期-或者-=天数
//	Date operator-(int day)//日期-天数
//	{
//		//Date ret(*this);
//
//		//ret._day -= day;
//		//while (ret._day <= 0)
//		//{
//		//	ret._month--;
//		//	if (ret._month <= 0)
//		//	{
//		//		ret._month = 12;
//		//		ret._year--;
//		//	}
//
//		//	ret._day += GetMonthDay(ret._year, ret._month);
//		//}
//
//		//return ret;
//
//		Date ret(*this);
//		ret -= day;
//		return ret;
//	}
//
//	Date& operator-=(int day)//日期-=天数
//	{
//		_day -= day;
//
//		while (_day <= 0)
//		{
//			_month--;
//			if (_month <= 0)
//			{
//				_year--;
//				_month = 12;
//			}
//			_day += GetMonthDay(_year, _month);
//		}
//
//		return (*this);
//	}
//
//	//日期 前置++
//	void operator++()
//	{
//		//_day++;
//		//while (_day > GetMonthDay(_year, _month))
//		//{
//		//	_day -= GetMonthDay(_year, _month);
//		//	_month++;
//
//		//	if (_month > 12)
//		//	{
//		//		_year++;
//		//		_month = 1;
//		//	}
//		//} 
//		(*this) += 1;
//	}
//
//	//日期 后置++
//	Date operator++(int)
//	{
//		//Date ret(*this);
//
//		//ret._day++;
//
//		//while (ret._day > GetMonthDay(_year, _month))
//		//{
//		//	ret._day -= GetMonthDay(_year, _month);
//		//	ret._month++;
//
//		//	if (ret._month > 12)
//		//	{
//		//		ret._year++;
//		//		ret._month = 1;
//		//	}
//		//}
//		//return ret;
//
//		Date ret(*this);
//		ret += 1;
//		return ret;
//	}
//
//	//日期 前置--
//	void operator--()
//	{
//		//_day--;
//
//		//while (_day == 0)
//		//{
//		//	_month--;
//		//	if (_month == 0)
//		//	{
//		//		_year--;
//		//		_month = 12;
//		//	}
//		//	_day += GetMonthDay(_year, _month);
//		//}
//
//		(*this) -= 1;
//	}
//
//	//日期 后置--
//	Date operator--(int)
//	{
//		//Date ret(*this);
//		//ret._day--;
//		//while (ret._day == 0)
//		//{
//		//	ret._month--;
//		//	if (ret._month == 0)
//		//	{
//		//		ret._year--;
//		//		ret._month = 12;
//		//	}
//		//	ret._day += GetMonthDay(ret._year, ret._month);
//		//}
//		Date ret(*this);
//		ret -= 1;
//		return ret;
//	}
//
//	//日期-日期
//	int operator-(const Date& d)
//	{
//		int ret = 0;//返回的差值天数
//
//		Date tmp(d);
//
//		//第一种情况 d1日期大于d
//		if ((*this) > d)
//		{
//			while (tmp._year != _year)
//			{
//				ret -= 365;
//				tmp += 365;
//			}
//
//			while (tmp._month != _month)
//			{
//				if (_month > tmp._month)
//				{
//					ret -= GetMonthDay(tmp._year, tmp._month);
//					tmp += GetMonthDay(tmp._year, tmp._month);
//				}
//				else
//				{
//					ret += GetMonthDay(tmp._year, tmp._month);
//					tmp -= GetMonthDay(tmp._year, tmp._month);
//				}
//			}
//
//			if (_day > tmp._day)
//			{
//				ret -= (_day - tmp._day);
//			}
//			else
//			{
//				ret += (tmp._day - _day);
//			}
//		}
//
//		//第二种情况 d1日期小于d
//		if ((*this) < d)
//		{
//			while (tmp._year != _year)
//			{
//				ret += 365;
//				tmp -= 365;
//			}
//
//			while (tmp._month != _month)
//			{
//				if (_month < tmp._month)
//				{
//					ret += GetMonthDay(tmp._year, tmp._month);
//					tmp -= GetMonthDay(tmp._year, tmp._month);
//				}
//				else
//				{
//					ret -= GetMonthDay(tmp._year, tmp._month);
//					tmp += GetMonthDay(tmp._year, tmp._month);
//				}
//			}
//
//			if (_day < tmp._day)
//			{
//				ret -= (_day-tmp._day);
//			}
//			else
//			{
//				ret += (tmp._day - _day);
//			}
//		}
//
//		//第三种情况 d1日期等于d
//		if ((*this) == d)
//		{
//			return ret;
//		}
//		return ret;
//	}
//
//	//赋值运算符重载
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//			return (*this);
//		}
//	}
//
//	//输出信息函数
//	void Show()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2024, 8, 10);
//	Date d2;
//	d2 = d1;
//	d2.Show();
//
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 0, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Show()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2024, 3, 12);
//	d1.Show();
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
////类实现栈
//class Stack
//{
//public:
//	Stack(int n = 10)//栈的构造函数
//	{
//		int* tmp = (int*)malloc(sizeof(int) * n);
//		_a = tmp;
//		_size = 0;
//		_capacity = 0;
//	}
//	~Stack()//栈的析构函数
//	{
//		free(_a);
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//private:
//	int* _a;//指向栈的指针
//	int _size;//栈中元素个数
//	int _capacity;//栈的容量
//};
//
//int main()
//{
//	Stack s1(4);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)//构造函数
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Show()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2024, 3, 12);
//	//下面两种写法相同 Date d2(d1)等价于Date d3=d1
//	Date d2(d1);
//	Date d3 = d1;
//
//	d1.Show();
//	d2.Show();
//	d3.Show();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Stack//栈类
//{
//public:
//	Stack(int n = 10)//栈的构造函数
//	{
//		int* tmp = (int*)malloc(sizeof(int) * n);
//		_a = tmp;
//		_size = _capacity = 0;
//	}
//	~Stack()//栈的析构函数
//	{
//		free(_a);
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//private:
//	int* _a;//指向栈的指针
//	int _size;//栈中元素个数
//	int _capacity;//栈的容量
//};
//
//int main()
//{
//	Stack s1;
//	Stack s2(s1);
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date& operator=(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		return (*this);
//	}
//	void Show()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2024, 3, 13);
//	Date d2;
//	d2 = d1;
//
//	d1.Show();
//	d2.Show();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Time
//{
//public:
//	Time(int hour, int min, int second)
//	{
//		cout << "Time()" << endl;
//		_hour = hour;
//		_min = min;
//		_second = second;
//	}
//	void Show()
//	{
//		cout << _hour << "-" << _min << "-" << _second << endl;
//	}
//private:
//	int _hour;
//	int _min;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1, int* tmp = nullptr)
//		:ret(*tmp)
//		, _t(1, 2, 3)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Show()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	int& ret;
//
//	Time _t;
//};
//
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	Date d1(2024, 3, 15, pa);
//	d1.Show();
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year)
//	{
//		_year;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(1);
//	Date d2 = 2;
//	Date d3 = d1;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		_n++;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._year;
//		_n++;
//	}
//	int ret()
//	{
//		return _n;
//	}
//private:
//	static int _n;
//	int _year;
//	int _month;
//	int _day;
//};
//
//int Date::_n = 0;
//
//int main()
//{
//	Date d1(2024, 3, 15);
//	Date d2 = d1;
//
//	cout << d1.ret() << endl;
//	return 0;
//}

//#include <climits>
//#include <iostream>
//using namespace std;
//
//class Date
//{
//public:
//    Date(int year, int month, int day)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    int GetMonthoDay(int year, int month)
//    {
//        int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//        {
//            arr[2]++;
//        }
//        return arr[month];
//    }
//
//    Date& dayadd(Date& d)
//    {
//        d._day++;
//        if (d._day > GetMonthoDay(d._year, d._month))
//        {
//            d._day -= GetMonthoDay(d._year, d._month);
//            d._month++;
//        }
//        if (d._month > 12)
//        {
//            d._year++;
//            d._month = 1;
//        }
//        return d;
//    }
//
//    int Judge(Date& d1, Date& d2)
//    {
//        if (d1._year == d2._year && d1._month == d2._month && d1._day == d2._day)
//        {
//            return 1;
//        }
//        else
//        {
//            return 0;
//        }
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    int year;
//    int month;
//    int day;
//    cin >> year;
//    cin >> month;
//    cin >> day;
//
//    int ret = 1;
//
//    Date d(year, month, day);
//
//    Date tmp(year, 1, 1);
//
//    while (!d.Judge(d, tmp))
//    {
//        ret++;
//        tmp.dayadd(tmp);
//    }
//
//    cout << ret << endl;
//
//    return 0;
//}
//
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	const Date* operator&() const
//	{
//		return this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	cout << &d1 << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Date
//{
//public:
//
//    int GetMonthDay(int year, int month)
//    {
//        int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//        {
//            arr[2]++;
//        }
//        return arr[month];
//    }
//
//    Date(int year = 0, int month = 1, int day = 1)
//        :_year(year)
//        , _month(month)
//        , _day(day)
//    {}
//
//    Date operator+(int day)
//    {
//        Date d(*this);
//        d._day += day;
//        while (d._day > GetMonthDay(d._year, d._month))
//        {
//            d._day -= GetMonthDay(d._year, d._month);
//            d._month++;
//            if (d._month > 12)
//            {
//                d._year++;
//                d._month = 1;
//            }
//        }
//        return d;
//    }
//
//    void Show()
//    {
//        printf("%d-%02d-%02d\n", _year, _month, _day);
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    int year;
//    int month;
//    int day;
//    int add;
//    cin >> year >> month >> day >> add;
//    Date d1(year, month, day);
//    Date ret = d1 + add;
//    ret.Show();
//    return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//
//		_count++;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//		_count++;
//	}
//
//	void Show()
//	{
//		int ret = GetCount();
//		cout << ret << endl;
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	static int GetCount()
//	{
//		return _count;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	static int _count;
//};
//
//int Date::_count = 0;
//
//int main()
//{
//	Date d1(2024, 3, 17);
//	Date d2 = d1;
//
//	d1.Show();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//	friend ostream& operator<<(ostream& out, Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//
//public:
//	Date(int year=1, int month=0, int day=0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void operator<<(ostream& out)
//	{
//		out << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year = 0;
//	int _month = 1;
//	int _day = 1;
//};
//
//ostream& operator<<(ostream& out, Date& d)
//{
//	out << d._year << "-" << d._month << "-" << d._day << endl;
//	return out;
//}
//
//istream& operator>>(istream& in, Date& d)
//{ 
//	in >> d._year >> d._month >> d._day;
//	return in;
//}
//
//int main()
//{
//	Date d1;
//	Date d2;
//
//	cin >> d1 >> d2;
//	cout << d1 << d2;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Time
//{
//	friend class Date;
//public:
//	Time(int hour = 24, int min = 0, int second = 0)
//		:_hour(hour)
//		,_min(min)
//		,_second(second)
//	{}
//	void Show()
//	{
//		cout << _hour << "-" << _min << "-" << _second << endl;
//	}
//private:
//	int _hour;
//	int _min;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void SetTime(int hour = 24, int min = 0, int second = 0)
//	{
//		_t._hour = hour;
//		_t._min = min;
//		_t._second = second;
//	}
//	void Show()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	Time _t;
//};
//
//int main()
//{
//	Date d1(2024, 3, 18);
//	d1.SetTime(20, 38, 26);
//	d1.Show();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//		class Time
//		{
//		public:
//			Time(int hour=24,int min=0,int second=0)
//				:_hour(hour)
//				,_min(min)
//				,_second(second)
//			{}
//		private:
//			int _hour;
//			int _min;
//			int _second;
//		};
//	Date(int year = 0, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void SetTime()
//	{
//
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int num[10] = { 1,2,3 };
//	cout << sizeof(num) << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year=0,int month=1,int day=1)
//	{
//		cout << "Date()" << endl;
//	}
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	int* ptr1 = (int*)malloc(sizeof(int));
//	int* ptr2 = new int;
//
//	Date* ptr3 = new Date;
//	Date* ptr4 = new Date[3];
//
//	delete ptr3;
//	delete[] ptr4;
//
//	return 0;
//}
//s

//
//#include<iostream>
//using namespace std;
//
//class ListNode
//{
//public:
//	ListNode(int val = 0)
//		:_val(val)
//		,_prev(nullptr)
//		,_tail(nullptr)
//	{
//		cout << "ListNode()" << endl;
//	}
//	~ListNode()
//	{
//		cout << "~ListNode()" << endl;
//	}
//private:
//	int _val;
//	ListNode* _prev;
//	ListNode* _tail;
//};
//
//int main()
//{
//	//ListNode* ptr1 = new ListNode;
//	//delete ptr1;
//
//	//int n = 10;
//	//ListNode* ptr2 = new ListNode[n];
//	//cout << sizeof(ListNode) << endl;
//	//delete[] ptr2;
//
//	//long long size = 30;
//	//int* tmp = (int*)operator new(size * 1024 * 1024 * 1024);
//	//cout << tmp << endl;
//
//	//long long size = 10;
//	//int* ptr1 = new int[size * 1024 * 1024 * 1024];
//	//cout << ptr1 << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	size_t n = 2;
//	char* ptr = new char[n * 1024 * 1024 * 1024];
//	cout << &ptr << endl;
//	const char* p = "abcd";
//	cout << &p << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//template<class T>
//
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//
//	double c = 1.1;
//	double d = 2.22;
//	cout << a << b << endl;
//
//	Swap(c, d);
//
//	cout << c << d << endl;
//
//	return 0;
//}
//
//#include"test.h"
//
//int Add(int a=0, int b=0)
//{
//	return a + b;
//}
//
//int main()
//{
//	int ret = Add();
//	cout << ret << endl;
//
//	return 0;
//}

//#include"test.h"
//
//typedef char* ptr;
//
//int main()
//{
//	ptr p1;
//	ptr* p2;
//	return 0;
//}

//#include"test.h"
//
//int main()
//{
//	auto a = 1;
//	auto b = 1.2;
//	auto c = 'c';
//
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	return 0;
//}

//#include"test.h"
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//	for (auto& e : arr)
//	{
//		cout << e << " ";
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	//初始化列表用法
//	Date(int year = 0, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//	void Show()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.Show();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	//无默认构造函数（默认构造函数是指：不需要传参的的构造函数）
//	Date(int year,int month,int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//	void Show()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Temp
//{
//public:
//	Temp(int& ptmp)
//		:_b(10)
//		,_a(ptmp)
//		,_d(0,0,0)
//	{}
//	void Show()
//	{
//		cout << _a << " " << _b << endl;
//	}
//private:
//	//必须要用初始化列表的三个成员变量
//	int& _a;
//	const int _b;
//	Date _d;//自定义类型，且无默认构造函数
//};
//
//int main()
//{
//	int tmp = 0;
//	Temp t1(tmp);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//private:
//	int _year;
//	static int count;
//};
//
//int Date::count = 0;
//
//int main()
//{
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//	friend ostream& operator<<(ostream& _out, const Date& d);
//public:
//	Date(int year=0,int month=1,int day=1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& _out, const Date& d)
//{
//	_out << d._year << "-" << d._month << "-" << d._day << endl;
//	return _out;
//}
//
//int main()
//{
//	Date d1(2024, 3, 24);
//	Date d2(2024, 3, 25);
//
//	cout << d1 << d2;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Time
//{
//	friend class Date;//声明Date类是它的朋友
//public:
//	Time(int hour=0,int min=0,int second=0)
//		:_hour(hour)
//		,_min(min)
//		,_second(second)
//	{}
//private:
//	int _hour;
//	int _min;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date(int year,int month,int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//	void SetTime(int hour, int min, int second)//这个函数可以突破访问权限去访问Time的成员变量
//	{
//		_t._hour = hour;
//		_t._min = min;
//		_t._second = second;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	Time _t;
//};
//
//int main()
//{
//	Date d1(2024, 3, 24);
//	d1.SetTime(0, 0, 0);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	class Time
//	{
//	public:
//		Time(int hour=0,int min=0,int second=0)
//			:_hour(hour)
//			,_min(min)
//			,_second(second)
//		{}
//		void SetDate(int year = 0, int month = 1, int day)
//		{
//			_year = year;
//		}
//	private:
//		int _hour;
//		int _min;
//		int _second;
//	};
//
//public:
//	Date(int year = 0, int month = 1, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Solution
//{
//public:
//	int GetSum(int n)
//	{
//		return n;
//	}
//};
//
//int main()
//{
//	Solution().GetSum(10);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//template<class T>
//class Vetor
//{
//public:
//	Vetor(int size=0,int capacity=0)
//		:_a(nullptr)
//		,_size(size)
//		,_capacity(capacity)
//	{}
//	~Vetor()
//	{
//		delete[] _a;
//		_size = 0;
//		_capacity = 0;
//	}
//	void Push(const T& x)
//	{
//		if (_size == _capacity)
//		{
//			int newcapacity = _capacity == 0 ? 2 : _capacity * 2;
//			T* tmp = new T[newcapacity];
//			memcpy(tmp, _a, sizeof(T) * _capacity);
//			_capacity = newcapacity;
//			delete[] _a;
//			_a = tmp;
//		}
//
//		_a[_size] = x;
//		_size++;
//	}
//	T& operator[](const int& i)
//	{
//		return _a[i];
//	}
//	int Getsize()
//	{
//		return _size;
//	}
//private:
//	T* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	Vetor<int> v;
//	v.Push(1);
//	v.Push(2);
//	v.Push(3);
//	v.Push(4);
//
//	for (int i = 0; i < v.Getsize(); i++)
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	string s1("hello");
//	s1.push_back('a');
//	s1.append("world");
//	s1 += 'b';
//	s1 += "ccc";
//
//	cout << s1 << " " << s1.size() << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	string s1("12345");
//
//	int num = 0;
//
//	for (int i = 0; i < s1.size(); i++)
//	{
//		num *= 10;
//		num += s1[i] - '0';
//	}
//	cout << num << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	char c1 = '1';
//	for (int i = 0; i < 10; i++)
//	{
//		c1++;
//	}
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//class Solution {
//public:
//    string addStrings(string num1, string num2)
//    {
//        int size1 = num1.size();
//        int size2 = num2.size();
//        string ret("");
//        int i = size1 - 1;
//        int j = size2 - 1;
//
//        int flag = 0;
//
//        while (i >= 0 && j >= 0)
//        {
//            int tmp = num1[i] + num2[j] + flag - '0' - '0';
//            if (tmp >= 10)
//            {
//                flag = 1;
//            }
//            else
//            {
//                flag = 0;
//            }
//            tmp %= 10;
//            ret += tmp + '0';
//            i--;
//            j--;
//        }
//        while (i >= 0)
//        {
//            int tmp = num1[i] + flag - '0';
//            if (tmp >= 10)
//            {
//                flag = 1;
//            }
//            else
//            {
//                flag = 0;
//            }
//            tmp %= 10;
//            ret += tmp + '0';
//            i--;
//        }
//        while (j >= 0)
//        {
//            int tmp = num2[j] + flag - '0';
//            if (tmp >= 10)
//            {
//                flag = 1;
//            }
//            else
//            {
//                flag = 0;
//            }
//            tmp %= 10;
//            ret += tmp + '0';
//            j--;
//        }
//        if (flag == 1)
//        {
//            ret += 1 + '0';
//        }
//        int size = ret.size();
//        for (int i = 0; i < size / 2; i++)
//        {
//            char ch = ret[i];
//            ret[i] = ret[size - i - 1];
//            ret[size -i- 1] = ch;
//        }
//        return ret;
//    }
//};
//
//int main()
//{
//    string num1("999");
//    string num2("999");
//
//    string ret = Solution().addStrings(num1, num2);
//
//
//    return 0;
//}
//
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int num = INT_MAX;
//	//cout << (num ^ 4) << endl;
//	//cout << (num ^ 78) << endl;
//	//cout << (num ^ 12) << endl;
//	//cout << (num ^ 1) << endl;
//	//cout << (num ^ 3) << endl;
//
//	//cout << (2147483635 ^ 12) << endl;
//	//cout << (2147483632 ^ 12) << endl;
//	//cout << (2147483632 ^ 1) << endl;
//	//cout << (2147483632 ^ 3) << endl;
//
//	//cout << (78 ^ 12 ^ 1 ^ 3) << endl;
//	//cout << (1 ^ 12 ^ 78 ^ 3) << endl;
//	//cout << (1 ^ 78 ^ 3 ^ 12) << endl;
//	//cout << (78 ^ 1 ^ 12 ^ 3) << endl;
//
//	//cout << (64 ^ 2147483632) << endl;
//	//cout << (78 ^ 12 ^ 1 ^ 3^2147483632) << endl;
//
//	cout << (64 ^ 2147483583) << endl;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int arr[100] = {
//        5, 6, 8, 6, 9, 1, 6, 1, 2, 4, 9, 1, 9, 8, 2, 3, 6, 4, 7, 7,
//        5, 9, 5, 0, 3, 8, 7, 5, 8, 1, 5, 8, 6, 1, 8, 3, 0, 3, 7, 9,
//        2, 7, 0, 5, 8, 8, 5, 7, 0, 9, 9, 1, 9, 4, 4, 6, 8, 6, 3, 3,
//        8, 5, 1, 6, 3, 4, 6, 7, 0, 7, 8, 2, 7, 6, 8, 9, 5, 6, 5, 6,
//        1, 4, 0, 1, 0, 0, 9, 4, 8, 0, 9, 1, 2, 8, 5, 0, 2, 5, 3, 3
//    };
//
//    int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//    int month[13] = { 0,1,2,3,4,5,6,7,8,9,10,11,12 };
//    int count = 0;
//
//    for (int i = 1; i <= 12; i++)
//    {
//        for (int j = 1; j <= day[i]; j++)
//        {
//            int data[8] = { 2,0,2,3,month[i] / 10,month[i] % 10,j / 10,j % 10 };
//            int l = 0;
//
//            for (int k = 0; k < 100; k++)
//            {
//                if (data[l] == arr[k])
//                {
//                    l++;
//                }
//                if (l == 8)
//                {
//                    count++;
//                    break;
//                }
//            }
//
//        }
//    }
//    cout << count << endl;
//    return 0;
//}
////
//#include<iostream>
//using namespace std;
//
//extern class AAA;
//
//class BBB
//{
//public:
//	void GetA()
//	{
//		cout << _A._a << endl;
//	}
//private:
//	int _size;
//	AAA _A;
//};
//
//class AAA
//{
//	/*friend void BBB::GetA();*/
//	friend class BBB;
//private:
//	int _a;
//};
//
//int main()
//{
//	BBB b1;
//	b1.GetA();
//	return 0;
//}

// 前置声明

//#include<iostream>
//
//class A; // 前置声明
//
//class B {
//public:
//    // 声明B类中有待定义的display函数，它将成为A类的友元函数
//    friend void display(A& aRef);
//};
//
//class A {
//private:
//    int mimi = 42; // 初始化私有成员
//public:
//    // 由于B类已经完成定义，这里可以直接使用B::display作为友元
//};
//
//// 在这里定义B类的display函数
//void B::display(A& aRef) {
//    std::cout << "A的秘密是: " << aRef.mimi << std::endl;
//}
//
//int main() {
//    A a;
//    B b;
//    b.display(a); // 此时调用的display函数能够访问A类的私有成员
//    return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void Show()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	Time _t;
//};
//
//class Time
//{
//public:
//	Time(int hour = 24, int min = 0, int second = 0)
//		:_hour(hour)
//		, _min(min)
//		, _second(second)
//	{}
//	void Show()
//	{
//		cout << _hour << "-" << _min << "-" << _second << endl;
//	}
//private:
//	int _hour;
//	int _min;
//	int _second;
//};
//
//int main()
//{
//	Date d1;
//	d1.Show();
//
//	return 0;
//}


//#include"Date.h"
//#include"Time.h"
//
//Date::Date(int year,int month,int day)
//	:_year(year)
//	,_month(month)
//	,_day(day)
//{}
//
//void Date::Show()
//{
//	cout << _year << "-" << _month << "-" << _day << endl;
//}
//
//
//
//Time::Time(int hour , int min , int second )
//	:_hour(hour)
//	,_min(min)
//	,_second(second)
//{}
//
//void Time::Show()
//{
//	cout << _hour << "-" << _min << "-" << _second << endl;
//}

//#include<iostream>
//using namespace std;
//
//int global = 0;
//static int i = 0;
//
//
//int main()
//{
//	int a = 1;
//	int b = 20;
//
//	int* tmp = (int*)malloc(sizeof(int));
//	int* tp = new int;
//
//	static int j = 0;
//
//	const char* s = "abcd";
//	char s2[10] = "abcd";
//
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int* tmp1 = new int;//申请一个int类型的空间
//	int* tmp2 = new int[10];//申请一个int类型的数组
//	int* tmp3 = new int(10);//申请一个int类型的空间，并初始化为10
//
//	delete tmp1;//释放tmp1指向的空间
//	delete[] tmp2;//释放tmp2指向的数组空间
//	delete tmp3;//释放tmp3指向的空间
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 0, int day = 0)
//	{
//		cout << "Date()" << endl;
//	}
//	
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	cout << "malloc的方式" << endl;
//	Date* d1 = (Date*)malloc(sizeof(Date));
//	free(d1);
//
//	cout << "中间隔开便于观察" << endl;
//
//	cout << "new的方式" << endl;
//	Date* d2 = new Date;
//	delete d2;
//	return 0;
//}


//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5 };
//
//	for (auto& e : arr)
//	{
//		cout << e << endl; 
//	}
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//string addStrings(string num1, string num2)
//{
//    int end1 = num1.size() - 1;
//    int end2 = num2.size() - 1;
//
//    string str;
//    int flag = 0;
//    while (end1 >= 0 || end2 >= 0)
//    {
//        int val1 = 0;
//        int val2 = 0;
//        if (end1 < 0)
//            val1 = 0;
//        else
//            val1 = num1[end1] - '0';
//        if (end2 < 0)
//            val2 = 0;
//        else
//            val2 = num2[end2] - '0';
//        int tmp = val1 + val2 + flag;
//        if (tmp > 9)
//        {
//            tmp %= 10;
//            flag = 1;
//        }
//        else
//        {
//            flag = 0;
//        }
//        str += tmp + '0';
//        end1--;
//        end2--;
//    }
//    if (flag == 1)
//        str += '1';
//    reverse(str.begin(), str.end());
//    return str;
//}
//
//class Solution {
//public:
//    string multiply(string num1, string num2)
//    {
//        string ret;
//        string str("0");
//
//        int end1 = num1.size() - 1;
//        int end2 = num2.size() - 1;
//        int flag = 0;
//        while (end2 >= 0)
//        {
//            int i = end1;
//            while (i >= 0)
//            {
//                int tmp = (num1[i] - '0') * (num2[end2] - '0') + flag;
//                flag = tmp / 10;
//                tmp %= 10;
//                ret += tmp + '0';
//                i--;
//            }
//            if (flag > 0)
//            {
//                ret += flag + '0';
//                flag = 0;
//            }
//            reverse(ret.begin(), ret.end());
//            str = addStrings(ret, str);
//            ret.resize(0);
//            end2--;
//        }
//        return str;
//    }
//};
//
//int main()
//{
//    string str1("123");
//    string str2("456");
//    string ret = Solution().multiply(str1, str2);
//    cout << ret << endl;
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//
////字符串转数字
//int ConvertNum(string& str)
//{
//	int count = 0;
//	for (int i = 0; i < str.size(); i++)
//	{
//		count *= 10;
//		count += str[i] - '0';
//	}
//	return count;
//}
//
////数字转字符串
//string ConvertStr(int num)
//{
//	string s;
//	while (num > 0)
//	{
//		int tmp = num % 10;
//		s += tmp + '0';
//		num /= 10;
//	}
//	reverse(s.begin(), s.end());
//	return s;
//}
//
//int main()
//{
//	string str("12345");
//	int ret = ConvertNum(str);
//	cout << ret << endl;
//
//	int num = 456;
//	string s = ConvertStr(num);
//	cout << s << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//void Swap(double& x, double& y)
//{
//	double tmp = x;
//	x = y;
//	y = tmp;
//}
//
//void Swap(char& x, char& y)
//{
//	char tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int main()
//{
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//template<class T>
//void Swap(T& x, T& y)
//{
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//
//void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//int main()
//{
//	int x1 = 10;
//	int y1 = 20;
//
//	Swap(x1, y1);
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
////定义一个自己的栈
//template<class T>
//class Stack
//{
//public:
//	//栈的一系列操作
//	//…………
//private:
//	T* _arr;//一个指向栈的指针
//};
//
//class Stack
//{
//public:
//	//栈的一系列操作
//	//…………
//private:
//	int* _arr;//一个指向栈的指针
//};
//
//class Stack
//{
//public:
//	//栈的一系列操作
//	//…………
//private:
//	double* _arr;//一个指向栈的指针
//};
//
//class Stack
//{
//public:
//	//栈的一系列操作
//	//…………
//private:
//	char* _arr;//一个指向栈的指针
//};
//
//int main()
//{
//	Stack<int> s1;//存放int类型的栈
//	Stack<double> s2;//存放double类型的栈
//	Stack<char> s3;//存放char类型的栈
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int singleNumber(vector<int>& nums)
//    {
//        vector<int> v;
//        v.resize(32);
//        for (int i = 0; i < nums.size(); i++)//获取每个nums的值；
//        {
//            for (int j = 0; j < 32; j++)
//            {
//                int tmp = nums[i];
//                tmp = tmp >> j;//对nums[i]进行右移操作
//                if ((tmp & 1) == 1)//如果右移之后的nums[i]与1按位与等于1，即该nums[i]的第一位是1，记录下来++
//                {
//                    v[31 - j]++;
//                }
//            }
//        }
//
//        int ret = 0;
//        for (int i = v.size() - 1; i >= 0; i--)//遍历数组v
//        {
//            v[i] %= 3;//对每个v[i]进行取模3，最后即可保留唯一出现一次数字的二进制码
//            if (v[i] == 1)
//            {
//                ret += pow(2, 31 - i);//通过二进制码来计算它的值
//            }
//        }
//        return ret;
//    }
//};
//
//int main()
//{
//    vector<int> nums;
//    nums.push_back(0);
//    nums.push_back(1);
//    nums.push_back(0);
//    nums.push_back(1);
//    nums.push_back(0);
//    nums.push_back(1);
//    nums.push_back(99);
//
//    int ret = Solution().singleNumber(nums);
//    cout << ret << endl;
//    return 0;
//}
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    vector<int> singleNumber(vector<int>& nums)
//    {
//        //对数进行分组，放到两个vector中
//        vector<int> v1;
//        vector<int> v2;
//        //将nums中的数全部异或在一起，找到唯一的两个数的异或结果
//        int result = 0;
//        for (int i = 0; i < nums.size(); i++)
//        {
//            result ^= nums[i];
//        }
//
//        //cout<<result<<endl;
//
//        //对异或结果的二进制位进行遍历，找到第一次出现二进制1的位置，后续通过这个1的位置来进行分组
//        int flag = 0;
//        for (int i = 0; i < 32; i++)
//        {
//            if (result & 1 == 1)
//            {
//                flag = i;
//                break;
//            }
//            result >>= 1;
//        }
//
//        //cout<<flag<<endl;
//
//        //遍历nums进行分组
//        for (int i = 0; i < nums.size(); i++)
//        {
//            int tmp = 1;
//            tmp <<= flag;
//            //cout<<tmp<<endl;
//            if (nums[i] & tmp == 1)
//            {
//                v1.push_back(nums[i]);
//            }
//            else
//            {
//                v2.push_back(nums[i]);
//            }
//        }
//
//        vector<int> ret;
//        int count = 0;
//        for (int i = 0; i < v1.size(); i++)
//        {
//            count ^= v1[i];
//        }
//        ret.push_back(count);
//
//        count = 0;
//        for (int i = 0; i < v2.size(); i++)
//        {
//            count ^= v2[i];
//        }
//        ret.push_back(count);
//        return ret;
//    }
//};
//
//int main()
//{
//    vector<int> nums;
//    nums.push_back(1);
//    nums.push_back(2);
//    nums.push_back(1);
//    nums.push_back(3);
//    nums.push_back(2);
//    nums.push_back(5);
//
//    Solution().singleNumber(nums);
//    return 0;
//}

//#include<iostream>
//#include<stdbool.h>
//using namespace std;
//
//bool Solution(int (*arr)[4], int row, int col, int num)
//{
//	if (arr == nullptr)
//	{
//		return false;
//	}
//
//	int brow = 0;//行
//	int bcol = col - 1;//列
//
//	while (brow < row && bcol >= 0)
//	{
//		if (arr[brow][bcol] == num)
//		{
//			return true;
//		}
//		else if (arr[brow][bcol] > num)
//		{
//			bcol--;
//		}
//		else
//		{
//			brow++;
//		}
//	}
//	return false;
//}
//
//void Test(arr)
//
//int main()
//{
//	int arr[4][4] = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
//	//cout << arr << endl;
//	//cout << arr + 1 << endl;
//
//	//cout << (*arr)[3] << endl;
//	//cout << (*(arr + 1))[3] << endl;
//	cout << Solution(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]) / sizeof(arr[0][0]), 7) << endl;
//	//cout << Solution(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), 7) << endl;
//	return 0;
//}

//#include <iostream>
//
//template <size_t rows, size_t cols>
//void printArray1(int (&arr)[rows][cols]) {
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            arr[i][j]++;
//        }
//    }
//}
//
//template <size_t rows, size_t cols>
//void printArray2(int(&arr)[rows][cols]) {
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            std::cout << arr[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
//}
//
//int main() {
//    int arr[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
//    printArray1(arr); // 输出：1 2 3 4  5 6 7 8  9 10 11 12
//    printArray2(arr); // 输出：1 2 3 4  5 6 7 8  9 10 11 12
//    return 0;
//}


//#include<iostream>
//using namespace std;
//
//void fun2(int& pa)
//{
//	pa++;
//}
//
//void fun1()
//{
//	int a = 10;
//	fun2(a);	
//}
//
//int main()
//{
//	fun1();
//	return 0;
//}
//#include<iostream>
//#include<vector>
//#include<stdbool.h>
//using namespace std;
//
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param pushV int整型vector
//     * @param popV int整型vector
//     * @return bool布尔型
//     */
//    bool IsPopOrder(vector<int>& pushV, vector<int>& popV)
//    {
//        //下一个popV值必须下面这个区间
//        int begin = 0;
//        int end = pushV.size() - 1;
//        while (!pushV.empty())
//        {
//            for (int i = 0; i < popV.size(); i++)
//            {
//                int tmp = popV[i];
//                //遍历区间，看存不存在
//                int j = 0;
//                for (j = begin; j <= end; j++)
//                {
//                    if (tmp == pushV[j])//当 当前popV值在该区间存在，则删除pushV中的popV值，并刷新区间
//                    {
//                        pushV.erase(pushV.begin() + j);
//                        begin = j - 1;
//                        end = end - 1;
//                        break;
//                    }
//                }
//                if (j == pushV.size())//如果遍历整个区间都没有找到需要的popV值，则说明不符合，返回false
//                {
//                    return false;;
//                }
//            }
//        }
//        return true;
//    }
//};
//
//int main()
//{
//    vector<int> pushV;
//    pushV.push_back(1);
//    pushV.push_back(2);
//    pushV.push_back(3);
//    pushV.push_back(4);
//    pushV.push_back(5);
//
//    vector<int> popV;
//    popV.push_back(4);
//    popV.push_back(5);
//    popV.push_back(3);
//    popV.push_back(2);
//    popV.push_back(1);
//
//    bool ret = Solution().IsPopOrder(pushV, popV);
//    cout << ret << endl;
//
//    return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//	v.push_back(6);
//
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		cout << *it << " ";
//		it += 10;
//	}
//	cout << endl;
//
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	string s1("hello world");
//
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		it += 2;
//	}
//	cout << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//void Print1(int (*parr)[5], int rows, int cols)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			cout << (*(parr + i))[j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//
//void Print2(int* parr, int rows, int cols)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			cout << *(parr + i * cols + j) << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//
//void Print3(int(&parr)[4][5],int rows,int cols)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			cout << parr[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//
//template<size_t row, size_t col>
//void Print4(int(&parr)[row][col])
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			cout << parr[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int arr[][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20} };
//	Print1(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]) / sizeof(arr[0][0]));
//	Print2(&arr[0][0], sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]) / sizeof(arr[0][0]));
//	Print3(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]) / sizeof(arr[0][0]));
//	Print4(arr);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<list>
//using namespace std;
//
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	vector<int>::iterator it1 = v.begin();
//	while (it1 != v.end())
//	{
//		cout << *it1 << " ";
//		it1 = it1 + 1;
//	}
//
//	list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_back(4);
//
//	list<int>::iterator it2 = l.begin();
//	while (it2 != l.end())
//	{
//		cout << *it2 << " ";
//		it2 = it2 + 1;
//	}
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//typedef const int INT;
//
//INT add(int num1, int num2)
//{
//	return num1 + num2;
//}
//
//int main()
//{
//	int x = 10;
//	int y = 20;
//	int ret = add(x, y);
//	ret++;
//	cout << ret << endl;
//	return 0;
//}
//第一次模拟实现list
//namespace My_list
//{
//	//封装链表结点类	
//	template<class T>
//	struct __list_node
//	{
//		//成员变量
//		T _data;
//		__list_node<T>* _prev;
//		__list_node<T>* _next;
//
//		//成员函数
//		__list_node(const T& val = T())
//			:_data(val)
//			, _prev(nullptr)
//			, _next(nullptr)
//		{
//		}
//	};
//
//	//封装迭代器类
//	//__list_iterator<T,T&,T> -> iterator
//	//__list_iterator<T,const T&,const T*> -> const iterator
//	template<class T, class Ref, class Ptr>
//	struct __list_iterator
//	{
//		typedef __list_node<T> Node;
//		typedef __list_iterator<T, Ref, Ptr> iterator;
//
//		//构造函数	构造迭代器
//		__list_iterator(Node* node = nullptr)
//			:_node(node)
//		{
//		}
//
//		//返回迭代器指向数据的引用
//		Ref operator*() const
//		{
//			return _node->_data;
//		}
//
//		//用于测试list里面存Date类的解引用操作		返回的是迭代器指向数据的指针
//		Ptr operator->() const
//		{
//			return &_node->_data;
//		}
//
//		//迭代器前置++操作
//		iterator operator++()
//		{
//			_node = _node->_next;
//			return *this;
//		}
//
//		//迭代器前置--操作
//		iterator operator--()
//		{
//			_node = _node->_prev;
//			return *this;
//		}
//
//		//迭代器后置++
//		iterator operator++(int)
//		{
//			iterator tmp(*this);
//			//_node = _node->_next;
//			++(*this);
//			return tmp;
//		}
//		//迭代器后置--
//		iterator operator--(int)
//		{
//			iterator tmp(*this);
//			//_node = _node->_prev;
//			--(*this);
//			return tmp;
//		}
//
//		//重载operator!=
//		bool operator!=(const iterator it) const
//		{
//			if (_node != it._node)
//			{
//				return true;
//			}
//			else
//			{
//				return false;
//			}
//		}
//
//		//重载operator==
//		bool operator==(const iterator it) const
//		{
//			return !(*this != it);
//		}
//
//		//成员变量
//		Node* _node;
//	};
//
//	//list类
//	template<class T>
//	class list
//	{
//		//链表结点类
//		typedef __list_node<T> Node;
//	public:
//		//迭代器类
//		typedef __list_iterator<T, T&, T*> iterator;
//		typedef __list_iterator<T, const T&, const T*> const_iterator;
//
//		//begin迭代器
//		iterator begin()
//		{
//			iterator it(_head->_next);
//			return it;
//		}
//
//		//end迭代器
//		iterator end()
//		{
//			iterator it(_head);
//			return it;
//		}
//
//		//const_begin迭代器
//		const_iterator begin() const
//		{
//			const_iterator cit(_head->_next);
//			return cit;
//		}
//
//		//const_end迭代器
//		const_iterator end() const
//		{
//			const_iterator cit(_head);
//			return cit;
//		}
//
//		//构造函数
//		list()
//			:_head(new Node)
//		{
//			//_head = new Node;	
//			_head->_prev = _head;
//			_head->_next = _head;
//		}
//
//		//析构函数
//		~list()
//		{
//			clear();
//			delete _head;
//			_head = nullptr;
//		}
//
//		//拷贝构造
//		//list<int> l2(l1)
//		list(const list<T>& tmp)
//			:_head(new Node)
//		{
//			_head->_next = _head;
//			_head->_prev = _head;
//
//			const_iterator it = tmp.begin();
//			while (it != tmp.end())
//			{
//				push_back(*it);
//				it++;
//			}
//		}
//
//		//赋值=重载
//		//list<int> l3;
//		//l3=l2;
//		list<T>& operator=(const list<T>& tmp)
//		{
//			if (this != &tmp)
//			{
//				list<T> l(tmp);
//				Swap(l);
//			}
//			return *this;
//		}
//
//		//交换两个链表
//		//l1.Swap(l2);
//		void Swap(list<T>& tmp)
//		{
//			swap(_head, tmp._head);
//		}
//
//		//clear清理函数	后续改进为调用erase函数
//		void clear()
//		{
//			Node* headnext = _head->_next;//找到头结点的下一个结点
//			//释放除头结点外的所有结点
//			while (headnext != _head)
//			{
//				Node* tmp = headnext->_next;
//				delete headnext;
//				headnext = tmp;
//			}
//
//			_head->_next = _head;
//			_head->_prev = _head;
//		}
//
//		//尾插
//		void push_back(const T& val)
//		{
//			////生成一个新结点，给新结点赋值
//			//Node* newnode = new Node(val);
//			//Node* tail = _head->_prev;//先找到尾结点
//
//			//tail->_next = newnode;
//			//newnode->_prev = tail;
//			//newnode->_next = _head;
//			//_head->_prev = newnode;
//
//			insert(end(), val);
//		}
//
//		//尾删
//		void pop_back()
//		{
//			iterator it = end();
//			erase(--it);
//		}
//
//		//头插
//		void push_front(const T& val)
//		{
//			insert(begin(), val);
//		}
//
//		//头删
//		void pop_front()
//		{
//			iterator it(begin());
//			erase(it);
//		}
//
//		//中间插入
//		iterator insert(iterator pos, const T& val)
//		{
//			Node* newnode = new Node(val);
//			Node* posprev = pos._node->_prev;
//
//			posprev->_next = newnode;
//			newnode->_prev = posprev;
//			newnode->_next = pos._node;
//			pos._node->_prev = newnode;
//
//			iterator it(newnode);
//			return it;
//		}
//
//		//中间删除
//		iterator erase(iterator pos)
//		{
//			assert(pos != end());
//
//			Node* posprev = pos._node->_prev;
//			Node* posnext = pos._node->_next;
//
//			posprev->_next = posnext;
//			posnext->_prev = posprev;
//
//			delete pos._node;
//
//			iterator it(posnext);
//			return it;
//		}
//
//	private:
//		Node* _head;
//	};
//
//	//测试list里面存Date类型
//	class Date
//	{
//	public:
//		Date(int year = 0, int month = 0, int day = 0)
//			:_year(year)
//			, _month(month)
//			, _day(day)
//		{
//
//		}
//		//private:
//		int _year;
//		int _month;
//		int _day;
//	};
//
//	void Test1()
//	{
//		list<int> l1;
//		l1.push_back(1);
//		l1.push_back(2);
//		l1.push_back(3);
//		l1.push_back(4);
//		l1.push_front(0);
//		l1.push_front(-1);
//		l1.push_front(-2);
//		l1.push_front(-3);
//
//		l1.pop_back();
//		l1.pop_back();
//
//		l1.pop_front();
//		l1.pop_front();
//
//		list<int>::iterator it = l1.begin();
//		while (it != l1.end())
//		{
//			cout << *it << " ";
//			++it;
//		}
//		cout << endl;
//	}
//
//	void Test2()
//	{
//		list<Date> l1;
//		l1.push_back(Date());
//		l1.push_back(Date());
//		l1.push_back(Date());
//		l1.push_back(Date());
//
//		list<Date>::iterator it = l1.begin();
//		while (it != l1.end())
//		{
//			cout << it->_year << "-" << it->_month << "-" << it->_day << endl;
//			it++;
//		}
//
//	}
//
//	//测试迭代器的非const和const
//	void Test3()
//	{
//		list<int> l1;
//		l1.push_back(1);
//		l1.push_back(2);
//		l1.push_back(3);
//		l1.push_back(4);
//
//		list<int>::iterator it = l1.begin();
//		while (it != l1.end())
//		{
//			(*it)++;
//			cout << *it << " ";
//			it++;
//		}
//		cout << endl;
//
//	}
//
//	//测试拷贝构造 和 赋值=重载
//	void Test4()
//	{
//		list<int> l1;
//		l1.push_back(1);
//		l1.push_back(2);
//		l1.push_back(3);
//		l1.push_back(4);
//
//		list<int> l2(l1);
//
//		list<int> l3;
//		l3 = l2;
//
//		list<int>::iterator it1 = l1.begin();
//		while (it1 != l1.end())
//		{
//			(*it1)++;
//			cout << *it1 << " ";
//			it1++;
//		}
//		cout << endl;
//
//		list<int>::iterator it2 = l2.begin();
//		while (it2 != l2.end())
//		{
//			(*it2)++;
//			cout << *it2 << " ";
//			it2++;
//		}
//		cout << endl;
//
//		list<int>::iterator it3 = l3.begin();
//		while (it3 != l3.end())
//		{
//			(*it3)++;
//			cout << *it3 << " ";
//			it3++;
//		}
//
//		cout << endl;
//	}
//}

//#include<iostream>
//using namespace std;
//
//template<class T,size_t N>
//class arr
//{
//public:
//
//private:
//	T _arr[N];
//};
//
//int main()
//{
//	arr<int,100> a1;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//
//template<class T>
//bool Compare(T& left, T& right)
//{
//	if (left == right)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//template<>
//bool Compare<char*>(char*& left, char*& right)
//{
//	if (strcmp(left, right) == 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//int main()
//{
//	char p1[] = "hello";
//	char p2[] = "hello";
//	
//	cout << Compare(p1, p2) << endl;
//
//	char* p3 = p1;
//	char* p4 = p2;
//
//	cout << Compare(p3, p4) << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//template<class T1,class T2>
//class Date
//{
//public:
//	Date()
//	{
//		cout << "Date<T1,T2>" << endl;
//	}
//private:
//	T1 _data1;
//	T2 _data2;
//};
//
//template<>
//class Date<int,char>
//{
//public:
//	Date()
//	{
//		cout << "Date<int,char>" << endl;
//	}
//private:
//	int _data1;
//	char _data2;
//};
//
//int main()
//{
//	Date<int, int> d1;
//	Date<int, double> d2;
//
//	Date<int, char> d3;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//template<class T,size_t N>
//class Arr
//{
//public:
//
//private:
//	T _arr[N];
//};
//
//int main()
//{
//	Arr<int, 10> a1;;
//	Arr<int, 100> a2;;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//template<class T>
//bool Compare(T& left, T& right)//比较函数，比较两个值是否相等
//{
//	if (left == right)
//		return true;
//	else
//		return false;
//}
//
//template<>
//bool Compare<char*>(char*& left, char*& right)
//{
//	if (strcmp(left, right) == 0)
//		return true;
//	else
//		return false;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 10;
//	cout << Compare(a, b) << endl;
//
//	char arr1[] = "hello";
//	char arr2[] = "hello";
//
//	char* p1 = arr1;
//	char* p2 = arr2;
//
//	cout << Compare(p1, p2) << endl;
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//template<class T1,class T2>
//class Date
//{
//public:
//	Date()
//	{
//		cout << "Date<T1,T2>" << endl;
//	}
//private:
//	T1 _data1;
//	T2 _data2;
//};
//
//template<class T1,class T2>
//class Date<T1*,T2*>
//{
//public:
//	Date()
//	{
//		cout << "Date<T1*,T2*>" << endl;
//	}
//private:
//	T1* _data1;
//	T2* _data2;
//};
//
//template<class T1, class T2>
//class Date<T1&, T2&>
//{
//public:
//	Date()
//	{
//		cout << "Date<T1&,T2&>" << endl;
//	}
//private:
//	const T1& _data1 = 10;
//	const T2& _data2 = 20;
//};
//
//int main()
//{
//	Date<int, int> d1;
//	Date<int*, int*> d2;
//	Date<int&, int&> d3;
//	return 0;
//}



//#include"Add.h"
//
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int ret = Add(a, b);
//	cout << ret << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	char _name[20] = "aaaaa";
//private:
//	int _age = 20;
//};
//
//class Student :public Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "stdid:" << _stdid << endl;
//	}
//protected:
//	int _stdid = 12345678;//学号
//};
//
//int main()
//{
//	Person p1;
//	Student s1;
//
//	p1.Print();
//	s1.Print();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//
//protected:
//	char _name[20] = "aaaaa";
//	int age = 20;
//};
//
//class Student :public Person
//{
//protected:
//	int _stdid = 12345678;
//};
//
//int main()
//{
//	Student s1;
//
//	//子类对象可以赋值给父类对象、指针、引用
//	Person p1 = s1;
//	Person* p2 = &s1;
//	Person& p3 = s1;
//
//	Student* s2 = (Student*)p2;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//namespace My_less_greater
//{
//	template<class T>
//	struct less
//	{
//		bool operator()(const T& x1, const T& x2)//重载一个operator()
//		{
//			return x1 < x2;
//		}
//	};
//
//	template<class T>
//	struct greater
//	{
//		bool operator()(const T& x1, const T& x2)
//		{
//			return x1 > x2;
//		}
//	};
//}
//
//int main()
//{
//	My_less_greater::less<int> lessFunc;//定义一个less的对象
//	int a = 10;
//	int b = 20;
//	bool ret = lessFunc(a, b);//等价于 lessFunc.operator()(a,b)
//	cout << ret << endl;
//	return 0;
//}




//#include<iostream>
//#include<string>
//using namespace std;
//
//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << ":" << _age << endl;
//	}
//protected:
//	string _name = "hello";
//	int _age = 18;
//};
//
//class Student :public Person
//{
//public:
//	void Print()
//	{
//		cout << _name << ":" << _age << ":" << _sno << endl;
//	}
//protected:
//	int _sno = 12345678;
//};
//
//int main()
//{
//	//Person p1;
//	//p1.Print();
//
//	//Student s1;
//	//s1.Print();
//
//	Student s1;
//	Person p1 = s1;
//	Person* p2 = &s1;
//	Person& p3 = s1;
//
//
//
//	return 0;
//}



//
//#include<iostream>
//#include<string>
//using namespace std;
//
//class Person
//{
//public:
//	//构造函数
//	Person()
//	{
//		cout << "Person()" << endl;
//	}
//
//	//析构函数
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//
//	//拷贝构造
//	Person(const Person& tmp)
//	{
//		cout << "Person(const Person& tmp)" << endl;
//	}
//
//	//赋值=重载
//	Person& operator=(const Person& tmp)
//	{
//		cout << "Person:operator=()" << endl;
//		return *this;
//	}
//protected:
//	string _name;
//	int _age;
//};
//
//class Student :public Person
//{
//public:
//	//构造函数
//	Student()
//	{
//		cout << "Student()" << endl;
//	}
//
//	//析构函数
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//
//	//拷贝构造
//	Student(const Student& tmp)
//		:Person(tmp)
//	{
//		cout << "Student(const Student& tmp)" << endl;
//	}
//
//	//赋值=重载
//	Student& operator=(const Student& tmp)
//	{
//		Person::operator=(tmp);
//		cout << "Student:operator=()" << endl;
//		return *this;
//	}
//protected:
//	int _sno;
//};
//
//int main()
//{
//	//Person p1;
//	Student s1;
//	//cout << endl;
//	//Student s2(s1);
//
//	Student s2;
//	s2 = s1;
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//class Person
//{
//public:
//	Person(const char* name = "name", const int& age = -1)
//		:_name(name)
//		,_age(age)
//	{
//		cout << "Person()" << endl;
//	}
//protected:
//	string _name;
//	int _age;
//};
//
//class Student :public Person
//{
//public:
//	Student(const char* name = "name", const int& age = -1, const int& sno = 11111111)
//		:Person(name, age)
//		,_sno(sno)
//	{
//		cout << "Student()" << endl;
//	}
//protected:
//	int _sno;
//};
//
//int main()
//{
//	Person p1("hello", 18);
//	Student s1;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	int _age;
//};
//
//class Student :virtual public Person
//{
//public:
//	int _sno;
//};
//
//int main()
//{
//	Person p1;
//	p1._age = 1;
//	Student s1;
//	s1._age = 2;
//	s1._sno = 3;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//
//	int _age;
//};
//
//class Student :virtual public Person
//{
//public:
//
//	int _sno;
//};
//
//class Teacher :virtual public Person
//{
//public:
//
//	int _tno;
//};
//
//class Assistant :public Student, public Teacher
//{
//public:
//
//	int _aaa;
//};
//
//int main()
//{
//	Assistant a1;
//	cout << sizeof(a1) << endl;
//
//	a1.Student::_age = 1;
//	a1.Teacher::_age = 2;
//	a1._sno = 3;
//	a1._tno = 4;
//	a1._aaa = 5;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	int _age = 1;//年龄
//};
//
////继承了父类Person的所有成员
//class Student :public Person
//{
//public:
//	int _sno = 2;//学号
//};
//
//int main()
//{
//	Student s1;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-半价" << endl;
//	}
//};
//
//void Func1(Person& tmp)
//{
//	tmp.BuyTicket();
//}
//
//void Func2(Student& tmp)
//{
//	tmp.BuyTicket();
//}
//
//int main()
//{
//	Person p1;
//
//	Student s1;
//
//	Func1(p1);
//
//	Func1(s1);
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	virtual ~A()
//	{
//		cout << "~A" << endl;
//	}
//};
//
//class B :public A
//{
//public:
//	 virtual~B()
//	{
//		cout << "~b" << endl;
//	}
//};
//
//int main()
//{
//	A* pa = new A;
//	delete pa;
//
//	A* pb = new B;
//	delete pb;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//	}
//
//	int _age;
//};
//
//class Student :public Person
//{
//public:
//	//virtual void BuyTichet()
//	//{
//	//	cout << "买票-半价" << endl;
//	//}
//
//	int _sno;
//};
//
//int main()
//{
//	Person p1;
//
//	Student s1;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	virtual void ButTicket() = 0;
//};
//
//class Student :public Person
//{
//public:
//	virtual void ButTicket()
//	{
//		cout << "买票-半价" << endl;
//	}
//};
//
//int main()
//{
//	Person p1;
//	Student s1;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//protected:
//	int _b = 1;
//};
//
//class Derive :public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//protected:
//	int _d = 2;
//};
//
//int main()
//{
//	Base b;
//	Derive d;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	void BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//	}
//
//	int _age;
//};
//
//class Student :public Person
//{
//public:
//	void BuyTicket()
//	{
//		cout << "买票-半价" << endl;
//	}
//
//	int _sno;
//};
//
//template<class T>
//void BuyTicket(T& tmp)
//{
//	tmp.BuyTicket();
//}
//
//
//int main()
//{
//	Person p1;
//
//	Student s1;
//
//	BuyTicket(p1);
//	BuyTicket(s1);
//
//	return 0;
//}

//#include<iostream> 
//using namespace std;
//
//class Person
//{
//public:
//	void Print()
//	{
//
//	}
//protected:
//	int _age;
//};
//
//class Student :public Person
//{
//public:
//	
//private:
//	int _sno;
//};
//
//int main()
//{
//
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//class Person
//{
//public:
//protected:
//	string _name;
//	int _age;
//};
//
//class Student :public Person
//{
//public:
//protected:
//	int _sno;
//};
//
//int main()
//{
//	Student s1;
//	//以下这些行为都是允许的
//	Person p1 = s1;
//	Person* p2 = &s1;
//	Person& p3 = s1;
//
//	s1 = p1;//反过来就不可以
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//
//	int _age = 1;
//	int _num = 2;
//};
//
//class Student :public Person
//{
//public:
//
//	int _num = 10;
//};
//
//int main()
//{
//	Person p1;
//	Student s1;
//
//	cout << s1._num << endl;//默认情况直接输出_num是子类的_num
//	cout << s1.Person::_num << endl;//如果想要输出基类的_num，就要指定Person的作用域
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "Person" << endl;
//	}
//protected:
//	int _age;
//};
//
//class Student :public Person
//{
//public:
//	void Print(int i)
//	{
//		cout << "Student" << endl;
//	}
//protected:
//	int _sno;
//};
//
//int main()
//{
//
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//class Person
//{
//public:
//	Person(int i)
//	{
//		cout << "Person()" << endl;
//	}
//protected:
//	string _name;
//	int _age;
//};
//
//class Student :public Person
//{
//public:
//	Student()
//		:Person(1)
//	{
//		cout << "Student()" << endl;
//	}
//protected:
//	int _sno;
//};
//
//int main()
//{
//	Person p1(1);
//	cout << endl;
//	Student s1;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student :public Person
//{
//public:
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};
//
//int main()
//{
//	Student s1;
//
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
//class Person
//{
//public:
//	Person(const char* name="name")
//		:_name(name)
//	{}
//
//	Person(const Person& tmp)
//	{
//		cout << "Person(const Person& tmp)" << endl;
//	}
//protected:
//	string _name;
//};
//
//class Student :public Person
//{
//public:
//	Student(const char* name = "name", int sno = 1)
//		:Person(name)
//		,_sno(sno)
//	{}
//
//	Student(const Student& tmp)
//		:Person(tmp)
//	{
//		cout << "Student(const Student& tmp)" << endl;
//	}
//protected:
//	int _sno;
//};
//
//int main()
//{
//	Student s1;
//	Student s2(s1);
//	return 0;
//}

//#include<iostream> 
//#include<string>
//using namespace std;
//
//class Person
//{
//public:
//	Person& operator=(const Person& tmp)
//	{
//		cout << "operator=(const Person& tmp)" << endl;
//		return *this;
//	}
//protected:
//	string _name;
//};
//
//class Student :public Person
//{
//public:
//	Student& operator=(const Student& tmp)
//	{
//		Person::operator=(tmp);
//		cout << "operator=(const Student& tmp)" << endl;
//		return *this;
//	}
//protected:
//	int _sno;
//};
//
//int main()
//{
//	Student s1;
//	Student s2;
//	s2 = s1;
//	return 0;
//}

//class Person
//
//class Student :public Person
//
//class PostGraduate :public Student

//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	int _arr[10];
//};
//
//class Student :virtual public Person
//{
//public:
//	int _sno;//学生学号
//};
//
//class Teacher :virtual public Person
//{
//public:
//	int _tno;//教师编号
//};
//
//class Assiant :public Student, public Teacher
//{
//public:
//	int _aaa;
//};
//
//int main()
//{
//	cout << sizeof(Assiant);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	int _age;
//};
//
//class Student
//{
//public:
//	Person p1;
//	int _sno;
//};
//
//int main()
//{
//
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票-半价" << endl;
//	}
//};
//
//void Func(Person& tmp)
//{
//	tmp.BuyTicket();
//}
//
//int main()
//{
//	Person p1;
//	Student s1;
//
//	Func(p1);
//	Func(s1);
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class A
//{};
//
//class B:public A
//{};
//
//class Person
//{
//public:
//	virtual A* BuyTicket()
//	{
//		cout << "买票-全价" << endl;
//		return new A;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual B* BuyTicket()
//	{
//		cout << "买票-半价" << endl;
//		return new B;
//	}
//};
//
//void Func(Person& tmp)
//{
//	tmp.BuyTicket();
//}
//
//int main()
//{
//	Person p1;
//	Student s1;
//
//	Func(p1);
//	Func(s1);
//
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//
//    TreeNode(const int& tmp)
//        :val(tmp)
//        , left(nullptr)
//        , right(nullptr)
//    {}
//};
//
//vector<vector<int>> levelOrder(TreeNode* root)
//{
//    vector<vector<int>> vv;
//    queue<TreeNode*> q;
//    if (root == nullptr)
//    {
//        return vv;
//    }
//
//    q.push(root);
//    while (!q.empty())
//    {
//        vector<int> v;
//        for (int i = 0; i < q.size(); i++)
//        {
//            TreeNode* node = q.front();
//            v.push_back(node->val);
//            q.pop();
//            if (node->left)
//                q.push(node->left);
//            if (node->right)
//                q.push(node->right);
//        }
//        vv.push_back(v);
//    }
//    return vv;
//}
//
//int main()
//{
//	TreeNode* A = new TreeNode(3);
//	TreeNode* B = new TreeNode(9);
//	TreeNode* C = new TreeNode(20);
//	TreeNode* D = new TreeNode(15);
//	TreeNode* E = new TreeNode(7);
//
//	A->left = B;
//	A->right = C;
//	C->left = D;
//	C->right = E;
//
//
//    vector<vector<int>> ret = levelOrder(A);
//
//    for (int i = 0; i < ret.size(); i++)
//    {
//        for (int j = 0; j < ret[i].size(); j++)
//        {
//            cout << ret[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//}

//#include<iostream>
//using namespace std;
//
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//
//    TreeNode(const int& tmp)
//        :val(tmp)
//        , left(nullptr)
//        , right(nullptr)
//    {}
//};
//
//bool Find(TreeNode* root, TreeNode* tmp)
//{
//    if (root->left == tmp)
//    {
//        return true;
//    }
//    else if (root->right == tmp)
//    {
//        return false;
//    }
//    else
//    {
//        if (root->left != nullptr)
//        {
//            Find(root->left, tmp);
//        }
//        if (root->right != nullptr)
//        {
//            Find(root->right, tmp);
//        }
//    }
//    return false;
//}
//
//TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//{
//    if (root == p || root == q)
//    {
//        return root;
//    }
//
//    bool pInLeft, pInRight;
//    bool qInLeft, qInRight;
//
//    pInLeft = Find(root, p);
//    pInRight = !pInLeft;
//
//    qInLeft = Find(root, q);
//    qInRight = !qInLeft;
//
//    if ((pInLeft && qInRight) || (pInRight && qInLeft))
//    {
//        return root;
//    }
//    else if (pInLeft && qInLeft)
//    {
//        return lowestCommonAncestor(root->left, p, q);
//    }
//    else
//    {
//        return lowestCommonAncestor(root->right, p, q);
//    }
//}
//
//int main()
//{
//    TreeNode* A = new TreeNode(3);
//    TreeNode* B = new TreeNode(5);
//    TreeNode* C = new TreeNode(1);
//    TreeNode* D = new TreeNode(6);
//    TreeNode* E = new TreeNode(2);
//    TreeNode* F = new TreeNode(0);
//    TreeNode* G = new TreeNode(8);
//    TreeNode* H = new TreeNode(7);
//    TreeNode* I = new TreeNode(4);
//
//    A->left = B;
//    A->right = C;
//    B->left = D;
//    B->right = E;
//    C->left = F;
//    C->right = G;
//    E->left = H;
//    E->right = I;
//
//    TreeNode* ret = lowestCommonAncestor(A, B, I);
//    cout << ret->val << endl;
//
//    return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//struct TreeNode
//{
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//
//    TreeNode(const int& tmp)
//        :val(tmp)
//        , left(nullptr)
//        , right(nullptr)
//    {}
//};
//
////在中序遍历中找到tmp的下标
//int Find(vector<int>& inorder, int begin, int end, int tmp)
//{
//    int ret = begin;
//    for (int i = begin; i <= end; i++)
//    {
//        if (inorder[i] == tmp)
//        {
//            return ret;
//        }
//        else
//        {
//            ret++;
//        }
//    }
//    return 0;
//}
//
////先构建根，再去递归构造根的左子树和右子树
//TreeNode* _buildTree(vector<int>& preorder, int begin1, int end1, vector<int>& inorder, int begin2, int end2)
//{
//    TreeNode* root = new TreeNode(preorder[begin1]);//先构造根节点
//
//    int mid = Find(inorder, begin2, end2, preorder[begin1]);//找到根节点在中序遍历的位置
//    //更新begin1,end1,begin2,end2
//    int left = mid - begin2;
//    int right = end2 - mid;
//
//    int fbegin = begin1;
//    begin1 = fbegin + 1;
//    end1 = fbegin + left;
//
//    begin2 = mid - left;
//    end2 = mid - 1;
//
//    if (begin1 <= end1 && begin2 <= end2)
//        root->left = _buildTree(preorder, begin1, end1, inorder, begin2, end2);
//    else
//        root->left = nullptr;
//
//    begin1 = fbegin + left + 1;
//    end1 = fbegin + left + right;
//
//    begin2 = mid + 1;
//    end2 = mid + right;
//
//    if (begin1 <= end1 && begin2 <= end2)
//        root->right = _buildTree(preorder, begin1, end1, inorder, begin2, end2);
//    else
//        root->right = nullptr;
//
//    return root;
//}
//
//TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
//{
//    return _buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
//}
//
//void Print(TreeNode* root)
//{
//    if (root == nullptr)
//    {
//        return;
//    }
//
//    cout << root->val << " ";
//    Print(root->left);
//    Print(root->right);
//}
//
//int main()
//{
//    vector<int> preorder;
//    vector<int> inorder;
//    int arr1[] = { 3,9,20,15,7 };
//    int arr2[] = { 9,3,15,20,7 };
//
//    for (auto& e : arr1)
//    {
//        preorder.push_back(e);
//    }
//
//    for (auto& e : arr2)
//    {
//        inorder.push_back(e);
//    }
//
//    TreeNode* ret = buildTree(preorder, inorder);
//
//    Print(ret);
//
//    return 0;
//}

//#include<iostream>
//#include<string>
//#include<vector>
//#include<map>
//using namespace std;
//
//vector<string> topKFrequent(vector<string>& words, int k)
//{
//    vector<string> ret;
//    map<string, int> Countmap;
//    for (auto& e : words)
//    {
//        map<string, int>::iterator it = Countmap.find(e);
//        if (it == Countmap.end())
//        {
//            Countmap.insert(make_pair(e, 1));
//        }
//        else
//        {
//            it->second++;
//        }
//    }
//
//    for (int i = k; i > 0; i--)
//    {
//        map<string, int>::iterator itmax = Countmap.begin();
//        map<string, int>::iterator itcom = ++itmax;
//        while (itcom != Countmap.end())
//        {
//            if (itcom->second > itmax->second)
//            {
//                itmax = itcom;
//            }
//            itcom++;
//        }
//        ret.push_back(itmax->first);
//        Countmap.erase(itmax);
//    }
//    return ret;
//}
//
//int main()
//{
//    string words[] = { "i", "love", "leetcode", "i", "love", "coding" };
//    vector<string> str;
//    for (auto& e : words)
//    {
//        str.push_back(e);
//    }
//    int k = 2;
//
//    vector<string> ret = topKFrequent(str, k);
//    for (auto& e : ret)
//    {
//        cout << e << " ";
//    }
//    cout << endl;
//    return 0;
//}




//#include<iostream>
//using namespace std;
//
//class A
//{};
//class B:public A
//{};
//
//class Person
//{
//public:
//	virtual A* BuyTicket()
//	{
//		cout << "普通人：买票-全价" << endl;
//		return new A;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual B* BuyTicket()
//	{
//		cout << "学  生：买票-半价" << endl;
//		return new B;
//	}
//};
//
//void func(Person& tmp)
//{
//	tmp.BuyTicket();
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	func(p);
//	func(s);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual ~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};
//
//int main()
//{
//	Person* p = new Person;
//	Person* s = new Student;
//	delete p;
//	delete s;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	virtual void BuyTicket() 
//	{
//		cout << "普通人：买票-全价" << endl;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "学  生：买票-半价" << endl;
//	}
//};
//
//void func(Person& tmp)
//{
//	tmp.BuyTicket();
//}
//
//int main()
//{
//	Person p;
//	Student s;
//	func(p);
//	func(s);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	virtual void BuyTicket() = 0;
//};
//
//class Student :public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "学  生：买票-半价" << endl;
//	}
//};
//
//void func(Person& tmp)
//{
//	tmp.BuyTicket();
//}
//
//int main()
//{
//	Student s;
//	func(s);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	virtual void Print(int x = 0)
//	{
//		cout << x << endl;
//	}
//};
//
//class B :public A
//{
//public:
//	virtual void Print(int x = 1)
//	{
//		cout << x << endl;
//	}
//};
//
//void func(A& tmp)
//{
//	tmp.Print();
//}
//
//int main()
//{
//	B b;
//	func(b);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Base
//{
//public:
//	virtual void Print()
//	{
//		cout << "Base()" << endl;
//	}
//
//	int _val;
//};
//
//int main()
//{
//	Base b;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	virtual void func1()
//	{
//		cout << "A:func1()" << endl;
//	}
//	virtual void func2()
//	{
//		cout << "A:func2()" << endl;
//	}
//	void func3()
//	{
//		cout << "A::func3()" << endl;
//	}
//};
//class B :public A
//{
//public:
//	virtual void func1()
//	{
//		cout << "B:func1()" << endl;
//	}
//};
//int main()
//{
//	A a;
//	B b;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "普通人：买票-全价" << endl;
//	}
//};
//class Student :public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "学  生：买票-半价" << endl;
//	}
//};
//void Print()
//{
//	cout << "111" << endl;
//}
//void func(Person& tmp)
//{
//	Print();
//	tmp.BuyTicket();
//}
//int main()
//{
//	Person p;
//	Student t;
//	func(p);
//	func(t);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	virtual void func1()
//	{
//		cout << "A::func1()" << endl;
//	}
//	virtual void func2()
//	{
//		cout << "A::func2()" << endl;
//	}
//};
//class B :public A
//{
//public:
//	virtual void func1()
//	{
//		cout << "B::func1()" << endl;
//	}
//	virtual void func3()
//	{
//		cout << "B::func3()" << endl;
//	}
//	virtual void func4()
//	{
//		cout << "B::func4()" << endl;
//	}
//};
//
//typedef void(*VFTable) ();//函数指针
//
//void Print(VFTable* table)
//{
//	for (int i = 0; *(table+i) != 0; i++)
//	{
//		cout << *(table + i) << "->";
//		VFTable f = *(table + i);
//		f();
//	}
//}
//
//int main()
//{
//	A a;
//	B b;
//
//	VFTable* p = (VFTable*)(*((int*)(&b)));
//	Print(p);
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	virtual void func1() {cout << "A::func1()" << endl;}
//	virtual void func2() {cout << "A::func2()" << endl;}
//};
//
//class B
//{
//public:
//	virtual void func1() {cout << "B::func1()" << endl;}
//	virtual void func2() {cout << "B::func2()" << endl;}
//};
//
//class C :public A, public B
//{
//public:
//	virtual void func1() {cout << "C::func1()" << endl;}
//	virtual void func3() {cout << "C::func3()" << endl;}
//};
//
//typedef void(*VFTable)();
//
//void Print(VFTable* tmp)
//{
//	for (int i = 0; *(tmp + i) != nullptr; i++)
//	{
//		cout << *(tmp + i) << "->";
//		VFTable f = *(tmp + i);
//		f();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	C c;
//
//	VFTable* p1 = (VFTable*)(*((int*)(&c)));//第一张虚函数表的第一个虚函数的地址
//	VFTable* p2 = (VFTable*)(*(int*)((char*)(&c) + sizeof(A)));
//	Print(p1);
//	Print(p2);
//	return 0;
//}

//#include<iostream>
//#include<map>
//using namespace std;
//
//int main()
//{
//	map<int, int> m;
//
//	m.insert(make_pair(1, 1));
//	m.insert(make_pair(2, 2));
//	m.insert(make_pair(3, 3));
//	m.insert(make_pair(4, 4));
//	m.insert(make_pair(5, 5));
//
//	map<int, int>::iterator it = m.begin();
//
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};
//
//TreeNode* _buildTree(vector<int>& preorder, int& i, vector<int>& inorder, int begin, int end)
//{
//    TreeNode* root = new TreeNode(preorder[i]);
//
//    int sz = begin;
//    while (sz <= end)
//    {
//        if (inorder[sz] == preorder[i])
//        {
//            break;
//        }
//        else
//        {
//            sz++;
//        }
//    }
//    //[begin,sz-1] i [sz+1,end]
//
//    end = sz - 1;
//    if (begin <= end)
//        root->left = _buildTree(preorder, ++i, inorder, begin, end);
//    else
//        root->left = nullptr;
//
//    begin = sz + 1;
//    if (begin <= end)
//        root->right = _buildTree(preorder, ++i, inorder, begin, end);
//    else
//        root->right = nullptr;
//
//    return root;
//}
//
//TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
//{
//    int a = 0;
//    return _buildTree(preorder, a, inorder, 0, inorder.size() - 1);
//}
//
//int main()
//{
//    int pre[] = { 3,9,20,15,7 };
//    int in[] = { 9,3,15,20,7 };
//    
//    vector<int> preorder;
//    vector<int> inorder;
//    for (auto& e : pre)
//    {
//        preorder.push_back(e);
//    }
//
//    for (auto& e : in)
//    {
//        inorder.push_back(e);
//    }
//
//    TreeNode* ro = buildTree(preorder, inorder);
//
//}

//#pragma once
//#include<iostream>
//#include<vector>
//#include<time.h>
//using namespace std;
//
//
//template<class K, class V>
//struct AVLTreeNode
//{
//	//成员变量
//	K _key;
//	V _val;
//	AVLTreeNode<K, V>* _left;
//	AVLTreeNode<K, V>* _right;
//	AVLTreeNode<K, V>* _parent;
//	int _bf;//平衡因子，来检查树是否平衡，平衡因子由   右数-左树
//
//	//成员函数
//	AVLTreeNode(pair<K, V> p)
//		:_key(p.first)
//		, _val(p.second)
//		, _left(nullptr)
//		, _right(nullptr)
//		, _parent(nullptr)
//		, _bf(0)
//	{}
//};
//
//template<class K, class V>
//class AVLTree
//{
//public:
//	typedef AVLTreeNode<K, V> Node;
//public:
//	//构造函数
//	AVLTree()
//		:_root(nullptr)
//	{}
//
//	//插入结点
//	bool insert(const pair<K, V>& p)
//	{
//		//如果此时tree为空，则直接把结点给_root
//		if (_root == nullptr)
//		{
//			_root = new Node(p);
//			return true;
//		}
//
//		//如果tree不为空，则查找空位，将结点进行插入
//		Node* cur = _root;
//		Node* curparent = nullptr;
//		while (cur != nullptr)
//		{
//			curparent = cur;
//			if (p.first > cur->_key)
//			{
//				cur = cur->_right;
//			}
//			else if (p.first < cur->_key)
//			{
//				cur = cur->_left;
//			}
//			else
//			{
//				return false;
//			}
//		}
//
//		cur = new Node(p);//生成一个结点给空位置
//		if (curparent->_key > cur->_key)//将新结点链接到树中
//		{
//			curparent->_left = cur;
//		}
//		else
//		{
//			curparent->_right = cur;
//		}
//		cur->_parent = curparent;
//
//		//插入新结点后，更新父结点的_bf平衡因子
//		while (curparent != nullptr)
//		{
//			if (curparent->_right == cur)
//			{
//				curparent->_bf++;
//			}
//			else
//			{
//				curparent->_bf--;
//			}
//
//			if (curparent->_bf == 0)
//			{
//				break;
//			}
//			else if (curparent->_bf == 1 || curparent->_bf == -1)
//			{
//				cur = curparent;
//				curparent = cur->_parent;
//			}
//			else if (curparent->_bf == 2 || curparent->_bf == -2)
//			{
//				//进行旋转处理
//				//1.左单旋
//				//2.右左单旋
//				//3.右单旋
//				//4.左右单旋
//				if (curparent->_bf == 2)
//				{
//					if (curparent->_right->_bf == 1)
//					{
//						RotateL(curparent);//左单旋
//					}
//					else
//					{
//						RotateRL(curparent);
//					}
//				}
//				else if (curparent->_bf == -2)
//				{
//					if (curparent->_left->_bf == -1)
//					{
//						RotateR(curparent);//右单旋
//					}
//					else
//					{
//						RotateLR(curparent);
//					}
//				}
//
//				break;
//			}
//		}
//
//		return true;
//	}
//
//	//删除结点
//	void erase(const K& key)
//	{
//		Node* cur = find(key);
//		if (cur == nullptr)
//		{
//			return;
//		}
//
//		//1.cur没有左右结点
//		//2.cur没有左结点，有右结点
//		//3.cur没有右结点，有左结点
//		//4.cur有左右结点
//
//		//确定cur的位置，因为第四种情况其实可以变为1，2，3的情况
//
//		if (cur->_left != nullptr && cur->_right != nullptr)
//		{
//			Node* cur_right_min = cur->_right;
//			while (cur_right_min->_left != nullptr)
//			{
//				cur_right_min = cur_right_min->_left;
//			}
//			cur->_key = cur_right_min->_key;
//			cur->_val = cur_right_min->_val;
//
//			cur = cur_right_min;
//		}
//
//		Node* cur_parent = cur->_parent;
//		Node* del = cur;
//
//		//调整父结点平衡因子
//		while (cur_parent != nullptr)
//		{
//			if (cur_parent->_left == cur)
//			{
//				cur_parent->_bf++;
//			}
//			else if (cur_parent->_right == cur)
//			{
//				cur_parent->_bf--;
//			}
//
//			//调整完父结点的平衡因子后，要进行判断是否往上继续调，还是进行旋转，还是结束调整
//
//			//1.如果cur_parent的平衡因子为1，-1，则结束调整，将结点删除
//			//2.如果平衡因子为0，则继续向上调整
//			//3.如果平衡因子为2，则进行旋转处理
//			if (cur_parent->_bf == 1 || cur_parent->_bf == -1)
//			{
//				break;
//			}
//			else if (cur_parent->_bf == 0)
//			{
//				cur = cur_parent;
//				cur_parent = cur->_parent;
//			}
//			else if (cur_parent->_bf == 2 || cur_parent->_bf == -2)
//			{
//				if (cur_parent->_bf == 2)
//				{
//					if (cur_parent->_right->_bf == 1)
//					{
//						RotateL(cur_parent);//左单旋
//					}
//					else
//					{
//						RotateRL(cur_parent);
//					}
//				}
//				else if (cur_parent->_bf == -2)
//				{
//					if (cur_parent->_left->_bf == -1)
//					{
//						RotateR(cur_parent);//右单旋
//					}
//					else
//					{
//						RotateLR(cur_parent);
//					}
//				}
//				break;
//			}
//		}
//
//		//带整棵树树调整完成后，再删除结点
//		//删除结点分为两种情况 del为要删除的结点
//		//1.del的左子树为null，右子树不为null
//		//2.del的右子树为null，左子树不为null
//		Node* del_parent = del->_parent;
//		//如果del的parent为空，说明del是唯一的根结点
//		if (del_parent == nullptr)
//		{
//			_root = nullptr;
//		}
//		else if (del->_left == nullptr && del->_right != nullptr)
//		{
//			if (del_parent->_left == del)
//			{
//				del_parent->_left = del->_right;
//			}
//			else
//			{
//				del_parent->_right = del->_right;
//			}
//		}
//		else
//		{
//			if (del_parent->_left == del)
//			{
//				del_parent->_left = del->_left;
//			}
//			else
//			{
//				del_parent->_right = del->_left;
//			}
//		}
//		delete del;
//
//		return;
//	}
//
//	//查找结点
//	Node* find(const K& key)
//	{
//		if (_root == nullptr)
//		{
//			return nullptr;
//		}
//
//		Node* cur = _root;
//		while (cur != nullptr)
//		{
//			if (key > cur->_key)
//			{
//				cur = cur->_right;
//			}
//			else if (key < cur->_key)
//			{
//				cur = cur->_left;
//			}
//			else
//			{
//				return cur;
//			}
//		}
//		return nullptr;
//	}
//
//	//中序遍历
//	void InOrder()
//	{
//		_InOrder(_root);
//		cout << endl;
//	}
//
//	//求二叉树的高度
//	int Height(Node* root)
//	{
//		if (root == nullptr)
//		{
//			return 0;
//		}
//
//		return fmax(Height(root->_left), Height(root->_right)) + 1;
//	}
//
//	//判断是否平衡
//	bool JudgeBalance()
//	{
//		Node* root = _root;
//		return _JudgeBalance(root);
//	}
//
//	//private:
//	bool _JudgeBalance(Node* root)
//	{
//		if (root == nullptr)
//		{
//			return true;
//		}
//
//		int heightleft = Height(root->_left);
//		int heightright = Height(root->_right);
//
//		return abs(heightleft - heightright) < 2
//			&& _JudgeBalance(root->_left)
//			&& _JudgeBalance(root->_right);
//	}
//
//	void _InOrder(Node* root)
//	{
//		if (root == nullptr)
//		{
//			return;
//		}
//
//		_InOrder(root->_left);
//
//		cout << root->_key << ":" << root->_val << "	";
//
//		_InOrder(root->_right);
//	}
//
//	//左单旋
//	void RotateL(Node* first)
//	{
//		//1.first的right 指向 second的left
//		//2.second的left 指向 first
//
//		//！！！注意，因为是三叉链，引入了parent指针，所以当某个结点的left或者right改变，则该结点的孩子的parent指针也要变
//		Node* second = first->_right;
//		Node* secondLeft = second->_left;
//
//		first->_right = secondLeft;
//		if (secondLeft != nullptr)
//		{
//			secondLeft->_parent = first;
//		}
//
//		second->_left = first;
//		Node* ppNode = first->_parent;//保留first的父结点，因为first有可能是树中的其中一棵子树，要通过first的父结点来链接下面的子树
//		first->_parent = second;
//
//
//		if (first == _root)//如果first是_root
//		{
//			_root = second;
//			second->_parent = nullptr;
//		}
//		else//如果first不是_root
//		{
//			if (ppNode->_left == first)
//			{
//				ppNode->_left = second;
//			}
//			else
//			{
//				ppNode->_right = second;
//			}
//			second->_parent = ppNode;
//		}
//
//		//更新平衡因子
//		first->_bf = second->_bf = 0;
//	}
//
//	//右单旋
//	void RotateR(Node* first)
//	{
//		//1.first的left  指向  second的right
//		//2.second的right  指向  first
//		Node* second = first->_left;
//		Node* secondRight = second->_right;
//
//		first->_left = secondRight;
//		if (secondRight != nullptr)
//		{
//			secondRight->_parent = first;
//		}
//
//		second->_right = first;
//		Node* ppNode = first->_parent;
//		first->_parent = second;
//
//		if (first == _root)
//		{
//			_root = second;
//			second->_parent = nullptr;
//		}
//		else
//		{
//			if (ppNode->_left == first)
//			{
//				ppNode->_left = second;
//			}
//			else
//			{
//				ppNode->_right = second;
//			}
//			second->_parent = ppNode;
//		}
//
//		first->_bf = second->_bf = 0;
//
//	}
//
//	//右左双旋
//	void RotateRL(Node* first)
//	{
//		Node* second = first->_right;
//		Node* third = second->_left;
//
//		int bf = third->_bf;
//
//		RotateR(second);//先右单旋
//		RotateL(first);//再左单旋
//
//		//旋转完成后，更新平衡因子
//		if (bf == 1)
//		{
//			first->_bf = -1;
//			second->_bf = 0;
//			third->_bf = 0;
//		}
//		else if (bf == -1)
//		{
//			first->_bf = 0;
//			second->_bf = 1;
//			third->_bf = 0;
//		}
//		else if (bf == 0)
//		{
//			first->_bf = 0;
//			second->_bf = 0;
//			third->_bf = 0;
//		}
//	}
//
//	//左右双旋
//	void RotateLR(Node* first)
//	{
//		Node* second = first->_left;
//		Node* third = second->_right;
//
//		int bf = third->_bf;
//
//		RotateL(second);
//		RotateR(first);
//
//		if (bf == 1)
//		{
//			first->_bf = 0;
//			second->_bf = -1;
//			third->_bf = 0;
//		}
//		else if (bf == -1)
//		{
//			first->_bf = 1;
//			second->_bf = 0;
//			third->_bf = 0;
//		}
//		else if (bf == 0)
//		{
//			first->_bf = 0;
//			second->_bf = 0;
//			third->_bf = 0;
//		}
//	}
//
//	void Print()
//	{
//		cout << _root->_key << endl;
//	}
//
//	//private:
//	Node* _root;
//};
//
//
//
//
//void Test1()
//{
//	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16,14 };
//	//int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	AVLTree<int, int> tree;
//	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
//	{
//		tree.insert(make_pair(arr[i], arr[i]));
//	}
//	tree.InOrder();
//
//		for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
//	{
//		tree.erase(arr[i]);
//		tree.InOrder();
//	}
//	cout << tree.JudgeBalance() << endl;
//}
//
//void Test2()
//{
//	srand(time(0));
//	const int a = 100000000;
//	vector<int> v;
//	for (int i = 0; i < a; i++)
//	{
//		v.push_back(rand());
//	}
//
//	size_t begin = clock();
//
//	AVLTree<int, int> root;
//	for (auto& e : v)
//	{
//		root.insert(make_pair(e, e));
//	}
//
//	size_t end = clock();
//	cout << end - begin << endl;
//}
//
////测试删除结点
//void Test3()
//{
//	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16,14 };
//	AVLTree<int, int> root;
//	for (auto& e : arr)
//	{
//		root.insert(make_pair(e, e));
//	}
//	root.InOrder();
//
//	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
//	{
//		root.erase(arr[i]);
//		root.InOrder();
//	}
//	//root.erase(16);
//	//root.InOrder();
//}
//
//int main()
//{
//	Test1();
//	//Test2();
//	//Test3();
//	return 0;
//}

//#include<iostream>
//#include<unordered_set>
//using namespace std;
//
//int main()
//{
//	unordered_set<int> us;
//	us.insert(10);
//	us.insert(1);
//	us.insert(5);
//	us.insert(3);
//
//	unordered_set<int>::iterator it = us.begin();
//	while (it != us.end())
//	{
//		cout << *it << endl;
//		it++;
//	}
//
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	return 0;
//}

//#include<iostream>
//#include<unordered_map>
//#include<string>
//using namespace std;
//
//int main()
//{
//	//unordered_map<int, int> m;
//	//int arr[] = { 15,23,4,9,63,4,6 };
//	//for (auto& e : arr)
//	//{
//	//	m.insert(make_pair(e, e));
//	//}
//
//	//unordered_map<int, int>::iterator it = m.begin();
//	//while (it != m.end())
//	//{
//	//	cout << it->first << ":" << it->second << " ";
//	//	it++;
//	//}
//
//	unordered_map<string, string> m;
//	m.insert(make_pair("排序", "sort"));
//	m.insert(make_pair("水", "water"));
//	m.insert(make_pair("谁", "who"));
//
//	unordered_map<string, string>::iterator it = m.begin();
//	while (it != m.end())
//	{
//		cout << it->first << ":" << it->second << " ";
//		it++;
//	}
//
//	return 0;
//}
//
//#include<iostream>
//#include<unordered_set>
//#include<string>
//using namespace std;
//
//class Person
//{
//public:
//	Person(const char* name,int age)
//		:_name(name)
//		,_age(age)
//	{}
//
//	bool operator==(const Person& tmp) const
//	{
//		if (strcmp(_name.c_str(), tmp._name.c_str()))
//		{
//			if (_age == tmp._age)
//			{
//				return true;
//			}
//		}
//		return false;
//	}
//
////private:
//	string _name;
//	int _age;
//};
//
//struct PersonHash {
//	size_t operator()(const Person& p) const 
//	{
//		return p._age;
//	}
//};
//
//int main()
//{
//	unordered_set<Person,PersonHash> table;
//	Person p1("xiaoming", 17);
//	table.insert(p1);
//	return 0;
//}

//#include <iostream>
//#include <unordered_set>
//#include <string>
//using namespace std;
//
//// 自定义 Person 类型
//class Person {
//public:
//    string name;
//    int age;
//
//    // 构造函数
//    Person(string n, int a) : name(n), age(a) 
//    {}
//
//    // 重载相等运算符
//    bool operator==(const Person& other) const {
//        return name == other.name && age == other.age;
//    }
//};
//
//// 自定义哈希函数
//struct PersonHash {
//    size_t operator()(const Person& p) const {
//        return hash<string>()(p.name) ^ hash<int>()(p.age);
//    }
//};
//
//int main() {
//    // 创建 unordered_set 来存储 Person 对象
//    unordered_set<Person, PersonHash> personSet;
//
//    // 向 set 中插入 Person 对象
//    personSet.insert(Person("Alice", 30));
//    personSet.insert(Person("Bob", 25));
//
//    // 遍历并打印 set 中的 Person 对象
//    for (const auto& person : personSet) {
//        cout << "Name: " << person.name << ", Age: " << person.age << std::endl;
//    }
//
//    return 0;
//}

//再次复习AVLTree，并编写一篇博客
//namespace blog_AVLTree
//{
//	template<class T>
//	struct TreeNode
//	{
//		//成员变量
//		T _data;//树结点存储的数据类型
//		TreeNode<T>* _left;//左孩子指针
//		TreeNode<T>* _right;//右孩子指针
//		TreeNode<T>* _parent;//父结点指针
//		int _bf;//平衡因子
//
//		//成员函数
//		TreeNode(const T& tmp)//构造函数
//			:_data(tmp)
//			, _left(nullptr)
//			, _right(nullptr)
//			, _parent(nullptr)
//			, _bf(0)
//		{}
//	};
//
//	template<class T>
//	class AVLTree
//	{
//		typedef TreeNode<T> Node;
//	public:
//		AVLTree()
//			:_root(nullptr)
//		{}
//
//		bool insert(const T& tmp)
//		{
//			//如果根节点为空，则直接插入
//			if (_root == nullptr)
//			{
//				_root = new Node(tmp);
//				return true;
//			}
//
//			//如果根节点不为空，则先按二叉搜索树的规则进行插入
//			Node* cur = _root;
//			Node* cur_parent = nullptr;
//			while (cur != nullptr)//往下找空位
//			{
//				if (tmp > cur->_data)
//				{
//					cur_parent = cur;
//					cur = cur->_right;
//				}
//				else if (tmp < cur->_data)
//				{
//					cur_parent = cur;
//					cur = cur->_left;
//				}
//				else
//				{
//					return false;
//				}
//			}
//
//			//找到空位后，给空位一个新结点
//			cur = new Node(tmp);
//			if (cur->_data > cur_parent->_data)
//			{
//				cur_parent->_right = cur;
//				cur->_parent = cur_parent;
//			}
//			else
//			{
//				cur_parent->_left = cur;
//				cur->_parent = cur_parent;
//			}
//
//			//插入完结点后，要更新平衡因子
//			while (cur_parent != nullptr)
//			{
//				if (cur_parent->_right == cur)
//				{
//					cur_parent->_bf++;
//				}
//				else
//				{
//					cur_parent->_bf--;
//				}
//
//				if (cur_parent->_bf == 0)
//				{
//					break;
//				}
//				else if (cur_parent->_bf == 1 || cur_parent->_bf == -1)
//				{
//					cur = cur_parent;
//					cur_parent = cur_parent->_parent;
//				}
//				else if (cur_parent->_bf == 2 || cur_parent->_bf == -2)
//				{
//					//进行旋转处理
//					if (cur_parent->_bf == 2)
//					{
//						if (cur->_bf == 1)//左单旋
//						{
//							RotateL(cur_parent);
//						}
//						else if (cur->_bf == -1)//右左双旋
//						{
//							RotateRL(cur_parent);
//						}
//					}
//					else if (cur_parent->_bf == -2)
//					{
//						if (cur->_bf == 1)//左右单旋
//						{
//							RotateLR(cur_parent);
//						}
//						else if (cur->_bf == -1)//右双旋
//						{
//							RotateR(cur_parent);
//						}
//					}
//					break;
//				}
//			}
//			return true;
//		}
//
//		//左单旋
//		void RotateL(Node* cur_parent)
//		{
//			Node* cur = cur_parent->_right;
//			Node* cur_left = cur->_left;
//
//			//改变指针的链接关系
//			cur_parent->_right = cur_left;
//			if (cur_left != nullptr)
//			{
//				cur_left->_parent = cur_parent;
//			}
//
//			cur->_left = cur_parent;
//			Node* cur_parent_parent = cur_parent->_parent;
//			cur_parent->_parent = cur;
//
//			//旋转完成后要判断cur_parent是否为根
//			if (cur_parent_parent != nullptr)//说明cur_parent不是根
//			{
//				if (cur_parent_parent->_data < cur_parent->_data)
//				{
//					cur_parent_parent->_right = cur;
//					cur->_parent = cur_parent_parent;
//				}
//				else
//				{
//					cur_parent_parent->_left = cur;
//					cur->_parent = cur_parent_parent;
//				}
//			}
//			else//说明cur_parent是根
//			{
//				_root = cur;
//				cur->_parent = nullptr;
//			}
//
//			//旋转完成后，平衡因子调整为0
//			cur_parent->_bf = cur->_bf = 0;
//		}
//
//		//右单旋
//		void RotateR(Node* cur_parent)
//		{
//			Node* cur = cur_parent->_left;
//			Node* cur_right = cur->_right;
//
//			cur_parent->_left = cur_right;
//			if (cur_right != nullptr)
//			{
//				cur_right->_parent = cur_parent;
//			}
//
//			cur->_right = cur_parent;
//			Node* cur_parent_parent = cur_parent->_parent;
//			cur_parent->_parent = cur;
//
//			if (cur_parent_parent != nullptr)
//			{
//				if (cur_parent_parent->_data > cur_parent->_data)
//				{
//					cur_parent_parent->_left = cur;
//					cur->_parent = cur_parent_parent;
//				}
//				else
//				{
//					cur_parent_parent->_right = cur;
//					cur->_parent = cur_parent_parent;
//				}
//			}
//			else
//			{
//				_root = cur;
//				cur->_parent = nullptr;
//			}
//
//			cur_parent->_bf = cur->_bf = 0;
//		}
//
//		//左右双旋
//		void RotateLR(Node* cur_parent)
//		{
//			Node* cur = cur_parent->_left;
//			Node* cur_right = cur->_right;
//
//			int bf = cur_right->_bf;
//
//			//先对cur进行一个左单旋
//			RotateL(cur);
//
//			//再对cur_parent进行一个右单旋
//			RotateR(cur_parent);
//
//			//旋转完成后，要更新平衡因子
//			if (bf == -1)
//			{
//				cur->_bf = 0;
//				cur_parent->_bf = 1;
//				cur_right->_bf = 0;
//			}
//			else if (bf == 1)
//			{
//				cur->_bf = -1;
//				cur_parent->_bf = 0;
//				cur_right->_bf = 0;
//			}
//			else if (bf == 0)//特殊情况
//			{
//				cur->_bf = 0;
//				cur_parent->_bf = 0;
//				cur_right->_bf = 0;
//			}
//		}
//
//		//右左双旋
//		void RotateRL(Node* cur_parent)
//		{
//			Node* cur = cur_parent->_right;
//			Node* cur_left = cur->_left;
//
//			int bf = cur_left->_bf;
//
//			//先对cur进行一个右单旋
//			RotateR(cur);
//
//			//再对cur_parent进行一个左单旋
//			RotateL(cur_parent);
//
//			//更新平衡因子
//			if (bf == -1)
//			{
//				cur->_bf = 1;
//				cur_parent->_bf = 0;
//				cur_left->_bf = 0;
//			}
//			else if (bf == 1)
//			{
//				cur->_bf = 0;
//				cur_parent->_bf = -1;
//				cur_left->_bf = 0;
//			}
//			else if (bf == 0)
//			{
//				cur->_bf = 0;
//				cur_parent->_bf = 0;
//				cur_left->_bf = 0;
//			}
//		}
//
//	private:
//		Node* _root;
//	};
//
//	void Test1()
//	{
//		AVLTree<int> root;
//		int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//		//int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//
//		for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//		{
//			root.insert(arr[i]);
//		}
//	}
//}
//
//int main()
//{
//	blog_AVLTree::Test1();
//	return 0;
//}


//学习C++11
//#include<iostream>
//#include<string>
//#include<vector>
//#include<map>
//using namespace std;

//class Person final
//{
//private:
//	string _name;
//	int _age;
//};
//
//class Student :Person
//{
//
//};

//int main()
//{
//	//列表初始化
//	//int a = 10;
//	//int b = { 10 };
//	//
//	//vector<int> v = { 1,2,3,4,4 };
//	//for (int& e : v)
//	//{
//	//	cout << e << " ";
//	//}
//	//cout << endl;
//
//	//string str;
//	//cout << typeid(str).name() << endl;
//
//	//auto e = str;
//	//cout << typeid(e).name() << endl;
//	////auto不能做为函数的形参和返回值
//
//	//decltype(str) aaa;
//	//cout << typeid(aaa).name() << endl;
//
//	//final修饰的类不能被继承，final修饰的虚函数不能被重写
//	//override用来修饰派生类的虚函数，被修饰的虚函数必须是重写父类的虚函数而来
//
//	int a = 10;
//	int& b = a;
//	const int& c = 10;
//
//	int&& d = 10;
//	int&& e = move(a);
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//void f(int& n)
//{
//	cout << "f(int& n)" << endl;
//}
//
//void f(int&& n)
//{
//	cout << "f(int&& n)" << endl;
//}
//
//int main()
//{
//	int a = 10;
//	f(a);
//	f(10);
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//
////string f(const char* str)
////{
////	string tmp(str);
////	return tmp;
////}
//
////左值引用 一般引用的都是 变量
////右值引用 一般引用的都是 常量、表达式、返回值
//
////右值引用也是一种引用，在C++11中，将右值引用分为纯右值和将亡值
////1.纯右值：内置类型的常量或者临时变量
////2.将亡值：自定义类的临时对象
////纯右值一般用来使用与所有需要深拷贝的类，
//
//class String
//{
//public:
//	String(const char* str)
//	{
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//
//	//拷贝构造
//	//无论如何都要做深拷贝
//	String(const String& tmp)
//	{
//		_str = new char[strlen(tmp._str) + 1];
//		strcpy(_str, tmp._str);
//		cout << "深拷贝" << endl;
//	}
//	
//	//移动拷贝
//	String(String&& tmp)
//		:_str(nullptr)
//	{
//		swap(_str, tmp._str);
//		cout << "移动拷贝" << endl;
//	}
//
//private:
//	char* _str = nullptr;
//};
//
//String f(const char* str)
//{
//	String tmp(str);
//	return tmp;
//}
//
//int main()
//{
//	int x = 10;
//	//左值引用
//	int& y = x;
//
//	//右值引用
//	int&& a = 10;
//
//	//左值引用不能直接引用常量，但是const左值可以引用常量
//	/*int& b = 10;*///直接报错；
//	const int& c = 10;//可以
//
//	//右值引用不能直接引用左值，但是可以引用move后的左值
//	/*int&& e = x;*///直接报错
//	int&& z = move(x);
//
//	String s1("hello world");
//	String s2(s1);
//	String s3(move(f("aaa")));
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//void fun(int& tmp)
//{
//	cout << "左值引用" << endl;
//}
//
//void fun(const int& tmp)
//{
//	cout << "const左值引用" << endl;
//}
//
//void fun(int&& tmp)
//{
//	cout << "右值引用" << endl;
//}
//
////模板中的 && 是万能应用的意思，既能引用左值，也能引用右值
//template<class T>
//void function(T&& tmp)
//{
//	fun(tmp);
//}
//
//int main()
//{
//	function(10);//右值
//	int a = 10;
//	function(a);//左值
//
//	const int b = 10;
//	
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	auto add1 = [](int x, int y)->int {return x + y; };
//	cout << add1(a, b) << endl;
//	return 0;
//}

//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//struct Goods
//{
//public:
//	Goods(std::string& name, int& price, int& nums)
//		:_name(name)
//		,_price(price)
//		,_nums(nums)
//	{}
//	std::string _name;
//	int _price;
//	int _nums;
//};
//
//struct CompareName
//{
//	bool operator()(const Goods& tmp1, const Goods& tmp2)
//	{
//		return tmp1._nums < tmp2._nums;
//	}
//};
//
//int main()
//{
//	std::string s1("椅子");
//	vector<Goods> v;
//	Goods g1(s1, 50, 10);
//	sort(v.begin(), v.end(), CompareName());
//	return 0;
//}

//#include<string>
//#include<algorithm>
//#include<vector>
//using namespace std;
//struct Goods
//{
//	string _name; 
//	double _price; 
//	int _evaluate; 
//	Goods(const char* str, double price, int evaluate)
//		:_name(str)
//		, _price(price)
//		, _evaluate(evaluate)
//	{}
//};
//
//struct ComparePriceLess
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price < gr._price;
//	}
//};
//
//struct ComparePriceGreater
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price > gr._price;
//	}
//};
//
//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2,3 }, { "菠萝", 1.5, 4 } };
//	sort(v.begin(), v.end(), ComparePriceLess());
//	sort(v.begin(), v.end(), ComparePriceGreater());
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//struct Goods
//{
//	string _name;
//	int _price;
//	int _number;
//
//	Goods(const char* name, const int price, const int number)
//		:_name(name)
//		,_price(price)
//		,_number(number)
//	{}
//};
//
//struct CompareNameLess
//{
//	bool operator()(const Goods& g1, const Goods& g2)
//	{
//		return g1._name < g2._name;
//	}
//};
//
//struct ComparePriceLess
//{
//	bool operator()(const Goods& g1, const Goods& g2)
//	{
//		return g1._price < g2._price;
//	}
//};
//
//struct CompareNumberLess
//{
//	bool operator()(const Goods& g1, const Goods& g2)
//	{
//		return g1._number < g2._number;
//	}
//};
//
//int main()
//{
//	vector<Goods> v = { {"椅子",20,50},{"凳子",15,40},{"桌子",50,20} };
//	//sort(v.begin(), v.end(), CompareNameLess());
//	//sort(v.begin(), v.end(), ComparePriceLess());
//	//sort(v.begin(), v.end(), CompareNumberLess());
//
//	auto Compare1 = [](const Goods& g1, const Goods& g2)->bool {return g1._name < g2._name; };
//	sort(v.begin(), v.end(), Compare1);
//
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<time.h>
//using namespace std;
//
//int main()
//{
//	//srand(time(0));
//	const int n = 10000000;
//	vector<int> tmp;
//	vector<int> v1;
//	vector<int> v2;
//	vector<int> v3;
//	vector<int> v4;
//
//	for (int i = 0; i < n; i++)
//	{
//		tmp.push_back(rand());
//	}
//
//	//左值比较
//	size_t begin1 = clock();
//	for (int i = 0; i < n; i++)
//	{
//		v1.push_back(move(tmp[i]));
//	}
//	size_t end1 = clock();
//
//	size_t begin2 = clock();
//	for (int i = 0; i < n; i++)
//	{
//		v1.emplace_back(move(tmp[i])); 
//	}
//	size_t end2 = clock();
//
//	cout << end1 - begin1 << endl;
//	cout << end2 - begin2 << endl;
//
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.emplace_back(1, 2, 3, 4);
//	return 0;
//}

//#include<iostream>
//#include<time.h>
//#include<string>
//#include<map>
//#include<vector>
//#include<list>
//using namespace std;
//
//int main()
//{
//	const int n = 10000000;
//	string str[] = { "aaa","bbb","ccc","ddd","eee" };
//	list<string> v1;
//	list<string> v2;
//
//		size_t begin1 = clock();
//		for (int i = 0; i < n; i++)
//		{
//			int j = i % 5;
//			v1.push_back(str[j]);
//		}
//		size_t end1 = clock();
//
//		size_t begin2 = clock();
//		for (int i = 0; i < n; i++)
//		{
//			int j = i % 5;
//			v1.emplace_back(str[j]);
//		}
//		size_t end2 = clock();
//		
//	cout << end1 - begin1 << endl;
//	cout << end2 - begin2 << endl;
//	return 0;
//}

//int main()
//{
//	map<string, string> m1;
//	map<string, string> m2;
//
//	string str[] = { "aaa","bbb","ccc","ddd","eee" };
//
//	const int n = 1000000;
//
//	size_t begin1 = clock();
//	for (int i = 0; i < n; i++)
//	{
//		int j = i % 5;
//		m1.insert(make_pair(str[j],str[j]));
//	}
//	size_t end1 = clock();
//
//	size_t begin2 = clock();
//	for (int i = 0; i < n; i++)
//	{
//		int j = i % 5;
//		m1.emplace(str[j], str[j]);
//	}
//	size_t end2 = clock();
//
//	cout << end1 - begin1 << endl;
//	cout << end2 - begin2 << endl;
//
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	vector<int> v;
//	v.push_back(10);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//    void duplicateZeros(vector<int>& arr)
//    {
//        int left = 0;
//        int right = arr.size() - 1;
//        int count = 0;
//        int flag = 0;
//        for (left = 0; left <= right; left++)
//        {
//            if (arr[left] == 0)
//            {
//                count += 2;
//                if (count == arr.size())
//                {
//                    flag = 0;
//                    break;
//                }
//                else if (count > arr.size())
//                {
//                    flag = 1;
//                    break;
//                }
//            }
//            else if (arr[left] != 0)
//            {
//                count++;
//                if (count == arr.size())
//                {
//                    flag = 0;
//                    break;
//                }
//                else if (count > arr.size())
//                {
//                    flag = 1;
//                    break;
//                }
//            }
//        }
//
//        printf("count:%d\n", count);
//        printf("left:%d,right:%d\n", left, right);
//        printf("flag:%d\n", flag);
//
//        if (flag == 0)
//        {
//            arr[right--] = arr[left--];
//        }
//        else if (flag == 1)
//        {
//            arr[right--] = arr[left];
//            arr[right--] = arr[left--];
//        }
//
//        while (left >= 0)
//        {
//            if (arr[left] == 0)
//            {
//                arr[right--] = arr[left];
//                if (right >= 0)
//                    arr[right--] = arr[left--];
//            }
//            else if (arr[left] != 0)
//            {
//                arr[right--] = arr[left--];
//            }
//        }
//    }
//
//int main()
//{
//    vector<int> arr = { 0,0,0,0,0,0,0 };
//    duplicateZeros(arr);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	vector<vector<int>> vv;
//
//	vector<int> v1 = { 0,0,0 };
//	vector<int> v2 = { 1,1,1 };
//	vector<int> v3 = { 2,2,2 };
//
//	vv.push_back(v1);
//	vv.push_back(v2);
//	vv.push_back(v3);
//
//	vector<vector<int>>::iterator first = vv.begin();
//	vector<vector<int>>::iterator end = vv.end();
//
//	cout << (*first)[0] << endl;
//
//	return 0;
//}

//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	vector<int> v1 = { 0,0,0 };
//	vector<int> v2 = { 1,1,1 };
//	vector<int> v3 = { 2,2,2 };
//
//	vector<vector<int>> vv;
//	vv.push_back(v1);
//	vv.push_back(v2);
//	vv.push_back(v3);
//
//	vector<vector<int>>::iterator first = vv.begin();
//	vector<vector<int>>::iterator end = vv.end();
//
//	while (first != end)
//	{
//		;
//	}
//
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//vector<vector<int>> threeSum(vector<int>& nums)
//{
//    sort(nums.begin(), nums.end());
//    //将 三数之和 问题降维成 两数之和
//    vector<vector<int>> ret;
//    int end = nums.size();//nums的末尾
//    int i = 0;
//    while (i < end)
//    {
//        int left = i + 1;
//        int right = end - 1;
//        while (left < right)
//        {
//            if ((nums[left] + nums[right]) > (-nums[i]))
//            {
//                right--;
//            }
//            else if ((nums[left] + nums[right]) < (-nums[i]))
//            {
//                left++;
//            }
//            else
//            {
//                vector<int> tmp;
//                tmp.push_back(nums[i]);
//                tmp.push_back(nums[left]);
//                tmp.push_back(nums[right]);
//                ret.push_back(tmp);
//                left++;
//                right--;
//                if (left < right)
//                {
//                    while (left < right && nums[left] == nums[left - 1])
//                    {
//                        left++;
//                    }
//
//                    while (left < right && nums[right] == nums[right + 1])
//                    {
//                        right--;
//                    }
//                }
//            }
//        }
//        i++;
//        while (i < end && nums[i] == nums[i - 1])
//        {
//            i++;
//        }
//    }
//    return ret;
//}

//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//
//int minSubArrayLen(int target, vector<int>& nums) {
//    int n = nums.size();
//    int left = 0, right = 0, sum = nums[0], ret = n + 1;
//    while (right < n)
//    {
//        sum += nums[right];
//        if (sum < target)
//        {
//            right++;
//        }
//        else if (sum >= target)
//        {
//            int len = right - left + 1;
//            if (len < ret)
//            {
//                ret = len;
//            }
//            sum -= nums[left++];
//            sum -= nums[right];
//        }
//    }
//    if (ret == (n + 1))
//        return 0;
//    else
//        return ret;
//}
//
//int main()
//{
//    vector<int> a = { 1,2,3,4,5 };
//    int ret  = minSubArrayLen(15, a);
//
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <unordered_set>
//
//using namespace std;
//
//int totalFruit(vector<int>& fruits)
//{
//    unordered_set<int> um;
//    int ret = 0;
//    for (int left = 0, right = 0; right < fruits.size(); )
//    {
//        um.insert(fruits[right]);
//        if (um.size() < 3)
//        {
//            right++;
//        }
//        else
//        {
//            //先记录长度
//            ret = max(ret, right - left);
//
//            unordered_set<int>::iterator it = um.begin();
//            int tmp = *it;
//            int tmpleft = left;
//            int pos = left;
//            while (tmpleft <= right)
//            {
//                if (fruits[tmpleft] == tmp)
//                {
//                    pos = tmpleft;
//                }
//                tmpleft++;
//            }
//            left = ++pos;
//            right++;
//            um.erase(it);
//        }
//        ret = max(ret, right - left);
//    }
//    return ret;
//}
//
//int main()
//{
//    vector<int> n = { 0,1,2,2 };
//    int ret = totalFruit(n);
//    cout << ret << endl;
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int* ptr = nullptr;
//	int tmp = 1000;
//	ptr = &tmp;
//	cout << *ptr << endl;
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//class String
//{
//public:
//	String(const char* str = "")
//		:_str(nullptr)
//	{
//		cout << "Stirng()" << endl;
//		_str = new char[strlen(str) + 1];
//		strcpy(_str, str);
//	}
//
//	//拷贝构造
//	//String s2(s1)
//	String(const String& tmp)
//	{
//		cout << "String(&)" << endl;
//		_str = new char[strlen(tmp._str) + 1];
//		strcpy(_str, tmp._str);
//	}
//
//	String(String&& tmp) noexcept
//		:_str(nullptr)
//	{
//		cout << "String(&&)" << endl;
//		swap(_str, tmp._str);
//	}
//
//	~String()
//	{
//		delete _str;
//	}
//private:
//	char* _str;
//};
//
//String function(const char* str)
//{
//	String tmp(str);
//	return tmp;
//}
//
//class A
//{
//public:
//	A(const int val = 0)
//		:_val(val)
//	{
//		cout << "A()" << endl;
//	}
//
//	A(const A& tmp)
//	{
//		cout << "A(&)" << endl;
//		_val = tmp._val;
//	}
//
//	A(A&& tmp)
//	{
//		cout << "A(&&)" << endl;
//		swap(_val, tmp._val);
//	}
//
//	~A()
//	{
//	}
//
//private:
//	int _val;
//};
//
//void f(const int& a)
//{
//	cout << "&" << endl;
//}
//
//void f(const int&& a)
//{
//	cout << "&&" << endl;
//}
//
//int main()
//{
//	//int a = 10;
//	//decltype(a) b = 20;
//	//cout << b << endl;
//
//	//int a = 10;
//	//int& pa = a;
//
//	//const int& pb = 10;
//	//int&& ppa = move(a);
//
//	String s1("hello");
//	String s2(s1);
//	//String s3(move(function("hello world")));
//	String s4(move(String("aaa")));
//
//	//int a = 10;
//	//int& pa = a;
//	//int x = 10;
//	//int y = 10;
//	//int&& ppa = x + y;
//
//	//A a1(a);
//	//A a2(a1);
//	//A a3(x + y);
//
//	//f(10);
//
//	return 0;
//}
//#include<ctime>
//#include<iostream>
//#include<string>
//
//#define NUM 1000000
//
//using namespace std;
//
//void Test1()
//{
//	string s("hello world");
//	for (int i = 0; i < NUM; i++)
//	{
//		string tmp(s);
//		s = tmp;
//	}
//}
//
//void Test2()
//{
//	string s("hello world");
//	for (int i = 0; i < NUM; i++)
//	{
//		string tmp(move(s));
//		s = move(tmp);
//	}
//}
//
//int main()
//{
//	int begin1 = clock();
//	Test1();
//	int end1 = clock();
//	int begin2 = clock();
//	Test2();
//	int end2 = clock();
//
//	cout << end1 - begin1 << endl;
//	cout << end2 - begin2 << endl;
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	char str1 = 'a';
//	char str2 = 'f';
//	char str3 = 'b';
//	char str4 = 'e';
//	char ret = str1 ^ str2 ^ str3 ^ str4;
//	cout << (int)ret << endl;
//
//	return 0;
//}
//#include<iostream>
//#include<unordered_map>
//#include<vector>
//#include<string>
//
//using namespace std;
//
//vector<int> findAnagrams(string s, string p)
//{
//    vector<int> ret;
//    unordered_map<char, int> um1;//映射s
//    unordered_map<char, int> um2;//映射p
//
//    for (int i = 0; i < p.size(); i++)
//        um2[p[i]]++;
//
//    for (int left = 0, right = 0; right < s.size(); right++)
//    {
//        um1[s[right]]++;
//        if (um1.size() == um2.size())
//        {
//            if (um1 == um2)
//            {
//                ret.push_back(left);
//            }
//
//            um1[s[left]]--;
//            if (um1[s[left]] == 0)
//            {
//                um1.erase(s[left]);
//            }
//            left++;
//        }
//    }
//    return ret;
//}
//
//int main()
//{
//    string s("cbaebabacd");
//    string p("abc");
//    vector<int> ret = findAnagrams(s, p);
//
//    return 0;
//}

//#include<iostream>
//#include<string>
//
//using namespace std;
//
//void Fun(int& x) { cout << "左值引用" << endl; }
//void Fun(const int& x) { cout << "const 左值引用" << endl; }
//void Fun(int&& x) { cout << "右值引用" << endl; }
//void Fun(const int&& x) { cout << "const 右值引用" << endl; }
//
//template<typename T>
//void PerfectForward(T&& t)
//{
//	Fun(forward<T>(t));
//}
//
//int main()
//{
//	PerfectForward(10);
//	int a = 10;
//	PerfectForward(a);
//	PerfectForward(std::move(a));
//	const int b = 8;
//	PerfectForward(b);
//	PerfectForward(std::move(b)); 
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//struct Goods
//{
//	Goods(const int price, const int num, const char* name)
//		:_price(price)
//		,_num(num)
//		,_name(name)
//	{}
//
//	int _price;
//	int _num;
//	string _name;
//};
//
////struct ComparePrice
////{
////	bool operator()(const Goods& g1, const Goods& g2)
////	{
////		return g1._name > g2._name;
////	}
////};
//
//bool ComparePrice(const Goods& g1,const Goods& g2)
//{
//	return g1._num > g2._num;
//}
//
//int main()
//{
//	vector<Goods> v = { {100,200,"apple"},{90,394,"banana"},{44,243,"organe"} };
//	
//	//sort(v.begin(), v.end(), ComparePrice());
//	sort(v.begin(), v.end(), ComparePrice);
//
//
//	[] {};//lamber表达式
//	//auto add = [](int x, int y)->int {return x + y; };
//	//cout << add(1, 2) << endl;
//
//	//sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2)->bool {return g1._num > g2._num; });
//
//
//	return 0;
//}

//#include<iostream>
//#include<thread>
//#include<mutex>
//#include<vector>
//
//using namespace std;
//
//int count = 0;
//mutex mtx;
//
//void Add(int n)
//{
//	mtx.lock();
//	for (int i = 0; i < n; i++)
//	{
//		::count++;
//	}
//	mtx.unlock();
//}
//
//int main()
//{
//	//lamber表达式
//	//auto add = [](int n)
//	//	{
//	//		mtx.lock();
//	//		for (int i = 0; i < n; i++)
//	//		{
//	//			::count++;
//	//		}
//	//		mtx.unlock();
//	//	};
//
//	//thread t1([](int n)
//	//	{
//	//		for (int i = 0; i < n; i++)
//	//		{
//	//			::count++;
//	//		}
//	//	}, 1000000);
//
//	//thread t2([](int n)
//	//	{
//	//		for (int i = 0; i < n; i++)
//	//		{
//	//			::count++;
//	//		}
//	//	}, 1000000);
//
//	//t1.join();
//	//t2.join();
//	int n = 5;
//	vector<thread> vthreads(n);
//	int m = 1000000;
//	for (int i = 0; i < n; i++)
//	{
//		vthreads[i] = (thread([](int m)
//			{
//				mtx.lock();
//				for (int i = 0; i < m; i++)
//				{
//					::count++;
//				}
//				mtx.unlock();
//			}, m));
//	}
//
//	for (auto& thread : vthreads)
//	{
//		thread.join();
//	}
//
//	cout << ::count << endl;
//
//	return 0;
//}

//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//using namespace std;
//
//int NUM = 10;
//
//int main()
//{
//	mutex mtx1, mtx2;
//	condition_variable cond1, cond2;
//
//	thread t1([&]()
//		{
//			for (int i = 0; i < NUM; i += 2)
//			{
//				unique_lock<mutex> lock1(mtx1);
//				//打印偶数
//				cout << i << endl;
//				cond2.notify_one();
//				cond1.wait(lock1);
//			}
//		});
//
//	thread t2([&]()
//		{
//			for (int i = 1; i < NUM; i += 2)
//			{
//				unique_lock<mutex> lock2(mtx2);
//				//打印奇数
//				cond2.wait(lock2);
//				cout << i << endl;
//				cond1.notify_one();
//			}
//		});
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}

//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//using namespace std;
//
//int NUM = 10;
//
//mutex mtx1, mtx2;
//condition_variable cond1, cond2;
//unique_lock<mutex> lock1(mtx1);
//unique_lock<mutex> lock2(mtx2);
//
//void start1(int n)
//{
//	for (int i = 0; i < n; i += 2)
//	{
//		//打印偶数
//		cout << i << endl;
//		cond2.notify_one();
//		cond1.wait(lock1);
//	}
//}
//
//void start2(int n)
//{
//	for (int i = 1; i < n; i += 2)
//	{
//		//打印奇数
//		cond2.wait(lock2);
//		cout << i << endl;
//		cond1.notify_one();
//	}
//}
//
//int main()
//{
//	try
//	{
//		thread t1(start1, NUM);
//		thread t2(start2, NUM);
//
//		t1.join();
//		t2.join();
//	}
//	catch (exception& e)
//	{
//		cout << e.what();
//	}
//
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int Div(int n, int m)
//{
//	if (m == 0)
//	{
//		throw(string("除数为0"));
//	}
//	return n / m;
//}
//
//int main()
//{
//	int input1, input2;
//	cin >> input1 >> input2;
//	try
//	{
//		int ret = Div(input1, input2);
//		cout << ret << endl;
//	}
//	catch (const string& err)
//	{
//		cout << err << endl;
//	}
//
//	return 0;
//}

//#include<iostream>
//
//using namespace std;
//
//int Div(int m, int n)
//{
//	if (n == 0)
//	{
//		throw(string("除数为0"));
//	}
//	return m / n;
//}
//
//void func(int m, int n)
//{
//	int* space = new int[100];
//	try
//	{
//		int ret = Div(m, n);
//	}
//	catch (const string& e)
//	{
//		//cout << e << endl;
//		delete[] space;
//		throw;
//	}
//	delete[] space;
//}
//
//int main()
//{
//	int m = 10;
//	int n = 0;
//	try
//	{
//		func(m, n);
//	}
//	catch(const string& e)
//	{
//		cout << e << endl;
//	}
//
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include"SmartPtr.h"
//using namespace std;
//
//int Func1(int m, int n)
//{
//	int* tmp = new int;
//	SmartPtr<int> ptr(tmp);
//
//	if (n == 0)
//	{
//		throw(string("除数为0"));
//	}
//
//	return m / n;
//}
//
//int main()
//{
//	int m = 10, n = 0;
//	try
//	{
//		int ret = Func1(m, n);
//		cout << ret << endl;
//	}
//	catch (const string& e)
//	{
//		cout << e << endl;
//	}
//	return 0;
//}

//#include<iostream>
//#include"SmartPtr.h"
//#include<list>
//
//struct Data
//{
//	Data(const int year, const int month, const int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{}
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
//		,_next(nullptr)
//		,_prev(nullptr)
//	{}
//public:
//	T _val;
//	my::share_ptr<ListNode<T>> _next;
//	my::share_ptr<ListNode<T>> _prev;
//};
//
//int main()
//{
//	//my::auto_ptr<int> sp1(new int);
//	//*sp1 = 10;
//	//cout << *sp1 << endl;
//	//my::auto_ptr<Data> sp1(new Data(1, 1, 1));
//	//(*sp1)._day = 2;
//	//sp1->_month = 2;
//	//my::auto_ptr<int> sp1(new int(1));
//	//my::auto_ptr<int> sp2(sp1);
//
//	//my::auto_ptr<int> sp3(new int(3));
//	//sp3 = sp2;
//
//	//my::share_ptr<int> sp1(new int(1));
//	//my::share_ptr<int> sp2(sp1);
//
//	//my::share_ptr<int> sp3(new int(10));
//	//sp3 = sp1;
//
//
//
//	//int n = 10000;
//	//my::share_ptr<int> sp = new int;
//	//cout << sp.use_count() << endl;
//	//thread t1([&]()
//	//	{
//	//		for (int i = 0; i < n; i++)
//	//		{
//	//			my::share_ptr<int> tmp(sp);
//	//		}
//	//	});
//
//	//thread t2([&]()
//	//	{
//	//		for (int i = 0; i < n; i++)
//	//		{
//	//			my::share_ptr<int> tmp(sp);
//	//		}
//	//	});
//
//	//t1.join();
//	//t2.join();
//
//	//cout << sp.use_count() << endl;
//
//
//
//	my::share_ptr<ListNode<int>> sp1(new ListNode<int>);
//	my::share_ptr<ListNode<int>> sp2(new ListNode<int>);
//	
//	//sp1->_next = sp2;
//	//sp2->_prev = sp1;
//
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<thread>
//using namespace std;
//
////编写一个只能在堆上开空间的类
//class HeapOnly
//{
//public:
//	static HeapOnly* CreateObject()
//	{
//		return new HeapOnly;
//	}
//private:
//	//构造函数私有
//	HeapOnly()
//	{}
//
//	//删除拷贝构造
//	HeapOnly(const HeapOnly& tmp) = delete;
//
//	////删除赋值=重载
//	//HeapOnly operator=(const HeapOnly& tmp) = delete;
//};
//
////编写一个只能在栈上开空间的类
//class StackOnly
//{
//public:
//	static StackOnly CreateObject()
//	{
//		return StackOnly();
//	}
//private:
//	StackOnly()
//	{}
//};
//
////单例模式
//class Singleton
//{
//public:
//	static Singleton* CreateObject()
//	{
//		if (_ptr == nullptr)
//		{
//			::_sleep(1000);
//			_ptr = new Singleton;
//		}
//		return _ptr;
//	}
//private:
//	//构造函数私有
//	Singleton()
//	{}
//private:
//	static Singleton* _ptr;
//};
//Singleton* Singleton::_ptr = nullptr;
//
//int main()
//{
//	//HeapOnly h1();
//	//HeapOnly* h1 = new HeapOnly;
//	//HeapOnly* h1 = HeapOnly::CreateObject();
//	////HeapOnly h2(*h1);
//	//HeapOnly* h3 = HeapOnly::CreateObject();
//	//*h3 = *h1;
//
//	//StackOnly s1 = StackOnly::CreateObject();
//	//Singleton* s1 = Singleton::CreateObject();
//	//Singleton* s2 = Singleton::CreateObject();
//	//Singleton* s3 = Singleton::CreateObject();
//	//Singleton* s4 = Singleton::CreateObject();
//
//	//cout << s1 << endl;
//	//cout << s2 << endl;
//	//cout << s3 << endl;
//	//cout << s4 << endl;
//	//const int n = 8;
//	//vector<thread> vt;
//	//for (int i = 0; i < n; i++)
//	//{
//	//	vt.push_back(thread([]() {
//	//		Singleton* s = Singleton::CreateObject();
//	//		cout << s << endl;
//	//		}));
//	//}
//
//	//for (auto& tmp : vt)
//	//{
//	//	tmp.join();
//	//}
//
//	const int ci = 10;
//	int* pi = const_cast<int*>(&ci);
//	*pi = 20;
//	cout << *pi << endl;
//	cout << ci << endl;
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
////C++类型转换
//int main()
//{
//	//C语言类型转换：隐式类型转换，显示类型转换
//	//int i = 10;
//	//double d = 8.8888;
//	//int i2 = d;//隐式类型转换
//	//cout << i2 << endl;
//
//	//int* pi = &i;
//	//int address = (int)pi;//显示类型转换
//	//cout << address << endl;
//
//	//C++类型转换
//	int i = 10;
//	double d = 8.8888;
//	double* pd = &d;
//	int i2 = static_cast<int>(d);//用于相似类型的转换
//	cout << i2 << endl;
//
//	int* pi = &i;
//	int address = reinterpret_cast<int>(pi);//强制类型转换，适用于任何类型
//	cout << address << endl;
//
//	const int n = 10;
//	int* pn = const_cast<int*>(&n);//用于去掉对象的const属性或者volatile属性
//	*pn = 20;
//	cout << n << endl;
//	cout << *pn << endl;
//
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
////ret = func(x);
//// 上面func可能是什么呢？那么func可能是函数名？函数指针？函数对象(仿函数对象)？也有可能
////是lamber表达式对象？所以这些都是可调用的类型！如此丰富的类型，可能会导致模板的效率低下！
////为什么呢？我们继续往下看
//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	return f(x);
//}
//
//double f(double i)
//{
//	return i / 2;
//}
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};
//
//int main()
//{
//	// 函数名
//	cout << useF(f, 11.11) << endl;
//	// 函数对象
//	cout << useF(Functor(), 11.11) << endl;
//	// lamber表达式
//	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
//	return 0;
//}

//#include<vector>
//#include<string>
//#include<unordered_map>
//#include<iostream>
//
//using namespace std;
//
//vector<int> findSubstring(string s, vector<string>& words)
//{
//    vector<int> ret;
//    unordered_map<string, int> us;//存储s的哈希表
//    unordered_map<string, int> uw;//存储words的哈希表
//    int uw_size = 0;
//    //先将words中的字符串存入uw哈希表中
//    vector<string>::iterator it = words.begin();
//    while (it != words.end())
//    {
//        uw[*it]++;
//        it++;
//        uw_size++;
//    }
//
//    int flag = words[0].size();
//    for (int left = 0; left < flag; left++)
//    {
//        us.clear();
//        int us_size = 0;
//        for (int right = left; right < s.size(); right += flag)
//        {
//            string tmp = s.substr(right, flag);
//            us[tmp]++;
//            us_size++;
//            if (us_size == uw_size)
//            {
//                if (us == uw)
//                {
//                    ret.push_back(left);
//                    string del = s.substr(left, flag);
//                    us[del]--;
//                    us_size--;
//                    if (us[del] == 0)
//                    {
//                        us.erase(del);
//                    }
//                    left += flag;
//                }
//                else
//                {
//                    string del = s.substr(left, flag);
//                    us[del]--;
//                    us_size--;
//                    if (us[del] == 0)
//                    {
//                        us.erase(del);
//                    }
//                    left += flag;
//                    // us.clear();
//                    // left=right;
//                    // right-=flag;
//                    // us_size=0;
//                }
//            }
//        }
//        left
//    }
//
//    return ret;
//}

//#include <string>
//#include <unordered_map>
//#include <iostream>
//
//using namespace std;
//
//string minWindow(string s, string t)
//{
//    int hash1[128] = { 0 };//存储t字符串中字符出现的次数
//    int kinds = 0;//记录t字符串中字符的种类
//    for (auto& ch : t)
//    {
//        if (hash1[ch] == 0)
//        {
//            kinds++;
//        }
//        hash1[ch]++;
//    }
//
//    int minlen = INT_MAX;
//    int begin;
//    int hash2[128] = { 0 };
//    for (int left = 0, right = 0, count = 0; right < s.size(); right++)
//    {
//        //进窗口
//        char in = s[right];
//        hash2[in]++;
//        if (hash2[in] == hash1[in])
//        {
//            count++;
//        }
//
//        while (count == kinds)
//        {
//            //更新结果
//            if ((right - left + 1) < minlen)
//            {
//                minlen = right - left + 1;
//                begin = left;
//            }
//
//            //出窗口
//            char out = s[left];
//            if (hash2[out] == hash1[out])
//            {
//                count--;
//            }
//            hash2[out]--;
//
//            left++;
//        }
//    }
//
//    if (minlen != INT_MAX)
//        return s.substr(begin, minlen);
//    return "";
//}
//int main()
//{
//    string s("ADOBECODEBANC");
//    string t("ABC");
//    string ret = minWindow(s, t);
//    cout << ret << endl;
//	return 0;
//}
//#include <vector>
//using namespace std;
//
//int searchInsert(vector<int>& nums, int target)
//{
//    int left = 0, right = nums.size();
//    while (left <= right)
//    {
//        int mid = left + (right - left) / 2;
//        if (nums[mid] > target)
//        {
//            right = mid - 1;
//        }
//        else if (nums[mid] < target)
//        {
//            left = mid + 1;
//        }
//        else
//        {
//            return mid;
//        }
//    }
//    return left;
//}
//
//int main()
//{
//    vector<int> num = { 1,3,5,6 };
//    int target = 7;
//    int ret = searchInsert(num, target);
//    return 0;
//}

//#include <iostream>
//#include <unordered_map>
//
//using namespace std;
//
//int& Func()
//{
//	int a = 1;
//	return a;
//}
//
//int main()
//{
//	unordered_map<string, int> u;
//	u.insert(make_pair("a", 1));
//	u.insert(make_pair("b", 2));
//	u.insert(make_pair("c", 3));
//
//	auto it = u.find("b");
//
//	auto& ret = Func();
//
//	return 0;
//}
//#include <vector>
//using namespace std;
//
//int searchInsert(vector<int>& nums, int target)
//{
//    int left = 0, right = nums.size();
//    while (left < right)
//    {
//        int mid = left + (right - left) / 2;
//        if (nums[mid] >= target)
//        {
//            right = mid;
//        }
//        else
//        {
//            left = mid + 1;
//        }
//    }
//    return left;
//}
//
//int main()
//{
//    vector<int> nums = { 1,3,5,6 };
//    int ret = searchInsert(nums, 7);
//    return 0;
//}

//#include<iostream>
//#include<unordered_map>
//#include<vector>
//using namespace std;
//
//int subarraysDivByK(vector<int>& nums, int k)
//{
//    int count = 0;//返回结果
//    int sum = 0;//用于计算前缀和
//    unordered_map<int, int> um;
//    for (int i = 0; i < nums.size(); i++)
//    {
//        auto it = um.find((sum % k + k) % k);
//        if (it != um.end())
//        {
//            count += it->second;
//        }
//
//        //插入新的前缀和%k
//        sum += nums[i];
//        um[(sum % k + k) % k]++;
//    }
//    return count;
//}
//
//int main()
//{
//    vector<int> nums = { 4, 5, 0, -2, -3, 1 };
//    int  k = 5;
//    int ret = subarraysDivByK(nums, k);
//    cout << ret << endl;
//    return 0;
//}
//#include <iostream>
//#include <unordered_map>
//#include <vector>
//using namespace std;
//
//int findMaxLength(vector<int>& nums)
//{
//	//返回值
//	int length = 0;
//
//	//先处理nums数组，把0变成-1
//	auto it = nums.begin();
//	while (it != nums.end())
//	{
//		if (*it == 0)
//			*it = -1;
//		it++;
//	}
//
//	//定义一个哈希表，哈希表<前缀和，前缀和数组的长度>
//	unordered_map<int, int> um;
//	int sum = 0;//记录前缀和
//	for (int i = 0; i < nums.size(); i++)
//	{
//		sum += nums[i];
//		if (sum == 0)
//		{
//			length = i + 1;
//			if (um.count(sum) == 0)
//				um.insert(make_pair(sum, i + 1));
//			continue;
//		}
//
//		auto it = um.find(sum);
//		if (it != um.end())
//		{
//			if (length < i + 1 - it->second)
//			length = i + 1 - it->second;
//		}
//
//		if (um.count(sum) == 0)
//			um.insert(make_pair(sum, i + 1));
//	}
//	return length;
//}
//
//int main()
//{
//	vector<int> nums = { 0,1,1,0,1,1,1,0 };
//	int ret = findMaxLength(nums);
//	return 0;
//}

//#include<vector>
//using namespace std;
//
//vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k)
//{
//    int ret_row = mat.size() + 2 * k + 2;
//    int ret_col = mat[0].size() + 2 * k + 2;
//    //生成二维前缀和数组
//    vector<vector<int>> dp(ret_row, vector<int>(ret_col, 0));
//    for (int i = k + 1; i < (ret_row - k - 1); i++)
//    {
//        int end = ret_col - k - 1;
//        for (int j = k + 1; j < end; j++)
//        {
//            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - k - 1][j - k - 1];
//        }
//    }
//
//    printf("1\n");
//
//    //计算临时的tmp_answer数组
//    vector<vector<int>> tmp_answer(ret_row, vector<int>(ret_col, 0));
//    for (int i = k + 1; i < ret_row - k - 1; i++)
//    {
//        for (int j = k + 1; j < ret_col - k - 1; j++)
//        {
//            tmp_answer[i][j] = dp[i + k][j + k] - dp[i + k][j - k - 1] - dp[i - k - 1][j + k] + dp[i - k - 1][j - k - 1];
//        }
//    }
//
//    printf("2\n");
//
//    //生成返回的answer数组
//    vector<vector<int>> answer(ret_row - 2 * k - 2, vector<int>(ret_col - 2 * k - 2, 0));
//    for (int i = 0; i < ret_row - 2 * k - 2; i++)
//    {
//        for (int j = 0; j < ret_col - 2 * k - 2; j++)
//        {
//            answer[i][j] = tmp_answer[i + k + 1][j + k + 1];
//        }
//    }
//    return answer;
//}
//
//int main()
//{
//	vector<vector<int>> mat = { {1,2,3},{ 4,5,6, },{7,8,9,} };
//	vector<vector<int>> ret =  matrixBlockSum(mat, 2);
//	return 0;
//}

//#include<iostream>
//#include<thread>
//#include<string>
//#include<functional>
//
//using namespace std;
//
//class Base
//{
//public:
//	Base(int a)
//		:_a(a)
//	{}
//
//	void Print(const std::string test)
//	{
//		cout << test << ":" << _a << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	Base b1(1);
//	Base b2(2);
//
//	thread t1(bind(&Base::Print, &b1, "aaa"));
//
//	t1.join();
//
//	return 0;
//}

//#include <memory>
//#include <vector>
//
//int main() {
//	std::vector<std::auto_ptr<int>> vec;
//	vec.push_back(std::auto_ptr<int>(new int(10))); // 会导致未定义行为
//	return 0;
//}

//#include <memory>
//using namespace std;
//
//int main()
//{
//	int* new_int = nullptr;
//	unique_ptr<int> up1(new_int);
//	unique_ptr<int> up2(new_int);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Test
//{
//private:
//	uint16_t _port;
//
//public:
//	explicit Test(uint16_t port)
//		:_port(port)
//	{}
//};
//
//int main()
//{
//	int n = 3489;
//	Test t1(n);
//	return 0;
//}

//#include <iostream>
//#include <thread>
//#include <condition_variable>
//using namespace std;
//
//condition_variable _cond;
//
//int count = 0;
//
//void threadfunc()
//{
//	while (::count != 100)
//	{
//		_cond.wait();
//	}
//}
//
//int main()
//{
//
//	return 0;
//}

//#include<iostream>
//#include<memory>
//
//using namespace std;
//
//int main()
//{
//	int* newnode = new int(10);
//	shared_ptr<int> sp1(newnode);
//	shared_ptr<int> sp2(newnode);
//	return 0;
//}

//#include <iostream>
//#include <memory>
//
//class MyClass
//{
//public:
//    void show()
//    {
//        // 手动生成新的 shared_ptr
//        std::shared_ptr<MyClass> self(this);
//        std::cout << "Object is being used" << std::endl;
//    }
//
//    ~MyClass()
//    {
//        std::cout << "MyClass destroyed" << std::endl;
//    }
//};
//
//int main()
//{
//    // 创建一个 shared_ptr 管理 MyClass 对象
//    std::shared_ptr<MyClass> obj = std::make_shared<MyClass>();
//
//
//    // 调用成员函数时生成新的 shared_ptr
//    obj->show();
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <atomic>
//
//using namespace std;
//
////int main()
////{
////	int constantValue = 10;
////
////	const int* ptr = &constantValue; // 指向常ᰁ的指针
////	const int& ref = constantValue; // 常ᰁ引⽤
////
////	//*ptr = 20;
////	//constantValue = 20;
////	ref = 20;
////
////	return  0;
////}
//
//int main()
//{
//	//vector<int> v1;
//	//vector<int> v2 = v1;//等价于vector<int> v2(v1)
//
//	//std::atomic<int> value = 99;
//	//return 0;
//
//	int x = 10;
//	int y = 20;
//	const int* ptr = &x;
//
//	 ptr = &y; // 错误，不能修改指针的值
//	 //*ptr = 30; // 错误，不能修改指针所指向的内容
//}

//#include <iostream>
//using namespace std;
//
//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//int main()
//{
//	f(0);
//	f(NULL);
//	f((int*)NULL);
//	return 0;
//}



//// 类中既有成员变量，又有成员函数
//class A1
//{
//public:
//	void f1() {}
//private:
//	int _a;
//};
//
//// 类中仅有成员函数
//class A2 
//{
//public:
//	void f2() {}
//};
//// 类中什么都没有---空类
//class A3
//{};
//
//int main()
//{
//	cout << sizeof(A1) << endl;
//	cout << sizeof(A2) << endl;
//	cout << sizeof(A3) << endl;
//	return 0;
//}

//class A
//{
//public:
//	void Print()
//	{
//		cout << "Print()" << endl;
//	}
//private:
//	int _a;
//};

//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->PrintA();
//	return 0;
//}

//int main()
//{
//	A* p = nullptr;
//	p->Print();
//	return 0;
//}



//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//private:
//	// 基本类型(内置类型)
//	int _year;
//	int _month;
//	int _day;
//	// 自定义类型
//	Time _t;
//};

//#include <iostream>
//using namespace std;

//class Date
//{
//public:
//	Date()
//	{
//		_year = 1900;
//		_month = 1;
//		_day = 1;
//	}
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// 以下测试函数能通过编译吗？
//void Test()
//{
//	Date d1;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Data
//{
//public:
//	Data(int year = 2025, int month = 2, int day = 27)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "构造函数" << endl;
//	}
//
//	Data(const Data& tmp)
//		:_year(tmp._year)
//		, _month(tmp._month)
//		, _day(tmp._day)
//	{
//		cout << "拷贝构造" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//int main() {
//	A aa(1);
//	aa.Print();
//}

//int main()
//{
//
//	return 0;
//}

//class Date
//{
//public:
//
//	explicit Date(int year)
//		:_year(year)
//	{}
//
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void Test()
//{
//	Date d1(2022);
//
//	d1 = 2023;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//class Time
//{
//	//friend class Date;
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//int main()
//{
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	A(const A& aa)
//		:_a(aa._a)
//	{
//		cout << "A(const A& aa)" << endl;
//	}
//	A& operator=(const A& aa)
//	{
//		cout << "A& operator=(const A& aa)" << endl;
//		if (this != &aa)
//		{
//			_a = aa._a;
//		}
//		return *this;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//void f1(A aa)
//{}
//
//A f2()
//{
//	A aa;
//	return aa;
//}
//
//int main()
//{
//	// 传值传参
//	A aa1;
//	f1(aa1);
//	cout << endl;
//	// 传值返回
//	f2();
//	cout << endl;
//	// 隐式类型，连续构造+拷贝构造->优化为直接构造
//	f1(1);
//	// 一个表达式中，连续构造+拷贝构造->优化为一个构造
//	f1(A(2));
//	cout << endl;
//	// 一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造
//	A aa2 = f2();
//	cout << endl;
//	// 一个表达式中，连续拷贝构造+赋值重载->无法优化
//	aa1 = f2();
//	cout << endl;
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 0, int day = 0)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "构造函数" << endl;
//	}
//
//	Date& operator=(const Date& tmp)
//	{
//		if (this != &tmp)
//		{
//			_year = tmp._year;
//			_month = tmp._month;
//			_day = tmp._day;
//			cout << "operator=" << endl;
//		}
//		return *this;
//	}
//
//	~Date()
//	{
//		cout << "析构函数" << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	vector<Date> v1;
//	Date d1;
//	v1.push_back(d1);
//
//	v1.clear();
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	string s1("hello world");
//	string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	
//	return 0;
//}

//#include <iostream>
//
//int main()
//{
//	const char* str[] = "\0";
//	printf("%d\n", strlen(str));
//	return 0;
//}

//#include <assert.h>
//#include <string.h>
//#include <stdio.h>
//
//class String
//{
//public:
//	String(const char* str = "")
//		:_str(new char[strlen(str) + 1])
//	{
//		strcpy(_str, str);
//	}
//
//	void Print()
//	{
//		printf(_str);
//	}
//
//	~String()
//	{
//		if (_str != nullptr)
//		{
//			delete[] _str;
//			_str = nullptr;
//		}
//	}
//
//private:
//	char* _str;
//};
//
//int main()
//{
//	String s1;
//	String s2("hello world");
//	s1.Print();
//	s2.Print();
//	return 0;
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	vector<int> v1;
//	printf("%d\n", v1.capacity());
//	v1.push_back(1);
//	v1.push_back(1);
//	v1.push_back(1);
//	v1.push_back(1);
//	v1.push_back(1);
//	v1.push_back(1);
//	v1.push_back(1);
//	printf("%d\n", v1.capacity());
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//#pragma once
//#include<assert.h>
//#include<iostream>
//#include<vector>
//namespace Vector_blog
//{
//	template<class T>
//	class vector
//	{
//	public:
//		typedef T* iterator;//可读可写迭代器
//		typedef const T* const_iterator;//只可读迭代器
//
//		//begin迭代器
//		iterator begin()
//		{
//			return _start;
//		}
//
//		//end迭代器
//		iterator end()
//		{
//			return _finish;
//		}
//
//		//const begin迭代器
//		const_iterator begin() const
//		{
//			return _start;
//		}
//
//		//const end迭代器
//		const_iterator end() const
//		{
//			return _finish;
//		}
//	public:
//		//无参构造函数：直接全部给nullptr即可
//		vector()
//			:_start(nullptr)
//			, _finish(nullptr)
//			, _endofstorage(nullptr)
//		{}
//
//		//拷贝构造函数
//		//vector<int> v1;
//		//vector<int> v2(v1);
//		vector(const vector<T>& v)
//			:_start(nullptr)
//			, _finish(nullptr)
//			, _endofstorage(nullptr)
//		{
//			const_iterator move = v.begin();
//			while (move != v.end())
//			{
//				push_back(*move);
//				move++;
//			}
//		}
//
//		//析构函数
//		~vector()
//		{
//			delete[] _start;
//			_start = _finish = _endofstorage = nullptr;
//		}
//
//		//交换函数，用于交换两个vector
//		void Swap(vector<T>& v)
//		{
//			swap(_start, v._start);
//			swap(_finish, v._finish);
//			swap(_endofstorage, v._endofstorage);
//		}
//
//		//赋值=重载函数
//		//vector<int> v1;
//		//v1=v2;
//		vector<T>& operator=(const vector<T>& v)
//		{
//			if (this != &v)
//			{
//				vector<T> tmp(v);
//				Swap(tmp);
//			}
//			return *this;
//		}
//
//		//调整vector的数据个数
//		void resize(const size_t n, const T& val = T())//第二个参数为一个T类型的缺省值
//		{
//			if (n < size())
//			{
//				_finish = _start + n;
//			}
//			else if (n > size())
//			{
//				if (n > capacity())//如果调整后的n大于容量，则需要扩容
//				{
//					reserve(n);
//				}
//				iterator it1 = begin() + n;
//				iterator it2 = end();
//				while (it2 < it1)
//				{
//					push_back(val);
//					it2++;
//				}
//			}
//		}
//
//		//调整vector的容量
//		void reserve(const size_t n)
//		{
//			//如果要调整的容量大于原来的容量才做调整
//			if (n > capacity())
//			{
//				T* tmp = new T[n];//开辟一块新空间
//				T* tmp_start = _start;
//				T* tmp_move = tmp;
//				while (tmp_start != _finish)
//				{
//					*tmp_move++ = *tmp_start++;
//				}
//
//				//释放旧空间，并调整_start,_finish,_endofstorage的位置
//				_finish = tmp + size();
//				_endofstorage = tmp + n;
//				delete[] _start;
//				_start = tmp;
//			}
//		}
//
//		//判断vector是否为空
//		bool empty() const
//		{
//			return !size();
//		}
//
//		//尾部插入
//		void push_back(const T& val)
//		{
//			insert(end(), val);
//		}
//
//		//尾删
//		void pop_back()
//		{
//			erase(end() - 1);
//		}
//
//		//中间插入
//		iterator insert(iterator pos, const T& val)
//		{
//			assert(pos <= end());
//			//如果容量已满，则扩容
//			if (size() == capacity())
//			{
//				size_t n = pos - begin();//扩容之前需要记住pos对于_start的偏移量，以防出现迭代器失效问题
//				size_t newcapacity = size() == 0 ? 4 : capacity() * 2;
//				reserve(newcapacity);
//				pos = _start + n;//更新pos位置
//			}
//
//			//将pos位置及其后面所以数据往后挪动
//			iterator move = end();
//			while (move != pos)
//			{
//				*move = *(move - 1);
//				move--;
//			}
//
//			*pos = val;
//			_finish++;
//
//			return pos;
//		}
//
//		//中间删除
//		iterator erase(iterator pos)
//		{
//			assert(pos < end());
//
//			iterator tmp = pos + 1;
//			while (tmp != end())
//			{
//				*(tmp - 1) = *tmp;
//				tmp++;
//			}
//
//			_finish--;
//
//			return pos;
//		}
//
//		//获取数据个数
//		size_t size() const
//		{
//			return _finish - _start;
//		}
//
//		//获取容量
//		size_t capacity() const
//		{
//			return _endofstorage - _start;
//		}
//
//		//重载operator[]
//		T& operator[](size_t pos)
//		{
//			//assert(pos < size());
//			return *(_start + pos);
//		}
//
//		//clear函数
//		void clear()
//		{
//			iterator it = begin();
//			while (it != end())
//			{
//				(*it).~T();
//				it++;
//			}
//			_finish = _start;
//		}
//	private:
//		iterator _start;
//		iterator _finish;
//		iterator _endofstorage;
//	};
//}
//
//int main()
//{
//	Vector_blog::vector<string> v1;
//	v1.push_back("hello");
//	v1.push_back("world");
//
//	for (int i = 0; i < 2; i++)
//	{
//		cout << v1[i] << " ";
//	}
//	cout << endl;
//
//	v1.clear();
//	for (int i = 0; i < 2; i++)
//	{
//		cout << v1[i] << " ";
//	}
//
//	return 0;
//}


//class Person
//{
//protected:
//	string _name; // 姓名
//	string _sex;// 性别
//	int _age; // 年龄
//};
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//void Test()
//{
//	Student sobj;
//	// 1.子类对象可以赋值给父类对象/指针/引用
//	Person pobj = sobj;
//	Person* pp = &sobj;
//	Person& rp = sobj;
//
//	//2.基类对象不能赋值给派生类对象
//	//sobj = pobj;
//
//	// 3.基类的指针可以通过强制类型转换赋值给派生类的指针
//	pp = &sobj;
//	Student * ps1 = (Student*)pp; // 这种情况转换时可以的。
//	ps1->_No = 10;
//
//	pp = &pobj;
//	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
//	ps2->_No = 10;
//}



//class Person
//{
//protected:
//	string _name = "小李子"; // 姓名
//	int _num = 111; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//void Test()
//{
//	Student s1;
//	s1.Print();
//};

//#include<string>
//#include<iostream>
//using namespace std;
//
//class Person
//{
//public:
//	Person(const char* name = "peter")
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int num)
//		: Person(name)
//		, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//
//	Student(const Student& s)
//		: Person(s)
//		, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	Student& operator = (const Student& s)
//	{
//		cout << "Student& operator= (const Student& s)" << endl;
//		if (this != &s)
//		{
//			Person::operator =(s);
//			_num = s._num;
//		}
//		return *this;
//	}
//
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//protected:
//	int _num; //学号
//};
//
//void Test()
//{
//	Student s1("jack", 18);
//	Student s2(s1);
//	Student s3("rose", 17);
//	s1 = s3;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//void Fun(int& x) { cout << "左值引用" << endl; }
//void Fun(const int& x) { cout << "const 左值引用" << endl; }
//
//void Fun(int&& x) { cout << "右值引用" << endl; }
//void Fun(const int&& x) { cout << "const 右值引用" << endl; }
//// 模板中的&&不代表右值引用，而是万能引用，其既能接收左值又能接收右值。
//// 模板的万能引用只是提供了能够接收同时接收左值引用和右值引用的能力，
//// 但是引用类型的唯一作用就是限制了接收的类型，后续使用中都退化成了左值，
//// 我们希望能够在传递过程中保持它的左值或者右值的属性, 就需要用我们下面学习的完美转发
//template<typename T>
//void PerfectForward(T&& t)
//{
//	Fun(std::forward<T>(t));
//}
//int main()
//{
//	PerfectForward(10);// 右值
//	int a;
//	PerfectForward(a); // 左值
//	PerfectForward(std::move(a)); // 右值
//	const int b = 8;
//	PerfectForward(b);// const 左值
//	PerfectForward(std::move(b)); // const 右值
//	return 0;
//}

//#include <thread>
//#include <iostream>
//using namespace std;
//void ThreadFunc1(int& x)
//{
//	x += 10;
//}
//void ThreadFunc2(int* x)
//{
//	*x += 10;
//}
//int main()
//{
//	int a = 10;
//	// 在线程函数中对a修改，不会影响外部实参，因为：线程函数参数虽然是引用方式，但其实际引用的是线程栈中的拷贝
//	thread t1(ThreadFunc1, std::ref(a));
//	t1.join();
//	cout << a << endl;
//
//	//// 如果想要通过形参改变外部实参时，必须借助std::ref()函数
//	//thread t2(ThreadFunc1, std::ref(a));
//	//t2.join();
//	//cout << a << endl;
//	//// 地址的拷贝
//	//thread t3(ThreadFunc2, &a);
//	//t3.join();
//	//cout << a << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class father
//{
//public:
//	father(int afather = 0)
//		:_afather(afather)
//	{
//
//	}
//protected:
//	int _afather;
//};
//
//class son :private father
//{
//public:
//	son(int bson = 0)
//		:_bson(bson)
//	{
//		
//	}
//
//	void Print()
//	{
//		cout << _afather << endl;
//	}
//private:
//	int _bson;
//};
//
//int main()
//{
//	son s;
//	s.Print();
//
//	return 0;
//}

//#include <iostream>
//#include <unordered_map>
//using namespace std;
//
//struct Node
//{
//public:
//    int _val;
//    Node* _next;
//    Node* _prev;
//
//    Node(int val = 0)
//        :_val(val),
//        _next(nullptr),
//        _prev(nullptr)
//    {}
//};
//
//class LRUCache
//{
//private:
//    unordered_map<int, Node*> _um;
//    Node* _head;
//    int _size;//链表的长度
//    int _capacity;//链表的最大长度
//
//public:
//    LRUCache(int capacity)
//        :_head(new Node(0)),
//        _size(0),
//        _capacity(capacity)
//    {
//        _head->_next = _head;
//        _head->_prev = _head;
//    }
//
//    int get(int key)
//    {
//        auto it = _um.find(key);
//        if (it == _um.end())
//        {
//            return -1;
//        }
//        //如果找到key，要更新最新位置
//        refresh(it->second);
//        return it->second->_val;
//    }
//
//    void put(int key, int value)
//    {
//        auto it = _um.find(key);
//        if (it != _um.end())
//        {
//            it->second->_val = value;
//            refresh(it->second);
//        }
//        else
//        {
//            if (_size == _capacity)
//            {
//                popfront();
//                _size--;
//            }
//            Node* node(new Node(value));
//            pushback(node);
//            _um[key] = node;
//            _size++;
//        }
//    }
//
//    //给一个结点的指针，更新这个结点的位置到最新的位置，即链表尾部
//    void refresh(Node* node)
//    {
//        //更新这个结点的是否，需要判断，该结点是否已经是尾结点，如果是，则不动
//        if (_head->_prev == node)
//            return;
//
//        Node* prev = node->_prev;
//        Node* tail = node->_next;
//        Node* end = _head->_prev;//链表中最后一个结点的位置
//        prev->_next = tail;
//        tail->_prev = prev;
//
//        _head->_prev = node;
//        node->_next = _head;
//        node->_prev = end;
//        end->_next = node;
//    }
//
//    //将一个结点尾插到链表中
//    void pushback(Node* node)
//    {
//        Node* end = _head->_prev;
//
//        _head->_prev = node;
//        node->_next = _head;
//        node->_prev = end;
//        end->_next = node;
//    }
//
//    //删除头节点
//    void popfront()
//    {
//        Node* del = _head->_next;
//        Node* cur = del->_next;
//        _um.erase(del->_val);
//
//        _head->_next = cur;
//        cur->_prev = _head;
//        delete del;
//    }
//};
//
//int main()
//{
//    LRUCache* lRUCache(new LRUCache(2));
//    lRUCache->put(1, 0);
//    lRUCache->put(2, 2);
//    lRUCache->get(1);
//    lRUCache->put(3, 3);
//    lRUCache->get(2);
//    lRUCache->put(4, 4);
//    lRUCache->get(1);
//    lRUCache->get(3);
//    lRUCache->get(4);
//    return 0;
//}

//#include <iostream>
//#include <memory>
//
//void test1() 
//{
//	int* p = new int(12);
//	std::shared_ptr<int> sp1(p);
//	std::shared_ptr<int> sp2(p);
//}
//
//void test2()
//{
//	std::shared_ptr<int> sp1 = std::make_shared<int>();
//	std::shared_ptr<int> sp2(sp1.get());
//}
//
//int main()
//{
//	//test1();
//	test2();
//	return 0;
//}

//#include <iostream>
//#include <memory>
//using namespace std;
//
//struct Student
//{
//	int _sno;
//};
//
//int main()
//{
//
//	return 0;
//}

//int numIslands(vector<vector<char>>& grid)
//{
//    int count = 0;
//
//    for (int i = 0; i < grid.size(); i++)
//    {
//        for (int j = 0; j < grid[i].size(); j++)
//        {
//            //先判断水平方向
//            if (((j - 1) < 0 && gird[i][j + 1] == '0')
//                || ((j + 1) == grid[i].size() && gird[i][j - 1] == '0')
//                || (grid[i][j - 1] == '0' && gird[i][j + 1]) == '0')
//            {
//                count++:
//            }
//
//            //再判断竖直方向
//            if (((i - 1) < 0 && gird[i + 1][j] == '0')
//                || ((i + 1) == gird.size() && gird[i - 1][j] == '0')
//                || (gird[i - 1][j] == '0' && grid[i + 1][j] == '0'))
//            {
//                count++;
//            }
//        }
//        return count;
//    }
//
//#include <iostream>
//
//using namespace std;
//
////判断一个字符是不是数字
//bool Judge(char ch)
//{
//    if (ch >= '1' && ch <= '9')
//        return true;
//    else
//        return false;
//}
//
//int main()
//{
//    Judge('a');
//	return 0;
//}

//#include <iostream>
//#include <memory>
//#include <functional>
//using namespace std;
//
//using func = function<void()>;
//
//class Student :public enable_shared_from_this<Student>
//{
//private:
//	int _sno;
//
//public:
//	Student(int sno)
//		:_sno(sno)
//	{}
//
//	void Print()
//	{
//		shared_ptr<Student> tmp = shared_from_this();
//		cout << tmp.use_count() << endl;
//		//shared_ptr<Student> tmp(this);
//		func cb = bind(&Student::readyPrint, tmp);
//		cout << tmp.use_count() << endl;
//		cb();
//		cout << tmp.use_count() << endl;
//	}
//
//	void readyPrint()
//	{
//		cout << _sno << endl;
//	}
//};
//
//void test1()
//{
//	shared_ptr<Student> sp(new Student(10));
//	cout << sp.use_count() << endl;
//	//Student sp(10);
//	sp->Print();
//	cout << sp.use_count() << endl;
//}
//
//void Show(int& tmp)
//{
//	cout << tmp << endl;
//	tmp += 10;
//}
//
//void test2()
//{
//	int count = 20;
//	func cb = bind(Show, count);
//	cb();
//	//Show(count);
//	cout << "test2():count:" << count << endl;
//}
//
//int main()
//{
//	test2();
//
//	return 0;
//}

//#include <iostream>
//#include <memory>
//using namespace std;
//
//class TcpConnection;
//
//class Channel
//{
//private:
//	shared_ptr<TcpConnection> _tie_;
//
//public:
//	Channel()
//	{}
//
//	~Channel()
//	{
//		cout << "~Channel()" << endl;
//	}
//
//	void tie(const shared_ptr<TcpConnection>& sp)
//	{
//		cout << sp.use_count() << endl;
//		_tie_ = sp;
//	}
//};
//
//class TcpConnection :public enable_shared_from_this<TcpConnection>
//{
//private:
//	unique_ptr<Channel> _channel_;
//
//public:
//	TcpConnection()
//		:_channel_(new Channel)
//	{}
//
//	~TcpConnection()
//	{
//		cout << "~TcpConnction()" << endl;
//	}
//
//	void test()
//	{
//		shared_ptr<TcpConnection> tmp(shared_from_this());
//		cout << tmp.use_count() << endl;
//		_channel_->tie(tmp);
//		cout << tmp.use_count() << endl;
//	}
//};
//
//int main()
//{
//	shared_ptr<TcpConnection> sp(new TcpConnection);
//	cout << sp.unique() << endl;
//	sp->test();
//
//	return 0;
//}

//#include <stdio.h>
//
//int main(void) 
//{
//	printf("%s , %3s\n", "computer", "computer");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//void func(int& tmp)
//{
//	cout << "&" << endl;
//}
//
//void func(int&& tmp)
//{
//	cout << "&&" << endl;
//}
//
//int main()
//{
//	//int&& tmp = 42;
//	//cout << &tmp << endl;
//	int x = 10;
//	func(x);
//	func(10);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class String
//{
//private:
//	char* _str;
//public:
//	String(const char* str = "")
//		:_str(new char[strlen(str) + 1])
//	{
//		cout << "构造函数" << endl;
//		strcpy(_str, str);
//	}
//
//	//拷贝构造
//	String(const String& str)
//		:_str(nullptr)
//	{
//		cout << "String(&)" << endl;
//		String tmp(str._str);
//		swap(_str, tmp._str);
//	}
//
//	//移动构造
//	String(String&& str)
//		:_str(nullptr)
//	{
//		cout << "String(&&)" << endl;
//		swap(_str, str._str);
//	}
//
//	void Print()
//	{
//		cout << _str << endl;
//	}
//};
//
//String func(const char* tmp)
//{
//	String str(tmp);
//	return move(str);
//}
//
//int main()
//{
//	String s3(func("aaa"));
//	s3.Print();
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int a[] = { 1, 2, 3, 4 };
//	int* b = a;
//	*b += 2;
//	*(b + 2) = 2;
//	b++;
//	printf("%d,%d\n", *b, *(b + 2));
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Student
//{
//private:
//	int _chinese;
//	int _math;
//	int _englist;
//public:
//	Student(int chinese = 0, int math = 0, int english = 0)
//		:_chinese(chinese),
//		_math(math),
//		_englist(english)
//	{
//
//	}
//};
//
//int main()
//{
//	Student s1(56, 25, 88);
//	Student s1(56, 25, 88);
//	Student s1(56, 25, 88);
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//struct Student
//{
//	int _chinese;
//	int _math;
//	int _englist;
//
//	Student(int chinese = 0, int math = 0, int english = 0)
//		:_chinese(chinese),
//		_math(math),
//		_englist(english)
//	{}
//};
//
//struct CompareChinese
//{
//	bool operator()(const Student& s1, const Student& s2)
//	{
//		return s1._chinese < s2._chinese;
//	}
//};
//
//int main()
//{
//	//Student s1(56, 25, 88);
//	//Student s1(67, 32, 46);
//	//Student s1(89, 57, 76);
//
//	vector<Student> v = { {56, 25, 88},{99, 32, 46},{89, 57, 76} };
//
//	//sort(v.begin(), v.end(),CompareChinese());
//	sort(v.begin(), v.end(), [](const Student& s1, const Student& s2)->bool {return s1._chinese < s2._chinese; });
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//void Func(int& x)
//{
//	cout << "左值引用" << endl;
//}
//
//void Func(const int& x)
//{
//	cout << "const 左值引用" << endl;
//}
//
//void Func(int&& x)
//{
//	cout << "右值引用" << endl;
//}
//
//void Func(const int&& x)
//{
//	cout << "cosnt 右值引用" << endl;
//}
//
//template<class T>
//void test(T&& tmp)
//{
//	Func(forward<T>(tmp));
//}
//
//int main()
//{
//	int a = 10;
//	test(a);
//	test(move(a));
//
//	const int b = 20;
//	test(b);
//	test(move(b));
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//struct ListNode 
//{
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
// 
//
////先写一个 合并两个有序链表
//    // 先写一个 合并两个有序的链表
//ListNode* mergeList(ListNode* head1, ListNode* head2)
//{
//    ListNode* head = new ListNode(0);
//    while (head1 != nullptr && head2 != nullptr)
//    {
//        if (head1->val < head2->val)
//        {
//            head->next = head1;
//            head1 = head1->next;
//            head = head->next;
//        }
//        else
//        {
//            head->next = head2;
//            head2 = head2->next;
//            head = head->next;
//        }
//    }
//
//    if (head1 != nullptr)
//    {
//        head->next = head1;
//    }
//    if (head2 != nullptr)
//    {
//        head->next = head2;
//    }
//    return head->next;
//}
//
//ListNode* sortList(ListNode* head)
//{
//    if (head == nullptr || head->next == nullptr)
//        return head;
//
//    ListNode* first = new ListNode(0, head);
//    // 先求链表的长度
//    ListNode* cur = first->next;
//    int length = 0;
//    while (cur != nullptr)
//    {
//        length++;
//        cur = cur->next;
//    }
//
//    // 开始归并
//    for (int everyLength = 1; everyLength < length; everyLength *= 2)
//    {
//        ListNode* prev = first;
//        cur = first->next; // 工作指针
//        while (cur != nullptr)
//        {
//            ListNode* head1 = cur;
//            for (int i = 1; i < everyLength; i++)
//            {
//                if (cur->next == nullptr)
//                {
//                    break;
//                }
//                cur = cur->next;
//            }
//            ListNode* head2 = cur->next;
//            cur->next = nullptr;
//
//            cur = head2;
//            for (int i = 1; i < everyLength; i++)
//            {
//                if (cur == nullptr || cur->next == nullptr)
//                {
//                    break;
//                }
//                cur = cur->next;
//            }
//
//            ListNode* next = nullptr;
//            if (cur != nullptr)
//            {
//                next = cur->next;
//                cur->next = nullptr;
//            }
//
//            ListNode* ret = mergeList(head1, head2);
//            prev->next = ret;
//            while (prev->next != nullptr)
//            {
//                prev = prev->next;
//            }
//            cur = next;
//        }
//    }
//    return first->next;
//}
//}
//
//int main()
//{
//    ListNode* head1(new ListNode(-1));
//    ListNode* head2(new ListNode(5));
//    ListNode* head3(new ListNode(3));
//    ListNode* head4(new ListNode(4));
//    ListNode* head5(new ListNode(0));
//
//    head1->next = head2;
//    head2->next = head3;
//    head3->next = head4;
//    head4->next = head5;
//
//    ListNode* ret = sortList(head1);
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//struct TreeNode
//{
//	int _val;
//	TreeNode* _left;
//	TreeNode* _right;
//
//	TreeNode(int val)
//		:_val(val),
//		_left(nullptr),
//		_right(nullptr)
//	{}
//};
//
//TreeNode* CreateTree(vector<int> vec, int left, int right)
//{
//	if (left > right)
//		return nullptr;
//
//	int mid = (left + right + 1) / 2;
//	TreeNode* root = new TreeNode(vec[mid]);
//	root->_left = CreateTree(vec, left, mid - 1);
//	root->_right = CreateTree(vec, mid + 1, right);
//	return root;
//}
//
//int main()
//{
//	vector<int> v = { 1,2,3,6,7,5 };
//	TreeNode* ret =  CreateTree(v, 0, v.size() - 1);
//
//	return 0;
//}

//#include <iostream>
//#include <mutex>
//using namespace std;

////饿汉单例模式
//class Singleton
//{
//private:
//	static Singleton _one;
//
//private:
//	Singleton()
//	{
//		cout << "构造函数" << endl;
//	}
//	~Singleton() = default;
//	Singleton(const Singleton& singleton) = delete;
//	Singleton operator=(const Singleton& singleton) = delete;
//
//public:
//	static Singleton* GetInstance()
//	{
//		return &_one;
//	}
//
//	void Log(const string& message)
//	{
//		cout << message << endl;
//	}
//};
//
//Singleton Singleton::_one;//饿汉模式的单例，对象实例需要在类外初始化

//懒汉单例模式
//懒汉模式需要保证线程安全
//class Singleton
//{
//private:
//	static Singleton* _one;
//	static mutex _mtx;
//
//	Singleton()
//	{
//		cout << "构造函数" << endl;
//	}
//	~Singleton() = default;
//	Singleton(const Singleton& slt) = delete;
//	Singleton& operator=(const Singleton& slt) = delete;
//public:
//
//	static Singleton* GetInstance()
//	{
//		if (_one == nullptr)
//		{
//			lock_guard<mutex> lock(_mtx);
//			if (_one == nullptr)
//			{
//				_one = new Singleton();
//			}
//		}
//		return _one;
//	}
//
//	void log(const string& message)
//	{
//		cout << message << endl;
//	}
//};
//
//Singleton* Singleton::_one = nullptr;
//mutex Singleton::_mtx;
//
//int main()
//{
//	//Singleton* s = Singleton::GetInstance();
//	//s->Log("hello world");
//
//	Singleton* s = Singleton::GetInstance();
//	s->log("hello linux");
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int&& a = 10;
//	a++;
//	cout << a << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class mystring
//{
//private:
//	char* _str;
//public:
//	mystring(const char* str)
//		:_str(new char[strlen(str) + 1])
//	{
//		strcpy(_str, str);
//		_str[strlen(_str)] = 0;
//	}
//
//	mystring(const mystring& tmp)
//		:_str(nullptr)
//	{
//		cout << "&" << endl;
//		mystring s(tmp._str);
//		swap(_str, s._str);
//	}
//
//	mystring(mystring&& tmp)
//		:_str(nullptr)
//	{
//		cout << "&&" << endl;
//		swap(_str, tmp._str);
//	}
//
//	void Print()
//	{
//		cout << _str << endl;
//	}
//};
//
//mystring Func(int val)
//{
//	char buffer[64] = { 0 };
//	itoa(val, buffer, 10);
//	mystring ret(buffer);
//	//ret.Print();
//	return std::move(ret);
//}
//
//int main()
//{
//	//mystring s("abc");
//	//s.Print();
//	mystring ret = Func(1234);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class A
//{
//public:
//	virtual void f() {}
//};
//
//class B : public A
//{};
//
//void fun(A* pa)
//{
//	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
//	B* pb1 = static_cast<B*>(pa);
//	B* pb2 = dynamic_cast<B*>(pa);
//	cout << "pb1:" << pb1 << endl;
//	cout << "pb2:" << pb2 << endl;
//}
//int main()
//{
//	A a;
//	B b;
//	fun(&a);
//	fun(&b);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//class Stack//栈类
//{
//public:
//	Stack(int n = 10)//栈的构造函数
//	{
//		int* tmp = (int*)malloc(sizeof(int) * n);
//		_a = tmp;
//		_size = _capacity = 0;
//	}
//	~Stack()//栈的析构函数
//	{
//		free(_a);
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//
//	Stack(const Stack& tmp)
//	{
//		_a = (int*)malloc(sizeof(int) * tmp._capacity);//开一个新的堆空间给新的s2对象
//		_size = tmp._size;
//		_capacity = tmp._capacity;
//	}
//private:
//	int* _a;//指向栈的指针
//	int _size;//栈中元素个数
//	int _capacity;//栈的容量
//};
//
//int main()
//{
//	Stack s1;
//	Stack s2(s1);
//
//	return 0;
//}

//#include <iostream>
//#include "mystring.h"
//
//int main()
//{
//	string_blog::Test1();
//	string_blog::Test2();
//	string_blog::Test3();
//	string_blog::Test4();
//	string_blog::Test5();
//
//	return 0;
//}

//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//constexpr int MAX_NUM = 200;
//
//// 共享状态
//std::mutex              mtx;
//std::condition_variable cv;
//int                     counter = 0;
//bool                    turn_even = true;  // true: 偶数线程打印，false: 奇数线程打印
//
//// 打印偶数的线程
//void print_even() 
//{
//    while (true) 
//    {
//        std::unique_lock<std::mutex> lock(mtx);
//        // 等待：要么轮到偶数线程，要么超出范围终止
//        cv.wait(lock, [] { return turn_even || counter > MAX_NUM; });
//
//        if (counter > MAX_NUM) 
//        {
//            // 通知对方也退出
//            cv.notify_all();
//            break;
//        }
//
//        // 此时 counter ≤ MAX_NUM 且 turn_even == true
//        std::cout << counter << std::endl;
//        ++counter;
//
//        // 切换为奇数线程
//        turn_even = false;
//        // 唤醒对方
//        cv.notify_all();
//    }
//}
//
//// 打印奇数的线程
//void print_odd() 
//{
//    while (true) 
//    {
//        std::unique_lock<std::mutex> lock(mtx);
//        // 等待：要么轮到奇数线程，要么超出范围终止
//        cv.wait(lock, [] { return !turn_even || counter > MAX_NUM; });
//
//        if (counter > MAX_NUM) 
//        {
//            cv.notify_all();
//            break;
//        }
//
//        // 此时 counter ≤ MAX_NUM 且 turn_even == false
//        std::cout << counter << std::endl;
//        ++counter;
//
//        // 切换为偶数线程
//        turn_even = true;
//        cv.notify_all();
//    }
//}
//
//int main() {
//    std::thread t_even(print_even);
//    std::thread t_odd(print_odd);
//
//    t_even.join();
//    t_odd.join();
//    return 0;
//}

//#include <iostream>
//#include <thread>
//#include <condition_variable>
//#include <mutex>
//
//using namespace std;
//
//int count = 0;
//mutex mtx;
//
//condition_variable cond1;
//condition_variable cond2;
//
//void print_one()
//{
//	while (true)
//	{
//		unique_lock<mutex> lock(mtx);
//		while (::count % 2 == 0)
//		{
//			::cond1.wait(lock);
//		}
//
//		if (::count > 200)
//		{
//			break;
//		}
//
//		cout << ::count++ << endl;
//		cond2.notify_one();
//	}
//}
//
//void print_two()
//{
//	while (true)
//	{
//		unique_lock<mutex> lock(mtx);
//		while (::count % 2 != 0)
//		{
//			::cond2.wait(lock);
//		}
//
//		if (::count > 200)
//		{
//			break;
//		}
//		cout << ::count++ << endl;
//		cond1.notify_one();
//	}
//}
//
//int main()
//{
//	thread t1(print_one);
//	thread t2(print_two);
//
//	t1.join();
//	cout << "t1->join" << endl;
//	t2.join();
//	cout << "t2->join" << endl;
//	return 0;
//}
//
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//constexpr int MAX_NUM = 200;
//
//std::mutex              mtx;
//std::condition_variable cv_even, cv_odd;
//int                     counter = 0;
//
////打印偶数
//void print_even() 
//{
//    std::unique_lock<std::mutex> lock(mtx);
//    while (counter <= MAX_NUM) 
//    {
//        // 等待轮到偶数或已经结束
//        //cv_even.wait(lock, [] { return (counter % 2 == 0) || (counter > MAX_NUM); });
//        while (counter % 2 != 0)
//        {
//            cv_even.wait(lock);
//        }
//
//        if (counter > MAX_NUM) 
//            break;
//
//        std::cout << counter << std::endl;
//        ++counter;
//        // 唤醒奇数线程
//        cv_odd.notify_one();
//    }
//    // 最后确保对方能退出
//    cv_odd.notify_one();
//}
//
////打印奇数
//void print_odd() 
//{
//    std::unique_lock<std::mutex> lock(mtx);
//    while (counter <= MAX_NUM) 
//    {
//        // 等待轮到奇数或已经结束
//        //cv_odd.wait(lock, [] { return (counter % 2 == 1) || (counter > MAX_NUM); });
//        while (counter % 2 == 0)
//        {
//            cv_odd.wait(lock);
//        }
//
//        if (counter > MAX_NUM) 
//            break;
//
//        std::cout << counter << std::endl;
//        ++counter;
//        // 唤醒偶数线程
//        cv_even.notify_one();
//    }
//    cv_even.notify_one();
//}
//
//int main() {
//    std::thread t_e(print_even);
//    std::thread t_o(print_odd);
//    t_e.join();
//    t_o.join();
//    return 0;
//}
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//
//	return 0;
//}

//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//class Solution
//{
//    string path;
//    vector<string> ret;
//
//public:
//    vector<string> letterCasePermutation(string s)
//    {
//        dfs(s, 0);
//        return ret;
//    }
//
//    void dfs(const string& s, int pos)
//    {
//        if (path.size() == s.size())
//        {
//            ret.push_back(path);
//            return;
//        }
//
//        unsigned char c = static_cast<unsigned char>(s[pos]);
//        if (isalpha(c))//说明是字母
//        {
//            //先统一全部转换成小写，在进行后面的操作
//            c = tolower(s[pos]);
//            cout << c << " ";
//
//            path += c;
//            dfs(s, pos + 1);
//            path.pop_back();
//
//            c = toupper(s[pos]);
//            cout << c << " ";
//
//            path += c;
//            dfs(s, pos + 1);
//            path.pop_back();
//
//        }
//        else//说明是数字
//        {
//            cout << s[pos] << " ";
//
//            path += s[pos];
//            dfs(s, pos + 1);
//            path.pop_back();
//
//        }
//    }
//};
//
//int main()
//{
//    string s("a1b2");
//    vector<string> ret = Solution().letterCasePermutation(s);
//
//
//	return 0;
//}
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
////O(n)
//string join(const vector<string>& arr, const string& seq)
//{
//	//可以进行一个预估的长度，避免频繁扩容
//	size_t total = 0;
//	size_t n = arr.size();
//	for (size_t i = 0; i < n; i++)
//	{
//		total += arr[i].size();
//	}
//	total += seq.size() * (n - 1);
//
//	string ret;
//	ret.reserve(total);
//
//	for (size_t i = 0; i < n; i++)
//	{
//		ret += arr[i];
//		if (i == arr.size() - 1)
//		{
//			break;
//		}
//		ret += seq;
//	}
//	return ret;
//}
//
//int main()
//{
//
//	return 0;
//}

//#include <iostream>
//#include <list>
//#include <string>
//#include <vector>
//using namespace std;
//
//void dfs(const vector<char>& str, vector<string>& ret, string& path, int pos)
//{
//	if (pos == 26)
//		return;
//
//	for (int i = pos; i < str.size(); i++)
//	{
//		path += str[i];
//		ret.push_back(path);
//		dfs(str, ret, path, i + 1);
//		path.pop_back();
//	}
//}
//
//vector<string> func()
//{
//	vector<char> str;
//	for (char i = 'a'; i <= 'z'; i++)
//	{
//		str.push_back(i);
//	}
//	vector<string> ret;
//	string path;
//	dfs(str, ret, path, 0);
//	return ret;
//}
//
//int main()
//{
//	vector<string> ret = func();
//	//for (int i = 0; i < ret.size(); i++)
//	//{
//	//	cout << ret[i] << " ";
//	//}
//	cout << ret.size();
//	return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

int func(int n)
{
	vector<bool> arr(n + 1, true);
	arr[0] = arr[1] = false;

	for (int i = 2; i < arr.size(); i++)
	{
		if (arr[i] == true)
		{
			for (int j = i*2; j < arr.size(); j += i)
			{
				arr[j] = false;
			}
		}
	}

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		if (arr[i] == true)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	cout << func(9999999999) << endl;
	return 0;
}