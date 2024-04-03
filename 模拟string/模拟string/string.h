#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

//实现一个简单的string类
namespace My_String
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



//模拟实现string的增删改查
namespace String
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

		//拷贝构造
		string(const string& pstr)
			:_str(new char[pstr.size()+1])
			,_size(pstr._size)
			,_capacity(pstr._capacity)
		{
			strcpy(_str, pstr._str);
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

		//赋值运算符重载
		string& operator=(const string& pstr)
		{
			if (this != &pstr)
			{
				char* tmp = new char[pstr.size() + 1];//开一块新的空间给this
				strcpy(tmp, pstr._str);//将要赋值的内容给到新开的空间
				delete[] _str;
				_str = tmp;
				_size = _capacity = pstr._size;

				return *this;
			}
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
		void resize(size_t i)
		{
			if (i > _size)//如果需要调整后的size比之前大
			{
				//如果调整后的size比底层的capacity大，则需要扩容
				if (i > _capacity)
				{
					reserve(i);
				}

				memset(_str + _size, 0, sizeof(char) * _capacity - _size);

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

		void insert(size_t pos, const char* pstr)
		{
			assert(pos <= _size);

		}

		void erase;

		void find;
		
		operator==();

		operator!=();

		operator>();

		operator>=();

		operator<();

		operator<=();

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
	istream& operator>>(istream& in, string& pstr)
	{
		char arr[10];
		cin >> arr;
		int len = strlen(arr);
		pstr.reserve(len+1);
		pstr.resize(len);

		for (int i = 0; i < pstr.size(); i++)
		{
			pstr[i] = arr[i];
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
		s1.resize(10);
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

	//测试重载cin>>
	void Test8()
	{
		string s1;
		cin >> s1;
		cout << s1 << endl;

		cin >> s1;
		cout << s1 << endl;
	}
}


