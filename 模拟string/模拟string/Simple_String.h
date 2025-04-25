#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

																				//ʵ��һ���򵥵�string��
namespace Simple_String
{
	class string
	{
	public:
		//���캯��
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
		
		//ȫȱʡ���캯��
		string(const char* pstr = "")
			:_str(new char[strlen(pstr)+1])
		{
			strcpy(_str, pstr);
		}

		//��������
		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		//��������
		string(const string& pstr)
			:_str(new char[pstr.size() + 1])
		{
			strcpy(_str, pstr._str);
		}

		//��ֵ���������
		string& operator=(const string& pstr)
		{
			if (this != &pstr)//�����Լ����Լ���ֵ���˷�����
			{
				char* tmp = new char[pstr.size() + 1];//������һ���µĿռ�
				strcpy(tmp, pstr._str);//��Ҫ��ֵ�����ݿ������¿ռ���
				delete[] _str;//�ͷ�_strָ��Ŀռ�
				_str = tmp;//���¿ռ����_str

				return *this;//����this�ַ������������Ȳ���
			}
		}

		//��ȡ�ַ�������
		size_t size() const
		{
			return strlen(_str);
		}

		//��ȡ�ַ�����ĳ���ַ�
		char& operator[](int size) const
		{
			return *(_str + size);
		}

	private:
		char* _str;
	};

	//����cout<<
	ostream& operator<<(ostream& out,string& str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			out << str[i];
		}
		out << endl;

		return out;
	}

	//���Թ��캯��
	void Test1()
	{
		string s1;
		string s2("hello");
	}

	//���Ա���
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

	//���Կ������� �� ��ֵ
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