#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
using namespace std;

//�ٴ���ϰģ��ʵ��string�࣬�������´������ڴ�������
namespace string_blog
{
	class string
	{
	public:
		//��char* ������Ϊiterator������
		typedef char* iterator;
		typedef const char* const_iterator;
	public:
		//�޲�����ι��캯��
		//string s1;
		//string s2("hello world");
		string(const char* tmp = "")//ȱʡֵ��""������һ�����ַ����������ַ�����ֻ��һ��\0
			:_str(new char[strlen(tmp) + 1])//�࿪һ���ռ���Ϊ�˴�\0
			, _size(strlen(tmp))
			, _capacity(strlen(tmp))
		{
			strcpy(_str, tmp);
		}

		//�������캯��
		//string s2(s1);
		//string(const string& tmp)
		//	:_str(new char[tmp.size()+1])//size()�����ں���ʵ��
		//	,_size(tmp._size)
		//	,_capacity(tmp._capacity)
		//{
		//	strcpy(_str, tmp._str);
		//}

		void Swap(string& s)//������������������string�����
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}

		//���������ִ�д��
		string(const string& s)
			:_str(nullptr)
		{
			string tmp(s._str);//��s���ַ���ȥ����tmp
			Swap(tmp);//��tmp��this���н���
		}

		//��������
		~string()
		{
			delete[] _str;//�ͷ�_strָ��Ŀռ�
			_str = nullptr;//��_strָ���ó�nullptr
			_size = _capacity = 0;
		}

		//��ֵ=����
		//string s1("hello world");
		//s1=s2;
		//string& operator=(const string& tmp)
		//{
		//	if (this != &tmp)//��ֹ�Լ����Լ���ֵ
		//	{
		//		delete[] _str;//���ͷ�ԭ�����ַ���
		//		char* ptr = new char[tmp.size() + 1];//��һ���¿ռ��_str
		//		strcpy(ptr, tmp._str);//��tmp�����ݿ�����ptr
		//		_str = ptr;
		//		_size = tmp._size;
		//		_capacity = tmp._capacity;
		//	}
		//	return *this;
		//}

		//��ֵ=���ص��ִ�д��
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s);//��sȥ����һ����ʱ����
				Swap(tmp);//��������string����
			}
			return *this;
		}

		//begin������
		iterator begin()
		{
			return _str;//���ص�һ���ַ���ָ��
		}

		//end������
		iterator end()
		{
			return _str + size();//����\0λ�õ�ָ��
		}

		//const begin������
		const_iterator begin() const
		{
			return _str;
		}

		//const end������
		const_iterator end() const
		{
			return _str + size();
		}

		//����string���ַ�����
		size_t size() const
		{
			return _size;
		}

		//����string������
		size_t capacity() const
		{
			return _capacity;
		}

		//����string������
		void reserve(const size_t n = 0)
		{
			if (n > size())//���Ҫ����������������ԭ�����������Ž��е���
			{
				char* tmp = new char[n + 1];//Ԥ��һ��λ�ô��\0
				strcpy(tmp, _str);//��ԭ�����ַ����������¿ռ���
				delete[] _str;//�ͷ�ԭ���Ŀռ�
				_str = tmp;//���¿ռ�_str
				_capacity = n;
			}
		}

		//����string��size
		void resize(const size_t n, const char& ch = '\0')
		{
			if (n > _size)
			{
				if (n > _capacity)//���size��������������Ҫ����
				{
					reserve(n);//���ݵ�n������
				}

				size_t left = _size;
				size_t right = n;
				while (left < right)//��ch�ַ����ݸ�ֵ��û�����ݵ�λ����
				{
					_str[left++] = ch;
				}

			}
			//�����һ��λ�ø�ֵ\0
			_str[n] = '\0';
			_size = n;//����_size
		}

		//clearʵ��
		void clear()
		{
			_str[0] = '\0';//����һ���ַ���λ�ø�\0
			_size = 0;//�������ȸ�0
		}

		//emptyʵ��
		bool empty() const
		{
			if (size() == 0)
				return true;
			else
				return false;
		}

		//����[]
		char& operator[](const size_t pos)
		{
			assert(pos < size());//���Ҫ���ص�λ�ò����ڣ������
			return *(_str + pos);
		}

		//����const[]
		const char& operator[](const size_t pos) const
		{
			assert(pos < size());//���Ҫ���ص�λ�ò����ڣ������
			return *(_str + pos);
		}

		//β��һ���ַ�
		void push_back(const char& ch)
		{
			insert(size(), 1, ch);
		}

		//βɾһ���ַ�
		void pop_back()
		{
			assert(size());
			erase(size() - 1, 1);
		}

		//β��һ���ַ���
		void append(const char* s)
		{
			insert(size(), s);
		}

		//����operator+=
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

		//��posλ�ò���һ���ַ���
		void insert(const size_t pos, const char* s)
		{
			assert(pos <= size());//���� �����λ��Ҫ<=size

			if ((size() + strlen(s)) > capacity())//�ж�׷���ַ����Ƿ���Ҫ����
			{
				reserve(size() + strlen(s));
			}

			//��posλ�ú���ַ�����Ų
			memmove(_str + pos + strlen(s), _str + pos, end() - (_str + pos));
			//��s�ַ������뵽pos��λ��
			memmove(_str + pos, s, strlen(s));
			
			_size = size() + strlen(s);//������_sizeֵ
			*(_str + size()) = '\0';//�����һ��λ�ø�ֵ\0
		}

		//��posλ�ò���n���ַ�
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

		//��posλ��ɾ��n���ַ�
		void erase(const size_t pos, size_t len)
		{
			assert(pos < size());

			if (len >= (size_t)(end() - (_str + pos)))//���Ҫɾ���ĳ��ȳ���pos������ַ������ȣ���ֱ��ɾ��β
			{
				*(_str + pos) = '\0';
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
			}

			_size = _size - len;
		}

		//�ַ�������    �ӵ�pos��λ�ÿ�ʼ����
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

		//ת��ΪC���ַ���
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
			//����֮ǰ����Ҫ����ַ���
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

	//����cout<<
	ostream& operator<<(ostream& out, string& s)
	{
		out << s.c_str() << endl;
		return out;
	}

	//����cin>>
	istream& operator>>(istream& in, string& s)
	{
		//����֮ǰ����Ҫ����ַ���
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

	//���Թ��캯�� �� ��ֵ=����
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

	////���Ե�����
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

	////����
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

	////����insert
	void Test5()
	{
		string s1("hello world");
		s1.getline();
		cout << s1 << endl;
	}
}