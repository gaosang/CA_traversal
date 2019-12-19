#pragma once
#include "stdafx.h"
class Irrev_pattern {
public:
	friend std::istream &read(std::istream& in, Irrev_pattern& irrev1);
	friend bool is_sub(Irrev_pattern& irrev1, Irrev_pattern& irrev2);
	friend std::ostream &print(std::ostream &os, const Irrev_pattern &irrev);//��ӡ
	friend std::ostream &print1(std::ostream &os, const Irrev_pattern &irrev);//��ӡ
	friend std::ostream &print2(std::ostream &os, const Irrev_pattern &irrev);//��ӡ
	friend std::ostream &print3(std::ostream &os, const Irrev_pattern &irrev);//��ӡ
	Irrev_pattern() = default;
	Irrev_pattern(std::istream& in);
	int get_r() const { return r; };
	void irrev_lma2ss();//��������ξ����������ϵ
private:
	int r = 0;
	std::vector<boost::dynamic_bitset<> > irrev_sta;//ת�ƾ������k����ͬ��ӦCA��λ��
	std::vector<boost::dynamic_bitset<> > irrev_lma;//������ξ��󣬱�ʾ����sta�ķ�������������
	std::vector<boost::dynamic_bitset<> > irrev_ss;//��ʾ����sta�ķ�����Ļ�����ϵ
};
std::istream &read(std::istream& in, Irrev_pattern& irrev1);
bool is_sub(Irrev_pattern& irrev1, Irrev_pattern& irrev2);//�ж�irrev1�Ľ⼯�Ƿ���irrev2�⼯���Ӽ�
std::ostream &print(std::ostream &os, const Irrev_pattern &irrev);//��ӡ