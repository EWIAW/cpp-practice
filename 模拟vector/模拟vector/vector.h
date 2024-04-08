#pragma once
#include<assert.h>
#include<iostream>
using namespace std;

namespace My_vector
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;

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
		vector(const vector<T>& tmp)
			:_start(new T[tmp.capacity()])
			,_finish(_start+tmp.size())
			,_endofstorage(_start+tmp.capacity())
		{
			memmove(_start, tmp._start, sizeof(T) * tmp.size());
		}

		//赋值=重载
		//vector<int> v3;
		//v3=v2;
		vector<T>& operator=(const vector<T>& tmp)//函数传参：用v2拷贝构造出一个tmp
		{
			if (this != &tmp)//判断防止自己给自己拷贝
			{
				vector<T> copy(tmp);
				Swap(copy);
				return *this;
			}
		}

		//begin迭代器
		iterator begin() const
		{
			return _start;
		}

		//end迭代器
		iterator end() const
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
					memmove(tmp, _start, sizeof(T) * size());//将原来空间的数据拷贝到新空间中
				}

				//注意！！！ 下面这两行代码一定要写在delete的前面
				_finish = tmp + size();//调整_finish的位置
				_endofstorage = tmp + sz;//调整_endofstorage的位置

				delete[] _start;
				_start = tmp;
			}
		}

		//调整size值
		void resize(size_t sz)
		{
			;
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

		//重载[]
		T& operator[](const size_t pos) 
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

	private:
		iterator _start;//一个迭代器指向第一个元素
		iterator _finish;//一个迭代器指向最后一个元素的下一个位置
		iterator _endofstorage;//一个迭代器指向容量的位置的下一个位置
	};



	//测试构造函数
	void Test1()
	{
		vector<int> v1;

		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		vector<int> v2(v1);

		cout << v1[0] << endl;
		cout << v1[1] << endl;
		cout << v1[2] << endl;
		cout << v1[3] << endl;

		cout << v2[0] << endl;
		cout << v2[1] << endl;
		cout << v2[2] << endl;
		cout << v2[3] << endl;
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

		cout << v2[0] << endl;
		cout << v2[1] << endl;
		cout << v2[2] << endl;
		cout << v2[3] << endl;
	}

	//测试迭代器和范围for
	void Test3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		vector<int>::iterator it = v1.begin();
		while (it != v1.end())
		{
			(*it)++;
			cout << *it << " ";
			it++;	
		}
		cout << endl;	

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void Test4()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);

		v1[0] = 10;

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}