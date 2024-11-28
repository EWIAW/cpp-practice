#pragma once
#include<iostream>
#include<vector>
#include<time.h>
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
		State _state;//״̬
	};

	template<class K, class T>
	class HashTable
	{
	public:
		//���캯��
		HashTable()
			:_nums(0)
		{
			_tables.resize(10);
		}

		//����
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

		//����
		bool insert(const T& data)
		{
			//��������
			//��ϣ������������ϣ����70%������ʱ��Ҫ��������
			if (_nums * 10 / _tables.size() == 7)
			{
				reserve();
			}

			size_t index = data % _tables.size();
			while (_tables[index]._state == EXITS)//�����λ�������ݣ�����Ҫ����ҿ�λ�����߽����ж�Ҫ����������Ƿ��Ѿ�����
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

		//����
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

		//ɾ��
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

		//����
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
		size_t _nums;//��Ч���ݸ���
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
			, _next(nullptr)
		{}
	};

	template<class T>
	struct HashTableIterator
	{
		typedef HashNode<T> Node;
		typedef HashTableIterator Self;

		HashTableIterator(Node* tmp, vector<Node*>* vec, size_t num)
			:_node(tmp)
			, _tab(vec)
			, _num(num)
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
				size_t i;
				for (i = _num + 1; i < _tab->size(); i++)
				{
					Node* cur = (*_tab)[i];
					if (cur != nullptr)
					{
						_node = cur;
						_num = i;
						goto exit;
					}
				}
				_num = i;
				_node = nullptr;
			}
		exit:
			return *this;
		}

		bool operator!=(Self tmp)
		{
			if (_node != tmp._node)
			{
				return true;
			}
			else
			{
				return false;
			}
		}


		//��Ա����
		vector<Node*>* _tab;
		size_t _num;
		Node* _node;
	};

	//int���͵�hash����
	template<class K>
	struct Hash
	{
		size_t operator()(const K& tmp)
		{
			return tmp;
		}
	};

	//string�ַ������͵ĺ���
	template<>
	struct Hash<string>
	{
		size_t operator()(const string& tmp)
		{
			size_t count = 0;
			for (int i = 0; i < tmp.size(); i++)
			{
				count += tmp[i];
			}
			return count;
		}
	};

	template<class V, class Hash = Hash<V>>
	class HashTable
	{
	public:
		typedef HashNode<V> Node;
		typedef HashTableIterator<V> iterator;
	public:
		Hash hash;

		//���캯��
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
					return iterator(cur, &_tables, i);
				}
			}
			return iterator(nullptr, &_tables, _tables.size());
		}

		iterator end()
		{
			return iterator(nullptr, &_tables, _tables.size());
		}

		//����
		void reserve()
		{
			HashTable<V> newtable;//��һ���µ�hash��ʱ��ϣ�����ɱ�Ľ�㶼�ù���
			newtable._tables.resize(_nums * 2);

			//�����ɱ�����ù���
			for (int i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur != nullptr)
				{
					Node* next = cur->_next;//����cur����һ�����

					size_t index = hash(cur->_data) % newtable._tables.size();
					//Node* newtable_cur = newtable._tables[index];

					cur->_next = newtable._tables[index];
					newtable._tables[index] = cur;

					cur = next;
				}
			}
			_tables.swap(newtable._tables);
		}

		//����
		bool insert(const V& data)
		{
			//�ٲ���֮ǰ��Ҫ�����жϣ��Ƿ���Ҫ�������������ĺ�����ͻ
			if (_nums == _tables.size())
			{
				reserve();
			}

			size_t index = hash(data) % _tables.size();
			//����֮ǰ��Ҫ�жϸ�ֵ��û�У�����У��򲻲���
			Node* cur = _tables[index];
			while (cur != nullptr)
			{
				if (cur->_data == data)
				{
					return false;
				}
				cur = cur->_next;
			}

			//���½��ͷ�嵽��ϣͰ��
			Node* newnode = new Node(data);
			newnode->_next = _tables[index];
			_tables[index] = newnode;
			_nums++;//��Ч���ݸ���6++
			return true;
		}

		//ɾ��
		bool erase(const V& data)
		{
			size_t index = hash(data) % _tables.size();
			Node* cur = _tables[index];
			Node* prev = nullptr;
			while (cur != nullptr)//��ʼ����Ҫɾ���Ľ��
			{
				if (cur->_data == data)//˵���ҵ��ˣ�����ɾ��
				{
					if (prev == nullptr)//˵��Ҫɾ���Ľ��ʱ��һ��
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

		//����
		Node* find(const V& data)
		{
			size_t index = hash(data) % _tables.size();
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
			cout << endl;
		}

	private:
		vector<Node*> _tables;
		size_t _nums;//��Ч���ݸ���
	};

	void Test1()
	{
		HashTable<int> table;
		int arr[] = { 15,25,5,17,15,27,37,6,16,26,19,18,48,562,3156,499,12,65898,621,674,8,2,18,5 };
		for (auto& e : arr)
		{
			table.insert(e);
		}

		table.Print();
		//table.erase(5);
		HashTable<int>::iterator it = table.begin();
		while (it != table.end())
		{
			cout << *it << " ";
			++it;
		}
	}

	void Test2()
	{
		srand(time(0));
		const int n = 10000;
		HashTable<int> table;
		for (int i = 0; i < n; i++)
		{
			table.insert(rand());
		}
		HashTable<int>::iterator it = table.begin();
		while (it != table.end())
		{
			cout << *it << " ";
			++it;
		}
	}

	void Test3()
	{
		HashTable<string> table;
		table.insert("sort");
		table.insert("left");
		table.insert("water");

		HashTable<string>::iterator it = table.begin();
		while (it != table.end())
		{
			cout << *it << endl;
			++it;
		}
	}
}
