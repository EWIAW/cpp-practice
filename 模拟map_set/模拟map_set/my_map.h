#pragma once
#include"RBTree.h"

namespace My_map
{
	template<class K, class V>
	class map
	{
	public:
		struct MapGetCompareValue
		{
			const K& operator()(const pair<K, V>& tmp)
			{
				return tmp.first;
			}
		};

		typedef typename RBTree<K, pair<K, V>, MapGetCompareValue>::iterator iterator;

		iterator begin()
		{
			return _tree.begin();
		}

		iterator end()
		{
			return _tree.end();
		}

		bool insert(const pair<K, V>& tmp)
		{
			return _tree.insert(tmp);
		}

	private:
		RBTree<K, pair<K, V>, MapGetCompareValue> _tree;
	};

	void map_test1()
	{
		map<int, int> m;
		m.insert(make_pair(1, 1));
		m.insert(make_pair(3, 3));
		m.insert(make_pair(12, 12));
		m.insert(make_pair(7, 7));
		m.insert(make_pair(6, 6));
		m.insert(make_pair(2, 2));

		map<int, int>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
	}
}