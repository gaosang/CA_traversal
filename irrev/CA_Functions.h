#pragma once
#include "glo_vars.h"
#include <boost/dynamic_bitset.hpp>
//��n����������ʱʹ��(nӦΪ�߳���)
void bit_add_n(bool (&bitvec)[ca_size][ca_size], const int n = 1);
//����1�ĸ���
int bit_count(bool bitvec[ca_size][ca_size]);
//�Ƚϴ�С������ԽС�������λԽ��
bool is_less(const bool (&bitvec1)[ca_size][ca_size], const bool(&bitvec2)[ca_size][ca_size]);
//ͨ��8�ֶԳƲ������ж�֮һ�����Ƿ����������
bool is_caled(const bool (&bitvec)[ca_size][ca_size]);
//if2�ж��Ƿ���Ҫ����
bool is_Ntril(const bool( &bitvec)[ca_size][ca_size]);
//��5*5��ʽת��Ϊ25��ʽ
void change_5_5to25(boost::dynamic_bitset<>& bitvec1, const bool(&bitvec2)[5][5]);
//����
void co_reset(bool(&bitvec)[5][5]);
//bitתΪ�ַ���
std::string bit2str(const bool(&bitvec)[ca_size][ca_size]);
//dynamic_bitset2string ��λ����λ
std::string co_to_string(boost::dynamic_bitset<>& bitvec);
//�ж�ϸ���Զ����ұ߽���±߽����������Ƿ����Ԫ�أ������ڷ���true
bool end_in_b2_2(const bool(&bitvec)[ca_size][ca_size]);
//�жϴ˽���Ƿ���Ҫ���
bool is_out_Ntri(const std::vector<boost::dynamic_bitset<> > (&co_mat));
//��ֵ��1����2
void assign1to2(const bool(&bitvec1)[5][5], bool(&bitvec2)[5][5]);
//��n����������ʱʹ��(nӦΪ�߳���)(�������ұ߽���±߽������Ԫ��)
void bit_add_n_2_2(bool(&bitvec)[ca_size][ca_size], const int n = 1);

//�����ú���
bool stop_cdt(const bool(&bitvec)[ca_size][ca_size]);