#include"RBTree.h"

void Test1()
{
	int arr[] = { 16,3,7,11,9,26,18,14,15 };
	//int arr[] = { 4,2,6,1,3,5,15,7,16,14 };
	RBTree<int, int> root;
	for (auto& e : arr)
	{
		root.insert(make_pair(e, e));
	}
	root.InOrder();

	cout << root.IsValidRBTree() << endl;
}

void Test2()
{
	srand(time(0));
	const int n = 1000000;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		v.push_back(rand());
	}

	int begin = clock();
	RBTree<int, int> root;
	for (int i = 0; i < n; i++)
	{
		root.insert(make_pair(v[i], v[i]));
	}
	int end = clock();
	cout << end - begin << endl;
}

int main()
{
	//Test1();
	Test2();
	return 0;
}