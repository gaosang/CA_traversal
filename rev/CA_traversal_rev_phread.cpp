//���߳����
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
const int THREAD_NUM = 255; //���õ��߳���Ŀ
int main()
{
	time_t timeBegin, timeEnd;
	timeBegin = time(NULL);//��ʼʱ��
	std::string str = "";
	std::vector<std::string> str_v(THREAD_NUM, "");
	std::cout << "���߳�:" << THREAD_NUM << std::endl;
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
	std::ofstream out("out.txt");//���ļ���
	out << str;

	//�����������ʱ
	timeEnd = time(NULL);
	std::ofstream out_time("time.txt");//���ļ���
	std::string str_time(std::to_string((timeEnd - timeBegin) / 60));
	str_time += "����";
	str_time = "�߳�����" + std::to_string(THREAD_NUM) + "\n" + "��ʱ" + str_time;
	out_time << str_time;
	std::cout << "�������" << std::endl;
	return 0;
}


//���ļ��㺯��
void rev(std::string &str, int thread_id) 
{
	//PmΪ��ȶԽǷֿ����Ĺ������
	bool Pm[5][5] = {
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 }
	};
	bit_add_n(Pm, thread_id);
	int A[CA_size][CA_size] = { 0 };//A����Ϊ�������
	for (; bit_count(Pm)<25; bit_add_n(Pm, THREAD_NUM))
	{
		if (is_caled(Pm)) //if1 if1��if2��˳���ܱ�
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