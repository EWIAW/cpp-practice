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
			//Ҫ�Ƚ��ԭ����Դ������
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
		std::mutex* _pmtx;//��Ҫ��������Ϊ����_pRefCount��ʱ����Ҫ��֤���̰߳�ȫ��
	};
}