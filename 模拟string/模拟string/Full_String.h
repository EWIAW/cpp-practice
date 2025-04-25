#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
//ģ��ʵ������string����ɾ�Ĳ�
namespace Full_String
{
	class string
	{
	public:
		//���캯��
		string(const char* pstr = "")
			:_str(new char[strlen(pstr) + 1])//�࿪�Ŀռ����ڴ��\0
			, _size(strlen(pstr))
			, _capacity(strlen(pstr))
		{
			strcpy(_str, pstr);
		}

		//��������
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		//��������	��ͳд��
		//string(const string& pstr)
		//	:_str(new char[pstr.size()+1])
		//	,_size(pstr._size)
		//	,_capacity(pstr._capacity)
		//{
		//	strcpy(_str, pstr._str);
		//}

		//��������	�ִ�д��
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

		//��ֵ���������	��ͳд��
		//string& operator=(const string& pstr)
		//{
		//	if (this != &pstr)
		//	{
		//		char* tmp = new char[pstr.size() + 1];//��һ���µĿռ��this
		//		strcpy(tmp, pstr._str);//��Ҫ��ֵ�����ݸ����¿��Ŀռ�
		//		delete[] _str;
		//		_str = tmp;
		//		_size = _capacity = pstr._size;

		//		return *this;
		//	}
		//}

		//��ֵ=����	�ִ�д��
		//string s3;
		//s3=s2;
		string& operator=(string pstr)
		{
			Swap(pstr);
			return *this;
		}

		//������
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		//��ȡ�ַ�������Ч�ַ�����
		size_t size() const
		{
			return _size;
		}

		//��ȡ�ַ���������
		size_t capacity() const
		{
			return _capacity;
		}

		//�����ַ����ĵ�i���ַ�
		char& operator[](size_t i) const
		{
			assert(i < _size);
			return _str[i];
		}

		//����C��ʽ���ַ���
		char* c_str() const
		{
			return _str;
		}

		//��������size
		void resize(size_t i, char ch = '0')
		{
			if (i > _size)//�����Ҫ�������size��֮ǰ��
			{
				//����������size�ȵײ��capacity������Ҫ����
				if (i > _capacity)
				{
					reserve(i);
				}

				memset(_str + _size, ch, sizeof(char) * (i - _size));

				_size = i;
				//char* tmp = new char[i + 1];//��һ������Ŀռ�
				//memset(tmp, 0, sizeof(char) * (i + 1));//�����ռ��ֵȫ����0
				//strcpy(tmp, _str);//��ԭʼ�ռ俽�����¿ռ�
				//delete[] _str;
				//_str = tmp;

				//_size = _capacity = i;
			}
			if (i < _size)//����������size��֮ǰС
			{
				_size = i;
				_str[i] = '\0';
			}
		}

		//��������capacity
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

		//β��һ���ַ�
		void push_back(const char& ch)
		{
			if (_size == _capacity)//���������Ҫ����
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
			_str[_size] = 0;//�����һ���ַ�����һ��λ�ø�\0		������
		}

		//β��һ���ַ���
		void append(const char* pstr)
		{
			//char* tmp = new char[_size + strlen(pstr) + 1];
			//strcpy(tmp, _str);//�뿽��ԭ����
			//strcpy(tmp + _size, pstr);//�ٿ����²����
			//delete[] + _str;
			//_str = tmp;

			size_t newcapacity = _size + strlen(pstr) + 1;//ȷ���µĿռ������
			reserve(newcapacity);//����
			strcpy(_str + _size, pstr);//��ԭ�ַ�����׷�����ַ���
			_size = newcapacity - 1;//����_size��ֵ
		}

		//����+=
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
			size_t newcapacity = _size + strlen(pstr);//ȷ���������ַ��������������С	
			reserve(newcapacity);//����
			memmove(_str + pos + strlen(pstr), _str + pos, sizeof(char) * (_size - pos + 1));//��pos֮����ַ����󿽱�����ȷ��λ����
			memmove(_str + pos, pstr, sizeof(char) * strlen(pstr));//��Ҫ������ַ���������ȷ��λ������
			_size = newcapacity;//����_size��ֵ

			return *this;
		}

		void erase(size_t pos, size_t len = -1)
		{
			assert(pos < _size);//���Ҫɾ����λ�ô���_size�������

			if ((pos + len) > _size)//���Ҫɾ���ĳ��ȣ����ں�����ַ�������Ҫɾ���ĳ��ȸ���ĩβ
			{
				len = _size - pos;
			}

			strcpy(_str + pos, _str + pos + len);//�ú�����ַ�������ǰ���
			_size = _size - len;
		}

		size_t find(const char* pstr, size_t pos = 0)
		{
			assert(pos < _size);

			char* ret = strstr(_str + pos, pstr);//�ַ�������
			if (ret == nullptr)//���û�ҵ�
			{
				return -1;
			}

			int count = 0;
			for (int i = 0; i < _size; i++)
			{
				if ((_str + i) == ret)//����retָ��ָ����ַ����±�
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

		void geline()//ʵ�ֿ�������ո�
		{
			resize(0);//����֮ǰ�Ȱ�ԭ�����������
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

	//����cout<<
	ostream& operator<<(ostream& out, string& pstr)
	{
		for (int i = 0; i < pstr.size(); i++)
		{
			out << pstr[i];
		}
		out << endl;
		return out;
	}

	//����cin>>
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
		pstr.resize(0);//����֮ǰ�Ȱ�ԭ�����������
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

	//���Թ��캯�����������죬��ֵ���������
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

	//����resize
	void Test2()
	{
		string s1("hello");
		cout << s1 << endl;
		s1.reserve(50);
		s1.resize(10, '8');
		s1[9] = 'a';
		cout << s1 << endl;

	}

	//����reserve
	void Test3()
	{
		string s1("hello");
		s1.reserve(10);
		cout << s1 << endl;
	}

	//����push_back
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

	//����append
	void Test5()
	{
		string s1;
		s1.append("hello");
		s1.append(" ");
		s1.append("world");
		s1.append("");

		cout << s1 << endl;
	}

	//����+=
	void Test6()
	{
		string s1("hello");
		s1 += ' ';
		s1 += "world";

		cout << s1 << endl;
	}

	//���Ե�����
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

	//��������cin>>  ��  getline
	void Test8()
	{
		string s1;
		s1.geline();
		cout << s1 << endl;

		s1.geline();
		cout << s1 << endl;
	}

	//����insert��erase
	void Test9()
	{
		string s1("helloabcdefghijk");

		s1.insert(0, " world");

		//s1.erase(0,3);

		cout << s1 << endl;
	}

	//����find
	void Test10()
	{
		string s1("hello world");
		int ret = s1.find("ha");
		cout << ret << endl;
	}

	//����==��>��<�������
	void Test11()
	{
		string s1("hello");
		bool ret1 = (s1 >= "hella");

		cout << ret1 << endl;
	}
}