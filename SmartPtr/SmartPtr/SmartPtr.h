#pragma once
#pragma once
#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

namespace my
{
	//C++98做法的智能指针
	//对于拷贝构造和赋值=重载来说，使用管理权转移的做法
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		//my::auto_ptr<T> sp2(sp1)
		auto_ptr(auto_ptr<T>& sp)
			:_ptr(sp._ptr)
		{
			sp._ptr = nullptr;
		}

		//auto_ptr<int> sp3 = sp1;
		auto_ptr<T>& operator=(auto_ptr<T>& sp)
		{
			if (this != &sp)
			{
				if (_ptr != nullptr)
					delete _ptr;
				_ptr = sp._ptr;
				sp._ptr = nullptr;
			}
			return *this;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		~auto_ptr()
		{
			if (_ptr != nullptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}
	private:
		T* _ptr;
	};



	//为了解决auto_ptr的问题，提出了unique_ptr指针，暴力的防拷贝和赋值
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		~unique_ptr()
		{
			if (_ptr != nullptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		unique_ptr(const unique_ptr<T>& sp) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& sp) = delete;
	private:
		T* _ptr;
	};



	//为解决以上两个智能指针的缺陷，提出了引用计数的方法
	//static int pcount的缺陷，对于不同维护不同空间的智能指针对象会出问题，存在内存泄漏
	//int& pcount的缺陷，初始化不方便
	//所以使用指针的方法，int* pcount;
	//share_ptr需要线程安全，所以要加锁处理
	template<class T>
	class share_ptr
	{
	public:
		//构造函数
		share_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(nullptr)
			, _mtx(nullptr)
		{
			_pcount = new int(1);
			_mtx = new mutex;
		}

		//拷贝构造
		//share_ptr<int> sp2(sp1);
		share_ptr(share_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _mtx(sp._mtx)
		{
			_mtx->lock();
			(*_pcount)++;
			_mtx->unlock();
		}

		//重载=
		//share_ptr<int> sp3 = sp1;
		share_ptr<T>& operator=(share_ptr<T>& sp)
		{
			if (this != &sp)
			{
				_mtx->lock();
				bool flag = false;
				//先把原来的空间释放掉
				if (--(*_pcount) == 0 && _pcount != nullptr)
				{
					cout << "赋值=delete" << endl;
					delete _ptr;
					delete _pcount;
					flag = true;
				}
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_mtx = sp._mtx;
				(*_pcount)++;
				_mtx->unlock();
				if (flag == true)
				{
					delete _mtx;
				}
			}
			return *this;
		}

		//析构函数
		~share_ptr()
		{
			_mtx->lock();
			bool flag = false;
			if (--(*_pcount) == 0 && _ptr != nullptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				delete _pcount;
				flag = true;
			}
			_mtx->unlock();
			if (flag == true)
			{
				delete _mtx;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		//获取有对象正在使用引用计数
		int use_count()
		{
			return *_pcount;
		}
	private:
		T* _ptr;
		int* _pcount;
		mutex* _mtx;
	};
}