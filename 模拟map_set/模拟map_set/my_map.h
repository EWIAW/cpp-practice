#pragma once
#include"RBTree.h"
#include<string>

namespace My_map
{
	template<class K, class V, class Compare=less<K>>
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

		typedef typename RBTree<K, pair<K, V>, Compare, MapGetCompareValue>::iterator iterator;

		iterator begin()
		{
			return _tree.begin();
		}

		iterator end()
		{
			return _tree.end();
		}

		pair<iterator,bool> insert(const pair<K, V>& tmp)
		{
			return _tree.insert(tmp);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));	
			return ret.first->second;
		}

	private:
		RBTree<K, pair<K, V>, Compare, MapGetCompareValue> _tree;
	};

	void map_test1()
	{
		map<int, int, greater<int>> m;
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

	void map_test2()
	{
		map<string, int> m;
		string str[] = { "Æ»¹û","Æ»¹û","Ñ©Àæ","Æ»¹û","Ïã½¶","Ïã½¶","Ñ©Àæ","Æ»¹û","Ïã½¶","Î÷¹Ï" };
		for (auto& e : str)
		{
			m[e]++;
		}

		for (auto& e : m)
		{
			cout << e.first << ":" << e.second << endl;
		}
	}
}