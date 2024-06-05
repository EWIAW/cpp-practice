#pragma once
#include<vector>
#include<iostream>
#include<string>
#include"bitset.h"

/*
namespace bloomfilter
{
	struct hash1
	{
		size_t operator()(const std::string& tmp)
		{
			size_t count = 0;
			for (int i = 0; i < tmp.size(); i++)
			{
				count *= 131;
				count += tmp[i];
			}
			return count;
		}
	};

	struct hash2
	{
		size_t operator()(const std::string& tmp)
		{
			size_t count = 0;
			for (int i = 0; i < tmp.size(); i++)
			{
				count = count * 65599 + tmp[i];
			}
			return count;
		}
	};

	struct hash3
	{
		size_t operator()(const std::string& tmp)
		{
			size_t count = 0;
			size_t magic = 63689;
			for (int i = 0; i < tmp.size(); i++)
			{
				count = count * magic + tmp[i];
				magic *= 378551;
			}
			return count;
		}

	};

	template<class Hash1 = hash1, class Hash2 = hash2, class Hash3 = hash3>
	class bloomfilter
	{
	public:
		bloomfilter(const size_t& sz)
		{
			size_t length = sz / 32 + 1;
			_vec.resize(length);
			_nums = sz;
		}

		void set(const std::string& tmp)
		{
			Hash1 hash1;
			Hash2 hash2;
			Hash3 hash3;
			size_t index1 = (hash1(tmp) % _nums) / 32;
			size_t bit1 = (hash1(tmp) % _nums) % 32;
			size_t index2 = (hash2(tmp) % _nums) / 32;
			size_t bit2 = (hash2(tmp) % _nums) % 32;
			size_t index3 = (hash3(tmp) % _nums) / 32;
			size_t bit3 = (hash3(tmp) % _nums) % 32;
			_vec[index1] = _vec[index1] | (1 << bit1);
			_vec[index2] = _vec[index2] | (1 << bit2);
			_vec[index3] = _vec[index3] | (1 << bit3);
		}

		bool test(const std::string& tmp)
		{
			Hash1 hash1;
			Hash2 hash2;
			Hash3 hash3;
			size_t index1 = (hash1(tmp) % _nums) / 32;
			size_t bit1 = (hash1(tmp) % _nums) % 32;
			size_t index2 = (hash2(tmp) % _nums) / 32;
			size_t bit2 = (hash2(tmp) % _nums) % 32;
			size_t index3 = (hash3(tmp) % _nums) / 32;
			size_t bit3 = (hash3(tmp) % _nums) % 32;
			
			if (_vec[index1] & (1 << bit1))
			{
				if (_vec[index2] & (1 << bit2))
				{
					if (_vec[index3] & (1 << bit3))
					{
						return true;
					}
				}
			}
			return false;
		}

	private:
		std::vector<int> _vec;
		size_t _nums;
	};

	void Test1()
	{
		bloomfilter<> bf(10000);
		std::string str1("abcd");
		std::string str2("aadd");
		std::string str3("accd");
		bf.set(str1);
		bf.set(str2);
		bf.set(str3);
		
		//for (int i = 0; i < 10; i++)
		//{
		//	std::cout << "bf[" << i << "]=" << bf.test(i) << std::endl;
		//}

		std::cout << bf.test("cccc") << std::endl;
	}
}
*/
namespace bloomfilter
{
	struct hash1
	{
		size_t operator()(const std::string& tmp)
		{
			size_t count = 0;
			for (int i = 0; i < tmp.size(); i++)
			{
				count *= 131;
				count += tmp[i];
			}
			return count;
		}
	};

	struct hash2
	{
		size_t operator()(const std::string& tmp)
		{
			size_t count = 0;
			for (int i = 0; i < tmp.size(); i++)
			{
				count = count * 65599 + tmp[i];
			}
			return count;
		}
	};

	struct hash3
	{
		size_t operator()(const std::string& tmp)
		{
			size_t count = 0;
			size_t magic = 63689;
			for (int i = 0; i < tmp.size(); i++)
			{
				count = count * magic + tmp[i];
				magic *= 378551;
			}
			return count;
		}
	};

	template<class T, class Hash1 = hash1, class Hash2 = hash2, class Hash3 = hash3>
	class bloomfilter
	{
	public:
		bloomfilter(const size_t& sz)
			:_bs(5 * sz)
			,_nums(5 * sz)
		{}

		void set(const T& tmp)
		{
			Hash1 hash1;
			Hash2 hash2;
			Hash3 hash3;

			size_t index1 = hash1(tmp) % _nums;
			size_t index2 = hash2(tmp) % _nums;
			size_t index3 = hash3(tmp) % _nums;

			_bs.set(index1);
			_bs.set(index2);
			_bs.set(index3);
		}

		bool test(const T& tmp)
		{
			Hash1 hash1;
			Hash2 hash2;
			Hash3 hash3;

			size_t index1 = hash1(tmp) % _nums;
			size_t index2 = hash2(tmp) % _nums;
			size_t index3 = hash3(tmp) % _nums;

			if (_bs.test(index1) == true)
			{
				if (_bs.test(index2) == true)
				{
					if (_bs.test(index3) == true)
					{
						return true;
					}
				}
			}
			return false;
		}
	private:
		bitset::bitset _bs;
		size_t _nums;
	};

	void Test1()
	{
		bloomfilter<std::string> bf(100);
		bf.set("abcd");
		bf.set("aadd");
		bf.set("accd");

		std::cout << bf.test("abcd") << std::endl;
		std::cout << bf.test("aadd") << std::endl;
		std::cout << bf.test("abcd") << std::endl;
		std::cout << bf.test("a") << std::endl;
	} 
}