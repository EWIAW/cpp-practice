#pragma once
#include<vector>
using namespace std;

namespace my_hash
{
	//数据结点
	template<class Val>
	struct HashNode
	{
		//成员变量
		Val _val;//数据
		HashNode<Val>* _next;//指向同一个桶中的下一个结点
		HashNode<Val>* _linknext;//指向下一个插入顺序的结点
		HashNode<Val>* _linkprev;//指向上一个插入顺序的结点

		//成员函数
		HashNode(const Val& val)
			:_val(val)
			, _next(nullptr)
			, _linknext(nullptr)
			, _linkprev(nullptr)
		{}
	};

	//迭代器
	template<class Val>
	struct HashIterator
	{
		typedef HashNode<Val> Node;
		typedef HashIterator<Val> Self;
		//成员变量
		Node* _node;

		//成员函数
		HashIterator(Node* tmp)
			:_node(tmp)
		{}

		Val& operator*()
		{
			return _node->_val;
		}

		Val* operator->()
		{
			return &_node->_val;
		}

		Self operator++()
		{
			_node = _node->_linknext;
			return *this;
		}

		Self operator--()
		{
			_node = _node->_linkprev;
			return *this;
		}

		bool operator!=(const Self& tmp)
		{
			if (_node != tmp._node)
				return true;
			else
				return false;
		}

	};

	//哈希表
	template<class K, class Val, class GetCompareKey, class Hash>
	class HashTable
	{
		typedef HashNode<Val> Node;
	public:
		typedef HashIterator<Val> iterator;
	public:
		//构造函数
		HashTable()
			:_nums(0)
			,_prev(nullptr)
			,_first(nullptr)
		{
			_vec.resize(10);
		}

		//析构函数
		~HashTable()
		{
			clear();
		}

		//清理函数
		void clear()
		{
			Node* cur = _first;
			while (cur != nullptr)
			{
				Node* next = cur->_linknext;//保存下一个结点
				delete cur;
				cur = next;
			}
		}

		iterator begin()
		{
			return iterator(_first);
		}

		iterator end()
		{
			return iterator(nullptr);
		}

		//检查是否需要扩容
		void CheckCapacity()
		{
			//如果有效数据个数等于_vec数组的长度，则进行扩容
			if (_nums == _vec.size())
			{
				GetCompareKey GCK;
				Hash hash;
				vector<Node*> newvec;//开一块新的指针数组
				newvec.resize(_nums * 2);//扩容到原来的两倍

				//遍历原数组，并将结点拿过来
				for (int i = 0; i < _vec.size(); i++)
				{
					Node* cur = _vec[i];
					while (cur != nullptr)
					{
						Node* next = cur->_next;//保存下一个结点

						size_t index = hash(GCK(cur->_val)) % newvec.size();//找到新的指针数组映射的位置
						cur->_next = newvec[index];
						newvec[index] = cur;

						cur = next;
					}
				}
				newvec.swap(_vec);
			}
		}

		//插入
		pair<iterator, bool> insert(const Val& tmp)
		{
			//插入之前要判断是否需要扩容
			CheckCapacity();

			GetCompareKey GCK;
			Hash hash;
			size_t index = hash(GCK(tmp)) % _vec.size();//找到它的映射下标
			//先去遍历桶，看要插入的数据有没有
			Node* cur = _vec[index];
			while (cur != nullptr)
			{
				if (cur->_val == tmp)//说明桶中已经有该值
				{
					return make_pair(iterator(cur), false);
				}
				cur = cur->_next;
			}
			//如果没有,再进行插入，使用头插法
			Node* newnode = new Node(tmp);
			newnode->_next = _vec[index];
			_vec[index] = newnode;
			
			//插入完成后，再链接到上一个插入结点的后面
			Node* prev = _prev;
			if (prev == nullptr)//如果上一个插入结点为nullptr，说明，newnode是第一个插入的结点
			{
				_prev = newnode;
				_first = newnode;
			}
			else
			{
				prev->_linknext = newnode;
				newnode->_linkprev = prev;
				_prev = newnode;
			}
			_nums++;
			return make_pair(iterator(newnode), true);
		}

		//删除
		bool erase(const K& tmp)
		{
			GetCompareKey GCK;
			Hash hash;
			size_t index = hash(tmp) % _vec.size();
			Node* cur = _vec[index];
			Node* cur_prev = nullptr;
			while (cur != nullptr)
			{
				if (GCK(cur->_val) == tmp)
				{
					//删除结点要注意要改变_next,_linknext,_linkprev三个指针
					//在这里先修改_linknext和_linkprev指针

					Node* cur_linkprev = cur->_linkprev;
					Node* cur_linknext = cur->_linknext;
					if (cur_linkprev == nullptr)//说明要删除的cur在插入顺序中是第一个
					{
						cur_linknext->_linkprev = nullptr;
						_first = cur_linknext;
					}
					else if (cur_linknext == nullptr)//说明要删除的cur是插入顺序中的最后一个
					{
						cur_linkprev->_linknext = nullptr;
					}
					else//说明要删除的cur是插入顺序中的中间位置
					{
						cur_linkprev->_linknext = cur_linknext;
						cur_linknext->_linkprev = cur_linkprev;
					}

					//再修改_next指针
					if (cur_prev == nullptr)//说明要删除的cur是桶中的第一个结点
					{
						_vec[index] = cur->_next;
					}
					else
					{
						cur_prev->_next = cur->_next;
					}

					delete cur;
					_nums--;
					return true;
				}
				cur_prev = cur;
				cur = cur->_next;
			}
			return false;
		}

		//查找
		iterator find(const K& key)
		{
			GetCompareKey GCK;
			Hash hash;
			size_t index = hash(key) % _vec.size();
			Node* cur = _vec[index];
			while (cur != nullptr)
			{
				if (GCK(cur->_val) == key)
				{
					return iterator(cur);
				}
				cur = cur->_next;
			}
			return iterator(nullptr);
		}

	private:
		vector<Node*> _vec;//指针数组
		size_t _nums;//有效数据个数
		Node* _prev;//保存上一个插入的结点
		Node* _first;//保存第一个插入的结点
	};

}