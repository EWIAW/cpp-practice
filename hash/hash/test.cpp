#include"blog_hash.h"
using namespace blog_hash;

using Node = blog_hash::hash_node<int>;

void Test1()
{
	blog_hash::hash<int> h;
	h.insert(3);
	h.insert(3);
	h.insert(3);
	h.insert(3);
	h.insert(3);
	h.insert(13);
	h.insert(23);
	h.insert(33);
	h.insert(5);
	h.insert(6);

	h.Print();
}

void Test2()
{
	blog_hash::hash<int> h;
	h.insert(3);
	h.insert(3);
	h.insert(3);
	h.insert(3);
	h.insert(3);
	h.insert(13);
	h.insert(23);
	h.insert(33);
	h.insert(5);
	h.insert(6);
	//²âÊÔ²éÕÒ
	Node* ret = h.find(23);
	std::cout << ret->_val << std::endl;
}

void Test3()
{
	blog_hash::hash<int> h;
	h.insert(3);
	h.insert(3);
	h.insert(3);
	h.insert(3);
	h.insert(3);
	h.insert(13);
	h.insert(23);
	h.insert(33);
	h.insert(5);
	h.insert(6);
	//²âÊÔÉ¾³ı
	h.erase(7);
	h.erase(8);
	h.Print();

}

void Test4()
{
	blog_hash::hash<std::string> h;
	h.insert("abc");
	h.insert("abc");
	h.insert("bca");
	h.insert("cba");
	h.insert("asdgfas");
	h.insert("wqer");
	h.insert("zxv");
	h.Print();
}

int main()
{
	//Close_Hash::Test1();
	//Open_Hash::Test1();
	//Open_Hash::Test2();
	//Open_Hash::Test3();

	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}