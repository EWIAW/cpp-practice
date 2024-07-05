#pragma once
#include<iostream>
#include<time.h>
using namespace std;
namespace blog_RBTree
{
	enum Color
	{
		BLACK,
		RED
	};

	template<class T>
	struct TreeNode
	{
		//成员变量
		T _data;//数据
		TreeNode<T>* _left;
		TreeNode<T>* _right;
		TreeNode<T>* _parent;
		Color _col;//保存结点的颜色

		//构造函数
		TreeNode(const T& data)
			:_data(data)
			,_left(nullptr)
			,_right(nullptr)
			,_parent(nullptr)
			,_col(RED)//每生成一个新结点，都将结点的颜色默认给红色，至于为什么，后面会解释
		{}
	};

	//红黑树的迭代器
	template<class T>
	struct RBTreeIterator
	{
		typedef TreeNode<T> Node;
		typedef RBTreeIterator Self;

		//构造函数
		RBTreeIterator(Node* tmp)
			:_node(tmp)
		{}

		//重载*
		T operator*()
		{
			return _node->_data;
		}

		//重载->
		T& operator->()
		{
			return &_node->_data;
		}

		//迭代器++
		Self operator++()
		{
			if (_node->_right != nullptr)
			{
				Node* cur = _node->_right;
				while (cur->_left != nullptr)
				{
					cur = cur->_left;
				}
				_node = cur;
			}
			else
			{
				Node* cur = _node;
				Node* parent = cur->_parent;
				while (parent != nullptr && parent->_right == cur)
				{
					cur = parent;
					parent = cur->_parent;
				}
				_node = parent;
			}
			return *this;
		}

		bool operator!=(const Self& tmp)
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

		//成员变量
		Node* _node;
	};

	template<class T, class GCV>
	class RBTree
	{
	public:
		typedef TreeNode<T> Node;
		typedef RBTreeIterator<T> iterator;
	public:
		//正向begin迭代器
		iterator begin()
		{
			Node* tmp = GetRoot();
			while (tmp->_left != nullptr)
			{
				tmp = tmp->_left;
			}
			return iterator(tmp);
		}

		//正向end迭代器
		iterator end()
		{
			return iterator(nullptr);
		}

		//构造函数
		RBTree()
			:_root(nullptr)//给根结点一个nullptr
		{}

		//插入结点
		bool insert(const T& data)
		{
			GCV gcv;//仿函数变量

			//如果树为NULL，则直接将新结点给到_root
			if (_root == nullptr)
			{
				_root = new Node(data);
				_root->_col = BLACK;//把新结点给_root后，要记得把颜色给位BLACK
				return true;
			}

			Node* cur = _root;
			Node* cur_parent = nullptr;
			while (cur != nullptr)
			{
				if (gcv(data) > gcv(cur->_data))
				{
					cur_parent = cur;
					cur = cur->_right;
				}
				else if (gcv(data) < gcv(cur->_data))
				{
					cur_parent = cur;
					cur = cur->_left;
				}
				else//说明该值已经存在，不进行插入
				{
					return false;	
				}
			}

			//将新结点插入
			cur = new Node(data);
			if (gcv(cur_parent->_data) > gcv(data))
			{
				cur_parent->_left = cur;
				cur->_parent = cur_parent;
			}
			else
			{
				cur_parent->_right = cur;
				cur->_parent = cur_parent;
			}

			//调整结点代码
			while (cur_parent != nullptr && cur_parent->_col == RED)
			{
				Node* grandparent = cur_parent->_parent;
				if (grandparent->_left == cur_parent)//正方向
				{
					Node* uncle = grandparent->_right;
					if (uncle != nullptr && uncle->_col == RED)//情况一,uncle存在且为红
					{
						cur_parent->_col = uncle->_col = BLACK;
						grandparent->_col = RED;
						//继续向上处理
						cur = grandparent;
						cur_parent = cur->_parent;
					}
					else//情况二和情况三
					{
						//这里情况三经过第一次旋转后可以变成情况二，所以可以先判断是否是情况三
						if (cur_parent->_right == cur)//这种情况就是情况三
						{
							//先进行一个左单旋
							RotateL(cur_parent);
							swap(cur, cur_parent);
						}
						//代码走到这里就一定是情况二了
						RotateR(grandparent);
						cur_parent->_col = BLACK;
						grandparent->_col = RED;
						break;
					}
				}
				else if (grandparent->_right == cur_parent)//反方向
				{
					Node* uncle = grandparent->_left;
					if (uncle != nullptr && uncle->_col == RED)//反方向的情况一
					{
						cur_parent->_col = uncle->_col = BLACK;
						grandparent->_col = RED;

						cur = grandparent;
						cur_parent = cur->_parent;
					}
					else//反方向的情况二和情况三
					{
						if (cur_parent->_left == cur)
						{
							RotateR(cur_parent);
							swap(cur, cur_parent);
						}
						RotateL(grandparent);
						cur_parent->_col = BLACK;
						grandparent->_col = RED;
						break;
					}
				}
			}
			_root->_col = BLACK;
		}
		
		//获取根结点
		Node* GetRoot()
		{
			return _root;
		}

	private:
		//左单旋	
		void RotateL(Node* cur_parent)
		{
			GCV gcv;
			Node* cur = cur_parent->_right;
			Node* cur_left = cur->_left;

			//改变指针的链接关系
			cur_parent->_right = cur_left;
			if (cur_left != nullptr)
			{
				cur_left->_parent = cur_parent;
			}

			cur->_left = cur_parent;
			Node* cur_parent_parent = cur_parent->_parent;
			cur_parent->_parent = cur;

			//旋转完成后要判断cur_parent是否为根
			if (cur_parent_parent != nullptr)//说明cur_parent不是根
			{
				if (gcv(cur_parent_parent->_data) < gcv(cur_parent->_data))
				{
					cur_parent_parent->_right = cur;
					cur->_parent = cur_parent_parent;
				}
				else
				{
					cur_parent_parent->_left = cur;
					cur->_parent = cur_parent_parent;
				}
			}
			else//说明cur_parent是根
			{
				_root = cur;
				cur->_parent = nullptr;
			}

		}

		//右单旋
		void RotateR(Node* cur_parent)
		{
			GCV gcv;
			Node* cur = cur_parent->_left;
			Node* cur_right = cur->_right;

			cur_parent->_left = cur_right;
			if (cur_right != nullptr)
			{
				cur_right->_parent = cur_parent;
			}

			cur->_right = cur_parent;
			Node* cur_parent_parent = cur_parent->_parent;
			cur_parent->_parent = cur;

			if (cur_parent_parent != nullptr)
			{
				if (gcv(cur_parent_parent->_data) > gcv(cur_parent->_data))
				{
					cur_parent_parent->_left = cur;
					cur->_parent = cur_parent_parent;
				}
				else
				{
					cur_parent_parent->_right = cur;
					cur->_parent = cur_parent_parent;
				}
			}
			else
			{
				_root = cur;
				cur->_parent = nullptr;
			}

		}

	private:
		Node* _root;
	};



}
