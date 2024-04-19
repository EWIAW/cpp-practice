#pragma once
#include<assert.h>
#include<iostream>
#include<vector>
using namespace std;

																				//第一次练习模拟vector
namespace My_vector
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;//可读可写迭代器
		typedef const T* const_iterator;//只能读迭代器

		//构造函数
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{

		}

		//析构函数
		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		//拷贝构造
		//vector<int> v2(v1)
		vector(const vector<T>& v)
			:_start(new T[v.capacity()])
			,_finish(_start)
			,_endofstorage(_start+v.capacity())
		{
			//memmove(_start, tmp._start, sizeof(T) * tmp.size());

			iterator pos = v._start;
			while (pos != v._finish)//将v1的数据赋值给v2
			{
				*_finish = *pos;
				pos++;
				_finish++;
			}
		}

		//赋值=重载
		//vector<int> v3;
		//v3=v2;
		vector<T>& operator=(const vector<T>& tmp)
		{
			if (this != &tmp)//判断防止自己给自己拷贝
			{
				vector<T> copy(tmp);
				Swap(copy);
				return *this;
			}
		}

		//begin迭代器
		iterator begin() 
		{
			return _start;
		}

		//end迭代器
		iterator end() 
		{
			return _finish;
		}

		//const_begin迭代器
		const_iterator begin() const
		{
			return _start;
		}

		//const_end迭代器
		const_iterator end() const
		{
			return _finish;
		}

		//扩容
		void reserve(size_t sz)
		{
			if (sz > capacity())//如果需要扩容的数大于原来的capacity才扩容
			{
				T* tmp = new T[sz];//开辟一块新空间

				if (_start != nullptr)
				{
					//memmove(tmp, _start, sizeof(T) * size());//将原来空间的数据拷贝到新空间中
					iterator pos1 = _start;
					iterator pos2 = tmp;
					while (pos1 != _finish)//将原来空间的数据拷贝到新空间中
					{
						*pos2++ = *pos1++;
					}
				}

				//注意！！！ 下面这两行代码一定要写在delete的前面
				_finish = tmp + size();//调整_finish的位置
				_endofstorage = tmp + sz;//调整_endofstorage的位置

				delete[] _start;
				_start = tmp;
			}
		}

		//调整size值
		void resize(const size_t sz, const T& val = T() )//给一个T类型的缺省值
		{
			if (sz < size())
			{
				_finish = _start + sz;
			}
			if (sz > size())
			{
				if (sz > capacity())//如果需要调整的size值大于容量，则需要扩容
				{
					reserve(sz);
				}

				while (_finish != _endofstorage)
				{
					*(_finish) = val;
					_finish++;
				}
			}
		}

		//判断vector是否为空
		bool empty() const
		{
			if (size() == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		//尾插
		void push_back(const T& val)
		{
			//插入前要判断是否要扩容
			if (_finish == _endofstorage)
			{
				size_t newcapacity = _finish == nullptr ? 2 : capacity() * 2;//如果_finish为空，即给2个空间，否则给原来的两倍
				reserve(newcapacity);
				//T* tmp = new T[newcapacity];

				//memmove(tmp, _start, sizeof(T) * size());//将原来位置的元素拷贝到新空间中

				////这两行代码一定要放在delete[]之前
				//_finish = tmp + size();
				//_endofstorage = tmp + newcapacity;

				//delete[] _start;
				//_start = tmp;
			}

			*_finish = val;
			_finish++;
		}

		//尾删
		void pop_back()
		{
			assert(size() != 0);
			_finish--;
		}

		//中间插入	!!!
		iterator insert(iterator pos, const T& val)
		{
			assert(pos >= _start && pos <= _finish);

			if (size() == capacity())//如果容量已满，则需要扩容，增容后，需要重新给pos迭代器赋值，否则会有迭代器失效问题
			{
				size_t tmp = pos - _start;
				size_t newcapacity = (capacity() == 0 ? 2 : capacity() * 2);
				reserve(newcapacity);
				pos = begin() + tmp;
			}

			iterator prev = _finish - 1;
			iterator tail = _finish;

			/*int flag = _finish - pos;*///要挪动的次数
			while (prev >= pos)//pos之后的元素往后挪
			{
				*tail = *prev;
				tail--;
				prev--;
			}

			//挪完数据后，_finish需要++
			_finish++;

			*pos = val;

			return pos;
		}

		//中间删除	!!!	
		iterator erase(iterator pos)
		{
			assert(pos < _finish);

			iterator prev = pos;
			iterator tail = pos + 1;

			while (tail<_finish)
			{
				*prev = *tail;
				prev++;
				tail++;
			}

			_finish--;

			return pos;
		}

		//重载[]
		T& operator[](const size_t pos) 
		{
			assert(pos < size());
			return *(_start + pos);
		}

		const T& operator[](const size_t pos) const
		{
			assert(pos < size());
			return *(_start + pos);
		}

		//返回vector中的元素个数
		size_t size() const
		{
			return _finish - _start;
		}

		//返回vector的容量
		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		//交换函数
		//vector<int> v1;
		//v1.Swap(v2);
		void Swap(vector<T>& tmp)
		{
			swap(_start, tmp._start);
			swap(_finish, tmp._finish);
			swap(_endofstorage, tmp._endofstorage);
		}

		//输出vector
		void print_arr() const
		{
			vector<int>::const_iterator it = begin();
			while (it != end())
			{
				cout << *it << " ";
				it++;
			}
			cout << endl;
		}

	private:
		iterator _start;//一个迭代器指向第一个元素
		iterator _finish;//一个迭代器指向最后一个元素的下一个位置
		iterator _endofstorage;//一个迭代器指向容量的位置的下一个位置
	};



	//测试构造函数	拷贝构造函数
	void Test1()
	{
		vector<int> v1;

		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		vector<int> v2(v1);

		v1.print_arr();
		v2.print_arr();
	}

	//测试赋值=
	void Test2()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		vector<int> v2;
		v2 = v1;

		v1.print_arr();
		v2.print_arr();
	}

	//测试迭代器
	void Test3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		const vector<int> v2(v1);
		v2.print_arr();
	}

	//测试resize
	void Test4()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);

		v1.resize(10);

		v1.resize(20, 10);

		v1.print_arr();
	}

	//测试尾删
	void Test5()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);

		v1.pop_back();
		v1.pop_back();

		v1.print_arr();
	}

	//测试中间插入，中间删除
	void Test6()
	{
		vector<int> v1;

		v1.insert(v1.begin(), 10);
		v1.insert(v1.end(), 20);
		v1.insert(v1.end(), 30);

		//v1.erase(v1.begin());
		//v1.erase(v1.end() - 2);

		vector<int> v2;
		v2.erase(v2.begin());

		v1.print_arr();
	}

	//测试reserve
	void Test7()
	{
		vector<string> v1;
		v1.push_back("11111");
		v1.push_back("22222");
		v1.push_back("33333");
		v1.push_back("44444");

		cout << v1[0] << endl;
		cout << v1[1] << endl;
		cout << v1[2] << endl;
		cout << v1[3] << endl;
	}
}



																			//第二次模拟vector，并用于写blog
namespace Vector_blog
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;//可读可写迭代器
		typedef const T* const_iterator;//只可读迭代器

		//begin迭代器
		iterator begin()
		{
			return _start;
		}

		//end迭代器
		iterator end()
		{
			return _finish;
		}

		//const begin迭代器
		const_iterator begin() const
		{
			return _start;
		}

		//const end迭代器
		const_iterator end() const
		{
			return _finish;
		}
	public:
		//无参构造函数：直接全部给nullptr即可
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{}

		//拷贝构造函数
		//vector<int> v1;
		//vector<int> v2(v1);
		vector(const vector<T>& v)
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{
			const_iterator move = v.begin();
			while (move != v.end())
			{
				push_back(*move);
				move++;
			}
		}

		//析构函数
		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		//交换函数，用于交换两个vector
		void Swap(vector<T>& v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endofstorage, v._endofstorage);
		}

		//赋值=重载函数
		//vector<int> v1;
		//v1=v2;
		vector<T>& operator=(const vector<T>& v)
		{
			if (this != &v)
			{
				vector<T> tmp(v);
				Swap(tmp);
			}
			return *this;
		}

		//调整vector的数据个数
		void resize(const size_t n, const T& val = T())//第二个参数为一个T类型的缺省值
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else if (n > size())
			{
				if (n > capacity())//如果调整后的n大于容量，则需要扩容
				{
					reserve(n);
				}
				iterator it1 = begin() + n;
				iterator it2 = end();
				while (it2 < it1)
				{
					push_back(val);
					it2++;
				}
			}
		}

		//调整vector的容量
		void reserve(const size_t n)
		{
			//如果要调整的容量大于原来的容量才做调整
			if (n > capacity())
			{
				T* tmp = new T[n];//开辟一块新空间
				T* tmp_start = _start;
				T* tmp_move = tmp;
				while (tmp_start != _finish)
				{
					*tmp_move++ = *tmp_start++;
				}

				//释放旧空间，并调整_start,_finish,_endofstorage的位置
				_finish = tmp + size();
				_endofstorage = tmp + n;
				delete[] _start;
				_start = tmp;
			}
		}

		//判断vector是否为空
		bool empty() const
		{
			return !size();
		}

		//尾部插入
		void push_back(const T& val)
		{
			insert(end(), val);
		}

		//尾删
		void pop_back()
		{
			erase(end() - 1);
		}

		//中间插入
		iterator insert(iterator pos, const T& val)
		{
			assert(pos <= end());
			//如果容量已满，则扩容
			if (size() == capacity())
			{
				size_t n = pos - begin();//扩容之前需要记住pos对于_start的偏移量，以防出现迭代器失效问题
				size_t newcapacity = size() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + n;//更新pos位置
			}

			//将pos位置及其后面所以数据往后挪动
			iterator move = end();
			while (move != pos)
			{
				*move = *(move - 1);
				move--;
			}

			*pos = val;
			_finish++;

			return pos;
		}

		//中间删除
		iterator erase(iterator pos)
		{
			assert(pos < end());

			iterator tmp = pos + 1;
			while (tmp != end())
			{
				*(tmp - 1) = *tmp;
				tmp++;
			}

			_finish--;

			return pos;
		}

		//获取数据个数
		size_t size() const
		{
			return _finish - _start;
		}

		//获取容量
		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		//重载operator[]
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return *(_start + pos);
		}

		//重载operator[] const 
		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return *(_start + pos);
		}

		//front函数
		T& front()
		{
			assert(size() > 0);
			return *_start;
		}

		//front函数 const
		const T& front() const
		{
			assert(size() > 0);
			return *_start;
		}

		//back函数
		T& back()
		{
			assert(size() > 0);
			return *(_start + size() - 1);
		}

		//back函数 const
		const T& back() const
		{
			assert(size() > 0);
			return *(_start + size() - 1);
		}

		//clear函数
		void clear()
		{
			_finish = _start;
		}

		bool operator==(const vector<T>& v)
		{
			if (size() == v.size())
			{
				iterator it1 = begin();
				iterator it2 = v.begin();
				while (it1 < end() && it2 < v.end())
				{
					if (*it1 == *it2)
					{
						it1++;
						it2++;
					}
					else
					{
						return false;
					}
				}
				return true;
			}
			else
			{
				return false;
			}
		}

		bool operator!=(const vector<T>& v)
		{
			return !(*this == v);
		}

		bool operator>(const vector<T>& v)
		{
			iterator it1 = begin();
			iterator it2 = v.begin();

			while (it1 < end() && it2 < v.end())
			{
				if (*it1 > *it2)
				{
					return true;
				}
				else if(*it1 < *it1)
				{
					return false;
				}
				else
				{
					it1++;
					it2++;
				}
			}

			if (it1 == end())
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		bool operator>=(const vector<T>& v)
		{
			return (*this > v || *this == v);
		}

		bool operator<(const vector<T>& v)
		{
			return !(*this >= v);
		}

		bool operator<=(const vector<T>& v)
		{
			return !(*this > v);
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

	//测试构造函数、拷贝构造、赋值=重载
	void Test1()
	{
		vector<int> v1;
		v1.insert(v1.end(), 1);
		v1.insert(v1.end(), 2);
		v1.insert(v1.end(), 3);
		v1.insert(v1.end(), 4);
		v1.insert(v1.end(), 5);
		v1.insert(v1.end(), 6);

		vector<int> v2(v1);
		vector<int> v3;
		v3 = v2;

		vector<int>::iterator it1 = v1.begin();
		while (it1 != v1.end())
		{
			cout << *it1 << " ";
			it1++;
		}
		cout << endl;

		vector<int>::iterator it2 = v2.begin();
		while (it2 != v2.end())
		{
			cout << *it2 << " ";
			it2++;
		}
		cout << endl;

		vector<int>::iterator it3 = v3.begin();
		while (it3 != v3.end())
		{
			cout << *it3 << " ";
			it3++;
		}
		cout << endl;
	}

	//测试resize和reserve
	void Test2()
	{
		vector<int> v1;
		v1.insert(v1.end(), 1);
		v1.insert(v1.end(), 2);
		v1.insert(v1.end(), 3);
		v1.insert(v1.end(), 4);

		v1.reserve(10);
		v1.resize(15, 20);

		vector<int>::iterator it1 = v1.begin();
		while (it1 != v1.end())
		{
			cout << *it1 << " ";
			it1++;
		}
		cout << endl;

		cout << v1.empty() << endl;
	}

	//测试operator[]
	void Test3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		for (int i = 0; i < v1.size(); i++)
		{
			cout << v1[i] << " ";
		}
		cout << endl;

		cout << v1.front() << endl;
		cout << v1.back() << endl;
	}

	//测试insert和erase
	void Test4()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		v1.insert(v1.begin() + 2, 50);
		v1.erase(v1.begin());
		v1.erase(v1.end() - 1);
		v1.erase(v1.begin() + 1);

		for (int i = 0; i < v1.size(); i++)
		{
			cout << v1[i] << " ";
		}
		cout << endl;
	}

	//
	void Test5()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.clear();

		for (int i = 0; i < v1.size(); i++)
		{
			cout << v1[i] << " ";
		}
		cout << endl;
	}
}