#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
//����������ִ�д��
namespace String_Copy
{
	class string
	{
	public:
		//���캯��
		string(const char* pstr = "")
			:_str(new char[strlen(pstr) + 1])
		{
			strcpy(_str, pstr);
		}

		//��������
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		//��������Ĵ�ͳд��
		//string s3(s2)
		//string(const string& pstr)
		//	:_str(new char[strlen(pstr._str)+1])
		//{
		//	strcpy(_str, pstr._str);
		//}

		//����������ִ�д��
		//string s2(s3)
		string(const string& pstr)
			:_str(nullptr)
		{
			string tmp(pstr._str);
			swap(_str, tmp._str);
		}

		//��ֵ=���صĴ�ͳд��
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

		//��ֵ=���ص��ִ�д��
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