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

	template<class T>
	class RBTree
	{
		typedef TreeNode<T> Node;
	public:
		//构造函数
		RBTree()
			:_root(nullptr)//给根结点一个nullptr
		{}

		//插入结点
		bool insert(const T& data)
		{
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
				if (data > cur->_data)
				{
					cur_parent = cur;
					cur = cur->_right;
				}
				else if (data < cur->_data)
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
			if (cur_parent->_data > data)
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

		//查找结点
		Node* find(const T& data)
		{
			Node* cur = _root;
			if (data > cur->_data)
			{
				cur = cur->_right;
			}
			else if (data < cur->_data)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
			return nullptr;
		}

		//判断是否符合红黑树的性质
		bool JudgeTree()
		{
			//空树也是红黑树
			if (_root == nullptr)
			{
				return true;
			}
			//性质1：树结点不是红的就是黑的
			//这条性质就没必要检查的了

			//性质2：根结点一定是黑色的
			if (_root->_col != BLACK)
			{
				cout << "违反性质2：根结点一定是黑色的" << endl;
				return false;
			}

			//性质5:所有叶子结点都是黑色的
			//这个性质也没必要检查

			size_t blackcount = 0;
			Node* cur = _root;
			while (cur != nullptr)//先求出一条路径中的黑色结点的个数
			{
				if (cur->_col == BLACK)
				{
					blackcount++;
				}
				cur = cur->_left;
			}
			size_t k = 0;//用来存储黑色结点的个数
			return _JudgeTree(_root, k, blackcount);//判断性质3和性质4

			//性质3：如果一个结点是红色的，那么它的孩子一定是黑色的
			//性质4：每条路径上的黑色结点的个数都相同
		}

	private:
		//左单旋	
		void RotateL(Node* cur_parent)
		{
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
				if (cur_parent_parent->_data < cur_parent->_data)
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
				if (cur_parent_parent->_data > cur_parent->_data)
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

		//获取根节点
		Node* GetRoot()
		{
			return _root;
		}

		//判断是否红黑树的子函数
		bool _JudgeTree(Node* root, size_t k, size_t blackcount)
		{
			//当root走到NULL的时候，判断这条路径的黑色结点个数是否==blackcount
			if (root == nullptr)
			{
				if (k == blackcount)
				{
					return true;
				}
				else
				{
					cout << "违反性质4：每条路径上的黑结点个数相同" << endl;
					return false;
				}
					

			}

			//如果结点是红色的，判断它的父结点是否也为红色
			Node* root_parent = root->_parent;
			if (root_parent != nullptr && root->_col == RED)
			{
				if (root_parent->_col == RED)
				{
					cout << "违反性质3：如果一个结点是红色的，那么它的孩子一定是黑色的" << endl;
					return false;
				}
			}

			//如果结点是黑色的，则k++
			if (root->_col == BLACK)
			{
				k++;
			}

			return _JudgeTree(root->_left, k, blackcount) && _JudgeTree(root->_right, k, blackcount);
		}

	private:
		Node* _root;
	};

	void Test1()
	{
		srand(time(0));
		RBTree<int> root;
		const int n = 10000;
		for (int i = 0; i < n; i++)
		{
			int input = rand();
			root.insert(input);
		}
		cout << root.JudgeTree() << endl;
	}
}
