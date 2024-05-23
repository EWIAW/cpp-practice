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

int main()
{
	Test1();
	return 0;
}