#include <thread>
#include <iostream>
#include <boost/dynamic_bitset.hpp>
#include <fstream>
#include <time.h>
#include <iomanip>
#include "CA_Functions.h"
#include <string>
#include <vector>
#include <algorithm>
#include "glo_vars.h"

void irrev(std::string &str1, std::string &str2, int thread_id);
const int THREAD_NUM = 255; //设置的线程数目
int main()
{
	std::cout << "Size:" + std::to_string(ca_size) << std::endl;
	std::cout << "多线程:" << THREAD_NUM << std::endl;
	time_t timeBegin, timeEnd;
	timeBegin = time(NULL);//初始时间
	std::string str1 = "";//1保存元素的相关细胞不超过右边界和下边界
	std::string str2 = "";
	std::vector<std::string> str_v1(THREAD_NUM, "");
	std::vector<std::string> str_v2(THREAD_NUM, "");
	std::vector<std::thread> threads;
	for (int i = 0; i < THREAD_NUM; ++i)
		threads.push_back(std::thread(irrev, std::ref(str_v1[i]), std::ref(str_v2[i]), i));
	for (auto& th : threads)
		th.join();

	for (int i = 0; i < THREAD_NUM; ++i)
	{
		str1 += "\n" + str_v1[i];
	}
	std::ofstream out1("out1.txt");//打开文件。
	out1 << str1;

	for (int i = 0; i < THREAD_NUM; ++i)
	{
		str2 += "\n" + str_v2[i];
	}
	std::ofstream out2("out2.txt");//打开文件。
	out2 << str2;

	//程序结束并计时
	timeEnd = time(NULL);
	std::ofstream out_time("time.txt");//打开文件。
	std::string str_time = "";
	str_time += "Size:" + std::to_string(ca_size) + "\n";
	str_time += "线程数：" + std::to_string(THREAD_NUM) + "\n" + "用时" + std::to_string((timeEnd - timeBegin) / 60) + "分钟";

	out_time << str_time;
	std::cout << "程序结束" << std::endl;

	return 0;
}


void irrev(std::string &str1, std::string &str2, int thread_id)
{
	std::vector<boost::dynamic_bitset<> > co_mat;//用于解参数矩阵方程
	boost::dynamic_bitset<> co_mat_tmp(25, 0);
	for (size_t i = 0; i < ca_size * ca_size; ++i)
		co_mat.push_back(co_mat_tmp);
	bool bit_sta[ca_size][ca_size] = { 0 };//代表着细胞自动机的元素位置，相应位置为1，对应转移矩阵的某行
	bool ca_co[ca_size][ca_size][5][5] = { 0 };//生成参数方程矩阵的中间矩阵变量
	bool ca_co_flag[ca_size][ca_size] = { 0 };//标志当前位置是否存在参数
	for (bit_add_n_2_2(bit_sta, thread_id); bit_count(bit_sta) < (ca_size-2)*(ca_size-2); bit_add_n_2_2(bit_sta, THREAD_NUM))
	{
		if (is_caled(bit_sta))//if1 if1与if2的顺序不能变
			continue;
		if (is_Ntril(bit_sta)) //if2判断是否需要计算
			continue;
		//构造参数矩阵，步骤1
		for (int i = 0; i < ca_size; ++i)
		{
			for (int j = 0; j < ca_size; ++j)
			{
				if (!bit_sta[i][j])
					continue;
				for (int m = 0; m < 5; ++m) {
					for (int n = 0; n < 5; ++n) {
						if (((i + m - 2) >= 0)&((i + m - 2) < ca_size)&((j + n - 2) >= 0)&((j + n - 2) < ca_size))
						{
							ca_co[i + m - 2][j + n - 2][m][n] = true;
							ca_co_flag[i + m - 2][j + n - 2] = true;
						}
					}
				}
			}
		}
		//构造参数矩阵，步骤2，并记录矩阵的行数
		int k = 0;
		for (int i = 0; i < ca_size; ++i)
		{
			for (int j = 0; j < ca_size; ++j)
			{
				if (ca_co_flag[i][j])
				{
					change_5_5to25(co_mat[k], ca_co[i][j]);
					co_reset(ca_co[i][j]);
					++k;
					ca_co_flag[i][j] = 0;
				}
			}
		}

		//k方程矩阵的有效行数
		//方程矩阵化行阶梯形矩阵
		int m = 0, n;
		for (n = 0; n < 25; ++n)//n代表列数
		{
			bool ex_flag = true;
			for (int i = m; i < k; ++i)
			{
				if (co_mat[i][n])
				{
					if (ex_flag)
					{
						co_mat[m].swap(co_mat[i]);
						ex_flag = false;
					}
					else
					{
						co_mat[i] ^= co_mat[m];
					}
				}
			}
			if (!ex_flag)
				m++;
		}
		//从行阶梯形矩阵化行最简形矩阵
		//矩阵的有效行数m<=25
		for (int i = 1; i < m; ++i)
		{
			for (int j = 0; j < 25; ++j)//找行的首个非零元
			{
				if (co_mat[i][j])
				{
					for (int l = i - 1; l >= 0; l--)
					{
						if(co_mat[l][j])
							co_mat[l] ^= co_mat[i];
					}
					break;
				}
			}
		}
		if (is_out_Ntri(co_mat))
		{
			if (end_in_b2_2(bit_sta))
			{
				str1 += "\n";
				str1 += bit2str(bit_sta);
				for (int i = 0; i < 25; ++i)
				{
					if (!co_mat[i].any())
						break;
					str1 += co_to_string(co_mat[i]);
					str1 += "\n";
				}
			}
			else
			{
				;
			}
		}
	}
}