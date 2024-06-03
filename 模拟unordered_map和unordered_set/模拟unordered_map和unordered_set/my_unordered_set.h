#pragma once
#include"my_hash.h"
using namespace std;
using namespace my_hash;

namespace my_unordered_set
{
	//哈希函数
	template<class Key>
	struct hash
	{
		size_t operator()(const Key& tmp)
		{
			return tmp;
		}
	};

	template<class Key, class Hash = hash<Key>>
	class unordered_set
	{
	public:
		//仿函数，获取要比较的值
		struct GetCompareKey
		{
			const Key& operator()(const Key& tmp)
			{
				return tmp;
			}
		};

		typedef typename HashTable<Key, Key, GetCompareKey, Hash>::iterator iterator;

		iterator begin()
		{
			return _tables.begin();
		}

		iterator end()
		{
			return _tables.end();
		}

		bool insert(const Key& tmp)
		{
			return _tables.insert(tmp);
		}

	private:
		HashTable<Key, Key, GetCompareKey, Hash> _tables;
	};

	void Test1()
	{
		unordered_set<int> s;
		int arr[] = { 1,56,23,47,14,15,22,23,65,48,95,100,7 };
		for (auto& e : arr)
		{
			s.insert(e);
		}
		unordered_set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
	}
}