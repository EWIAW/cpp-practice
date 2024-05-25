#pragma once
#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

enum Color
{
	RED,
	BLACK
};

template<class K,class V>
struct RBTreeNode
{
	RBTreeNode(const pair<K,V>& tmp)
		:_kv(tmp)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_col(BLACK)
	{}

	pair<K,V> _kv;
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	Color _col;
};

template<class K,class V>
class RBTree
{
public:
	typedef RBTreeNode<K,V> Node;
public:
	bool insert(const pair<K, V>& tmp)
	{
		//如果根节点为空，则直接将新结点给到_root
		if (_root == nullptr)
		{
			_root = new Node(tmp);
			return true;
		}

		//先根据二叉搜索树的插入规则，找到可以插入的位置先
		Node* curParent = nullptr;
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (tmp.first > cur->_kv.first)
			{
				curParent = cur;
				cur = cur->_right;
			}
			else if (tmp.first < cur->_kv.first)
			{
				curParent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		//找到空位后，接新结点进行插入
		cur = new Node(tmp);
		if (cur->_kv.first < curParent->_kv.first)
		{
			curParent->_left = cur;
			cur->_parent = curParent;
		}
		else
		{
			curParent->_right = cur;
			cur->_parent = curParent;
		}

		//每插入一个新结点，都将该结点的颜色默认位RED
		cur->_col = RED;

		//插入新结点后，要进行检查，是否要调整

		//一.如果cur的父结点为BLACK，则不需要调整

		//二.如果cur的父结点为RED，且uncle结点存在且为红，则需要调整

		//三.①如果cur的父结点为RED，且uncle结点不存在，则需要调整(单旋) 
		//  .②如果cur的父结点为RED，且uncle结点存在且为BLACK，则需要调整（单旋）

		//四.①如果cur的父结点为RED，且uncle结点不存在，则需要调整(双旋) 
		//  .②如果cur的父结点为RED，且uncle结点存在且为BLACK，则需要调整（双旋）

		
		//我们可以把情况二、三、四 分为 两种情况，分别是 curparent在grangparent的_left 、 curparent在grangparent的_right
		while (curParent != nullptr && curParent->_col == RED)
		{
			Node* grandparent = curParent->_parent;
			if (grandparent->_left == curParent)
			{
				Node* uncle = grandparent->_right;
				if (uncle != nullptr && uncle->_col == RED)//情况二
				{
					curParent->_col = uncle->_col = BLACK;
					grandparent->_col = RED;

					//继续向上处理
					cur = grandparent;
					curParent = cur->_parent;
				}
				else
				{
					//情况四
					if (curParent->_right == cur)//说明此时是一个折线，也就是情况四，先处理情况四的原因是，情况四经过一个单旋后会变成情况三
					{
						RotateL(curParent);
						swap(cur, curParent);
					}
					//情况三
					RotateR(grandparent);
					curParent->_col = BLACK;
					grandparent->_col = RED;
					break;
				}
			}
			else
			{
				Node* uncle = grandparent->_left;
				if (uncle != nullptr && uncle->_col == RED)
				{
					curParent->_col = uncle->_col = BLACK;
					grandparent->_col = RED;

					cur = grandparent;
					curParent = cur->_parent;
				}
				else
				{
					if (curParent->_left == cur)
					{
						RotateR(curParent);
						swap(cur, curParent);
					}
					RotateL(grandparent);
					curParent->_col = BLACK;
					grandparent->_col = RED;
					break;
				}
			}
		}
		_root->_col = BLACK;

	}

	void RotateR(Node* first)
	{
		Node* second = first->_left;
		Node* secondright = second->_right;

		first->_left = secondright;
		if (secondright != nullptr)
		{
			secondright->_parent = first;
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
				second->_parent = ppNode;
			}
			else
			{
				ppNode->_right = second;
				second->_parent = ppNode;
			}
		}

	}

	void RotateL(Node* first)
	{
		Node* second = first->_right;
		Node* secondleft = second->_left;

		first->_right = secondleft;
		if (secondleft != nullptr)
		{
			secondleft->_parent = first;
		}

		second->_left = first;
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
				second->_parent = ppNode;
			}
			else
			{
				ppNode->_right = second;
				second->_parent = ppNode;
			}
		}
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	Node* GetRoot()
	{
		return _root;
	}

	bool IsValidRBTree()
	{
		Node* pRoot = GetRoot();
		// 空树也是红黑树
		if (nullptr == pRoot)
			return true;
		// 检测根节点是否满足情况
		if (BLACK != pRoot->_col)
		{
			cout << "违反红黑树性质二：根节点必须为黑色" << endl;
			return false;
		}
		// 获取任意一条路径中黑色节点的个数
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_col)
				blackCount++;
			pCur = pCur->_left;
		}
		// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}

	bool _IsValidRBTree(Node* pRoot, size_t k, const size_t blackCount)
	{
		//走到null之后，判断k和black是否相等
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
				return false;
			}
			return true;
		}
		// 统计黑色节点的个数
		if (BLACK == pRoot->_col)
			k++;
		// 检测当前节点与其双亲是否都为红色
		Node* pParent = pRoot->_parent;
		if (pParent && RED == pParent->_col && RED == pRoot->_col)
		{
			cout << "违反性质三：没有连在一起的红色节点" << endl;
			return false;
		}
		return _IsValidRBTree(pRoot->_left, k, blackCount) &&
			_IsValidRBTree(pRoot->_right, k, blackCount);
	}

	private:
		Node* _root = nullptr;
};