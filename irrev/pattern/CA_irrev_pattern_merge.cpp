#include "stdafx.h"
#include "Irrev_pattern.h"
int main() {
	std::ifstream in("out.txt");
	std::forward_list<Irrev_pattern>  ir_pt;
	Irrev_pattern tmp1;
	if (read(in, tmp1))
	{
		auto prev = ir_pt.before_begin();
		ir_pt.insert_after(prev, tmp1);
	}
	while (1)
	{
		Irrev_pattern tmp(in);
		if (!in)//�ļ��Ѷ���
		{
			break;
		}
		//1�Ƿ���ڰ���tmp������
		bool flag = false;
		for (auto &ir_it : ir_pt)
		{
			if (is_sub(tmp, ir_it))
			{
				flag = true;
				break;
			}
		}
		if (flag)
			continue;
		//2tmp�Ƿ����ir_pt��ĳЩ����
		auto prev = ir_pt.before_begin();
		auto curr = ir_pt.begin();
		while (curr != ir_pt.end())
		{
			if (is_sub(*curr, tmp))
			{
				curr = ir_pt.erase_after(prev);
			}
			else
			{
				prev = curr;
				++curr;
			}
		}
		prev = ir_pt.before_begin();
		ir_pt.insert_after(prev, tmp);
	}
	std::ofstream out("out_result.txt");//���ļ���
	for (auto &ir_it : ir_pt)
	{
		print(out, ir_it);
	}
	return 0;
}