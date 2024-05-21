#pragma once
#include<iostream>
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
				break;
			}
		}

		return true;
	}

	//左单旋
	void RotateL()
	{
		//1.parent的right 指向 mid的left
		//2.mid的left 指向 parent
	}

private:
	Node* _root;
};