#include"BinarySearchTree.h"

////测试插入和删除
//void Blog_test1()
//{
//	Blog_Tree<int> root;
//	int arr1[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16,14 };
//	for (auto& e : arr1)
//	{
//		root.insert(e);
//	}
//	root.InOrder();
//
//	for (auto& e : arr1)
//	{
//		root.erase(e);
//		root.InOrder();
//	}
//}
//
////测试查找
//void Blog_test2()
//{
//	Blog_Tree<int> root;
//	int arr1[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16,14 };
//	for (auto& e : arr1)
//	{
//		root.insert(e);
//	}
//	Blog_TreeNode<int>* tmp = root.find(20);
//	if (tmp != nullptr)
//	{
//		cout << tmp->_key << endl;
//	}
//	else
//	{
//		cout << "不存在给值" << endl;
//	}
//}

//字典树
void Blog_test1()
{
	Blog_Tree<string, string> root;
	root.insert("树", "tree");
	root.insert("排序", "sort");
	root.insert("水", "water");

	Blog_TreeNode<string, string>* tmp = root.find("排序");
	if (tmp == nullptr)
	{
		cout << "无该单词" << endl;
	}
	else
	{
		cout << tmp->_val << endl;
	}
}

//统计次数
void Blog_test2()
{
	string str[] = { "衣服","鞋子","衣服","裤子","衣服","衣服","裤子","鞋子","帽子","帽子","袜子" };
	Blog_Tree<string, int> root;
	for (auto& e : str)
	{
		Blog_TreeNode<string, int>* tmp = root.find(e);
		if (tmp == nullptr)
		{
			root.insert(e, 1);
		}
		else
		{
			tmp->_val++;
		}
	}
	root.InOrder();
}

int main()
{
	//Blog_test1();
	Blog_test2();
	return 0;
}