#pragma once
#include"blog_RBTree.h"

using namespace blog_RBTree;

namespace my_blog_my_map
{
	template<class Key , class T>
	class blog_my_map
	{
	public:

		//��ȡ��Ҫ�Ƚϵ�ֵ
		struct GetCompareValue
		{
			const Key operator()(const pair<Key,T>& data)
			{
				return data.first;
			}
		};

		typedef typename blog_RBTree::RBTree<pair<Key,T>, GetCompareValue>::iterator iterator;

		iterator begin()
		{
			return _tree.begin();
		}

		iterator end()
		{
			return _tree.end();
		}

		//����
		pair<iterator, bool> insert(const pair<Key,T>& data)
		{
			return _tree.insert(data);
		}

		//����operator[]
		T& operator[](const Key& tmp)
		{
			pair<iterator, bool> it = insert(make_pair(tmp, T()));
			return it.first->second;
		}

	private:
		//��Ա����
		blog_RBTree::RBTree<pair<Key, T>, GetCompareValue> _tree;
	};

	void Test1()
	{
		blog_my_map<int, int> m;
		m.insert(make_pair(1, 1));
		m.insert(make_pair(56, 56));
		m.insert(make_pair(45, 45));
		m.insert(make_pair(8, 8));
		m[100];
		m[200] = 999;

		blog_my_map<int,int>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << (*it).first << ":" << (*it).second << endl;
			++it;
		}
	}
}