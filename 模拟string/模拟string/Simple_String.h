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