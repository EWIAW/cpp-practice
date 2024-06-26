#pragma once
#include<iostream>
#include<vector>
#include<time.h>
using namespace std;


	template<class K, class V>
struct AVLTreeNode
	{
		//成员变量
		K _key;
		V _val;
		AVLTreeNode<K, V>* _left;
		AVLTreeNode<K, V>* _right;
		AVLTreeNode<K, V>* _parent;
		int _bf;//平衡因子，来检查树是否平衡，平衡因子由   右数-左树

		//成员函数
		AVLTreeNode(pair<K, V> p)
			:_key(p.first)
			, _val(p.second)
			, _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _bf(0)
		{}
	};

template<class K, class V>
class AVLTree
{
public:
	typedef AVLTreeNode<K, V> Node;
public:
		//构造函数
	AVLTree()
		:_root(nullptr)
	{}

		//插入结点
	bool insert(const pair<K, V>& p)
		{
			//如果此时tree为空，则直接把结点给_root
			if (_root == nullptr)
			{
				_root = new Node(p);
				return true;
			}

			//如果tree不为空，则查找空位，将结点进行插入
			Node* cur = _root;
			Node* curparent = nullptr;
			while (cur != nullptr)
			{
				curparent = cur;
				if (p.first > cur->_key)
				{
					cur = cur->_right;
				}
				else if (p.first < cur->_key)
				{
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(p);//生成一个结点给空位置
			if (curparent->_key > cur->_key)//将新结点链接到树中
			{
				curparent->_left = cur;
			}
			else
			{
				curparent->_right = cur;
			}
			cur->_parent = curparent;

			//插入新结点后，更新父结点的_bf平衡因子
			while (curparent != nullptr)
			{
				if (curparent->_right == cur)
				{
					curparent->_bf++;
				}
				else
				{
					curparent->_bf--;
				}

				if (curparent->_bf == 0)
				{
					break;
				}
				else if (curparent->_bf == 1 || curparent->_bf == -1)
				{
					cur = curparent;
					curparent = cur->_parent;
				}
				else if (curparent->_bf == 2 || curparent->_bf == -2)
				{
					//进行旋转处理
					//1.左单旋
					//2.右左单旋
					//3.右单旋
					//4.左右单旋
					if (curparent->_bf == 2)
					{
						if (curparent->_right->_bf == 1)
						{
							RotateL(curparent);//左单旋
						}
						else
						{
							RotateRL(curparent);
						}
					}
					else if (curparent->_bf == -2)
					{
						if (curparent->_left->_bf == -1)
						{
							RotateR(curparent);//右单旋
						}
						else
						{
							RotateLR(curparent);
						}
					}

					break;
				}
			}

			return true;
		}

		//删除结点
	void erase(const K& key)
		{
			Node* cur = find(key);
			if (cur == nullptr)
			{
				return;
			}

			//1.cur没有左右结点
			//2.cur没有左结点，有右结点
			//3.cur没有右结点，有左结点
			//4.cur有左右结点

			//确定cur的位置，因为第四种情况其实可以变为1，2，3的情况

			if (cur->_left != nullptr && cur->_right != nullptr)
			{
				Node* cur_right_min = cur->_right;
				while (cur_right_min->_left != nullptr)
				{
					cur_right_min = cur_right_min->_left;
				}
				cur->_key = cur_right_min->_key;
				cur->_val = cur_right_min->_val;

				cur = cur_right_min;
			}

			Node* cur_parent = cur->_parent;
			Node* del = cur;

			//调整父结点平衡因子
			while (cur_parent != nullptr)
			{
				if (cur_parent->_left == cur)
				{
					cur_parent->_bf++;
				}
				else if (cur_parent->_right == cur)
				{
					cur_parent->_bf--;
				}

				//调整完父结点的平衡因子后，要进行判断是否往上继续调，还是进行旋转，还是结束调整

				//1.如果cur_parent的平衡因子为1，-1，则结束调整，将结点删除
				//2.如果平衡因子为0，则继续向上调整
				//3.如果平衡因子为2，则进行旋转处理
				if (cur_parent->_bf == 1 || cur_parent->_bf == -1)
				{
					break;
				}
				else if (cur_parent->_bf == 0)
				{
					cur = cur_parent;
					cur_parent = cur->_parent;
				}
				else if (cur_parent->_bf == 2 || cur_parent->_bf == -2)
				{
					if (cur_parent->_bf == 2)
					{
						if (cur_parent->_right->_bf == 1)
						{
							RotateL(cur_parent);//左单旋
						}
						else
						{
							RotateRL(cur_parent);
						}
					}
					else if (cur_parent->_bf == -2)
					{
						if (cur_parent->_left->_bf == -1)
						{
							RotateR(cur_parent);//右单旋
						}
						else
						{
							RotateLR(cur_parent);
						}
					}
					break;
				}
			}

			//带整棵树树调整完成后，再删除结点
			//删除结点分为两种情况 del为要删除的结点
			//1.del的左子树为null，右子树不为null
			//2.del的右子树为null，左子树不为null
			Node* del_parent = del->_parent;
			//如果del的parent为空，说明del是唯一的根结点
			if (del_parent == nullptr)
			{
				_root = nullptr;
			}
			else if (del->_left == nullptr && del->_right != nullptr)
			{
				if (del_parent->_left == del)
				{
					del_parent->_left = del->_right;
				}
				else
				{
					del_parent->_right = del->_right;
				}
			}
			else
			{
				if (del_parent->_left == del)
				{
					del_parent->_left = del->_left;
				}
				else
				{
					del_parent->_right = del->_left;
				}
			}
			delete del;

			return;
		}

		//查找结点
	Node* find(const K& key)
		{
			if (_root == nullptr)
			{
				return nullptr;
			}

			Node* cur = _root;
			while (cur != nullptr)
			{
				if (key > cur->_key)
				{
					cur = cur->_right;
				}
				else if (key < cur->_key)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;
		}

		//中序遍历
	void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

		//求二叉树的高度
	int Height(Node* root)
		{
			if (root == nullptr)
			{
				return 0;
			}

			return fmax(Height(root->_left), Height(root->_right)) + 1;
		}

		//判断是否平衡
	bool JudgeBalance()
		{
			Node* root = _root;
			return _JudgeBalance(root);
		}

		//private:
	bool _JudgeBalance(Node* root)
		{
			if (root == nullptr)
			{
				return true;
			}

			int heightleft = Height(root->_left);
			int heightright = Height(root->_right);

			return abs(heightleft - heightright) < 2
				&& _JudgeBalance(root->_left)
				&& _JudgeBalance(root->_right);
		}

	void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_InOrder(root->_left);

			cout << root->_key << ":" << root->_val << "	";

			_InOrder(root->_right);
		}

		//左单旋
	void RotateL(Node* first)
		{
			//1.first的right 指向 second的left
			//2.second的left 指向 first

			//！！！注意，因为是三叉链，引入了parent指针，所以当某个结点的left或者right改变，则该结点的孩子的parent指针也要变
			Node* second = first->_right;
			Node* secondLeft = second->_left;

			first->_right = secondLeft;
			if (secondLeft != nullptr)
			{
				secondLeft->_parent = first;
			}

			second->_left = first;
			Node* ppNode = first->_parent;//保留first的父结点，因为first有可能是树中的其中一棵子树，要通过first的父结点来链接下面的子树
			first->_parent = second;


			if (first == _root)//如果first是_root
			{
				_root = second;
				second->_parent = nullptr;
			}
			else//如果first不是_root
			{
				if (ppNode->_left == first)
				{
					ppNode->_left = second;
				}
				else
				{
					ppNode->_right = second;
				}
				second->_parent = ppNode;
			}

			//更新平衡因子
			first->_bf = second->_bf = 0;
		}

		//右单旋
	void RotateR(Node* first)
		{
			//1.first的left  指向  second的right
			//2.second的right  指向  first
			Node* second = first->_left;
			Node* secondRight = second->_right;

			first->_left = secondRight;
			if (secondRight != nullptr)
			{
				secondRight->_parent = first;
			}

			second->_right = first;
			Node* ppNode = first->_parent;
			first->_parent = second;

			if (first == _root)
			{
				_root = second;
				second->_parent = nullptr;
			}
			else
			{
				if (ppNode->_left == first)
				{
					ppNode->_left = second;
				}
				else
				{
					ppNode->_right = second;
				}
				second->_parent = ppNode;
			}

			first->_bf = second->_bf = 0;

		}

		//右左双旋
	void RotateRL(Node* first)
		{
			Node* second = first->_right;
			Node* third = second->_left;

			int bf = third->_bf;

			RotateR(second);//先右单旋
			RotateL(first);//再左单旋

			//旋转完成后，更新平衡因子
			if (bf == 1)
			{
				first->_bf = -1;
				second->_bf = 0;
				third->_bf = 0;
			}
			else if (bf == -1)
			{
				first->_bf = 0;
				second->_bf = 1;
				third->_bf = 0;
			}
			else if (bf == 0)
			{
				first->_bf = 0;
				second->_bf = 0;
				third->_bf = 0;
			}
		}

		//左右双旋
	void RotateLR(Node* first)
		{
			Node* second = first->_left;
			Node* third = second->_right;

			int bf = third->_bf;

			RotateL(second);
			RotateR(first);

			if (bf == 1)
			{
				first->_bf = 0;
				second->_bf = -1;
				third->_bf = 0;
			}
			else if (bf == -1)
			{
				first->_bf = 1;
				second->_bf = 0;
				third->_bf = 0;
			}
			else if (bf == 0)
			{
				first->_bf = 0;
				second->_bf = 0;
				third->_bf = 0;
			}
		}

	void Print()
		{
			cout << _root->_key << endl;
		}

		//private:
	Node* _root;
};



//再次复习AVLTree，并编写一篇博客
namespace blog_AVLTree
{
	template<class T>
	struct TreeNode
	{
		//成员变量
		T _data;//树结点存储的数据类型
		TreeNode<T>* _left;//左孩子指针
		TreeNode<T>* _right;//右孩子指针
		TreeNode<T>* _parent;//父结点指针
		int _bf;//平衡因子

		//成员函数
		TreeNode(const T& tmp)//构造函数
			:_data(tmp)
			, _left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _bf(0)
		{}
	};

	template<class T>
	class AVLTree
	{
		typedef TreeNode<T> Node;
	public:
		AVLTree()
			:_root(nullptr)
		{}

		//插入
		bool insert(const T& tmp)
		{
			//如果根节点为空，则直接插入
			if (_root == nullptr)
			{
				_root = new Node(tmp);
				return true;
			}

			//如果根节点不为空，则先按二叉搜索树的规则进行插入
			Node* cur = _root;
			Node* cur_parent = nullptr;
			while (cur != nullptr)//往下找空位
			{
				if (tmp > cur->_data)
				{
					cur_parent = cur;
					cur = cur->_right;
				}
				else if (tmp < cur->_data)
				{
					cur_parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			//找到空位后，给空位一个新结点
			cur = new Node(tmp);
			if (cur->_data > cur_parent->_data)
			{
				cur_parent->_right = cur;
				cur->_parent = cur_parent;
			}
			else
			{
				cur_parent->_left = cur;
				cur->_parent = cur_parent;
			}

			//插入完结点后，要更新平衡因子
			while (cur_parent != nullptr)
			{
				if (cur_parent->_right == cur)
				{
					cur_parent->_bf++;
				}
				else
				{
					cur_parent->_bf--;
				}

				if (cur_parent->_bf == 0)
				{
					break;
				}
				else if (cur_parent->_bf == 1 || cur_parent->_bf == -1)
				{
					cur = cur_parent;
					cur_parent = cur_parent->_parent;
				}
				else if (cur_parent->_bf == 2 || cur_parent->_bf == -2)
				{
					//进行旋转处理
					if (cur_parent->_bf == 2)
					{
						if (cur->_bf == 1)//左单旋
						{
							RotateL(cur_parent);
						}
						else if(cur->_bf == -1)//右左双旋
						{
							RotateRL(cur_parent);
						}
					}
					else if (cur_parent->_bf == -2)
					{
						if (cur->_bf == 1)//左右单旋
						{
							RotateLR(cur_parent);
						}
						else if (cur->_bf == -1)//右单旋
						{
							RotateR(cur_parent);
						}
					}
					break;
				}
			}
			return true;
		}

		//查找结点
		Node* find(const T& tmp)
		{
			Node* cur = _root;
			while (cur != nullptr)
			{
				if (tmp > cur->_data)
				{
					cur = cur->_right;
				}
				else if (tmp < cur->_data)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;
		}

		//中序遍历
		void InOrder()
		{
			Node* cur = _root;
			_InOrder(cur);
		}

		//求树的高度
		int height(Node* cur)
		{
			if (cur == nullptr)
				return 0;

			return fmax(height(cur->_left), height(cur->_right)) + 1;
		}

		//判断是否平衡
		bool JudgeBanlance()
		{
			Node* cur = _root;
			return _JudgeBanlance(cur);
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

				//旋转完成后，平衡因子调整为0
				cur_parent->_bf = cur->_bf = 0;
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

				cur_parent->_bf = cur->_bf = 0;
			}

			//左右双旋
			void RotateLR(Node* cur_parent)
			{
				Node* cur = cur_parent->_left;
				Node* cur_right = cur->_right;

				int bf = cur_right->_bf;

				//先对cur进行一个左单旋
				RotateL(cur);

				//再对cur_parent进行一个右单旋
				RotateR(cur_parent);

				//旋转完成后，要更新平衡因子
				if (bf == -1)
				{
					cur->_bf = 0;
					cur_parent->_bf = 1;
					cur_right->_bf = 0;
				}
				else if (bf == 1)
				{
					cur->_bf = -1;
					cur_parent->_bf = 0;
					cur_right->_bf = 0;
				}
				else if (bf == 0)//特殊情况
				{
					cur->_bf = 0;
					cur_parent->_bf = 0;
					cur_right->_bf = 0;
				}
			}

			//右左双旋
			void RotateRL(Node* cur_parent)
			{
				Node* cur = cur_parent->_right;
				Node* cur_left = cur->_left;

				int bf = cur_left->_bf;

				//先对cur进行一个右单旋
				RotateR(cur);

				//再对cur_parent进行一个左单旋
				RotateL(cur_parent);

				//更新平衡因子
				if (bf == -1)
				{
					cur->_bf = 1;
					cur_parent->_bf = 0;
					cur_left->_bf = 0;
				}
				else if (bf == 1)
				{
					cur->_bf = 0;
					cur_parent->_bf = -1;
					cur_left->_bf = 0;
				}
				else if (bf == 0)
				{
					cur->_bf = 0;
					cur_parent->_bf = 0;
					cur_left->_bf = 0;
				}
			}

			//中序遍历的子函数
			void _InOrder(Node* cur)
			{
				if (cur == nullptr)
					return;

				_InOrder(cur->_left);
				cout << cur->_data << " ";
				_InOrder(cur->_right);
			}

			//判断是否平衡的子函数
			bool _JudgeBanlance(Node* cur)
			{
				if (cur == nullptr)
					return true;

				int left_height = height(cur->_left);//求cur左子树的高度
				int right_height = height(cur->_right);//求cur右子树的高度

				return abs(left_height - right_height) < 2
					&& _JudgeBanlance(cur->_left)
					&& _JudgeBanlance(cur->_right);
			}

	private:
		Node* _root;
	};

	void Test1()
	{
		AVLTree<int> root;
		//int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

		for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		{
			root.insert(arr[i]);
		}
		root.InOrder();
		cout << root.JudgeBanlance() << endl;
	}

	void Test2()
	{
		srand(time(0));
		AVLTree<int> root;
		const int n = 100;
		for (int i = 0; i < n; i++)
		{
			root.insert(rand());
		}
		root.InOrder();
		cout << root.JudgeBanlance() << endl;
	}
}


