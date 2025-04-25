#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
//模拟实现完整string的增删改查
namespace Full_String
{
	class string
	{
	public:
		//构造函数
		string(const char* pstr = "")
			:_str(new char[strlen(pstr) + 1])//多开的空间用于存放\0
			, _size(strlen(pstr))
			, _capacity(strlen(pstr))
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
		void resize(size_t i, char ch = '0')
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

		size_t find(const char* pstr, size_t pos = 0)
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
		s1.resize(10, '8');
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