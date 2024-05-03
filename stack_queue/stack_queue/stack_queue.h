#pragma once
#include<iostream>
#include<vector>
#include<list>
using namespace std;

namespace My_stack
{
	template<class T,class Container>
	class stack
	{
	public:
		void push(const T& val)
		{
			_stack.push_back(val);
		}

		void pop()
		{
			_stack.pop_back();
		}

		T& top()
		{
			return _stack.back();
		}

		int size()
		{
			return _stack.size();
		}

		bool empty()
		{
			return _stack.empty();
		}

	private:
		Container _stack;
	};

	void Test1()
	{
		stack<int, list<int>> s;

		s.push(1);
		s.push(2);
		s.push(3);
		s.push(4);

		while (!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
	}
}

namespace My_queue
{
	template<class T,class Container>
	class queue
	{
	public:
		void push(const T& val)
		{
			_queue.push_back(val);
		}

		void pop()
		{
			_queue.pop_front();
		}

		int size()
		{
			_queue.size();
		}

		bool empty()
		{
			return _queue.empty();
		}

		T& front()
		{
			return _queue.front();
		}

		T& back()
		{
			return _queue.back();
		}

	private:
		Container _queue; 
	};

	void Test1()
	{
		queue<int, list<int>> q;

		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);

		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}
}