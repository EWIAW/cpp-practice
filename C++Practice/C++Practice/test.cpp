//#include<iostream>

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

#include<iostream>
#include<thread>
#include<mutex>
#include<vector>

using namespace std;

int count = 0;
mutex mtx;

void Add(int n)
{
	mtx.lock();
	for (int i = 0; i < n; i++)
	{
		::count++;
	}
	mtx.unlock();
}

int main()
{
	//lamber表达式
	//auto add = [](int n)
	//	{
	//		mtx.lock();
	//		for (int i = 0; i < n; i++)
	//		{
	//			::count++;
	//		}
	//		mtx.unlock();
	//	};

	//thread t1([](int n)
	//	{
	//		for (int i = 0; i < n; i++)
	//		{
	//			::count++;
	//		}
	//	}, 1000000);

	//thread t2([](int n)
	//	{
	//		for (int i = 0; i < n; i++)
	//		{
	//			::count++;
	//		}
	//	}, 1000000);

	//t1.join();
	//t2.join();
	int n = 5;
	vector<thread> vthreads(n);
	int m = 1000000;
	for (int i = 0; i < n; i++)
	{
		vthreads[i] = (thread([](int m)
			{
				mtx.lock();
				for (int i = 0; i < m; i++)
				{
					::count++;
				}
				mtx.unlock();
			}, m));
	}

	for (auto& thread : vthreads)
	{
		thread.join();
	}

	cout << ::count << endl;

	return 0;
}