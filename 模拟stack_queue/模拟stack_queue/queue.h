#pragma once
#include<iostream>
#include<list>

namespace My_queue
{
	template<class T,class Container=list<T>>
	class queue
	{
	public:
		queue()
		{}

		//入队列
		void push(const T& val)
		{
			_l.push_back(val);
		}

		//出队列
		void pop()
		{
			_l.pop_front();
		}

		//取对头
		T& front()
		{
			return _l.front();
		}

		const T& front() const
		{
			return _l.front();
		}

		//取队尾
		T& back()
		{
			return _l.back();
		}

		const T& back() const
		{
			return _l.back();
		}

		//判断是否为空
		bool empty() const
		{
			return _l.empty();
		}

		//获取数据个数
		size_t size() const
		{
			return _l.size();
		}

	private:
		Container _l;
	};

	void Test1()
	{
		queue<int> q1;
		q1.push(1);
		q1.push(2);
		q1.push(3);
		q1.push(4);

		cout << q1.size() << endl;

		while (!q1.empty())
		{
			cout << q1.front() << " ";
			q1.pop();
		}
	}
}