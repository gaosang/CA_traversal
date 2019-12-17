#pragma once
#include "glo_vars.h"
#include <boost/dynamic_bitset.hpp>
//加n函数，遍历时使用(n应为线程数)
void bit_add_n(bool (&bitvec)[ca_size][ca_size], const int n = 1);
//计算1的个数
int bit_count(bool bitvec[ca_size][ca_size]);
//比较大小，索引越小，其比特位越低
bool is_less(const bool (&bitvec1)[ca_size][ca_size], const bool(&bitvec2)[ca_size][ca_size]);
//通过8种对称操作，判断之一规则是否曾经计算过
bool is_caled(const bool (&bitvec)[ca_size][ca_size]);
//if2判断是否需要计算
bool is_Ntril(const bool( &bitvec)[ca_size][ca_size]);
//把5*5形式转化为25形式
void change_5_5to25(boost::dynamic_bitset<>& bitvec1, const bool(&bitvec2)[5][5]);
//清零
void co_reset(bool(&bitvec)[5][5]);
//bit转为字符串
std::string bit2str(const bool(&bitvec)[ca_size][ca_size]);
//dynamic_bitset2string 低位到低位
std::string co_to_string(boost::dynamic_bitset<>& bitvec);
//判断细胞自动机右边界和下边界两行以内是否存在元素，不存在返回true
bool end_in_b2_2(const bool(&bitvec)[ca_size][ca_size]);
//判断此结果是否需要输出
bool is_out_Ntri(const std::vector<boost::dynamic_bitset<> > (&co_mat));
//赋值，1赋给2
void assign1to2(const bool(&bitvec1)[5][5], bool(&bitvec2)[5][5]);
//加n函数，遍历时使用(n应为线程数)(不考虑右边界和下边界的俩行元素)
void bit_add_n_2_2(bool(&bitvec)[ca_size][ca_size], const int n = 1);

//调试用函数
bool stop_cdt(const bool(&bitvec)[ca_size][ca_size]);