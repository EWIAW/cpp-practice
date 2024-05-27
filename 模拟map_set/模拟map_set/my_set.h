#pragma once
#include"RBTree.h"

namespace My_set
{
	template<class K, class Compare=less<K>>
	class set
	{
	public:
		struct SetGetCompareValue
		{
			const K& operator()(const K& tmp)
			{
				return tmp;
			}
		};

		typedef typename RBTree<K, K, Compare, SetGetCompareValue>::iterator iterator;

		pair<iterator, bool> insert(const K& tmp)
		{
			return _tree.insert(tmp);
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
		RBTree<K, K, Compare, SetGetCompareValue> _tree;
	};

	void set_test1()
	{
		set<int,greater<int>> s;
		s.insert(1);
		s.insert(10);
		s.insert(5);
		s.insert(18);
		s.insert(2);
		s.insert(7);

		set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << endl;
			++it;
		}
		
	}
}
