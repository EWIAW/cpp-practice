#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//构造函数	赋值=重载
void Test_Vector1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	vector<int> v2(v1);

	for (int i = 0; i < v1.size(); i++)
	{
		v1[i] += 2;
		cout << v1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	vector<int> v3;
	v3 = v1;

	for (int i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}
	cout << endl;
}

//遍历
void Test_Vector2()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	for (int i = 0; i < v1.size(); i++)
	{
		v1[i] *= 2;
		cout << v1[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//范围for	被编译器替换成迭代器
	for (auto arr : v1)
	{
		cout << arr << " ";
	}
	cout << endl;
}

//迭代器
void Test_Vector3()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	//正向迭代器
	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//反向迭代器
	vector<int>::reverse_iterator rit = v1.rbegin();
	while (rit != v1.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	//正向const迭代器
	vector<int>::const_iterator cit = v1.begin();
	while (cit != v1.end())
	{
		cout << *cit << " ";
		cit++;
	}
	cout << endl;

	//反向const迭代器
	vector<int>::const_reverse_iterator rcit = v1.rbegin();
	while (rcit != v1.rend())
	{
		cout << *rcit << " ";
		rcit++;
	}
	cout << endl;
}

//capacity
void Test_Vector4()
{
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);

	v1.resize(10);

	cout << v1.size() << endl;
	cout << v1.max_size() << endl;
	cout << v1.capacity() << endl;

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
}

void Test_Vector5()
{
	vector<int> v1;
	v1.push_back(50);
	v1.push_back(27);
	v1.push_back(21);
	v1.push_back(10);

	vector<int>::iterator it = find(v1.begin(), v1.end(), 20);

	//v1.erase(it);

	sort(v1.begin(), v1.end());

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
}

void Test_Vector6()
{
	vector<vector<int>> vv;
	vv.resize(5);
	int& ret = vv[0].at(0);
	ret = 10;
	cout << vv[0].at(0) << endl;
}

int main()
{
	//Test_Vector1();
	//Test_Vector2();
	//Test_Vector3();
	//Test_Vector4();
	//Test_Vector5();
	Test_Vector6();
	return 0;
}

