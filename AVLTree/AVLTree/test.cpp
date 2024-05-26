#include"AVLTree.h"

void Test1()
{
	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16,14 };
	AVLTree<int, int> root;
	for (auto& e : arr)
	{
		root.insert(make_pair(e, e));
	}
	root.InOrder();
	cout << root.JudgeBalance() << endl;
}

void Test2()
{
	srand(time(0));
	const int a = 10000000;
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

int main()
{
	//Test1();
	Test2();
	return 0;
}