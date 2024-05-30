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

template<class K>
struct Blog_TreeNode
{
	//成员变量
	K _key;
	Blog_TreeNode<K>* _left;
	Blog_TreeNode<K>* _right;

	//构造函数
	Blog_TreeNode(const K& key)
		:_key(key)
		,_left(nullptr)
		,_right(nullptr)
	{}

};

template<class K>
class Blog_Tree
{
	typedef Blog_TreeNode<K> Node;
public:
	//构造函数
	Blog_Tree()
		:_root(nullptr)
	{}

	//析构函数
	~Blog_Tree()
	{
		destory(_root);
	}

	//插入结点
	bool insert(const K& data)
	{
		//如果树为空，则直接将新结点给到_root
		if (_root == nullptr)
		{
			_root = new Node(data);
		}

		//如果树不为空，这开始找空位，将新结点插入
		Node* cur = _root;
		Node* cur_parent = nullptr;//这里要提前保留cur的parent，因为后面插入时要用到
		while (cur != nullptr)
		{
			if (data > cur->_key)//如果要插入的数据大于cur，则cur往右走
			{
				cur_parent = cur;//保留cur的parent
				cur = cur->_right;
			}
			else if (data < cur->_key)//如果要插入的数据小于cur，则cur往左走
			{
				cur_parent = cur;//保留cur的parent
				cur = cur->_left;
			}
			else//如果相等，说明树中已有，则不插入，返回失败
			{
				return false;
			}
		}

		//找到空位后，将新结点进行插入
		Node* newnode = new Node(data);
		if (cur_parent->_key > newnode->_key)
		{
			cur_parent->_left = newnode;
		}
		else
		{
			cur_parent->_right = newnode;
		}

		return true;
	}

	//删除结点
	bool erase(const K& data)
	{
		if (_root == nullptr)
		{
			return false;
		}

		//先找到要删除的结点
		Node* cur = _root;
		Node* cur_parent = nullptr;
		while (cur != nullptr)
		{
			//先找到要删除的结点
			if (data > cur->_key)
			{
				cur_parent = cur;
				cur = cur->_right;
			}
			else if (data < cur->_key)
			{
				cur_parent = cur;
				cur = cur->_left;
			}
			else//找到了cur要删除的结点
			{
				//判断是那种删除情况
				if (cur->_left == nullptr && cur->_right == nullptr)
				{
					if (cur_parent == nullptr)//如果cur_parent为空，说明删除的cur为_root
					{
						_root = nullptr;
					}
					else
					{
						if (cur_parent->_left == cur)
						{
							cur_parent->_left = nullptr;
						}
						else
						{
							cur_parent->_right = nullptr;
						}
					}
					delete cur;
				}
				else if (cur->_left == nullptr && cur->_right != nullptr)
				{
					if (cur_parent == nullptr)//如果cur_parent为空，说明删除的cur为_root
					{
						_root = cur->_right;
					}
					else
					{
						if (cur_parent->_left == cur)
						{
							cur_parent->_left = cur->_right;
						}
						else
						{
							cur_parent->_right = cur->_right;
						}
					}
					delete cur;
				}
				else if (cur->_left != nullptr && cur->_right == nullptr)
				{
					if (cur_parent == nullptr)
					{
						_root = cur->_left;
					}
					else
					{
						if (cur_parent->_left == cur)
						{
							cur_parent->_left = cur->_left;
						}
						else
						{
							cur_parent->_right = cur->_left;
						}
						delete cur;
					}
				}
				else
				{
					Node* cur_right_min = cur->_right;//cur右子树的最小左结点
					Node* cur_right_min_parent = cur;
					while (cur_right_min->_left != nullptr)//去找cur右子树的最小左结点
					{
						cur_right_min_parent = cur_right_min;
						cur_right_min = cur_right_min->_left;
					}
					cur->_key = cur_right_min->_key;//找到后将其赋值给cur，后转变为删除cur_right_min

					if (cur_right_min_parent->_key > cur_right_min->_key)
					{
						cur_right_min_parent->_left = cur_right_min->_right;
					}
					else
					{
						cur_right_min_parent->_right = cur_right_min->_right;
					}
					delete cur_right_min;
				}
				return true;
			}
		}
		return false;
	}

	Node* find(const K& data)
	{
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (data > cur->_key)
			{
				cur = cur->_right;
			}
			else if (data < cur->_key)
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

private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}

	void destory(Node* root)
	{
		if (root == nullptr)
			return;

		destory(root->_left);
		destory(root->_right);
		delete root;
	}
private:
	Node* _root;
};

void Blog_test1()
{
	Blog_Tree<int> root;
	int arr1[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16,14 };
	int arr2[] = { 1,5,4,6,1,2,6,816,41,14 };
	for (auto& e : arr1)
	{
		root.insert(e);
	}
	root.InOrder();

	for (auto& e : arr2)
	{
		root.erase(e);
		root.InOrder();
	}
	
	root.InOrder();
}

void Blog_test2()
{
	Blog_Tree<int>* root = new Blog_Tree<int>;
	int arr1[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16,14 };
	for (auto& e : arr1)
	{
		root->insert(e);
	}
	root->InOrder();

	delete root;
}
