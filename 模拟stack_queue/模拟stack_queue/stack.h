#pragma once
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

namespace My_Stack
{
	//使用模板来给一个vector参数
	template<class T,class Container=vector<T>>
	class stack
	{
	public:
		stack()
		{}

		//入栈
		void push(const T& val)
		{
			_s.push_back(val);
		}

		//出栈
		void pop()
		{
			_s.pop_back();
		}

		//判断是否为空
		bool empty() const
		{
			return _s.empty();
		}

		//获取数据个数
		size_t size() const
		{
			return _s.size();
		}

		//取栈顶数据
		T& top()
		{
			return _s.back();
		}

		//const类型取栈顶数据
		const T& top() const
		{
			return _s.back();
		}

	private:
		Container _s;
	};

	void Test1()
	{
		stack<int> s1;
		s1.push(1);
		s1.push(2);
		s1.push(3);
		s1.push(4);

		while (!s1.empty())
		{
			cout << s1.top() << " ";
			s1.pop();
		}
	}

	void Test2()
	{
		stack<int> s1;
		s1.push(1);
		s1.push(2);
		s1.push(3);
		s1.push(4);

		int a = s1.top();
		s1.pop();
		s1.push(10);
	
		cout << a << endl;
	}
}

namespace deque_stack
{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		stack(){}
		//入栈
		void push(const T& val){_s.push_back(val);}
		//出栈
		void pop(){_s.pop_back();}
		//判断是否为空
		bool empty() const{return _s.empty();}
		//获取数据个数
		size_t size() const{return _s.size();}
		//取栈顶数据
		T& top(){return _s.back();}
		//const类型取栈顶数据
		const T& top() const{return _s.back();}
	private:
		Container _s;
	};

	void Test1()
	{
		stack<int> s1;
		s1.push(1);
		s1.push(2);
		s1.push(3);
		s1.push(4);
		while (!s1.empty())
		{
			cout << s1.top() << " ";
			s1.pop();
		}
	}
}