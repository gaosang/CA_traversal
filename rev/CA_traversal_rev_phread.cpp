//多线程相关
#include <thread>

#include <iostream>
#include "det_structure_q_5.h"
#include <boost/dynamic_bitset.hpp>
#include <fstream>
#include <time.h>
#include <iomanip>
#include "CA_Functions.h"
#include <string>
#include <vector>
#include <algorithm>

void rev(std::string &str, int thread_id);
const int THREAD_NUM = 255; //设置的线程数目
int main()
{
	time_t timeBegin, timeEnd;
	timeBegin = time(NULL);//初始时间
	std::string str = "";
	std::vector<std::string> str_v(THREAD_NUM, "");
	std::cout << "多线程:" << THREAD_NUM << std::endl;
	std::vector<std::thread> threads;
	for (int i = 0; i < THREAD_NUM; ++i)
		threads.push_back(std::thread(rev, std::ref(str_v[i]), i));
	for (auto& th : threads) 
		th.join();

	for (int i = 0; i < THREAD_NUM; ++i)
	{
		str += "\n" + str_v[i];
	}
	std::string filename = "out.txt";
	std::ofstream out("out.txt");//打开文件。
	out << str;

	//程序结束并计时
	timeEnd = time(NULL);
	std::ofstream out_time("time.txt");//打开文件。
	std::string str_time(std::to_string((timeEnd - timeBegin) / 60));
	str_time += "分钟";
	str_time = "线程数：" + std::to_string(THREAD_NUM) + "\n" + "用时" + str_time;
	out_time << str_time;
	std::cout << "程序结束" << std::endl;
	return 0;
}


//核心计算函数
void rev(std::string &str, int thread_id) 
{
	//Pm为五等对角分块矩阵的规则矩阵
	bool Pm[5][5] = {
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 }
	};
	bit_add_n(Pm, thread_id);
	int A[CA_size][CA_size] = { 0 };//A数组为结果矩阵
	for (; bit_count(Pm)<25; bit_add_n(Pm, THREAD_NUM))
	{
		if (is_caled(Pm)) //if1 if1与if2的顺序不能变
			continue;
		if (is_Utrimtx(Pm)) //if2
			continue;
		for (int m = 1; m <= CA_size; m++) {
			for (int n = 1; n <= CA_size; n++)
			{
				A[m - 1][n - 1] = det_structure_q_5(m, n, Pm);
			}
		}
		if (bit_count(A) == 100)
		{
			str += bit2str(Pm);
			str += "\n";
		}
	}
}