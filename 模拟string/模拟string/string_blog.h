#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
using namespace std;

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
			:_str(new char[strlen(tmp) + 1])//多开一个空间是为了存\0
			, _size(strlen(tmp))
			, _capacity(strlen(tmp))
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
			_str[n] = '\0';
			_size = n;//更新_size
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
			
			_size = size() + strlen(s);//调整新_size值
			*(_str + size()) = '\0';//将最后一个位置赋值\0
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
			
			_size = _size + n;
			*(_str + size()) = '\0';
		}

		//在pos位置删除n个字符
		void erase(const size_t pos, size_t len)
		{
			assert(pos < size());

			if (len >= (size_t)(end() - (_str + pos)))//如果要删除的长度长于pos后面的字符串长度，则直接删到尾
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
		int find(const char* s, const size_t pos = 0) const
		{
			char* tmp = strstr(_str + pos, s);
			if (tmp == nullptr)
			{
				return -1;
			}
			else
			{
				return (int)(tmp - _str);
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

	////测试迭代器
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

	////测试
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

	////测试insert
	void Test5()
	{
		string s1("hello world");
		s1.getline();
		cout << s1 << endl;
	}
}