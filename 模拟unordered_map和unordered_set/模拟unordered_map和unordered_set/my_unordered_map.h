#pragma once
#include"my_hash.h"
#include<iostream>
#include<string>
using namespace std;
using namespace my_hash;

namespace my_unordered_map
{
	//哈希函数(整形)
	template<class Key>
	struct hash
	{
		size_t operator()(const Key& tmp)
		{
			return tmp;
		}
	};

	template<>
	struct hash<string>
	{
		size_t operator()(const string& tmp)
		{
			size_t count = 0;
			for (int i = 0; i < tmp.size(); i++)
			{
				count += tmp[i] - 'a';
			}
			return count;
		}
	};

	template<class Key, class Val, class Hash = hash<Key>>
	class unordered_map
	{
	public:
		//仿函数，获取要比较的值
		struct GetCompareKey
		{
			const Key& operator()(const pair<Key, Val>& tmp)
			{
				return tmp.first;
			}
		};

		typedef typename HashTable<Key, pair<Key, Val>, GetCompareKey, Hash>::iterator iterator;

		iterator begin()
		{
			return _tables.begin();
		}

		iterator end()
		{
			return _tables.end();
		}

		bool insert(const pair<Key, Val>& tmp)
		{
			return _tables.insert(tmp);
		}

	private:
		HashTable<Key, pair<Key, Val>, GetCompareKey, Hash> _tables;
	};

	void Test1()
	{
		unordered_map<int, int> m;
		int arr[] = { 1,56,23,47,14,15,22,23,65,48,95,100,7 };
		for (auto& e : arr)
		{
			m.insert(make_pair(e, e));
		}
		unordered_map<int, int>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
	}

	void Test2()
	{
		unordered_map<string, string> m;
		m.insert(make_pair("sort", "排序"));
		m.insert(make_pair("left", "左边"));
		m.insert(make_pair("water", "水"));
		m.insert(make_pair("language", "语言"));
		unordered_map<string, string>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
	}
}