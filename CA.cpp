// CA.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int main()
{
	int a = 2;

	//计时代码
	double dur,dur0;
	clock_t start, end,start0,end0;
	start = clock();
	//参数设置，size为细胞自动机的最大尺寸（size为大于零的尺寸），Pm为五等对角分块矩阵的规则矩阵
	const int Pm[5][5] = {
		{0,0,0,0,0},
		{0,0,1,0,0},
		{0,1,0,1,0},
		{0,0,1,0,0},
		{0,0,0,0,0}
	};
	constexpr unsigned int size = 41;
	double Time[size] = { 0 };
	int A[size][size] = { 0 };//A数组为结果矩阵
	std::ofstream app("out_time.txt");//打开文件。
	for (size_t size_i = 40; size_i <= size; size_i++) {
		start0 = clock();
		for (int m = 1; m <= size_i; m++) {
			for (int n = 1; n <= size_i; n++)
			{
				A[m - 1][n - 1] = det_structure_q_5(m, n, Pm);
			}
			std::cout << "\r";
			std::cout << "迭代数:" << std::setw(3)<<size_i << "/" << std::setw(3) << size << "	";
			std::cout << "本次迭代完成度:" << std::setw(3) << m << "/" << std::setw(3) << size_i;

		}
		end0 = clock();
		dur0 = (double)(end0 - start0) / CLOCKS_PER_SEC;
		Time[size_i - 1] = dur0;
		app << size_i << "," << dur0;//将每个元素写入文件，以逗号分隔。
		app << std::endl;//每行输出结束，添加换行。
	}


	std::ofstream out("out.txt");//打开文件。
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			out << A[i][j] << ',';//将每个元素写入文件，以逗号分隔。
		}
		out << std::endl;//每行输出结束，添加换行。
	}

	//输出时间
	std::cout << std::endl;
	end = clock();
	dur = (double)(end - start);
	std::cout.setf(std::ios::fixed);
	std::cout << "Time:\t" << std::setprecision(3) << dur / CLOCKS_PER_SEC << " " << "seconds  < " << std::setprecision(3) << dur / CLOCKS_PER_SEC / 60 << " minuts >" << std::endl;
	//程序结束
	std::cout << "end" << std::endl;
	//std::cin >> a;
	return 0;
}

//假设x为指示size的自变量，那么程序用时与x的关系为
//t=2.6956*(x/64)^7+10.7222*(x/64)^6-19.7517*(x/64)^5+42.2011*(x/64)^4-25.7702*(x/64)^3+8.0901*(x/64)^2-0.8311*(x/64)+0.0348(单位为秒，cpu为赛扬G1840)

