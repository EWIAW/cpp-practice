#pragma once
#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

//AVLTree的实现，基于map来实现的key，value模型
template<class K,class V>
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
	AVLTreeNode(pair<K,V> p)
		:_key(p.first)
		,_val(p.second)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
	{}
};

template<class K,class V>
class AVLTree
{
public:
	typedef AVLTreeNode<K,V> Node;
public:
	//构造函数
	AVLTree()
		:_root(nullptr)
	{}

	bool insert(const pair<K,V>& p)
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
			else if(p.first < cur->_key)
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
				else if(curparent->_bf == -2)
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

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);

		cout << root->_key << ":" << root->_val << endl;

		_InOrder(root->_right);
	}

	//中序遍历
	void InOrder()
	{
		_InOrder(_root);
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

	//判断是否平衡
	bool JudgeBalance()
	{
		Node* root = _root;
		return _JudgeBalance(root);
	}

private:
	Node* _root;
};