// CA.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
int main()
{
	int a = 2;

	//��ʱ����
	double dur,dur0;
	clock_t start, end,start0,end0;
	start = clock();
	//�������ã�sizeΪϸ���Զ��������ߴ磨sizeΪ������ĳߴ磩��PmΪ��ȶԽǷֿ����Ĺ������
	const int Pm[5][5] = {
		{0,0,0,0,0},
		{0,0,1,0,0},
		{0,1,0,1,0},
		{0,0,1,0,0},
		{0,0,0,0,0}
	};
	constexpr unsigned int size = 41;
	double Time[size] = { 0 };
	int A[size][size] = { 0 };//A����Ϊ�������
	std::ofstream app("out_time.txt");//���ļ���
	for (size_t size_i = 40; size_i <= size; size_i++) {
		start0 = clock();
		for (int m = 1; m <= size_i; m++) {
			for (int n = 1; n <= size_i; n++)
			{
				A[m - 1][n - 1] = det_structure_q_5(m, n, Pm);
			}
			std::cout << "\r";
			std::cout << "������:" << std::setw(3)<<size_i << "/" << std::setw(3) << size << "	";
			std::cout << "���ε�����ɶ�:" << std::setw(3) << m << "/" << std::setw(3) << size_i;

		}
		end0 = clock();
		dur0 = (double)(end0 - start0) / CLOCKS_PER_SEC;
		Time[size_i - 1] = dur0;
		app << size_i << "," << dur0;//��ÿ��Ԫ��д���ļ����Զ��ŷָ���
		app << std::endl;//ÿ�������������ӻ��С�
	}


	std::ofstream out("out.txt");//���ļ���
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			out << A[i][j] << ',';//��ÿ��Ԫ��д���ļ����Զ��ŷָ���
		}
		out << std::endl;//ÿ�������������ӻ��С�
	}

	//���ʱ��
	std::cout << std::endl;
	end = clock();
	dur = (double)(end - start);
	std::cout.setf(std::ios::fixed);
	std::cout << "Time:\t" << std::setprecision(3) << dur / CLOCKS_PER_SEC << " " << "seconds  < " << std::setprecision(3) << dur / CLOCKS_PER_SEC / 60 << " minuts >" << std::endl;
	//�������
	std::cout << "end" << std::endl;
	//std::cin >> a;
	return 0;
}

//����xΪָʾsize���Ա�������ô������ʱ��x�Ĺ�ϵΪ
//t=2.6956*(x/64)^7+10.7222*(x/64)^6-19.7517*(x/64)^5+42.2011*(x/64)^4-25.7702*(x/64)^3+8.0901*(x/64)^2-0.8311*(x/64)+0.0348(��λΪ�룬cpuΪ����G1840)

