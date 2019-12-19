#include "stdafx.h"
//dynamic_bitset2string 低位到低位
std::string co_to_string(const boost::dynamic_bitset<>& bitvec)
{
	std::string str;
	to_string(bitvec, str);
	reverse(str.begin(), str.end());
	return str;
}

void idx_cal8(std::vector<std::vector<unsigned int> > &idx)
{
	//顺时针90度
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			idx[1][i * 5 + j] = (5 - j - 1) * 5 + i;
		}
	}


	//顺时针180度
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			idx[2][i * 5 + j] = (5 - i - 1) * 5 + 5 - j - 1;
		}
	}

	//顺时针270度
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			idx[3][i * 5 + j] = (j) * 5 + 5 - i - 1;
		}
	}


	//水平翻转
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			idx[4][i * 5 + j] = (5 - i - 1) * 5 + j;
		}
	}


	//竖直翻转
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			idx[5][i * 5 + j] = (i) * 5 + 5 - j - 1;
		}
	}


	//对角线翻转/
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			idx[6][i * 5 + j] = (5 - j - 1) * 5 + 5 - i - 1;
		}
	}


	//对角线翻转左上右下
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			idx[7][i * 5 + j] = (j) * 5 + i;
		}
	}
}