#pragma once
#include<vector>
#include<iostream>

//位图
namespace bitset
{
	class bitset
	{
	public:
		//构造函数	vector的大小开 要存数据的最大值
		bitset(const size_t& sz)
		{
			//一个int类型的数据，有32个比特位，所以一个int类型的数据可以存32个映射关系
			size_t length = sz / 32 + 1;//vector的长度
			_vec.resize(length);
			_nums = 0;
		}

		//插入
		void set(const size_t& num)
		{
			//先求num在第vector的第几个位置，再求num再该位置的第几个比特位
			size_t index = num / 32;//求出在vector的第几个位置
			size_t bit = num % 32;//求出在该位置的第几个bit位
			//将该bit位变为1
			_vec[index] = _vec[index] | (1 << bit);
			_nums++;
		}

		//删除
		void reset(const size_t& num)
		{
			size_t index = num / 32;
			size_t bit = num % 32;
			_vec[index] = _vec[index] & ~(1 << bit);
			_nums--;
		}

		//判断num的位置是否存在
		bool test(const size_t& num)
		{
			size_t index = num / 32;
			size_t bit = num % 32;
			return _vec[index] & (1 << bit);
		}

	private:
		std::vector<int> _vec;
		size_t _nums;//记录位图的大小
	};

	void Test1()
	{
		bitset bs(100);
		bs.set(97);
		bs.set(98);
		bs.set(99);

		bs.set(99);

		bs.reset(99);

		for (int i = 0; i < 100; i++)
		{
			std::cout << "bs[" << i << "]=" << bs.test(i) << std::endl;
		}
	}

	void Test2()
	{
		unsigned int n = -1;
		bitset bs(n);
	}
}