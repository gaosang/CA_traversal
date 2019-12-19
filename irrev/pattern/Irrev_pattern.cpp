#include "Irrev_pattern.h"
std::istream &read(std::istream& in, Irrev_pattern& irrev1){
	std::string str;
	while (std::getline(in, str))
	{
		if (str.length() != 0)
		{
			reverse(str.begin(), str.end());
			boost::dynamic_bitset<> bitvec(str);
			irrev1.irrev_sta.push_back(bitvec);
			break;
		}
	}
	if (!in)
		return in;//�ļ��Ѿ�����
	irrev1.r = 0;
	//irrev_sta
	for (std::string::size_type i = 1; i < irrev1.irrev_sta[0].size(); ++i)
	{
		std::getline(in, str);
		reverse(str.begin(), str.end());
		boost::dynamic_bitset<> bitvec(str);
		irrev1.irrev_sta.push_back(bitvec);
	}
	//irrev_lma
	for (std::getline(in, str); str.length() != 0; std::getline(in, str))
	{
		reverse(str.begin(), str.end());
		boost::dynamic_bitset<> bitvec(str);
		irrev1.irrev_lma.push_back(bitvec);
		++irrev1.r;
	}
	boost::dynamic_bitset<> tmp(25, 0);
	for (int i = 0; i < 25 - irrev1.r; ++i)
	{
		irrev1.irrev_ss.push_back(tmp);
	}
	irrev1.irrev_lma2ss();
	return in;
}

//Irrev_pattern::Irrev_pattern()
//{
//	boost::dynamic_bitset<> tmp1(10, 0);
//	for (int i = 0; i < 10; ++i)
//	{
//		irrev_sta.push_back(tmp1);
//	}
//	boost::dynamic_bitset<> tmp2(25, 0);
//	for (int i = 0; i < 25; ++i)
//	{
//		irrev_lma.push_back(tmp2);
//		irrev_ss.push_back(tmp2);
//	}
//}

Irrev_pattern::Irrev_pattern(std::istream& in)
{
	read(in, *this);
}

//irrev_lma ������ξ��󣬱�ʾ����sta�ķ�������������
//irrev_ss ��ʾ����sta�ķ�����Ļ�����ϵ
void Irrev_pattern::irrev_lma2ss()
{
	//�������ͨ���ʵ����б任
	std::vector<int> idx_r(r);
	std::vector<int> idx_n_r(25-r);
	int idx_n_r_m = -1;
	int idx_n_r_j = 0;
	for (int i = 0; i < r; ++i)
	{
		idx_r[i] = irrev_lma[i].find_first();
		for (++idx_n_r_m; idx_n_r_m < idx_r[i]; ++idx_n_r_m)
		{
			idx_n_r[idx_n_r_j] = idx_n_r_m;
			++idx_n_r_j;
		}
	}
	for (int i = 0; i < 25 - r; ++i)
	{
		irrev_ss[i][idx_n_r[i]] = true;
		for (int j = 0; j < r; ++j)
		{
			if ((irrev_ss[i] & irrev_lma[j]).count() % 2)
			{
				irrev_ss[i][idx_r[j]] = true;
			}
		}
	}
}

//�ж�irrev1�Ľ⼯�Ƿ���irrev2�⼯���Ӽ�
bool is_sub(Irrev_pattern& irrev1, Irrev_pattern& irrev2)
{
	static std::vector<unsigned int> idx_tmp(25, 0);
	static bool pra_once = true;
	if (pra_once)
		for (int i = 0; i < 25; ++i)
			idx_tmp[i] = i;
	static std::vector<std::vector<unsigned int> > idx(8, idx_tmp);
	if (pra_once)
	{
		idx_cal8(idx);
		pra_once = false;
	}
	if (irrev1.r < irrev2.r)//irrev1�Ļ�����ϵά��(25-r)��
	{
		return false;
	}
	//irrev1�Ļ�����ϵ�Ƿ�����irrev2��������ξ���
	boost::dynamic_bitset<> tmp(25, 0);
	bool sub_flag = true;
	for (int idx_i = 0; idx_i < 8; ++idx_i)
	{
		sub_flag = true;
		for (int i = 0; i < 25 - irrev1.r; ++i)
		{
			for (int m = 0; m < 25; ++m)
			{
				tmp[m] = irrev1.irrev_ss[i][idx[idx_i][m]];
			}
			for (int j = 0; j < irrev2.r; ++j)
			{
				if ((tmp & irrev2.irrev_lma[j]).count() % 2)//���ڲ������
				{
					sub_flag = false;
					break;
				}
			}
			if (!sub_flag)
				break;
		}
		if (sub_flag)
			break;
	}
	return sub_flag;
}

//��ӡ
std::ostream &print(std::ostream &os, const Irrev_pattern &irrev)
{
	print1(os, irrev);
	print2(os, irrev);
	print3(os, irrev);
	return os;
}
std::ostream &print1(std::ostream &os, const Irrev_pattern &irrev)
{
	os << "irrev_sta" << std::endl;
	for (int i = 0; i < irrev.irrev_sta.size(); ++i)
	{
		os << co_to_string(irrev.irrev_sta[i]) << std::endl;
	}
	return os;
}
std::ostream &print2(std::ostream &os, const Irrev_pattern &irrev)
{
	os << "irrev_lma" << std::endl;
	for (int i = 0; i < irrev.r; ++i)
	{
		os << co_to_string(irrev.irrev_lma[i]) << std::endl;
	}
	return os;
}
std::ostream &print3(std::ostream &os, const Irrev_pattern &irrev)
{
	os << "irrev_ss" << std::endl;
	for (int i = 0; i < 25 - irrev.r; ++i)
	{
		os << co_to_string(irrev.irrev_ss[i]) << std::endl;
	}
	return os;
}