#pragma once
#include<iostream>
#include<vector>
using namespace std;

namespace Close_Hash
{
	enum State
	{
		EMPTY,
		EXITS,
		DELETE
	};

	template<class T>
	struct HashData
	{
		T _data;
		State _state;//状态
	};

	template<class K, class T>
	class HashTable
	{
	public:
		//构造函数
		HashTable()
			:_nums(0)
		{
			_tables.resize(10);
		}

		//扩容
		void reserve()
		{
			HashTable<K, T> newtable;
			newtable._tables.resize(_tables.size() * 2);
			for (auto& e : _tables)
			{
				if (e._state == EXITS)
				{
					newtable.insert(e._data);
				}
			}
			_tables.swap(newtable._tables);
		}

		//插入
		bool insert(const T& data)
		{
			//负载因子
			//哈希表不能满，当哈希表有70%的数据时就要进行扩容
			if (_nums * 10 / _tables.size() == 7)
			{
				reserve();
			}

			size_t index = data % _tables.size();
			while (_tables[index]._state == EXITS)//如果该位置有数据，则需要向后找空位，或者进行判断要插入的数据是否已经存在
			{
				if (_tables[index]._data == data)
				{
					return false;
				}

				index++;
				if (index == _tables.size())
				{
					index = 0;
				}
			}
			_tables[index]._data = data;
			_tables[index]._state = EXITS;
			_nums++;
			return true;
		}

		//查找
		HashData<T>* find(const T& data)
		{
			size_t index = data % _tables.size();
			while (_tables[index]._state != EMPTY)
			{
				if (_tables[index]._data == data)
				{
					if (_tables[index]._state == EXITS)
					{
						return &_tables[index];
					}
					else if (_tables[index]._state == DELETE)
					{
						return nullptr;
					}
				}
				index++;
				if (index == _tables.size())
				{
					index = 0;
				}
			}
			return nullptr;
		}

		//删除
		bool erase(const T& data)
		{
			HashData<T>* tmp = find(data);
			if (tmp == nullptr)
			{
				return false;
			}
			tmp->_state = DELETE;
			return true;
		}

		//遍历
		void Print()
		{
			for (auto& e : _tables)
			{
				cout << e._data << " ";
			}
			cout << endl;
		}

	private:
		vector<HashData<T>> _tables;
		size_t _nums;//有效数据个数
	};

	void Test1()
	{
		HashTable<int, int> table;
		int arr[] = { 4,14,24,5,15,25,6,16 };
		for (auto& e : arr)
		{
			table.insert(e);
		}
		table.Print();
	}
}

namespace Open_Hash
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			,_next(nullptr)
		{}
	};

	template<class T>
	struct HashTableIterator
	{
		typedef HashNode<T> Node;
		typedef HashTableIterator Self;

		HashTableIterator(Node* tmp)
			:_node(tmp)
		{}

		T& operator*()
		{
			return _node->_data;
		}

		Self operator++()
		{
			_node = _node->_next;
			if (_node == nullptr)
			{

			}
			return *this;
		}


		//成员变量
		Node* _node;
	};

	template<class V>
	class HashTable
	{
	public:
		typedef HashNode<V> Node;
		typedef HashTableIterator<V> iterator;
	public:
		//构造函数
		HashTable()
			:_nums(0)
		{
			_tables.resize(10);
		}

		iterator begin()
		{
			for (int i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				if (cur != nullptr)
				{
					return iterator(cur);
				}
			}
			return iterator(nullptr);
		}

		iterator end()
		{
			return iterator(nullptr);
		}

		//扩容
		void reserve()
		{
			HashTable<V> newtable;//开一张新的hash临时哈希表，将旧表的结点都拿过来
			newtable._tables.resize(_nums * 2);
			
			//遍历旧表将结点拿过来
			for (int i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur != nullptr)
				{
					Node* next = cur->_next;//保存cur的下一个结点

					size_t index = cur->_data % newtable._tables.size();
					//Node* newtable_cur = newtable._tables[index];

					cur->_next = newtable._tables[index];
					newtable._tables[index] = cur;

					cur = next;
				}
			}
			_tables.swap(newtable._tables);
		}

		//插入
		bool insert(const V& data)
		{
			//再插入之前，要进行判断，是否需要扩容来避免更多的函数冲突
			if (_nums == _tables.size())
			{
				reserve();
			}

			size_t index = data % _tables.size();
			//插入之前，要判断该值有没有，如果有，则不插入
			Node* cur = _tables[index];
			while (cur != nullptr)
			{
				if (cur->_data == data)
				{
					return false;
				}
				cur = cur->_next;
			}

			//将新结点头插到哈希桶中
			Node* newnode = new Node(data);
			newnode->_next = _tables[index];
			_tables[index] = newnode;
			_nums++;//有效数据个数6++
			return true;
		}

		//删除
		bool erase(const V& data)
		{
			size_t index = data % _tables.size();
			Node* cur = _tables[index];
			Node* prev = nullptr;
			while (cur != nullptr)//开始查找要删除的结点
			{
				if (cur->_data == data)//说明找到了，将他删除
				{
					if (prev == nullptr)//说明要删除的结点时第一个
					{
						_tables[index] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					_nums--;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}
			return false;
		}

		//查找
		Node* find(const V& data)
		{
			size_t index = data % _tables.size();
			Node* cur = _tables[index];
			while (cur != nullptr)
			{
				if (cur->_data == data)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return nullptr;
		}

		void Print()
		{
			for (int i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur != nullptr)
				{
					cout << cur->_data << " ";
					cur = cur->_next;
				}
			}
		}

	private:
		vector<Node*> _tables;
		size_t _nums;//有效数据个数
	};

	void Test1()
	{
		HashTable<int> table;
		int arr[] = { 15,25,5,17,15,27,37,6,16,26,19,18 };
		for (auto& e : arr)
		{
			table.insert(e);
		}

		table.Print();
		table.erase(5);
	}
}
