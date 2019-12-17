#include "glo_vars.h"
#include <boost/dynamic_bitset.hpp>
//加n函数，遍历时使用(n应为线程数)
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
		if (cnt == ca_size * ca_size)//全1加一还是全1，避免溢位
		{
			for (int i = 0; i < ca_size; i++)
				for (int j = 0; j < ca_size; ++j)
					bitvec[i][j] = 1;
			break;
		}
	}
}

//加n函数，遍历时使用(n应为线程数)(不考虑右边界和下边界的俩行元素)
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
		if (cnt == (ca_size -2) * (ca_size-2))//全1加一还是全1，避免溢位
		{
			for (int i = 0; i < ca_size-2; i++)
				for (int j = 0; j < ca_size-2; ++j)
					bitvec[i][j] = 1;
			break;
		}
	}
}

//计算1的个数
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

//比较大小，索引越小，其比特位越低,相等返回false
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

//通过8种对称操作，判断之一规则是否曾经计算过
bool is_caled(const bool(&bitvec)[ca_size][ca_size])
{
	bool tmp[ca_size][ca_size];
	//顺时针90度
	for (int i = 0; i < ca_size; i++)
	{
		for (int j = 0; j < ca_size; ++j)
		{
			tmp[i][j] = bitvec[ca_size-j-1][i];
		}
	}
	if (is_less(tmp, bitvec))
		return true;

	//顺时针180度
	for (int i = 0; i < ca_size; i++)
	{
		for (int j = 0; j < ca_size; ++j)
		{
			tmp[i][j] = bitvec[ca_size - i - 1][ca_size - j - 1];
		}
	}
	if(is_less(tmp, bitvec))
		return true;

	//顺时针270度
	for (int i = 0; i < ca_size; i++)
	{
		for (int j = 0; j < ca_size; ++j)
		{
			tmp[i][j] = bitvec[j][ca_size - i - 1];
		}
	}
	if (is_less(tmp, bitvec))
		return true;

	//水平翻转
	for (int i = 0; i < ca_size; i++)
	{
		for (int j = 0; j < ca_size; ++j)
		{
			tmp[i][j] = bitvec[ca_size - i - 1][j];
		}
	}
	if (is_less(tmp, bitvec))
		return true;

	//竖直翻转
	for (int i = 0; i < ca_size; i++)
	{
		for (int j = 0; j < ca_size; ++j)
		{
			tmp[i][j] = bitvec[i][ca_size - j - 1];
		}
	}
	if (is_less(tmp, bitvec))
		return true;

	//对角线翻转/
	for (int i = 0; i < ca_size; i++)
	{
		for (int j = 0; j < ca_size; ++j)
		{
			tmp[i][j] = bitvec[ca_size - j - 1][ca_size - i - 1];
		}
	}
	if (is_less(tmp, bitvec))
		return true;

	//对角线翻转左上右下
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

//if2判断是否需要计算
bool is_Ntril(const bool(&bitvec)[ca_size][ca_size])
{
	return false;
}

//把5*5形式转化为25形式
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

//清零
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

//bit转为字符串
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

//dynamic_bitset2string 低位到低位
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

//判断细胞自动机右边界和下边界两行以内是否存在元素，不存在返回true
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

//判断此结果是否需要输出
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

	//元素全为0，不考虑
	if (co_mat[0].count() == 0)
		return false;
	//25个参数全为零
	if (co_mat[24][24])
		return false;

	int cnt;
	//上三角矩阵
	//上
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
	//下
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
	//左
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
	//右
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
	

	//一个角9个0
	//右下
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
	//左上
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
	//右上
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
	//左下
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

//赋值，1赋给2
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