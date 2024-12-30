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
		//shared_ptr() = default;
		//构造函数
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pRefCount(new int(1))
			, _pmtx(new std::mutex)
		{
			if (_ptr == nullptr)//防止拿nullptr构造智能指针
			{
				*_pRefCount = 0;
			}
		}

		//析构函数
		~shared_ptr()
		{
			Release();
		}

		//拷贝构造
		shared_ptr(shared_ptr<T>& sp)
		{
			std::unique_lock<std::mutex> lock(*sp._pmtx);//加锁保护
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pmtx = sp._pmtx;
			if (_ptr != nullptr)
			{
				(*_pRefCount)++;
			}
		}

		//operator=重载
		shared_ptr<T>& operator=(shared_ptr<T>& sp)
		{
			if (this != &sp)//防止自己给自己赋值
			{
				//先释放原来所指向的资源
				Release();
				{
					std::unique_lock<std::mutex> lock(*sp._pmtx);
					_ptr = sp._ptr;
					_pRefCount = sp._pRefCount;
					_pmtx = sp._pmtx;
					if (_pRefCount != nullptr)
					{
						(*_pRefCount)++;
					}
				}
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

		int use_count()
		{
			return *_pRefCount;
		}

		T* get() const
		{
			return _ptr;
		}
	private:
		//释放资源
		void Release()
		{
			if (_pmtx != nullptr)
			{
				_pmtx->lock();
				bool flag = false;//辅助判断是否需要是否_pmtx
				if (_pRefCount != nullptr && --(*_pRefCount) == 0)
				{
					std::cout << "shared_ptr所指向的资源已被释放" << std::endl;
					delete _ptr;
					delete _pRefCount;
					flag = true;
					//delete _pmtx;这里不能直接delete，是因为锁还在使用
				}
				_pmtx->unlock();
				if (flag == true)
				{
					delete _pmtx;
				}
			}
			_ptr = nullptr;
			_pRefCount = nullptr;
			_pmtx = nullptr;
		}

	private:
		T* _ptr;
		int* _pRefCount;
		std::mutex* _pmtx;//需要锁，是因为操作_pRefCount的时候，需要保证是线程安全的
	};

	template<class T>
	class weak_ptr
	{
	public:
		//构造函数
		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get())
		{}

		//operator=重载
		weak_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			_ptr = sp.get();
			return *this;
		}

	private:
		T* _ptr;
	};
}

//namespace bit
//{
//	template<class T>
//	class shared_ptr
//	{
//	public:
//		shared_ptr(T* ptr = nullptr)
//			:_ptr(ptr)
//			, _pRefCount(new int(1))
//			, _pmtx(new std::mutex)
//		{}
//		shared_ptr(const shared_ptr<T>& sp)
//			:_ptr(sp._ptr)
//			, _pRefCount(sp._pRefCount)
//			, _pmtx(sp._pmtx)
//		{
//			AddRef();
//		}
//		void Release()
//		{
//			_pmtx->lock();
//			bool flag = false;
//			if (--(*_pRefCount) == 0 && _ptr)
//			{
//				std::cout << "delete:" << _ptr << std::endl;
//				delete _ptr;
//				delete _pRefCount;
//				flag = true;
//			}
//			_pmtx->unlock();
//			if (flag == true)
//			{
//				delete _pmtx;
//			}
//		}
//		void AddRef()
//		{
//			_pmtx->lock();
//			++(*_pRefCount);
//			_pmtx->unlock();
//		}
//		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
//		{
//			//if (this != &sp)
//			if (_ptr != sp._ptr)
//			{
//				Release();
//				_ptr = sp._ptr;
//				_pRefCount = sp._pRefCount;
//				_pmtx = sp._pmtx;
//				AddRef();
//			}
//			return *this;
//		}
//		int use_count()
//		{
//			return *_pRefCount;
//		}
//		~shared_ptr()
//		{
//			Release();
//		}
//		// 像指针一样使用
//		T& operator*()
//		{
//			return *_ptr;
//		}
//		T* operator->()
//		{
//			return _ptr;
//		}
//		T* get() const
//		{
//			return _ptr;
//		}
//	private:
//		T* _ptr;
//		int* _pRefCount;
//		std::mutex* _pmtx;
//	};
//
//	template<class T>
//	class weak_ptr
//	{
//	public:
//		weak_ptr(const shared_ptr<T>& sp)
//			:_ptr()
//		{}
//
//	private:
//		T* _ptr;
//	};
//}