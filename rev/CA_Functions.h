#pragma once
#include "glo_vars.h"
void bit_add_n(bool (&bitvec)[5][5]); //��1����������ʱʹ��
void bit_add_n(bool (&bitvec)[5][5], const int n);//��n����������ʱʹ��(nӦΪ�߳���)
int bit_count(bool (&bitvec)[5][5]); //����1�ĸ���
int bit_count(int bitvec[CA_size][CA_size]);
bool is_less(const bool(&bitvec1)[5][5], const bool(&bitvec2)[5][5]);//�Ƚϴ�С������ԽС�������λԽ��
bool is_caled(const bool(&bitvec)[5][5]);//ͨ��8�ֶԳƲ������ж�֮һ�����Ƿ����������
void Pm_cout(const bool(&bitvec)[5][5]);//�������
bool is_Utrimtx(const bool(&bitvec)[5][5]);//�ж��Ƿ��������Ǿ���
std::string bit2str(const bool(&bitvec)[5][5]);//bitתΪ�ַ���
bool mt_cir_all(const bool(&bitvec)[5][5], int thread_num1);//�ж��Ƿ���Ҫѭ��(�˺�������©����THREAD_NUM������)
