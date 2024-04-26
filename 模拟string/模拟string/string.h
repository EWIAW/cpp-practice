#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

																				//实现一个简单的string类
namespace Simple_String
{
	class string
	{
	public:
		//构造函数
		//string()
		//	:_str(new char)
		//{
		//	(*_str) = '\0';
		//}
		// 
		//string(const char* pstr)
		//	:_str(new char[strlen(pstr)+1])
		//{
		//	strcpy(_str, pstr);
		//}
		
		//全缺省构造函数
		string(const char* pstr = "")
			:_str(new char[strlen(pstr)+1])
		{
			strcpy(_str, pstr);
		}

		//析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		//拷贝构造
		string(const string& pstr)
			:_str(new char[pstr.size() + 1])
		{
			strcpy(_str, pstr._str);
		}

		//赋值运算符重载
		string& operator=(const string& pstr)
		{
			if (this != &pstr)//避免自己给自己赋值，浪费性能
			{
				char* tmp = new char[pstr.size() + 1];//先申请一块新的空间
				strcpy(tmp, pstr._str);//将要赋值的内容拷贝到新空间中
				delete[] _str;//释放_str指向的空间
				_str = tmp;//将新空间给到_str

				return *this;//返回this字符串，处理连等操作
			}
		}

		//获取字符串长度
		size_t size() const
		{
			return strlen(_str);
		}

		//获取字符串的某个字符
		char& operator[](int size) const
		{
			return *(_str + size);
		}

	private:
		char* _str;
	};

	//重载cout<<
	ostream& operator<<(ostream& out,string& str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			out << str[i];
		}
		out << endl;

		return out;
	}

	//测试构造函数
	void Test1()
	{
		string s1;
		string s2("hello");
	}

	//测试遍历
	void Test2()
	{
		string s1;
		const string s2("hello");
		for (int i = 0; i < s1.size(); i++)
		{
			//s1[i]++;
			cout << s1[i] << " ";
		}
		cout << endl;

		for (int i = 0; i < s2.size(); i++)
		{
			//s1[i]++;
			cout << s2[i] << " ";
		}
		cout << endl;
	}

	//测试拷贝构造 和 赋值
	void Test3()
	{
		string s1("hello");
		string s2(s1);
		string s3;
		s2 = s2;

		std::cout << s1 << std::endl;
		std::cout << s2 << std::endl;
		std::cout << s3 << std::endl;

	}
}



																				//模拟实现完整string的增删改查
namespace Full_String
{
	class string
	{
	public:
		//构造函数
		string(const char* pstr = "")
			:_str(new char[strlen(pstr) + 1])//多开的空间用于存放\0
			,_size(strlen(pstr))
			,_capacity(strlen(pstr))
		{
			strcpy(_str, pstr);
		}

		//析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		//拷贝构造	传统写法
		//string(const string& pstr)
		//	:_str(new char[pstr.size()+1])
		//	,_size(pstr._size)
		//	,_capacity(pstr._capacity)
		//{
		//	strcpy(_str, pstr._str);
		//}

		//拷贝构造	现代写法
		//string s2(s1)
		string(const string& pstr)
			:_str(nullptr)
		{
			string tmp(pstr._str);
			Swap(tmp);
		}

		void Swap(string& pstr)
		{
			swap(_str, pstr._str);
			swap(_size, pstr._size);
			swap(_capacity, pstr._capacity);
		}

		//赋值运算符重载	传统写法
		//string& operator=(const string& pstr)
		//{
		//	if (this != &pstr)
		//	{
		//		char* tmp = new char[pstr.size() + 1];//开一块新的空间给this
		//		strcpy(tmp, pstr._str);//将要赋值的内容给到新开的空间
		//		delete[] _str;
		//		_str = tmp;
		//		_size = _capacity = pstr._size;

		//		return *this;
		//	}
		//}

		//赋值=重载	现代写法
		//string s3;
		//s3=s2;
		string& operator=(string pstr)
		{
			Swap(pstr);
			return *this;
		}

		//迭代器
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		//获取字符串的有效字符个数
		size_t size() const
		{
			return _size;
		}

		//获取字符串的容量
		size_t capacity() const
		{
			return _capacity;
		}

		//返回字符串的第i个字符
		char& operator[](size_t i) const
		{
			assert(i < _size);
			return _str[i];
		}

		//返回C形式的字符串
		char* c_str() const
		{
			return _str;
		}

		//调整它的size
		void resize(size_t i,char ch= '0')
		{
			if (i > _size)//如果需要调整后的size比之前大
			{
				//如果调整后的size比底层的capacity大，则需要扩容
				if (i > _capacity)
				{
					reserve(i);	
				}
				 
				memset(_str + _size, ch, sizeof(char) * (i - _size));

				_size = i;
				//char* tmp = new char[i + 1];//开一个更大的空间
				//memset(tmp, 0, sizeof(char) * (i + 1));//将这块空间的值全部给0
				//strcpy(tmp, _str);//将原始空间拷贝给新空间
				//delete[] _str;
				//_str = tmp;

				//_size = _capacity = i;
			}
			if (i < _size)//如果调整后的size比之前小
			{
				_size = i;
				_str[i] = '\0';
			}
		}

		//调整它的capacity
		void reserve(size_t i)
		{
			if (i > _capacity)
			{
				char* tmp = new char[i + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = i;
			}
		}

		//尾插一个字符
		void push_back(const char& ch)
		{
			if (_size == _capacity)//如果，则需要扩容
			{
				size_t newcapacity = (_capacity == 0 ? 4 : _capacity * 2);
				//char* tmp = new char[newcapacity + 1];
				//strcpy(tmp, _str);
				//delete[] _str;
				//_str = tmp;  
				//_capacity = newcapacity;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			_size++;
			_str[_size] = 0;//将最后一个字符的下一个位置给\0		！！！
		}

		//尾插一个字符串
		void append(const char* pstr)
		{
			//char* tmp = new char[_size + strlen(pstr) + 1];
			//strcpy(tmp, _str);//想拷贝原来的
			//strcpy(tmp + _size, pstr);//再拷贝新插入的
			//delete[] + _str;
			//_str = tmp;

			size_t newcapacity = _size + strlen(pstr) + 1;//确定新的空间的容量
			reserve(newcapacity);//扩容
			strcpy(_str + _size, pstr);//在原字符串后追加新字符串
			_size = newcapacity - 1;//调整_size的值
		}

		//重载+=
		void operator+=(const char& ch)
		{
			push_back(ch);
		}

		void operator+=(const char* pstr)
		{
			append(pstr);
		}

		string& insert(size_t pos, const char* pstr)
		{
			assert(pos <= _size);
			size_t newcapacity = _size + strlen(pstr);//确定插入新字符串后的新容量大小	
			reserve(newcapacity);//扩容
			memmove(_str + pos + strlen(pstr), _str + pos, sizeof(char) * (_size - pos + 1));//将pos之后的字符往后拷贝到正确的位置上
			memmove(_str + pos, pstr, sizeof(char) * strlen(pstr));//将要插入的字符拷贝到正确的位置上上
			_size = newcapacity;//调整_size的值

			return *this;
		}

		void erase(size_t pos, size_t len = -1)
		{
			assert(pos < _size);//如果要删除的位置大于_size，则断言

			if ((pos + len) > _size)//如果要删除的长度，长于后面的字符串，则将要删除的长度给到末尾
			{
				len = _size - pos;
			}

			strcpy(_str + pos, _str + pos + len);//用后面的字符串覆盖前面的
			_size = _size - len;
		}

		size_t find(const char* pstr, size_t pos =0)
		{
			assert(pos < _size);

			char* ret = strstr(_str + pos, pstr);//字符串查找
			if (ret == nullptr)//如果没找到
			{
				return -1;
			}

			int count = 0;
			for (int i = 0; i < _size; i++)
			{
				if ((_str + i) == ret)//查找ret指针指向的字符的下标
				{
					break;
				}
				count++;
			}
			return count;
		}

		bool operator==(const char* pstr)
		{
			int len = strlen(pstr);

			if (_size != len)
			{
				return false;
			}

			for (int i = 0; i < _size; i++)
			{
				if (_str[i] != pstr[i])
				{
					return false;
				}
			}
			
			return true;
		}

		bool operator!=(const char* pstr)
		{
			return !(*this == pstr);
		}

		bool operator>(const char* pstr)
		{
			int ret = strcmp(_str, pstr);
			if (ret == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool operator>=(const char* pstr)
		{
			return *this > pstr || *this == pstr;
		}

		bool operator<(const char* pstr)
		{
			return !(*this >= pstr);
		}

		bool operator<=(const char* pstr)
		{
			return !(*this > pstr);
		}

		void geline()//实现可以输入空格
		{
			resize(0);//输入之前先把原来的内容清空
			char ch;
			while (1)
			{
				ch = cin.get();
				if (ch == '\n')
				{
					break;
				}
				else
				{
					*this += ch;
				}
			}
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

	//重载cout<<
	ostream& operator<<(ostream& out, string& pstr)
	{
		for (int i = 0; i < pstr.size(); i++)
		{
			out << pstr[i];
		}
		out << endl;
		return out;
	}

	//重载cin>>
	//istream& operator>>(istream& in, string& pstr)
	//{
	//	char arr[10];
	//	cin >> arr;
	//	int len = strlen(arr);
	//	pstr.reserve(len+1);
	//	pstr.resize(len);

	//	for (int i = 0; i < pstr.size(); i++)
	//	{
	//		pstr[i] = arr[i];
	//	}

	//	return in;
	//}

	istream& operator>>(istream& in, string& pstr)
	{
		pstr.resize(0);//输入之前先把原来的内容清空
		char ch;
		while (1)
		{
			ch = in.get();
			if (ch == ' ' || ch == '\n')
			{
				break;
			}
			else
			{
				pstr += ch;
			}
		}

		return in;
	}

	//测试构造函数，拷贝构造，赋值运算符重载
	void Test1()
	{
		string s1;
		string s2("hello");
		string s3(s2);
		string s4;
		s4 = s3;
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << s3.c_str() << endl;
		cout << s4.c_str() << endl;
	}

	//测试resize
	void Test2()
	{
		string s1("hello");
		cout << s1 << endl;
		s1.reserve(50);
		s1.resize(10,'8');
		s1[9] = 'a';
		cout << s1 << endl;

	}

	//测试reserve
	void Test3()
	{
		string s1("hello");
		s1.reserve(10);
		cout << s1 << endl;
	}

	//测试push_back
	void Test4()
	{
		string s1;
		//string s2("hello");

		s1.push_back('a');

		s1.push_back(' ');
		s1.push_back('w');
		s1.push_back('o');
		s1.push_back('r');
		s1.push_back('l');
		s1.push_back('d');
		cout << s1 << endl;
		//cout << s2 << endl;
	}

	//测试append
	void Test5()
	{
		string s1;
		s1.append("hello");
		s1.append(" ");
		s1.append("world");
		s1.append("");

		cout << s1 << endl;
	}

	//测试+=
	void Test6()
	{
		string s1("hello");
		s1 += ' ';
		s1 += "world";

		cout << s1 << endl;
	}

	//测试迭代器
	void Test7()
	{
		string s1("hello world");
		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}

	//测试重载cin>>  和  getline
	void Test8()
	{
		string s1;
		s1.geline();
		cout << s1 << endl;

		s1.geline();
		cout << s1 << endl;
	}

	//测试insert和erase
	void Test9()
	{
		string s1("helloabcdefghijk");

		s1.insert(0, " world");
		
		//s1.erase(0,3);

		cout << s1 << endl;
	}

	//测试find
	void Test10()
	{
		string s1("hello world");
		int ret = s1.find("ha");
		cout << ret << endl;
	}

	//测试==、>、<等运算符
	void Test11()
	{
		string s1("hello");
		bool ret1 = (s1 >= "hella");

		cout << ret1 << endl;
	}
}


																				//拷贝构造的现代写法
namespace String_Copy
{
	class string
	{
	public:
		//构造函数
		string(const char* pstr="")
			:_str(new char[strlen(pstr)+1])
		{
			strcpy(_str, pstr);
		}

		//析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		//拷贝构造的传统写法
		//string s3(s2)
		//string(const string& pstr)
		//	:_str(new char[strlen(pstr._str)+1])
		//{
		//	strcpy(_str, pstr._str);
		//}

		//拷贝构造的现代写法
		//string s2(s3)
		string(const string& pstr)
			:_str(nullptr)
		{
			string tmp(pstr._str);
			swap(_str, tmp._str);
		}

		//赋值=重载的传统写法
		//string s3;
		//s3=s2
		//string& operator=(const string& pstr)
		//{
		//	if (this != &pstr)
		//	{
		//		char* tmp = new char[strlen(pstr._str) + 1];
		//		strcpy(tmp, pstr._str);
		//		delete[] _str;
		//		_str = tmp;

		//		return *this;
		//	}
		//}

		//赋值=重载的现代写法
		//string s3
		//s3=s2
		//string& operator=(string& pstr)
		//{
		//	if (this != &pstr)
		//	{
		//		string tmp(pstr._str);
		//		swap(_str, tmp._str);
		//	}
		//	return *this;
		//}

		string& operator=(string pstr)
		{
			if (this != &pstr)
			{
				swap(_str, pstr._str);
			}
			return *this;
		}

		char& operator[](size_t size)
		{
			return _str[size];
		}

		size_t size()
		{
			return strlen(_str);
		}

	private:
		char* _str;
	};

	void Test1()
	{
		string s1("hello");
		string s2(s1);
		string s3;
		s3 = s2;

		for (int i = 0; i < s1.size(); i++)
		{
			cout << s1[i];
		}
		cout << endl;

		for (int i = 0; i < s2.size(); i++)
		{
			cout << s2[i];
		}
		cout << endl;

		for (int i = 0; i < s3.size(); i++)
		{
			cout << s3[i];
		}
		cout << endl;
	}
}



																//再次练习模拟实现string类，并且以下代码用于创作博客
namespace string_blog
{
	class string
	{
	public:
		//对char* 重命名为iterator迭代器
		typedef char* iterator;
		typedef const char* const_iterator;
	public:
		//无参与带参构造函数
		//string s1;
		//string s2("hello world");
		string(const char* tmp = "")//缺省值给""，代表一个空字符串，而空字符串中只有一个\0
			:_str(new char[strlen(tmp)+1])//多开一个空间是为了存\0
			,_size(strlen(tmp))
			,_capacity(strlen(tmp))
		{
			strcpy(_str, tmp);
		}

		//拷贝构造函数
		//string s2(s1);
		//string(const string& tmp)
		//	:_str(new char[tmp.size()+1])//size()函数在后面实现
		//	,_size(tmp._size)
		//	,_capacity(tmp._capacity)
		//{
		//	strcpy(_str, tmp._str);
		//}

		void Swap(string& s)//交换函数，交换两个string类对象
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}

		//拷贝构造现代写法
		string(const string& s)
			:_str(nullptr)
		{
			string tmp(s._str);//用s的字符串去构造tmp
			Swap(tmp);//用tmp和this进行交换
		}

		//析构函数
		~string()
		{
			delete[] _str;//释放_str指向的空间
			_str = nullptr;//把_str指针置成nullptr
			_size = _capacity = 0;
		}

		//赋值=重载
		//string s1("hello world");
		//s1=s2;
		//string& operator=(const string& tmp)
		//{
		//	if (this != &tmp)//防止自己给自己赋值
		//	{
		//		delete[] _str;//先释放原来的字符串
		//		char* ptr = new char[tmp.size() + 1];//开一块新空间给_str
		//		strcpy(ptr, tmp._str);//将tmp的内容拷贝给ptr
		//		_str = ptr;
		//		_size = tmp._size;
		//		_capacity = tmp._capacity;
		//	}
		//	return *this;
		//}

		//赋值=重载的现代写法
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s);//用s去构造一个临时对象
				Swap(tmp);//交换两个string对象
			}
			return *this;
		}

		//begin迭代器
		iterator begin()
		{
			return _str;//返回第一个字符的指针
		}

		//end迭代器
		iterator end()
		{
			return _str + size();//返回\0位置的指针
		}

		//const begin迭代器
		const_iterator begin() const
		{
			return _str;
		}

		//const end迭代器
		const_iterator end() const
		{
			return _str + size();
		}

		//返回string的字符个数
		size_t size() const
		{
			return _size;
		}

		//返回string的容量
		size_t capacity() const
		{
			return _capacity;
		}

		//调整string的容量
		void reserve(const size_t n = 0)
		{
			if (n > size())//如果要调整到的容量大于原来的容量，才进行调整
			{
				char* tmp = new char[n + 1];//预留一个位置存放\0
				strcpy(tmp, _str);//将原来的字符串拷贝到新空间中
				delete[] _str;//释放原来的空间
				_str = tmp;//把新空间_str
				_capacity = n;
			}
		}

		//调整string的size
		void resize(const size_t n, const char& ch = '\0')
		{
			if (n > _size)
			{
				if (n > _capacity)//如果size大于容量，则需要扩容
				{
					reserve(n);//扩容到n个容量
				}

				size_t left = _size;
				size_t right = n;
				while (left < right)//将ch字符内容赋值到没有内容的位置中
				{
					_str[left++] = ch;
				}
			}
			//将最后一个位置赋值\0
			*_str = '\0';
		}

		//clear实现
		void clear()
		{
			_str[0] = '\0';//将第一个字符的位置给\0
			_size = 0;//并将长度给0
		}

		//empty实现
		bool empty() const 
		{
			if (size() == 0)
				return true;
			else
				return false;
		}

		//重载[]
		char& operator[](const size_t pos)
		{
			assert(pos < size());//如果要返回的位置不存在，则断言
			return *(_str + pos);
		}

		//重载const[]
		const char& operator[](const size_t pos) const
		{
			assert(pos < size());//如果要返回的位置不存在，则断言
			return *(_str + pos);
		}

		//尾插一个字符
		void push_back(const char& ch)
		{
			insert(size(), 1, ch);
		}

		//尾删一个字符
		void pop_back()
		{
			assert(size());
			erase(size() - 1, 1);
		}

		//尾插一个字符串
		void append(const char* s)
		{
			insert(size(), s);
		}

		//重载operator+=
		string& operator+=(const char* s)
		{
			append(s);
			return *this;
		}

		string& operator+=(const char& ch)
		{
			push_back(ch);
			return *this;
		}

		//在pos位置插入一个字符串
		void insert(const size_t pos, const char* s)
		{
			assert(pos <= size());//断言 插入的位置要<=size

			if ((size() + strlen(s)) > capacity())//判断追加字符串是否需要扩容
			{
				reserve(size() + strlen(s));
			}

			//将pos位置后的字符串后挪
			memmove(_str + pos + strlen(s), _str + pos, end() - (_str + pos));
			//将s字符串插入到pos的位置
			memmove(_str + pos, s, strlen(s));
			//将最后一个位置赋值\0
			*(_str + capacity()) = '\0';
			_size = size() + strlen(s);//调整新_size值
		}

		//在pos位置插入n个字符
		void insert(const size_t pos, size_t n, const char& ch)
		{
			assert(pos <= size());
			if ((size() + n) > capacity())
			{
				reserve(size() + n);
			}
			memmove(_str + pos + n, _str + pos, end() - (_str + pos));
			memset(_str + pos, ch, n);
			*(_str + capacity()) = '\0';
			_size = _size + n;
		}

		//在pos位置删除n个字符
		void erase(const size_t pos, size_t len)
		{
			assert(pos < size());
			
			if (len >= (end() - (_str + pos)))//如果要删除的长度长于pos后面的字符串长度，则直接删到尾
			{
				*(_str + pos) = '\0';
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
			}

			_size = _size - len;
		}

		//字符串查找    从第pos个位置开始查找
		int find(const char* s, const size_t pos =0) const
		{
			char* tmp = strstr(_str + pos, s);
			if (tmp == nullptr)
			{
				return -1;
			}
			else
			{
				return tmp - _str;
			}
		}

		//转换为C形字符串
		char* c_str() const
		{
			return _str;
		}

		bool operator==(const char* s) const 
		{
			int ret = strcmp(_str, s);
			if (ret == 0)
				return true;
			else
				return false;
		}

		bool operator!=(const char* s) const
		{
			return !(*this == s);
		}

		bool operator>(const char* s) const
		{
			int ret = strcmp(_str, s);
			if (ret > 0)
				return true;
			else
				return false;
		}

		bool operator>=(const char* s) const
		{
			return (*this > s) && (*this == s);
		}

		bool operator<(const char* s) const
		{
			return !(*this >= s);
		}

		bool operator<=(const char* s) const
		{
			return (*this < s) && (*this == s);
		}

		void getline()
		{
			//输入之前，需要清空字符串
			clear();
			while (1)
			{
				char ch;
				//cin >> ch;
				ch = cin.get();
				if (ch == '\n')
				{
					break;
				}
				else
				{
					(*this) += ch;
				}
			}
			(*this) += '\0';
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

	//重载cout<<
	ostream& operator<<(ostream& out, string& s)
	{
		out << s.c_str() << endl;
		return out;
	}

	//重载cin>>
	istream& operator>>(istream& in, string& s)
	{
		//输入之前，需要清空字符串
		s.clear();
		while (1)
		{
			char ch;
			//cin >> ch;
			ch = in.get();
			if (ch == ' ' || ch == '\n')
			{
				break;
			}
			else
			{
				s += ch;
			}
		}
		s += '\0';
		return in;
	}

	//测试构造函数 和 赋值=重载
	void Test1()
	{
		string s1;
		string s2("hello world");
		string s3(s2);
		s1 = s3;

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
		cout << s3.c_str() << endl;
	}

	//测试迭代器
	void Test2()
	{
		string s1("hello world");
		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}

	//测试
	void Test3()
	{
		string s1("hello world");
		s1.clear();
		s1.resize(10, 'b');
		cout << s1.c_str() << endl;
		cout << s1.empty() << endl;
		s1.clear();
		cout << s1.c_str() << endl;
		cout << s1.empty() << endl;
	}

	void Test4()
	{
		string s1("hello world");
		for (int i = 0; i < s1.size(); i++)
		{
			s1[i] -= 1;
		}
		cout << s1.c_str() << endl;
	}

	//测试insert
	void Test5()
	{
		string s1("hello world");
		s1.getline();
		cout << s1 << endl;
	}
}