//复习智能指针，并写一篇博客
#pragma once
#include<iostream>
#include<mutex>

namespace blog_smartptr
{
	template<class T>
	class auto_ptr
	{
	public:
		//构造函数
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}
		//析构函数
		~auto_ptr()
		{
			if (_ptr != nullptr)
			{
				delete _ptr;
				std::cout << "auto_ptr所指向资源已被释放" << std::endl;
			}
		}

		//拷贝构造，将原来的auto_ptr所管理的资源转移给新的auto_ptr对象
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		//operator=重载
		auto_ptr<T>& operator=(auto_ptr<T>& sp)
		{
			if (this != &sp)
			{
				if (_ptr != nullptr)//如果_ptr有指向的资源，要先将_ptr所指向的资源释放掉，否则会出现内存泄漏
				{
					delete _ptr;
				}
				_ptr = sp._ptr;
				sp._ptr = nullptr;
			}
			return *this;
		}

		//实现可以模拟指针的原生行为
		//重载operator*
		T& operator*()
		{
			return *_ptr;
		}
		//重载operator->
		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr != nullptr)
			{
				delete _ptr;
				std::cout << "unique_ptr所指向资源已被释放" << std::endl;
			}
		}

		//非常简单粗暴的将拷贝构造和operator=重载函数删除掉
		unique_ptr(const unique_ptr<T>& up) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& up) = delete;

		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return &_ptr;
		}
	private:
		T* _ptr;
	};

	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(const T* ptr)
			:_ptr(ptr)
			, _pRefCount(new int(1))
			, _pmtx(new std::mutex)
		{}

		shared_ptr(shared_ptr<T>& sp)
			: _ptr(sp._ptr)
			, _pmtx(sp._pmtx)
			, _pRefCount(sp._pRefCount)
		{
			{
				std::mutex lock(_pmtx);
				(*_pRefCount)++;
			}
		}

		shared_ptr<T>& operator=(shared_ptr<T>& sp)
		{
			//要先解决原来资源的问题
			{
				std::mutex lock(_pmtx);
				(*_pRefCount)--;
				if (*_pRefCount == 0)
				{
					delete _ptr;
				}
			}
		}

		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return &_ptr;
		}
	private:
		T* _ptr;
		int* _pRefCount;
		std::mutex* _pmtx;//需要锁，是因为操作_pRefCount的时候，需要保证是线程安全的
	};
}