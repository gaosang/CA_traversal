#pragma once
#include "glo_vars.h"
void bit_add_n(bool (&bitvec)[5][5]); //加1函数，遍历时使用
void bit_add_n(bool (&bitvec)[5][5], const int n);//加n函数，遍历时使用(n应为线程数)
int bit_count(bool (&bitvec)[5][5]); //计算1的个数
int bit_count(int bitvec[CA_size][CA_size]);
bool is_less(const bool(&bitvec1)[5][5], const bool(&bitvec2)[5][5]);//比较大小，索引越小，其比特位越低
bool is_caled(const bool(&bitvec)[5][5]);//通过8种对称操作，判断之一规则是否曾经计算过
void Pm_cout(const bool(&bitvec)[5][5]);//输出规则
bool is_Utrimtx(const bool(&bitvec)[5][5]);//判断是否是上三角矩阵
std::string bit2str(const bool(&bitvec)[5][5]);//bit转为字符串
bool mt_cir_all(const bool(&bitvec)[5][5], int thread_num1);//判断是否仍要循环(此函数会遗漏最后的THREAD_NUM种情形)
