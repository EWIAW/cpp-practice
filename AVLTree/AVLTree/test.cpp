#include"AVLTree.h"

void Test1()
{
	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16,14 };
	//int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVLTree<int, int> tree;
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		tree.insert(make_pair(arr[i], arr[i]));
	}
	tree.InOrder();

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		tree.erase(arr[i]);
		tree.InOrder();
	}
	cout << tree.JudgeBalance() << endl;
}

void Test2()
{
	srand(time(0));
	const int a = 100000000;
	vector<int> v;
	for (int i = 0; i < a; i++)
	{
		v.push_back(rand());
	}

	size_t begin = clock();

	AVLTree<int, int> root;
	for (auto& e : v)
	{
		root.insert(make_pair(e, e));
	}
	
	size_t end = clock();
	cout << end - begin << endl;
}

//²âÊÔÉ¾³ý½áµã
void Test3()
{
	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16,14 };
	AVLTree<int, int> root;
	for (auto& e : arr)
	{
		root.insert(make_pair(e, e));
	}
	root.InOrder();
	
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		root.erase(arr[i]);
		root.InOrder();
	}
	//root.erase(16);
	//root.InOrder();
}

int main()
{
	Test1();
	//Test2();
	//Test3();
	return 0;
}