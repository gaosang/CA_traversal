#include "glo_vars.h"
#include <boost/dynamic_bitset.hpp>
//��n����������ʱʹ��(nӦΪ�߳���)
void bit_add_n(bool(&bitvec)[ca_size][ca_size], const int n = 1)
{
	bool flag;
	for (int k = 0; k < n; k++)
	{
		int cnt = 0;
		for (int i = 0; i < ca_size; i++)
		{
			for (int j = 0; j < ca_size; ++j)
			{
				flag = bitvec[i][j];
				bitvec[i][j] ^= true;
				if (!flag)
					break;
				else
					cnt++;
			}
			if (!flag)
				break;
		}
		if (cnt == ca_size * ca_size)//ȫ1��һ����ȫ1��������λ
		{
			for (int i = 0; i < ca_size; i++)
				for (int j = 0; j < ca_size; ++j)
					bitvec[i][j] = 1;
			break;
		}
	}
}

//��n����������ʱʹ��(nӦΪ�߳���)(�������ұ߽���±߽������Ԫ��)
void bit_add_n_2_2(bool(&bitvec)[ca_size][ca_size], const int n = 1)
{
	bool flag;
	for (int k = 0; k < n; k++)
	{
		int cnt = 0;
		for (int i = 0; i < ca_size - 2; i++)
		{
			for (int j = 0; j < ca_size - 2; ++j)
			{
				flag = bitvec[i][j];
				bitvec[i][j] ^= true;
				if (!flag)
					break;
				else
					cnt++;
			}
			if (!flag)
				break;
		}
		if (cnt == (ca_size -2) * (ca_size-2))//ȫ1��һ����ȫ1��������λ
		{
			for (int i = 0; i < ca_size-2; i++)
				for (int j = 0; j < ca_size-2; ++j)
					bitvec[i][j] = 1;
			break;
		}
	}
}

//����1�ĸ���
int bit_count(bool bitvec[ca_size][ca_size])
{
	int cnt = 0;
	for (int i = 0; i < ca_size; i++)
	{
		for (int j = 0; j < ca_size; ++j)
		{
			if (bitvec[i][j])
				++cnt;
		}
	}
	return cnt;
}

//�Ƚϴ�С������ԽС�������λԽ��,��ȷ���false
bool is_less(const bool(&bitvec1)[ca_size][ca_size], const bool(&bitvec2)[ca_size][ca_size])
{
	for (int i = ca_size-1; i >= 0; i--)
	{
		for (int j = ca_size-1; j >= 0; j--)
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
bool is_caled(const bool(&bitvec)[ca_size][ca_size])
{
	bool tmp[ca_size][ca_size];
	//˳ʱ��90��
	for (int i = 0; i < ca_size; i++)
	{
		for (int j = 0; j < ca_size; ++j)
		{
			tmp[i][j] = bitvec[ca_size-j-1][i];
		}
	}
	if (is_less(tmp, bitvec))
		return true;

	//˳ʱ��180��
	for (int i = 0; i < ca_size; i++)
	{
		for (int j = 0; j < ca_size; ++j)
		{
			tmp[i][j] = bitvec[ca_size - i - 1][ca_size - j - 1];
		}
	}
	if(is_less(tmp, bitvec))
		return true;

	//˳ʱ��270��
	for (int i = 0; i < ca_size; i++)
	{
		for (int j = 0; j < ca_size; ++j)
		{
			tmp[i][j] = bitvec[j][ca_size - i - 1];
		}
	}
	if (is_less(tmp, bitvec))
		return true;

	//ˮƽ��ת
	for (int i = 0; i < ca_size; i++)
	{
		for (int j = 0; j < ca_size; ++j)
		{
			tmp[i][j] = bitvec[ca_size - i - 1][j];
		}
	}
	if (is_less(tmp, bitvec))
		return true;

	//��ֱ��ת
	for (int i = 0; i < ca_size; i++)
	{
		for (int j = 0; j < ca_size; ++j)
		{
			tmp[i][j] = bitvec[i][ca_size - j - 1];
		}
	}
	if (is_less(tmp, bitvec))
		return true;

	//�Խ��߷�ת/
	for (int i = 0; i < ca_size; i++)
	{
		for (int j = 0; j < ca_size; ++j)
		{
			tmp[i][j] = bitvec[ca_size - j - 1][ca_size - i - 1];
		}
	}
	if (is_less(tmp, bitvec))
		return true;

	//�Խ��߷�ת��������
	for (int i = 0; i < ca_size; i++)
	{
		for (int j = 0; j < ca_size; ++j)
		{
			tmp[i][j] = bitvec[j][i];
		}
	}
	if (is_less(tmp, bitvec))
		return true;

	return false;
}

//if2�ж��Ƿ���Ҫ����
bool is_Ntril(const bool(&bitvec)[ca_size][ca_size])
{
	return false;
}

//��5*5��ʽת��Ϊ25��ʽ
void change_5_5to25(boost::dynamic_bitset<>& bitvec1, const bool(&bitvec2)[5][5])
{
	bitvec1.reset();
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (bitvec2[i][j])
				bitvec1.set(i * 5 + j);
		}
	}
}

//����
void co_reset(bool(&bitvec)[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			bitvec[i][j] = false;
		}
	}
}

//bitתΪ�ַ���
std::string bit2str(const bool(&bitvec)[ca_size][ca_size])
{
	std::string str = "";
	for (int i = 0; i < ca_size; i++)
	{
		for (int j = 0; j < ca_size; ++j)
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

//dynamic_bitset2string ��λ����λ
std::string co_to_string(boost::dynamic_bitset<>& bitvec)
{
	std::string str;
	to_string(bitvec, str);
	reverse(str.begin(), str.end());
	return str;
}


bool stop_cdt(const bool(&bitvec)[ca_size][ca_size])
{
	bool Pm[5][5] = {
		{ 0,0,0,1,0 },
		{ 1,0,0,0,0 },
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 }
	};
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (Pm[i][j] != bitvec[i][j])
				return false;
		}
	}
	return true;
}

//�ж�ϸ���Զ����ұ߽���±߽����������Ƿ����Ԫ�أ������ڷ���true
bool end_in_b2_2(const bool(&bitvec)[ca_size][ca_size])
{
	for (int i = 0; i < ca_size; ++i)
	{
		for (int j = ca_size - 2; j < ca_size; ++j)
		{
			if (bitvec[i][j])
				return false;
		}
	}
	for (int i = ca_size - 2; i < ca_size; ++i)
	{
		for (int j = 0; j < ca_size; ++j)
		{
			if (bitvec[i][j])
				return false;
		}
	}
	return true;
}

//�жϴ˽���Ƿ���Ҫ���
bool is_out_Ntri(const std::vector<boost::dynamic_bitset<> >(&co_mat))
{
	bool Pm[5][5] = {
		{ 1,1,1,1,1 },
		{ 1,1,1,1,1 },
		{ 1,1,1,1,1 },
		{ 1,1,1,1,1 },
		{ 1,1,1,1,1 }
	};
	int index = 0;
	for (int i = 0; i < 25; ++i)
	{
		if (co_mat[i].count() == 1)
		{
			index = co_mat[i].find_first();
			Pm[index / 5][index % 5] = 0;
		}
	}

	//Ԫ��ȫΪ0��������
	if (co_mat[0].count() == 0)
		return false;
	//25������ȫΪ��
	if (co_mat[24][24])
		return false;

	int cnt;
	//�����Ǿ���
	//��
	cnt = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (Pm[i][j])
				++cnt;
		}
	}
	if (cnt == 0)
		return false;
	//��
	cnt = 0;
	for (int i = 3; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (Pm[i][j])
				++cnt;
		}
	}
	if (cnt == 0)
		return false;
	//��
	cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (Pm[i][j])
				++cnt;
		}
	}
	if (cnt == 0)
		return false;
	//��
	cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 3; j < 5; ++j)
		{
			if (Pm[i][j])
				++cnt;
		}
	}
	if (cnt == 0)
		return false;
	

	//һ����9��0
	//����
	cnt = 0;
	for (int i = 2; i < 5; i++)
	{
		for (int j = 2; j < 5; ++j)
		{
			if (Pm[i][j])
				++cnt;
		}
	}
	if (cnt == 0)
		return false;
	//����
	cnt = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (Pm[i][j])
				++cnt;
		}
	}
	if (cnt == 0)
		return false;
	//����
	cnt = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 2; j < 5; ++j)
		{
			if (Pm[i][j])
				++cnt;
		}
	}
	if (cnt == 0)
		return false;
	//����
	cnt = 0;
	for (int i = 2; i < 5; i++)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (Pm[i][j])
				++cnt;
		}
	}
	if (cnt == 0)
		return false;

	return true;
}

//��ֵ��1����2
void assign1to2(const bool(&bitvec1)[5][5], bool(&bitvec2)[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; ++j)
		{
			bitvec2[i][j] = bitvec1[i][j];
		}
	}
}