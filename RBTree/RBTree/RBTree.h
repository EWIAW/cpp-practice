#pragma once
#include<iostream>
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
	bool insert(const pair<K,V>& tmp)
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

		//1.如果cur的父结点为BLACK，则不需要调整
		//2.如果cur的父结点为RED，且uncle结点存在且为红，则需要调整
		//3.如果cur的父结点为RED，且uncle结点不存在，则需要调整
		//4.如果cur的父结点为RED，且uncle结点存在且为BLACK，则需要调整

		Node* grandParent = curParent->_parent;

		if (curParent->_col == BLACK)
		{
			return true;
		}
		
	}
private:
	Node* _root = nullptr;
};