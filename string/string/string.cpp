#include<iostream>
#include<string>
using namespace std;

//构造函数
void TestString1()
{
	string s1;//无参构造空字符串
	string s2("hello world");//有参构造
	string s3(s2);//拷贝构造
	string s4(10, 'a');//构造10个a
	string s5(s2, 2, 7);//从s2的第2个位置开始用7个字符来构造
	string s6("hello world", 5);//用该字符串的前五个来构造
	string s7(s2.begin(), s2.end());//迭代器构造

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;
}

//遍历
void TestString2()
{
	//正常for循环
	string s1("hello world");
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	//范围for
	for (auto& ch : s1)
	{
		cout << ch << " ";
	}
	cout << endl;

}

//迭代器
void TestString3()
{
	//四种迭代器
	//1.正向、反向
	//2.const、非const

	string s1("hello world");
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		(*it)++;
		cout << *it << " ";
		it++;
	}
	cout << endl;

	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		(*rit)--;
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	string::const_iterator cit = s1.begin();
	while (cit != s1.end())
	{
		cout << *cit << " ";
		cit++;
	}
	cout << endl;

	string::const_reverse_iterator rcit = s1.rbegin();
	while (rcit != s1.rend())
	{
		cout << *rcit << " ";
		rcit++;
	}
	cout << endl;
}

//Capacity
void TestString4()
{
	string s1("hello world");
	cout << s1.size() << endl;//字符串有效字符个数
	cout << s1.capacity() << endl;//字符串容量
	//cout << s1.max_size() << endl;

	s1.resize(5);//改变size的值为5
	cout << s1 << endl;	
	
	s1.resize(20,'0');//改变size的值为20，并且不够的用0补（如果没有给第二个参数，默认补\0）
	cout << s1 << endl;

	//s1.resize(5);
	//cout << s1 << endl;

	s1.reserve(100);//改变字符串的容量到指定数值
	s1.reserve(5);//只能扩容，不能缩容
	cout << s1 << endl;

	s1.clear();//清空字符串内存
	cout << s1 << endl;

	cout << s1.empty() << endl;
}

void TestString5()
{
	//insert在中间插入字符串
	//string s1("hello");
	//string s2(" world");

	//s1.insert(5,s2);//从某个位置插入一个字符串
	//s1.insert(5, s2, 2, 2);从第五个位置插入一个字符串，插入这个字符串的第二个位置开始插入2个
	//s1.insert(5, "world");//从某个位置插入一个字符串
	//s1.insert(5, " world", 3);//插入 world的前三个

	//cout << s1 << endl;



	//erase在中间删除
	
	string s1("hello world");
	s1.erase(3, 2);
	cout << s1 << endl;
}

void TestString6()
{
	//char str[] = "中国";
	//cout << str << endl;

}

//int main()
//{
//	//TestString1();
//	//TestString2();
//	//TestString3();
//	//TestString4();
//	//TestString5();
//	TestString6();
//	return 0;
//}
class Solution {
public:
	bool isPalindrome(string s)
	{
		for (int i = 0; i < s.size(); i++)
		{
			s[i] = tolower(s[i]);
		}

		int begin = 0;
		int end = s.size() - 1;
		while (begin < end)
		{
			while (begin < end && (!isalpha(s[begin]) && !isalnum(s[begin])))
			{
				begin++;
			}
			while (begin < end && (!isalpha(s[end]) && !isalnum(s[begin])))
			{
				end--;
			}
			if (s[begin] == s[end])
			{
				begin++;
				end--;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};

#include<iostream>
using namespace std;

int main()
{
	string str("A man, a plan, a canal: Panama");
	Solution().isPalindrome(str);
	return 0;
}