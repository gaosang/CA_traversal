#include <iostream>
#include "glo_vars.h"
//void bit_add_n(boost::dynamic_bitset& bitvec��
//��1����������ʱʹ��
void bit_add_n(bool (&bitvec)[5][5])
{
	bool flag;
	int cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			flag = bitvec[i][j];
			bitvec[i][j] = bitvec[i][j] ^ true;
			if (!flag)
				break;
			else
				cnt++;
		}
		if (!flag)
			break;
	}
	if (cnt == 25)//ȫ1��һ����ȫ1��������λ
	{
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; ++j)
				bitvec[i][j] = 1;
	}
}
//��n����������ʱʹ��
void bit_add_n(bool(&bitvec)[5][5], const int n)
{
	bool flag;
	for (int k = 0; k < n; k++)
	{
		int cnt = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; ++j)
			{
				flag = bitvec[i][j];
				bitvec[i][j] = bitvec[i][j] ^ true;
				if (!flag)
					break;
				else
					cnt++;
			}
			if (!flag)
				break;
		}
		if (cnt == 25)//ȫ1��һ����ȫ1��������λ
		{
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; ++j)
					bitvec[i][j] = 1;
			break;
		}
	}
}

//����1�ĸ���
int bit_count(bool(&bitvec)[5][5])
{
	int cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (bitvec[i][j])
				++cnt;
		}
	}
	return cnt;
}

int bit_count(int bitvec[CA_size][CA_size])
{
	int cnt = 0;
	for (int i = 0; i < CA_size; i++)
	{
		for (int j = 0; j < CA_size; ++j)
		{
			if (bitvec[i][j])
				++cnt;
		}
	}
	return cnt;
}


//�Ƚϴ�С������ԽС�������λԽ��,��ȷ���false
bool is_less(const bool(&bitvec1)[5][5], const bool(&bitvec2)[5][5])
{
	for (int i = 4; i >=0 ; i--)
	{
		for (int j = 4; j >= 0; j--)
		{
			if (bitvec1[i][j] ^ bitvec2[i][j])
			{
				if (bitvec2[i][j])
					return true;
				else
					return false;
			}
		}
	}
	return false;
}

//ͨ��8�ֶԳƲ������ж�֮һ�����Ƿ����������
bool is_caled(const bool(&bitvec)[5][5])
{
	bool tmp[5][5];
	//˳ʱ��90��
	tmp[0][0] = bitvec[4][0], tmp[0][1] = bitvec[3][0], tmp[0][2] = bitvec[2][0], tmp[0][3] = bitvec[1][0], tmp[0][4] = bitvec[0][0];
	tmp[1][0] = bitvec[4][1], tmp[1][1] = bitvec[3][1], tmp[1][2] = bitvec[2][1], tmp[1][3] = bitvec[1][1], tmp[1][4] = bitvec[0][1];
	tmp[2][0] = bitvec[4][2], tmp[2][1] = bitvec[3][2], tmp[2][2] = bitvec[2][2], tmp[2][3] = bitvec[1][2], tmp[2][4] = bitvec[0][2];
	tmp[3][0] = bitvec[4][3], tmp[3][1] = bitvec[3][3], tmp[3][2] = bitvec[2][3], tmp[3][3] = bitvec[1][3], tmp[3][4] = bitvec[0][3];
	tmp[4][0] = bitvec[4][4], tmp[4][1] = bitvec[3][4], tmp[4][2] = bitvec[2][4], tmp[4][3] = bitvec[1][4], tmp[4][4] = bitvec[0][4];
	if (is_less(tmp, bitvec))
		return true;

	//˳ʱ��180��
	tmp[0][0] = bitvec[4][4], tmp[0][1] = bitvec[4][3], tmp[0][2] = bitvec[4][2], tmp[0][3] = bitvec[4][1], tmp[0][4] = bitvec[4][0];
	tmp[1][0] = bitvec[3][4], tmp[1][1] = bitvec[3][3], tmp[1][2] = bitvec[3][2], tmp[1][3] = bitvec[3][1], tmp[1][4] = bitvec[3][0];
	tmp[2][0] = bitvec[2][4], tmp[2][1] = bitvec[2][3], tmp[2][2] = bitvec[2][2], tmp[2][3] = bitvec[2][1], tmp[2][4] = bitvec[2][0];
	tmp[3][0] = bitvec[1][4], tmp[3][1] = bitvec[1][3], tmp[3][2] = bitvec[1][2], tmp[3][3] = bitvec[1][1], tmp[3][4] = bitvec[1][0];
	tmp[4][0] = bitvec[0][4], tmp[4][1] = bitvec[0][3], tmp[4][2] = bitvec[0][2], tmp[4][3] = bitvec[0][1], tmp[4][4] = bitvec[0][0];
	if (is_less(tmp, bitvec))
		return true;

	//˳ʱ��270��
	tmp[0][0] = bitvec[0][4], tmp[0][1] = bitvec[1][4], tmp[0][2] = bitvec[2][4], tmp[0][3] = bitvec[3][4], tmp[0][4] = bitvec[4][4];
	tmp[1][0] = bitvec[0][3], tmp[1][1] = bitvec[1][3], tmp[1][2] = bitvec[2][3], tmp[1][3] = bitvec[3][3], tmp[1][4] = bitvec[4][3];
	tmp[2][0] = bitvec[0][2], tmp[2][1] = bitvec[1][2], tmp[2][2] = bitvec[2][2], tmp[2][3] = bitvec[3][2], tmp[2][4] = bitvec[4][2];
	tmp[3][0] = bitvec[0][1], tmp[3][1] = bitvec[1][1], tmp[3][2] = bitvec[2][1], tmp[3][3] = bitvec[3][1], tmp[3][4] = bitvec[4][1];
	tmp[4][0] = bitvec[0][0], tmp[4][1] = bitvec[1][0], tmp[4][2] = bitvec[2][0], tmp[4][3] = bitvec[3][0], tmp[4][4] = bitvec[4][0];
	if (is_less(tmp, bitvec))
		return true;

	//ˮƽ��ת
	tmp[0][0] = bitvec[4][0], tmp[0][1] = bitvec[4][1], tmp[0][2] = bitvec[4][2], tmp[0][3] = bitvec[4][3], tmp[0][4] = bitvec[4][4];
	tmp[1][0] = bitvec[3][0], tmp[1][1] = bitvec[3][1], tmp[1][2] = bitvec[3][2], tmp[1][3] = bitvec[3][3], tmp[1][4] = bitvec[3][4];
	tmp[2][0] = bitvec[2][0], tmp[2][1] = bitvec[2][1], tmp[2][2] = bitvec[2][2], tmp[2][3] = bitvec[2][3], tmp[2][4] = bitvec[2][4];
	tmp[3][0] = bitvec[1][0], tmp[3][1] = bitvec[1][1], tmp[3][2] = bitvec[1][2], tmp[3][3] = bitvec[1][3], tmp[3][4] = bitvec[1][4];
	tmp[4][0] = bitvec[0][0], tmp[4][1] = bitvec[0][1], tmp[4][2] = bitvec[0][2], tmp[4][3] = bitvec[0][3], tmp[4][4] = bitvec[0][4];
	if (is_less(tmp, bitvec))
		return true;

	//��ֱ��ת
	tmp[0][0] = bitvec[0][4], tmp[0][1] = bitvec[0][3], tmp[0][2] = bitvec[0][2], tmp[0][3] = bitvec[0][1], tmp[0][4] = bitvec[0][0];
	tmp[1][0] = bitvec[1][4], tmp[1][1] = bitvec[1][3], tmp[1][2] = bitvec[1][2], tmp[1][3] = bitvec[1][1], tmp[1][4] = bitvec[1][0];
	tmp[2][0] = bitvec[2][4], tmp[2][1] = bitvec[2][3], tmp[2][2] = bitvec[2][2], tmp[2][3] = bitvec[2][1], tmp[2][4] = bitvec[2][0];
	tmp[3][0] = bitvec[3][4], tmp[3][1] = bitvec[3][3], tmp[3][2] = bitvec[3][2], tmp[3][3] = bitvec[3][1], tmp[3][4] = bitvec[3][0];
	tmp[4][0] = bitvec[4][4], tmp[4][1] = bitvec[4][3], tmp[4][2] = bitvec[4][2], tmp[4][3] = bitvec[4][1], tmp[4][4] = bitvec[4][0];
	if (is_less(tmp, bitvec))
		return true;

	//�Խ��߷�ת/
	tmp[0][0] = bitvec[4][4], tmp[0][1] = bitvec[3][4], tmp[0][2] = bitvec[2][4], tmp[0][3] = bitvec[1][4], tmp[0][4] = bitvec[0][4];
	tmp[1][0] = bitvec[4][3], tmp[1][1] = bitvec[3][3], tmp[1][2] = bitvec[2][3], tmp[1][3] = bitvec[1][3], tmp[1][4] = bitvec[0][3];
	tmp[2][0] = bitvec[4][2], tmp[2][1] = bitvec[3][2], tmp[2][2] = bitvec[2][2], tmp[2][3] = bitvec[1][2], tmp[2][4] = bitvec[0][2];
	tmp[3][0] = bitvec[4][1], tmp[3][1] = bitvec[3][1], tmp[3][2] = bitvec[2][1], tmp[3][3] = bitvec[1][1], tmp[3][4] = bitvec[0][1];
	tmp[4][0] = bitvec[4][0], tmp[4][1] = bitvec[3][0], tmp[4][2] = bitvec[2][0], tmp[4][3] = bitvec[1][0], tmp[4][4] = bitvec[0][0];
	if (is_less(tmp, bitvec))
		return true;

	//�Խ��߷�ת\
	tmp[0][0] = bitvec[0][0], tmp[0][1] = bitvec[1][0], tmp[0][2] = bitvec[2][0], tmp[0][3] = bitvec[3][0], tmp[0][4] = bitvec[4][0];
	tmp[1][0] = bitvec[0][1], tmp[1][1] = bitvec[1][1], tmp[1][2] = bitvec[2][1], tmp[1][3] = bitvec[3][1], tmp[1][4] = bitvec[4][1];
	tmp[2][0] = bitvec[0][2], tmp[2][1] = bitvec[1][2], tmp[2][2] = bitvec[2][2], tmp[2][3] = bitvec[3][2], tmp[2][4] = bitvec[4][2];
	tmp[3][0] = bitvec[0][3], tmp[3][1] = bitvec[1][3], tmp[3][2] = bitvec[2][3], tmp[3][3] = bitvec[3][3], tmp[3][4] = bitvec[4][3];
	tmp[4][0] = bitvec[0][4], tmp[4][1] = bitvec[1][4], tmp[4][2] = bitvec[2][4], tmp[4][3] = bitvec[3][4], tmp[4][4] = bitvec[4][4];
	if (is_less(tmp, bitvec))
		return true;

	return false;
}

//�������
void Pm_cout(const bool(&bitvec)[5][5])
{
	std::cout << bitvec[0][0] << bitvec[0][1] << bitvec[0][2] << bitvec[0][3] << bitvec[0][4] << std::endl;
	std::cout << bitvec[1][0] << bitvec[1][1] << bitvec[1][2] << bitvec[1][3] << bitvec[1][4] << std::endl;
	std::cout << bitvec[2][0] << bitvec[2][1] << bitvec[2][2] << bitvec[2][3] << bitvec[2][4] << std::endl;
	std::cout << bitvec[3][0] << bitvec[3][1] << bitvec[3][2] << bitvec[3][3] << bitvec[3][4] << std::endl;
	std::cout << bitvec[4][0] << bitvec[4][1] << bitvec[4][2] << bitvec[4][3] << bitvec[4][4] << std::endl;
}

//�ж��Ƿ��������Ǿ���
bool is_Utrimtx(const bool(&bitvec)[5][5])
{
	for (int i = 3; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (bitvec[i][j])
				return false;
		}
	}
	return true;
}

//bitתΪ�ַ���
std::string bit2str(const bool(&bitvec)[5][5])
{
	std::string str = "";
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (bitvec[i][j])
				str += "1";
			else
				str += "0";
		}
		str += "\n";
	}
	return str;
}

//�ж��Ƿ���Ҫѭ��(�˺�������©����THREAD_NUM������)
bool mt_cir_all(const bool(&bitvec)[5][5], int thread_num1)
{
	unsigned long cnt = 0;
	unsigned long NUM = 0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			NUM += 1UL <<(5 * i + j);
			if (bitvec[i][j]) 
			{
				cnt += 1UL << (5 * i + j);
			}
		}
	}
	if ((cnt + thread_num1) <= NUM)
		return true;
	else
		return false;
}
