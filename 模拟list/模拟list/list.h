#pragma once
#include<iostream>
#include<stdbool.h>
#include<assert.h>
#include<algorithm>
using namespace std;

namespace My_list
{
	//封装链表结点类	
	template<class T>
	struct __list_node
	{
		//成员变量
		T _data;
		__list_node<T>* _prev;
		__list_node<T>* _next;

		//成员函数
		__list_node(const T& val = T())
			:_data(val)
			,_prev(nullptr)
			,_next(nullptr)
		{
		}
	};

	//封装迭代器类
	//__list_iterator<T,T&,T> -> iterator
	//__list_iterator<T,const T&,const T*> -> const iterator
	template<class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef __list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> iterator;

		//构造函数	构造迭代器
		__list_iterator(Node* node=nullptr)
			:_node(node)
		{
		}

		//返回迭代器指向数据的引用
		Ref operator*() const
		{
			return _node->_data;
		}

		//用于测试list里面存Date类的解引用操作		返回的是迭代器指向数据的指针
		Ptr operator->() const
		{
			return &_node->_data;
		}

		//迭代器前置++操作
		iterator operator++()
		{
			_node = _node->_next;
			return *this;
		}

		//迭代器前置--操作
		iterator operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		//迭代器后置++
		iterator operator++(int)
		{
			iterator tmp(*this);
			//_node = _node->_next;
			++(*this);
			return tmp; 
		}
		//迭代器后置--
		iterator operator--(int)
		{
			iterator tmp(*this);
			//_node = _node->_prev;
			--(*this);
			return tmp;
		}

		//重载operator!=
		bool operator!=(const iterator it) const
		{
			if (_node != it._node)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		//重载operator==
		bool operator==(const iterator it) const 
		{
			return !(*this != it);
		}

		//成员变量
		Node* _node;
	};

	//list类
	template<class T>
	class list
	{
		//链表结点类
		typedef __list_node<T> Node;
	public:
		//迭代器类
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		//begin迭代器
		iterator begin()
		{
			iterator it(_head->_next);
			return it;
		}

		//end迭代器
		iterator end()
		{
			iterator it(_head);
			return it;
		}

		//const_begin迭代器
		const_iterator begin() const
		{
			const_iterator cit(_head->_next);
			return cit;
		}

		//const_end迭代器
		const_iterator end() const
		{
			const_iterator cit(_head);
			return cit;
		}

		//构造函数
		list()
			:_head(new Node)
		{
			//_head = new Node;	
			_head->_prev = _head;
			_head->_next = _head;
		}

		//析构函数
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		//拷贝构造
		//list<int> l2(l1)
		list(const list<T>& tmp)
			:_head(new Node)
		{
			_head->_next = _head;
			_head->_prev = _head;

			const_iterator it = tmp.begin();
			while (it != tmp.end())
			{
				push_back(*it);
				it++;
			}
		}

		//赋值=重载
		//list<int> l3;
		//l3=l2;
		list<T>& operator=(const list<T>& tmp)
		{
			if (this != &tmp)
			{
				list<T> l(tmp);
				Swap(l);
			}
			return *this;
		}

		//交换两个链表
		//l1.Swap(l2);
		void Swap(list<T>& tmp)	
		{
			swap(_head, tmp._head);
		}

		//clear清理函数	后续改进为调用erase函数
		void clear()
		{
			Node* headnext = _head->_next;//找到头结点的下一个结点
			//释放除头结点外的所有结点
			while (headnext != _head)
			{
				Node* tmp = headnext->_next;
				delete headnext;
				headnext = tmp;
			}

			_head->_next = _head;
			_head->_prev = _head;
		}

		//尾插
		void push_back(const T& val)
		{
			////生成一个新结点，给新结点赋值
			//Node* newnode = new Node(val);
			//Node* tail = _head->_prev;//先找到尾结点

			//tail->_next = newnode;
			//newnode->_prev = tail;
			//newnode->_next = _head;
			//_head->_prev = newnode;

			insert(end(), val);
		}

		//尾删
		void pop_back()
		{
			iterator it = end();
			erase(--it);
		}

		//头插
		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		//头删
		void pop_front()
		{
			iterator it(begin());
			erase(it);
		}

		//中间插入
		iterator insert(iterator pos, const T& val)
		{
			Node* newnode = new Node(val);
			Node* posprev = pos._node->_prev;

			posprev->_next = newnode;
			newnode->_prev = posprev;
			newnode->_next = pos._node;
			pos._node->_prev = newnode;	

			iterator it(newnode);
		return it;
		}

		//中间删除
		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* posprev = pos._node->_prev;
			Node* posnext = pos._node->_next;

			posprev->_next = posnext;
			posnext->_prev = posprev;

			delete pos._node;

			iterator it(posnext);
			return it;
		}

	private:
		Node* _head;
	};

	//测试list里面存Date类型
	class Date
	{
	public:
		Date(int year = 0, int month = 0, int day = 0)
			:_year(year)
			,_month(month)
			,_day(day)
		{

		}
	//private:
		int _year;
		int _month;
		int _day;
	};

	void Test1()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		l1.push_front(0);
		l1.push_front(-1);
		l1.push_front(-2);
		l1.push_front(-3);

		l1.pop_back();
		l1.pop_back();

		l1.pop_front();
		l1.pop_front();

		list<int>::iterator it = l1.begin();
		while (it != l1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void Test2()
	{
		list<Date> l1;
		l1.push_back(Date());
		l1.push_back(Date());
		l1.push_back(Date());
		l1.push_back(Date());

		list<Date>::iterator it = l1.begin();
		while (it != l1.end())
		{
			cout << it->_year << "-" << it->_month << "-" << it->_day << endl;
			it++;
		}
		
	}

	//测试迭代器的非const和const
	void Test3()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);

		list<int>::iterator it = l1.begin();
		while (it != l1.end())
		{
			(*it)++;
			cout << *it << " ";
			it++;
		}
		cout << endl;

	}

	//测试拷贝构造 和 赋值=重载
	void Test4()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);

		list<int> l2(l1);

		list<int> l3;
		l3 = l2;

		list<int>::iterator it1 = l1.begin();
		while (it1 != l1.end())
		{
			(*it1)++;
			cout << *it1 << " ";
			it1++;
		}
		cout << endl;

		list<int>::iterator it2 = l2.begin();
		while (it2 != l2.end())
		{
			(*it2)++;
			cout << *it2 << " ";
			it2++;
		}
		cout << endl;

		list<int>::iterator it3 = l3.begin();
		while (it3 != l3.end())
		{
			(*it3)++;
			cout << *it3 << " ";
			it3++;
		}

		cout << endl;
	}
}