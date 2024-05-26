#pragma once
#include"RBTree.h"

namespace My_set
{
	template<class K>
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

		bool insert(const K& tmp)
		{
			return _tree.insert(tmp);

		}
	private:
		RBTree<K, K, SetGetCompareValue> _tree;
	};

	void set_test1()
	{
		set<int> s;
		s.insert(1);
		s.insert(10);
		s.insert(5);
		s.insert(18);
		s.insert(2);
		s.insert(7);
	}
}
