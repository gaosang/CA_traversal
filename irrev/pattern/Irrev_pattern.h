#pragma once
#include "stdafx.h"
class Irrev_pattern {
public:
	friend std::istream &read(std::istream& in, Irrev_pattern& irrev1);
	friend bool is_sub(Irrev_pattern& irrev1, Irrev_pattern& irrev2);
	friend std::ostream &print(std::ostream &os, const Irrev_pattern &irrev);//打印
	friend std::ostream &print1(std::ostream &os, const Irrev_pattern &irrev);//打印
	friend std::ostream &print2(std::ostream &os, const Irrev_pattern &irrev);//打印
	friend std::ostream &print3(std::ostream &os, const Irrev_pattern &irrev);//打印
	Irrev_pattern() = default;
	Irrev_pattern(std::istream& in);
	int get_r() const { return r; };
	void irrev_lma2ss();//由行最简形矩阵导入基础解系
private:
	int r = 0;
	std::vector<boost::dynamic_bitset<> > irrev_sta;//转移矩阵存在k行相同对应CA的位置
	std::vector<boost::dynamic_bitset<> > irrev_lma;//行最简形矩阵，表示满足sta的方程组的行最简形
	std::vector<boost::dynamic_bitset<> > irrev_ss;//表示满足sta的方程组的基础解系
};
std::istream &read(std::istream& in, Irrev_pattern& irrev1);
bool is_sub(Irrev_pattern& irrev1, Irrev_pattern& irrev2);//判断irrev1的解集是否是irrev2解集的子集
std::ostream &print(std::ostream &os, const Irrev_pattern &irrev);//打印