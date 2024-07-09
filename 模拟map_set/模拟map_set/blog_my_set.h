#pragma once
#include"blog_RBTree.h"

using namespace blog_RBTree;

namespace my_blog_my_set
{
	template<class T>
	class blog_my_set
	{
	public:

		//获取需要比较的值
		struct GetCompareValue
		{
			const T operator()(const T& data)
			{
				return data;
			}
		};

		typedef typename blog_RBTree::RBTree<T, GetCompareValue>::iterator iterator;

		//插入
		pair<iterator,bool> insert(const T& data)
		{
			return _tree.insert(data);
		}

		iterator begin()
		{
			return _tree.begin();
		}

		iterator end()
		{
			return _tree.end();
		}
	private:
		//成员变量
		blog_RBTree::RBTree<T, GetCompareValue> _tree;
	};

	void Test1()
	{
		blog_my_set<int> s;
		s.insert(10);
		s.insert(12);
		s.insert(22);
		s.insert(19);

		blog_my_set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << endl;
			++it;
		}
	}
}

