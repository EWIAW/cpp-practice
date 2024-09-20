#pragma once
#pragma once
#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

namespace my
{
	//C++98����������ָ��
	//���ڿ�������͸�ֵ=������˵��ʹ�ù���Ȩת�Ƶ�����
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



	//Ϊ�˽��auto_ptr�����⣬�����unique_ptrָ�룬�����ķ������͸�ֵ
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



	//Ϊ���������������ָ���ȱ�ݣ���������ü����ķ���
	//static int pcount��ȱ�ݣ����ڲ�ͬά����ͬ�ռ������ָ����������⣬�����ڴ�й©
	//int& pcount��ȱ�ݣ���ʼ��������
	//����ʹ��ָ��ķ�����int* pcount;
	//share_ptr��Ҫ�̰߳�ȫ������Ҫ��������
	template<class T>
	class share_ptr
	{
	public:
		//���캯��
		share_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(nullptr)
			, _mtx(nullptr)
		{
			_pcount = new int(1);
			_mtx = new mutex;
		}

		//��������
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

		//����=
		//share_ptr<int> sp3 = sp1;
		share_ptr<T>& operator=(share_ptr<T>& sp)
		{
			if (this != &sp)
			{
				_mtx->lock();
				bool flag = false;
				//�Ȱ�ԭ���Ŀռ��ͷŵ�
				if (--(*_pcount) == 0 && _pcount != nullptr)
				{
					cout << "��ֵ=delete" << endl;
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

		//��������
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

		//��ȡ�ж�������ʹ�����ü���
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