#pragma once
#include<iostream>
using namespace std;

//结点类
template<class T>
struct BinarySearchTreeNode
{
	//成员函数
	BinarySearchTreeNode(const T& val)
		:_data(val)
		,_left(nullptr)
		,_right(nullptr)
	{}

	//成员变量
	T _data;
	BinarySearchTreeNode<T>* _left;
	BinarySearchTreeNode<T>* _right;
};

//二叉搜索树类
template<class T>
class BinarySearchTree
{
	typedef BinarySearchTreeNode<T> Node;
public:
	//构造函数
	BinarySearchTree()
		:_root(nullptr)
	{}

	//插入结点
	bool insert(const T& val)
	{
		//如果树为空
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		//开始找要插入的位置，找之前，要保存parent的位置
		while (cur != nullptr)
		{
			if (val > cur->_data)//如果要插入的值大于当前结点
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (val < cur->_data)//如果要插入的值小于当前结点
			{
				parent = cur;
				cur = cur->_left;
			}
			else//如果要插入的结点已存在，则不进行插入，返回插入失败
			{
				return false;
			}
		}

		Node* newnode = new Node(val);
		if (parent->_data > val)
		{
			parent->_left = newnode;
		}
		else
		{
			parent->_right = newnode;
		}

		return true;
	}

	//查找结点
	Node* Find(const T& val)
	{
		if (_root == nullptr)
			return nullptr;

		Node* cur = _root;
		while (cur != nullptr)
		{
			if (val > cur->_data)
			{
				cur = cur->_right;
			}
			else if (val < cur->_data)
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

	//删除结点
	bool Erase(const T& val)
	{
		//如果树为空，则直接返回false
		if (_root == nullptr)
			return false;

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (val > cur->_data)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (val < cur->_data)
			{
				parent = cur;
				cur = cur->_left;
			}
			else//如果cur==val，即找到了要删除的结点，开始进行删除操作
			{
				//1.cur的left为null，right不为null
				//2.cur的right为null，left不为null
				//3.cur的left、right都不为null
				if (cur->_left == nullptr)//1.cur的left为null，right不为null
				{
					//如果要删除的结点cur是最顶根
					if (parent == nullptr)
					{
						_root = cur->_right;
					}
					else
					{
						//如果要删除的结点cur不是最顶根
						if (parent->_data > cur->_data)
							parent->_left = cur->_right;
						else
							parent->_right = cur->_right;
					}

					delete cur;
				}			
				else if (cur->_right == nullptr)//2.cur的right为null，left不为null
				{
					//如果要删除的结点cur是最顶根
					if (parent == nullptr)
					{
						_root = cur->_left;
					}
					else
					{
						//如果要删除的结点cur不是最顶根
						if (parent->_data > cur->_data)
							parent->_left = cur->_left;
						else
							parent->_right = cur->_left;
					}

					delete cur;
				}
				else//3.cur的left、right都不为null
				{
					//找右子树的最小根节点
					Node* rightMinParent = cur;
					Node* rightMin = cur->_right;
					while (rightMin->_left != nullptr)
					{
						rightMinParent = rightMin;
						rightMin = rightMin->_left;
					}

					cur->_data = rightMin->_data;
					//swap(cur->_data, rightMin->_data);

					if(rightMinParent->_data > rightMin->_data)
						rightMinParent->_left = rightMin->_right;
					else
						rightMinParent->_right = rightMin->_right;

					delete rightMin;
				}

				return true;
			}
		}

		//如果没有找到结点则返回false
		return false;
	}

	//中序遍历
	void _InOrder(Node* cur)
	{
		if (cur == nullptr)
			return;

		_InOrder(cur->_left);
		cout << cur->_data << " ";
		_InOrder(cur->_right);
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	Node* _root;//一个指针指向根节点
};

void Test1()
{
	BinarySearchTree<int> root;
	int arr[] = { 5,3,7,1,4,6,8,0,2,9 };
	for (auto& e : arr)
	{
		root.insert(e);
	}

	root.InOrder();

	//root.Erase(7);
	//root.InOrder();

	//root.Erase(0);
	//root.InOrder();

	//root.Erase(1);
	//root.InOrder();

	for (auto& e : arr)
	{
		root.Erase(e);
		root.InOrder();
	}
}

//测试删除
void Test2()
{
	BinarySearchTree<int> root;
	int arr[] = { 5,3,4,1,7,8,2,6,0,9 };

	for (auto& e : arr)
	{
		root.insert(e);
	}

	root.Erase(7);
	root.InOrder();
}

