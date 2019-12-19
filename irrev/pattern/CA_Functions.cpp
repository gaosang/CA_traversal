#include "stdafx.h"
//dynamic_bitset2string ��λ����λ
std::string co_to_string(const boost::dynamic_bitset<>& bitvec)
{
	std::string str;
	to_string(bitvec, str);
	reverse(str.begin(), str.end());
	return str;
}

void idx_cal8(std::vector<std::vector<unsigned int> > &idx)
{
	//˳ʱ��90��
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			idx[1][i * 5 + j] = (5 - j - 1) * 5 + i;
		}
	}


	//˳ʱ��180��
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			idx[2][i * 5 + j] = (5 - i - 1) * 5 + 5 - j - 1;
		}
	}

	//˳ʱ��270��
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			idx[3][i * 5 + j] = (j) * 5 + 5 - i - 1;
		}
	}


	//ˮƽ��ת
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			idx[4][i * 5 + j] = (5 - i - 1) * 5 + j;
		}
	}


	//��ֱ��ת
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			idx[5][i * 5 + j] = (i) * 5 + 5 - j - 1;
		}
	}


	//�Խ��߷�ת/
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			idx[6][i * 5 + j] = (5 - j - 1) * 5 + 5 - i - 1;
		}
	}


	//�Խ��߷�ת��������
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			idx[7][i * 5 + j] = (j) * 5 + i;
		}
	}
}