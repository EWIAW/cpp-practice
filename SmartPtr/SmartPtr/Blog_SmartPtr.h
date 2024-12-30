//��ϰ����ָ�룬��дһƪ����
#pragma once
#include<iostream>
#include<mutex>

namespace blog_smartptr
{
	template<class T>
	class auto_ptr
	{
	public:
		//���캯��
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}
		//��������
		~auto_ptr()
		{
			if (_ptr != nullptr)
			{
				delete _ptr;
				std::cout << "auto_ptr��ָ����Դ�ѱ��ͷ�" << std::endl;
			}
		}

		//�������죬��ԭ����auto_ptr���������Դת�Ƹ��µ�auto_ptr����
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		//operator=����
		auto_ptr<T>& operator=(auto_ptr<T>& sp)
		{
			if (this != &sp)
			{
				if (_ptr != nullptr)//���_ptr��ָ�����Դ��Ҫ�Ƚ�_ptr��ָ�����Դ�ͷŵ������������ڴ�й©
				{
					delete _ptr;
				}
				_ptr = sp._ptr;
				sp._ptr = nullptr;
			}
			return *this;
		}

		//ʵ�ֿ���ģ��ָ���ԭ����Ϊ
		//����operator*
		T& operator*()
		{
			return *_ptr;
		}
		//����operator->
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
				std::cout << "unique_ptr��ָ����Դ�ѱ��ͷ�" << std::endl;
			}
		}

		//�ǳ��򵥴ֱ��Ľ����������operator=���غ���ɾ����
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
		//���캯��
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pRefCount(new int(1))
			, _pmtx(new std::mutex)
		{
			if (_ptr == nullptr)//��ֹ��nullptr��������ָ��
			{
				*_pRefCount = 0;
			}
		}

		//��������
		~shared_ptr()
		{
			Release();
		}

		//��������
		shared_ptr(shared_ptr<T>& sp)
		{
			std::unique_lock<std::mutex> lock(*sp._pmtx);//��������
			_ptr = sp._ptr;
			_pRefCount = sp._pRefCount;
			_pmtx = sp._pmtx;
			if (_ptr != nullptr)
			{
				(*_pRefCount)++;
			}
		}

		//operator=����
		shared_ptr<T>& operator=(shared_ptr<T>& sp)
		{
			if (this != &sp)//��ֹ�Լ����Լ���ֵ
			{
				//���ͷ�ԭ����ָ�����Դ
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
		//�ͷ���Դ
		void Release()
		{
			if (_pmtx != nullptr)
			{
				_pmtx->lock();
				bool flag = false;//�����ж��Ƿ���Ҫ�Ƿ�_pmtx
				if (_pRefCount != nullptr && --(*_pRefCount) == 0)
				{
					std::cout << "shared_ptr��ָ�����Դ�ѱ��ͷ�" << std::endl;
					delete _ptr;
					delete _pRefCount;
					flag = true;
					//delete _pmtx;���ﲻ��ֱ��delete������Ϊ������ʹ��
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
		std::mutex* _pmtx;//��Ҫ��������Ϊ����_pRefCount��ʱ����Ҫ��֤���̰߳�ȫ��
	};

	template<class T>
	class weak_ptr
	{
	public:
		//���캯��
		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get())
		{}

		//operator=����
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
//		// ��ָ��һ��ʹ��
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