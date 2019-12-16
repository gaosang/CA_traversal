#include "det_structure_q_5.h"
#include "glo_vars.h"
#include <iostream>
#include <map>
#include <boost/dynamic_bitset.hpp>
int det_structure_q_5(const int m, const int n, const bool(&Pm)[5][5])
{
	static thread_local bool once_initialize = true;//静态变量初始化一次
	static thread_local std::map<int, int> Q_index;//m*n到相应的vector索引
	static thread_local std::vector<std::vector<boost::dynamic_bitset<> > > Q;
	static thread_local std::vector<std::vector<boost::dynamic_bitset<> > > Qa;
	static thread_local std::vector<std::vector<boost::dynamic_bitset<> > > Qa5;
	if (once_initialize)
	{
		//确定索引
		int num_Q = 0;
		for (int i = 1; i <= CA_size; ++i)
		{
			for (int j = 1; j <= CA_size; ++j)
			{
				auto ret = Q_index.insert({ i*j, num_Q });
				if (ret.second)
					++num_Q;
			}
		}
		num_Q = 0;
		for (auto map_it = Q_index.cbegin(); map_it != Q_index.cend(); ++map_it)
		{
			Q_index[map_it->first] = num_Q;
			++num_Q;
		}
		//Q,Qa
		for (auto map_it = Q_index.cbegin(); map_it != Q_index.cend(); ++map_it)
		{
			std::vector<boost::dynamic_bitset<>> Q_tmp1(map_it->first, boost::dynamic_bitset<>(map_it->first));
			Q.push_back(Q_tmp1);
			int sdf;
			std::vector<boost::dynamic_bitset<>> Q_tmp2(5, boost::dynamic_bitset<>(map_it->first));
			Qa.push_back(Q_tmp2);
		}
		//Qa5
		for (int i = 1; i <= CA_size; ++i)
		{
			std::vector<boost::dynamic_bitset<>> Q_tmp(5, boost::dynamic_bitset<>(5 * i));
			Qa5.push_back(Q_tmp);
		}

	}
	once_initialize = false;
	int mn = m*n;
	std::vector<std::vector<boost::dynamic_bitset<> > >::size_type Q_index_mn = Q_index[mn];
	for (auto &bitset_vec : Q[Q_index_mn])
		bitset_vec.reset();
	for (auto &bitset_vec : Qa[Q_index_mn])
		bitset_vec.reset();
	for (auto &bitset_vec : Qa5[n - 1])
		bitset_vec.reset();

	if (m <= 4) {
		switch (n) {
		case 1:
			Qa5[n - 1][0][0] = Pm[0][2];
			Qa5[n - 1][0][n] = Pm[1][2];
			Qa5[n - 1][0][2 * n] = Pm[2][2];
			Qa5[n - 1][0][3 * n] = Pm[3][2];
			Qa5[n - 1][0][4 * n] = Pm[4][2];

			break;
		case 2:

			Qa5[n - 1][0][0] = Pm[0][2]; Qa5[n - 1][0][1] = Pm[0][3];
			Qa5[n - 1][0][n] = Pm[1][2]; Qa5[n - 1][0][n + 1] = Pm[1][3];
			Qa5[n - 1][0][2 * n] = Pm[2][2]; Qa5[n - 1][0][2 * n + 1] = Pm[2][3];
			Qa5[n - 1][0][3 * n] = Pm[3][2]; Qa5[n - 1][0][3 * n + 1] = Pm[3][3];
			Qa5[n - 1][0][4 * n] = Pm[4][2]; Qa5[n - 1][0][4 * n + 1] = Pm[4][3];

			Qa5[n - 1][1][0] = Pm[0][1]; Qa5[n - 1][1][1] = Pm[0][2];
			Qa5[n - 1][1][n] = Pm[1][1]; Qa5[n - 1][1][n + 1] = Pm[1][2];
			Qa5[n - 1][1][2 * n] = Pm[2][1]; Qa5[n - 1][1][2 * n + 1] = Pm[2][2];
			Qa5[n - 1][1][3 * n] = Pm[3][1]; Qa5[n - 1][1][3 * n + 1] = Pm[3][2];
			Qa5[n - 1][1][4 * n] = Pm[4][1]; Qa5[n - 1][1][4 * n + 1] = Pm[4][2];

			break;
		case 3:

			Qa5[n - 1][0][0] = Pm[0][2]; Qa5[n - 1][0][1] = Pm[0][3]; Qa5[n - 1][0][2] = Pm[0][4];
			Qa5[n - 1][0][n] = Pm[1][2]; Qa5[n - 1][0][n + 1] = Pm[1][3]; Qa5[n - 1][0][n + 2] = Pm[1][4];
			Qa5[n - 1][0][2 * n] = Pm[2][2]; Qa5[n - 1][0][2 * n + 1] = Pm[2][3]; Qa5[n - 1][0][2 * n + 2] = Pm[2][4];
			Qa5[n - 1][0][3 * n] = Pm[3][2]; Qa5[n - 1][0][3 * n + 1] = Pm[3][3]; Qa5[n - 1][0][3 * n + 2] = Pm[3][4];
			Qa5[n - 1][0][4 * n] = Pm[4][2]; Qa5[n - 1][0][4 * n + 1] = Pm[4][3]; Qa5[n - 1][0][4 * n + 2] = Pm[4][4];

			Qa5[n - 1][1][0] = Pm[0][1]; Qa5[n - 1][1][1] = Pm[0][2]; Qa5[n - 1][1][2] = Pm[0][3];
			Qa5[n - 1][1][n] = Pm[1][1]; Qa5[n - 1][1][n + 1] = Pm[1][2]; Qa5[n - 1][1][n + 2] = Pm[1][3];
			Qa5[n - 1][1][2 * n] = Pm[2][1]; Qa5[n - 1][1][2 * n + 1] = Pm[2][2]; Qa5[n - 1][1][2 * n + 2] = Pm[2][3];
			Qa5[n - 1][1][3 * n] = Pm[3][1]; Qa5[n - 1][1][3 * n + 1] = Pm[3][2]; Qa5[n - 1][1][3 * n + 2] = Pm[3][3];
			Qa5[n - 1][1][4 * n] = Pm[4][1]; Qa5[n - 1][1][4 * n + 1] = Pm[4][2]; Qa5[n - 1][1][4 * n + 2] = Pm[4][3];

			Qa5[n - 1][2][0] = Pm[0][0]; Qa5[n - 1][2][1] = Pm[0][1]; Qa5[n - 1][2][2] = Pm[0][2];
			Qa5[n - 1][2][n] = Pm[1][0]; Qa5[n - 1][2][n + 1] = Pm[1][1]; Qa5[n - 1][2][n + 2] = Pm[1][2];
			Qa5[n - 1][2][2 * n] = Pm[2][0]; Qa5[n - 1][2][2 * n + 1] = Pm[2][1]; Qa5[n - 1][2][2 * n + 2] = Pm[2][2];
			Qa5[n - 1][2][3 * n] = Pm[3][0]; Qa5[n - 1][2][3 * n + 1] = Pm[3][1]; Qa5[n - 1][2][3 * n + 2] = Pm[3][2];
			Qa5[n - 1][2][4 * n] = Pm[4][0]; Qa5[n - 1][2][4 * n + 1] = Pm[4][1]; Qa5[n - 1][2][4 * n + 2] = Pm[4][2];
			break;
		case 4:
			Qa5[n - 1][0][0] = Pm[0][2]; Qa5[n - 1][0][1] = Pm[0][3]; Qa5[n - 1][0][2] = Pm[0][4];
			Qa5[n - 1][0][n] = Pm[1][2]; Qa5[n - 1][0][n + 1] = Pm[1][3]; Qa5[n - 1][0][n + 2] = Pm[1][4];
			Qa5[n - 1][0][2 * n] = Pm[2][2]; Qa5[n - 1][0][2 * n + 1] = Pm[2][3]; Qa5[n - 1][0][2 * n + 2] = Pm[2][4];
			Qa5[n - 1][0][3 * n] = Pm[3][2]; Qa5[n - 1][0][3 * n + 1] = Pm[3][3]; Qa5[n - 1][0][3 * n + 2] = Pm[3][4];
			Qa5[n - 1][0][4 * n] = Pm[4][2]; Qa5[n - 1][0][4 * n + 1] = Pm[4][3]; Qa5[n - 1][0][4 * n + 2] = Pm[4][4];

			Qa5[n - 1][1][0] = Pm[0][1]; Qa5[n - 1][1][1] = Pm[0][2]; Qa5[n - 1][1][2] = Pm[0][3]; Qa5[n - 1][1][3] = Pm[0][4];
			Qa5[n - 1][1][n] = Pm[1][1]; Qa5[n - 1][1][n + 1] = Pm[1][2]; Qa5[n - 1][1][n + 2] = Pm[1][3]; Qa5[n - 1][1][n + 3] = Pm[1][4];
			Qa5[n - 1][1][2 * n] = Pm[2][1]; Qa5[n - 1][1][2 * n + 1] = Pm[2][2]; Qa5[n - 1][1][2 * n + 2] = Pm[2][3]; Qa5[n - 1][1][2 * n + 3] = Pm[2][4];
			Qa5[n - 1][1][3 * n] = Pm[3][1]; Qa5[n - 1][1][3 * n + 1] = Pm[3][2]; Qa5[n - 1][1][3 * n + 2] = Pm[3][3]; Qa5[n - 1][1][3 * n + 3] = Pm[3][4];
			Qa5[n - 1][1][4 * n] = Pm[4][1]; Qa5[n - 1][1][4 * n + 1] = Pm[4][2]; Qa5[n - 1][1][4 * n + 2] = Pm[4][3]; Qa5[n - 1][1][4 * n + 3] = Pm[4][4];

			Qa5[n - 1][2][0] = Pm[0][0]; Qa5[n - 1][2][1] = Pm[0][1]; Qa5[n - 1][2][2] = Pm[0][2]; Qa5[n - 1][2][3] = Pm[0][3];
			Qa5[n - 1][2][n] = Pm[1][0]; Qa5[n - 1][2][n + 1] = Pm[1][1]; Qa5[n - 1][2][n + 2] = Pm[1][2]; Qa5[n - 1][2][n + 3] = Pm[1][3];
			Qa5[n - 1][2][2 * n] = Pm[2][0]; Qa5[n - 1][2][2 * n + 1] = Pm[2][1]; Qa5[n - 1][2][2 * n + 2] = Pm[2][2]; Qa5[n - 1][2][2 * n + 3] = Pm[2][3];
			Qa5[n - 1][2][3 * n] = Pm[3][0]; Qa5[n - 1][2][3 * n + 1] = Pm[3][1]; Qa5[n - 1][2][3 * n + 2] = Pm[3][2]; Qa5[n - 1][2][3 * n + 3] = Pm[3][3];
			Qa5[n - 1][2][4 * n] = Pm[4][0]; Qa5[n - 1][2][4 * n + 1] = Pm[4][1]; Qa5[n - 1][2][4 * n + 2] = Pm[4][2]; Qa5[n - 1][2][4 * n + 3] = Pm[4][3];

			Qa5[n - 1][4][n - 3] = Pm[0][0]; Qa5[n - 1][4][n - 2] = Pm[0][1]; Qa5[n - 1][4][n - 1] = Pm[0][2];
			Qa5[n - 1][4][2 * n - 3] = Pm[1][0]; Qa5[n - 1][4][2 * n - 2] = Pm[1][1]; Qa5[n - 1][4][2 * n - 1] = Pm[1][2];
			Qa5[n - 1][4][3 * n - 3] = Pm[2][0]; Qa5[n - 1][4][3 * n - 2] = Pm[2][1]; Qa5[n - 1][4][3 * n - 1] = Pm[2][2];
			Qa5[n - 1][4][4 * n - 3] = Pm[3][0]; Qa5[n - 1][4][4 * n - 2] = Pm[3][1]; Qa5[n - 1][4][4 * n - 1] = Pm[3][2];
			Qa5[n - 1][4][5 * n - 3] = Pm[4][0]; Qa5[n - 1][4][5 * n - 2] = Pm[4][1]; Qa5[n - 1][4][5 * n - 1] = Pm[4][2];
			break;
		default:
			Qa5[n - 1][0][0] = Pm[0][2]; Qa5[n - 1][0][1] = Pm[0][3]; Qa5[n - 1][0][2] = Pm[0][4];
			Qa5[n - 1][0][n] = Pm[1][2]; Qa5[n - 1][0][n + 1] = Pm[1][3]; Qa5[n - 1][0][n + 2] = Pm[1][4];
			Qa5[n - 1][0][2 * n] = Pm[2][2]; Qa5[n - 1][0][2 * n + 1] = Pm[2][3]; Qa5[n - 1][0][2 * n + 2] = Pm[2][4];
			Qa5[n - 1][0][3 * n] = Pm[3][2]; Qa5[n - 1][0][3 * n + 1] = Pm[3][3]; Qa5[n - 1][0][3 * n + 2] = Pm[3][4];
			Qa5[n - 1][0][4 * n] = Pm[4][2]; Qa5[n - 1][0][4 * n + 1] = Pm[4][3]; Qa5[n - 1][0][4 * n + 2] = Pm[4][4];

			Qa5[n - 1][1][0] = Pm[0][1]; Qa5[n - 1][1][1] = Pm[0][2]; Qa5[n - 1][1][2] = Pm[0][3]; Qa5[n - 1][1][3] = Pm[0][4];
			Qa5[n - 1][1][n] = Pm[1][1]; Qa5[n - 1][1][n + 1] = Pm[1][2]; Qa5[n - 1][1][n + 2] = Pm[1][3]; Qa5[n - 1][1][n + 3] = Pm[1][4];
			Qa5[n - 1][1][2 * n] = Pm[2][1]; Qa5[n - 1][1][2 * n + 1] = Pm[2][2]; Qa5[n - 1][1][2 * n + 2] = Pm[2][3]; Qa5[n - 1][1][2 * n + 3] = Pm[2][4];
			Qa5[n - 1][1][3 * n] = Pm[3][1]; Qa5[n - 1][1][3 * n + 1] = Pm[3][2]; Qa5[n - 1][1][3 * n + 2] = Pm[3][3]; Qa5[n - 1][1][3 * n + 3] = Pm[3][4];
			Qa5[n - 1][1][4 * n] = Pm[4][1]; Qa5[n - 1][1][4 * n + 1] = Pm[4][2]; Qa5[n - 1][1][4 * n + 2] = Pm[4][3]; Qa5[n - 1][1][4 * n + 3] = Pm[4][4];

			Qa5[n - 1][2][0] = Pm[0][0]; Qa5[n - 1][2][1] = Pm[0][1]; Qa5[n - 1][2][2] = Pm[0][2]; Qa5[n - 1][2][3] = Pm[0][3]; Qa5[n - 1][2][4] = Pm[0][4];
			Qa5[n - 1][2][n] = Pm[1][0]; Qa5[n - 1][2][n + 1] = Pm[1][1]; Qa5[n - 1][2][n + 2] = Pm[1][2]; Qa5[n - 1][2][n + 3] = Pm[1][3]; Qa5[n - 1][2][n + 4] = Pm[1][4];
			Qa5[n - 1][2][2 * n] = Pm[2][0]; Qa5[n - 1][2][2 * n + 1] = Pm[2][1]; Qa5[n - 1][2][2 * n + 2] = Pm[2][2]; Qa5[n - 1][2][2 * n + 3] = Pm[2][3]; Qa5[n - 1][2][2 * n + 4] = Pm[2][4];
			Qa5[n - 1][2][3 * n] = Pm[3][0]; Qa5[n - 1][2][3 * n + 1] = Pm[3][1]; Qa5[n - 1][2][3 * n + 2] = Pm[3][2]; Qa5[n - 1][2][3 * n + 3] = Pm[3][3]; Qa5[n - 1][2][3 * n + 4] = Pm[3][4];
			Qa5[n - 1][2][4 * n] = Pm[4][0]; Qa5[n - 1][2][4 * n + 1] = Pm[4][1]; Qa5[n - 1][2][4 * n + 2] = Pm[4][2]; Qa5[n - 1][2][4 * n + 3] = Pm[4][3]; Qa5[n - 1][2][4 * n + 4] = Pm[4][4];

			Qa5[n - 1][4][n - 4] = Pm[0][0]; Qa5[n - 1][4][n - 3] = Pm[0][1]; Qa5[n - 1][4][n - 2] = Pm[0][2]; Qa5[n - 1][4][n - 1] = Pm[0][3];
			Qa5[n - 1][4][2 * n - 4] = Pm[1][0]; Qa5[n - 1][4][2 * n - 3] = Pm[1][1]; Qa5[n - 1][4][2 * n - 2] = Pm[1][2]; Qa5[n - 1][4][2 * n - 1] = Pm[1][3];
			Qa5[n - 1][4][3 * n - 4] = Pm[2][0]; Qa5[n - 1][4][3 * n - 3] = Pm[2][1]; Qa5[n - 1][4][3 * n - 2] = Pm[2][2]; Qa5[n - 1][4][3 * n - 1] = Pm[2][3];
			Qa5[n - 1][4][4 * n - 4] = Pm[3][0]; Qa5[n - 1][4][4 * n - 3] = Pm[3][1]; Qa5[n - 1][4][4 * n - 2] = Pm[3][2]; Qa5[n - 1][4][4 * n - 1] = Pm[3][3];
			Qa5[n - 1][4][5 * n - 4] = Pm[4][0]; Qa5[n - 1][4][5 * n - 3] = Pm[4][1]; Qa5[n - 1][4][5 * n - 2] = Pm[4][2]; Qa5[n - 1][4][5 * n - 1] = Pm[4][3];

			Qa5[n - 1][3][n - 3] = Pm[0][0]; Qa5[n - 1][3][n - 2] = Pm[0][1]; Qa5[n - 1][3][n - 1] = Pm[0][2];
			Qa5[n - 1][3][2 * n - 3] = Pm[1][0]; Qa5[n - 1][3][2 * n - 2] = Pm[1][1]; Qa5[n - 1][3][2 * n - 1] = Pm[1][2];
			Qa5[n - 1][3][3 * n - 3] = Pm[2][0]; Qa5[n - 1][3][3 * n - 2] = Pm[2][1]; Qa5[n - 1][3][3 * n - 1] = Pm[2][2];
			Qa5[n - 1][3][4 * n - 3] = Pm[3][0]; Qa5[n - 1][3][4 * n - 2] = Pm[3][1]; Qa5[n - 1][3][4 * n - 1] = Pm[3][2];
			Qa5[n - 1][3][5 * n - 3] = Pm[4][0]; Qa5[n - 1][3][5 * n - 2] = Pm[4][1]; Qa5[n - 1][3][5 * n - 1] = Pm[4][2];
			break;
		}
	}
	else {
		switch (n) {
		case 1:
			Qa[Q_index_mn][0][0] = Pm[0][2];
			Qa[Q_index_mn][0][n] = Pm[1][2];
			Qa[Q_index_mn][0][2 * n] = Pm[2][2];
			Qa[Q_index_mn][0][3 * n] = Pm[3][2];
			Qa[Q_index_mn][0][4 * n] = Pm[4][2];

			break;
		case 2:

			Qa[Q_index_mn][0][0] = Pm[0][2]; Qa[Q_index_mn][0][1] = Pm[0][3];
			Qa[Q_index_mn][0][n] = Pm[1][2]; Qa[Q_index_mn][0][n + 1] = Pm[1][3];
			Qa[Q_index_mn][0][2 * n] = Pm[2][2]; Qa[Q_index_mn][0][2 * n + 1] = Pm[2][3];
			Qa[Q_index_mn][0][3 * n] = Pm[3][2]; Qa[Q_index_mn][0][3 * n + 1] = Pm[3][3];
			Qa[Q_index_mn][0][4 * n] = Pm[4][2]; Qa[Q_index_mn][0][4 * n + 1] = Pm[4][3];

			Qa[Q_index_mn][1][0] = Pm[0][1]; Qa[Q_index_mn][1][1] = Pm[0][2];
			Qa[Q_index_mn][1][n] = Pm[1][1]; Qa[Q_index_mn][1][n + 1] = Pm[1][2];
			Qa[Q_index_mn][1][2 * n] = Pm[2][1]; Qa[Q_index_mn][1][2 * n + 1] = Pm[2][2];
			Qa[Q_index_mn][1][3 * n] = Pm[3][1]; Qa[Q_index_mn][1][3 * n + 1] = Pm[3][2];
			Qa[Q_index_mn][1][4 * n] = Pm[4][1]; Qa[Q_index_mn][1][4 * n + 1] = Pm[4][2];

			break;
		case 3:

			Qa[Q_index_mn][0][0] = Pm[0][2]; Qa[Q_index_mn][0][1] = Pm[0][3]; Qa[Q_index_mn][0][2] = Pm[0][4];
			Qa[Q_index_mn][0][n] = Pm[1][2]; Qa[Q_index_mn][0][n + 1] = Pm[1][3]; Qa[Q_index_mn][0][n + 2] = Pm[1][4];
			Qa[Q_index_mn][0][2 * n] = Pm[2][2]; Qa[Q_index_mn][0][2 * n + 1] = Pm[2][3]; Qa[Q_index_mn][0][2 * n + 2] = Pm[2][4];
			Qa[Q_index_mn][0][3 * n] = Pm[3][2]; Qa[Q_index_mn][0][3 * n + 1] = Pm[3][3]; Qa[Q_index_mn][0][3 * n + 2] = Pm[3][4];
			Qa[Q_index_mn][0][4 * n] = Pm[4][2]; Qa[Q_index_mn][0][4 * n + 1] = Pm[4][3]; Qa[Q_index_mn][0][4 * n + 2] = Pm[4][4];

			Qa[Q_index_mn][1][0] = Pm[0][1]; Qa[Q_index_mn][1][1] = Pm[0][2]; Qa[Q_index_mn][1][2] = Pm[0][3];
			Qa[Q_index_mn][1][n] = Pm[1][1]; Qa[Q_index_mn][1][n + 1] = Pm[1][2]; Qa[Q_index_mn][1][n + 2] = Pm[1][3];
			Qa[Q_index_mn][1][2 * n] = Pm[2][1]; Qa[Q_index_mn][1][2 * n + 1] = Pm[2][2]; Qa[Q_index_mn][1][2 * n + 2] = Pm[2][3];
			Qa[Q_index_mn][1][3 * n] = Pm[3][1]; Qa[Q_index_mn][1][3 * n + 1] = Pm[3][2]; Qa[Q_index_mn][1][3 * n + 2] = Pm[3][3];
			Qa[Q_index_mn][1][4 * n] = Pm[4][1]; Qa[Q_index_mn][1][4 * n + 1] = Pm[4][2]; Qa[Q_index_mn][1][4 * n + 2] = Pm[4][3];

			Qa[Q_index_mn][2][0] = Pm[0][0]; Qa[Q_index_mn][2][1] = Pm[0][1]; Qa[Q_index_mn][2][2] = Pm[0][2];
			Qa[Q_index_mn][2][n] = Pm[1][0]; Qa[Q_index_mn][2][n + 1] = Pm[1][1]; Qa[Q_index_mn][2][n + 2] = Pm[1][2];
			Qa[Q_index_mn][2][2 * n] = Pm[2][0]; Qa[Q_index_mn][2][2 * n + 1] = Pm[2][1]; Qa[Q_index_mn][2][2 * n + 2] = Pm[2][2];
			Qa[Q_index_mn][2][3 * n] = Pm[3][0]; Qa[Q_index_mn][2][3 * n + 1] = Pm[3][1]; Qa[Q_index_mn][2][3 * n + 2] = Pm[3][2];
			Qa[Q_index_mn][2][4 * n] = Pm[4][0]; Qa[Q_index_mn][2][4 * n + 1] = Pm[4][1]; Qa[Q_index_mn][2][4 * n + 2] = Pm[4][2];
			break;
		case 4:
			Qa[Q_index_mn][0][0] = Pm[0][2]; Qa[Q_index_mn][0][1] = Pm[0][3]; Qa[Q_index_mn][0][2] = Pm[0][4];
			Qa[Q_index_mn][0][n] = Pm[1][2]; Qa[Q_index_mn][0][n + 1] = Pm[1][3]; Qa[Q_index_mn][0][n + 2] = Pm[1][4];
			Qa[Q_index_mn][0][2 * n] = Pm[2][2]; Qa[Q_index_mn][0][2 * n + 1] = Pm[2][3]; Qa[Q_index_mn][0][2 * n + 2] = Pm[2][4];
			Qa[Q_index_mn][0][3 * n] = Pm[3][2]; Qa[Q_index_mn][0][3 * n + 1] = Pm[3][3]; Qa[Q_index_mn][0][3 * n + 2] = Pm[3][4];
			Qa[Q_index_mn][0][4 * n] = Pm[4][2]; Qa[Q_index_mn][0][4 * n + 1] = Pm[4][3]; Qa[Q_index_mn][0][4 * n + 2] = Pm[4][4];

			Qa[Q_index_mn][1][0] = Pm[0][1]; Qa[Q_index_mn][1][1] = Pm[0][2]; Qa[Q_index_mn][1][2] = Pm[0][3]; Qa[Q_index_mn][1][3] = Pm[0][4];
			Qa[Q_index_mn][1][n] = Pm[1][1]; Qa[Q_index_mn][1][n + 1] = Pm[1][2]; Qa[Q_index_mn][1][n + 2] = Pm[1][3]; Qa[Q_index_mn][1][n + 3] = Pm[1][4];
			Qa[Q_index_mn][1][2 * n] = Pm[2][1]; Qa[Q_index_mn][1][2 * n + 1] = Pm[2][2]; Qa[Q_index_mn][1][2 * n + 2] = Pm[2][3]; Qa[Q_index_mn][1][2 * n + 3] = Pm[2][4];
			Qa[Q_index_mn][1][3 * n] = Pm[3][1]; Qa[Q_index_mn][1][3 * n + 1] = Pm[3][2]; Qa[Q_index_mn][1][3 * n + 2] = Pm[3][3]; Qa[Q_index_mn][1][3 * n + 3] = Pm[3][4];
			Qa[Q_index_mn][1][4 * n] = Pm[4][1]; Qa[Q_index_mn][1][4 * n + 1] = Pm[4][2]; Qa[Q_index_mn][1][4 * n + 2] = Pm[4][3]; Qa[Q_index_mn][1][4 * n + 3] = Pm[4][4];

			Qa[Q_index_mn][2][0] = Pm[0][0]; Qa[Q_index_mn][2][1] = Pm[0][1]; Qa[Q_index_mn][2][2] = Pm[0][2]; Qa[Q_index_mn][2][3] = Pm[0][3];
			Qa[Q_index_mn][2][n] = Pm[1][0]; Qa[Q_index_mn][2][n + 1] = Pm[1][1]; Qa[Q_index_mn][2][n + 2] = Pm[1][2]; Qa[Q_index_mn][2][n + 3] = Pm[1][3];
			Qa[Q_index_mn][2][2 * n] = Pm[2][0]; Qa[Q_index_mn][2][2 * n + 1] = Pm[2][1]; Qa[Q_index_mn][2][2 * n + 2] = Pm[2][2]; Qa[Q_index_mn][2][2 * n + 3] = Pm[2][3];
			Qa[Q_index_mn][2][3 * n] = Pm[3][0]; Qa[Q_index_mn][2][3 * n + 1] = Pm[3][1]; Qa[Q_index_mn][2][3 * n + 2] = Pm[3][2]; Qa[Q_index_mn][2][3 * n + 3] = Pm[3][3];
			Qa[Q_index_mn][2][4 * n] = Pm[4][0]; Qa[Q_index_mn][2][4 * n + 1] = Pm[4][1]; Qa[Q_index_mn][2][4 * n + 2] = Pm[4][2]; Qa[Q_index_mn][2][4 * n + 3] = Pm[4][3];

			Qa[Q_index_mn][3][n - 3] = Pm[0][0]; Qa[Q_index_mn][3][n - 2] = Pm[0][1]; Qa[Q_index_mn][3][n - 1] = Pm[0][2];
			Qa[Q_index_mn][3][2 * n - 3] = Pm[1][0]; Qa[Q_index_mn][3][2 * n - 2] = Pm[1][1]; Qa[Q_index_mn][3][2 * n - 1] = Pm[1][2];
			Qa[Q_index_mn][3][3 * n - 3] = Pm[2][0]; Qa[Q_index_mn][3][3 * n - 2] = Pm[2][1]; Qa[Q_index_mn][3][3 * n - 1] = Pm[2][2];
			Qa[Q_index_mn][3][4 * n - 3] = Pm[3][0]; Qa[Q_index_mn][3][4 * n - 2] = Pm[3][1]; Qa[Q_index_mn][3][4 * n - 1] = Pm[3][2];
			Qa[Q_index_mn][3][5 * n - 3] = Pm[4][0]; Qa[Q_index_mn][3][5 * n - 2] = Pm[4][1]; Qa[Q_index_mn][3][5 * n - 1] = Pm[4][2];

			break;
		default:
			Qa[Q_index_mn][0][0] = Pm[0][2]; Qa[Q_index_mn][0][1] = Pm[0][3]; Qa[Q_index_mn][0][2] = Pm[0][4];
			Qa[Q_index_mn][0][n] = Pm[1][2]; Qa[Q_index_mn][0][n + 1] = Pm[1][3]; Qa[Q_index_mn][0][n + 2] = Pm[1][4];
			Qa[Q_index_mn][0][2 * n] = Pm[2][2]; Qa[Q_index_mn][0][2 * n + 1] = Pm[2][3]; Qa[Q_index_mn][0][2 * n + 2] = Pm[2][4];
			Qa[Q_index_mn][0][3 * n] = Pm[3][2]; Qa[Q_index_mn][0][3 * n + 1] = Pm[3][3]; Qa[Q_index_mn][0][3 * n + 2] = Pm[3][4];
			Qa[Q_index_mn][0][4 * n] = Pm[4][2]; Qa[Q_index_mn][0][4 * n + 1] = Pm[4][3]; Qa[Q_index_mn][0][4 * n + 2] = Pm[4][4];

			Qa[Q_index_mn][1][0] = Pm[0][1]; Qa[Q_index_mn][1][1] = Pm[0][2]; Qa[Q_index_mn][1][2] = Pm[0][3]; Qa[Q_index_mn][1][3] = Pm[0][4];
			Qa[Q_index_mn][1][n] = Pm[1][1]; Qa[Q_index_mn][1][n + 1] = Pm[1][2]; Qa[Q_index_mn][1][n + 2] = Pm[1][3]; Qa[Q_index_mn][1][n + 3] = Pm[1][4];
			Qa[Q_index_mn][1][2 * n] = Pm[2][1]; Qa[Q_index_mn][1][2 * n + 1] = Pm[2][2]; Qa[Q_index_mn][1][2 * n + 2] = Pm[2][3]; Qa[Q_index_mn][1][2 * n + 3] = Pm[2][4];
			Qa[Q_index_mn][1][3 * n] = Pm[3][1]; Qa[Q_index_mn][1][3 * n + 1] = Pm[3][2]; Qa[Q_index_mn][1][3 * n + 2] = Pm[3][3]; Qa[Q_index_mn][1][3 * n + 3] = Pm[3][4];
			Qa[Q_index_mn][1][4 * n] = Pm[4][1]; Qa[Q_index_mn][1][4 * n + 1] = Pm[4][2]; Qa[Q_index_mn][1][4 * n + 2] = Pm[4][3]; Qa[Q_index_mn][1][4 * n + 3] = Pm[4][4];

			Qa[Q_index_mn][2][0] = Pm[0][0]; Qa[Q_index_mn][2][1] = Pm[0][1]; Qa[Q_index_mn][2][2] = Pm[0][2]; Qa[Q_index_mn][2][3] = Pm[0][3]; Qa[Q_index_mn][2][4] = Pm[0][4];
			Qa[Q_index_mn][2][n] = Pm[1][0]; Qa[Q_index_mn][2][n + 1] = Pm[1][1]; Qa[Q_index_mn][2][n + 2] = Pm[1][2]; Qa[Q_index_mn][2][n + 3] = Pm[1][3]; Qa[Q_index_mn][2][n + 4] = Pm[1][4];
			Qa[Q_index_mn][2][2 * n] = Pm[2][0]; Qa[Q_index_mn][2][2 * n + 1] = Pm[2][1]; Qa[Q_index_mn][2][2 * n + 2] = Pm[2][2]; Qa[Q_index_mn][2][2 * n + 3] = Pm[2][3]; Qa[Q_index_mn][2][2 * n + 4] = Pm[2][4];
			Qa[Q_index_mn][2][3 * n] = Pm[3][0]; Qa[Q_index_mn][2][3 * n + 1] = Pm[3][1]; Qa[Q_index_mn][2][3 * n + 2] = Pm[3][2]; Qa[Q_index_mn][2][3 * n + 3] = Pm[3][3]; Qa[Q_index_mn][2][3 * n + 4] = Pm[3][4];
			Qa[Q_index_mn][2][4 * n] = Pm[4][0]; Qa[Q_index_mn][2][4 * n + 1] = Pm[4][1]; Qa[Q_index_mn][2][4 * n + 2] = Pm[4][2]; Qa[Q_index_mn][2][4 * n + 3] = Pm[4][3]; Qa[Q_index_mn][2][4 * n + 4] = Pm[4][4];

			Qa[Q_index_mn][3][n - 4] = Pm[0][0]; Qa[Q_index_mn][3][n - 3] = Pm[0][1]; Qa[Q_index_mn][3][n - 2] = Pm[0][2]; Qa[Q_index_mn][3][n - 1] = Pm[0][3];
			Qa[Q_index_mn][3][2 * n - 4] = Pm[1][0]; Qa[Q_index_mn][3][2 * n - 3] = Pm[1][1]; Qa[Q_index_mn][3][2 * n - 2] = Pm[1][2]; Qa[Q_index_mn][3][2 * n - 1] = Pm[1][3];
			Qa[Q_index_mn][3][3 * n - 4] = Pm[2][0]; Qa[Q_index_mn][3][3 * n - 3] = Pm[2][1]; Qa[Q_index_mn][3][3 * n - 2] = Pm[2][2]; Qa[Q_index_mn][3][3 * n - 1] = Pm[2][3];
			Qa[Q_index_mn][3][4 * n - 4] = Pm[3][0]; Qa[Q_index_mn][3][4 * n - 3] = Pm[3][1]; Qa[Q_index_mn][3][4 * n - 2] = Pm[3][2]; Qa[Q_index_mn][3][4 * n - 1] = Pm[3][3];
			Qa[Q_index_mn][3][5 * n - 4] = Pm[4][0]; Qa[Q_index_mn][3][5 * n - 3] = Pm[4][1]; Qa[Q_index_mn][3][5 * n - 2] = Pm[4][2]; Qa[Q_index_mn][3][5 * n - 1] = Pm[4][3];

			Qa[Q_index_mn][4][n - 3] = Pm[0][0]; Qa[Q_index_mn][4][n - 2] = Pm[0][1]; Qa[Q_index_mn][4][n - 1] = Pm[0][2];
			Qa[Q_index_mn][4][2 * n - 3] = Pm[1][0]; Qa[Q_index_mn][4][2 * n - 2] = Pm[1][1]; Qa[Q_index_mn][4][2 * n - 1] = Pm[1][2];
			Qa[Q_index_mn][4][3 * n - 3] = Pm[2][0]; Qa[Q_index_mn][4][3 * n - 2] = Pm[2][1]; Qa[Q_index_mn][4][3 * n - 1] = Pm[2][2];
			Qa[Q_index_mn][4][4 * n - 3] = Pm[3][0]; Qa[Q_index_mn][4][4 * n - 2] = Pm[3][1]; Qa[Q_index_mn][4][4 * n - 1] = Pm[3][2];
			Qa[Q_index_mn][4][5 * n - 3] = Pm[4][0]; Qa[Q_index_mn][4][5 * n - 2] = Pm[4][1]; Qa[Q_index_mn][4][5 * n - 1] = Pm[4][2];
			break;
		}
	}
	if (m <= 4) {
		for (std::vector<boost::dynamic_bitset<>>::size_type i = 0; i < m; ++i) {
			if (i == 0)
				for (std::vector<boost::dynamic_bitset<>>::size_type j = 0; j < n; ++j)
					if (j == 0)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][0];
						Q[Q_index_mn][i*n + j] >>= 2 * n;
					}
					else if (j == 1)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][1];
						Q[Q_index_mn][i*n + j] >>= 2 * n;
					}
					else if (j <= n - 3 || j == 2)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][2];
						Q[Q_index_mn][i*n + j] >>= 2 * n;
						Q[Q_index_mn][i*n + j] <<= j - 2;
					}
					else if (j == n - 2 || j == 3)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][4];
						Q[Q_index_mn][i*n + j] >>= 2 * n;
					}
					else //(j=n-1)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][3];
						Q[Q_index_mn][i*n + j] >>= 2 * n;
					}
			else if (i == 1)
				for (std::vector<boost::dynamic_bitset<>>::size_type j = 0; j < n; ++j)
					if (j == 0)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][0];
						Q[Q_index_mn][i*n + j] >>= n;
					}
					else if (j == 1)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][1];
						Q[Q_index_mn][i*n + j] >>= n;
					}
					else if (j <= n - 3 || j == 2)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][2];
						Q[Q_index_mn][i*n + j] >>= n;
						Q[Q_index_mn][i*n + j] <<= j - 2;
					}
					else if (j == n - 2 || j == 3)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][4];
						Q[Q_index_mn][i*n + j] >>= n;
					}
					else //(j=n-1)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][3];
						Q[Q_index_mn][i*n + j] >>= n;
					}
			else if (i == 2)
				for (std::vector<boost::dynamic_bitset<>>::size_type j = 0; j < n; ++j)
					if (j == 0)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][0];
						Q[Q_index_mn][i*n + j] <<= (i - 2)*n;
					}
					else if (j == 1)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][1];
						Q[Q_index_mn][i*n + j] <<= (i - 2)*n;
					}
					else if (j <= n - 3 || j == 2)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][2];
						Q[Q_index_mn][i*n + j] <<= (i - 2)*n + j - 2;
					}
					else if (j == n - 2 || j == 3)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][4];
						Q[Q_index_mn][i*n + j] <<= (i - 2)*n;
					}
					else //(j=n-1)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][3];
						Q[Q_index_mn][i*n + j] <<= (i - 2)*n;
					}
			else if (i == 3)
				for (std::vector<boost::dynamic_bitset<>>::size_type j = 0; j < n; ++j)
					if (j == 0)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][0];
						Q[Q_index_mn][i*n + j] <<= n;
					}
					else if (j == 1)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][1];
						Q[Q_index_mn][i*n + j] <<= n;
					}
					else if (j <= n - 3 || j == 2)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][2];
						Q[Q_index_mn][i*n + j] <<= n + j - 2;
					}
					else if (j == n - 2 || j == 3)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][4];
						Q[Q_index_mn][i*n + j] <<= n;
					}
					else //(j=n-1)
					{
						Q[Q_index_mn][i*n + j] = Qa5[n - 1][3];
						Q[Q_index_mn][i*n + j] <<= n;
					}
		}
	}
	else {
		for (std::vector<boost::dynamic_bitset<>>::size_type i = 0; i < m; ++i) {
			if (i == 0)
				for (std::vector<boost::dynamic_bitset<>>::size_type j = 0; j < n; ++j)
					if (j == 0)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][0];
						Q[Q_index_mn][i*n + j] >>= 2 * n;
					}
					else if (j == 1)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][1];
						Q[Q_index_mn][i*n + j]>>= 2 * n;
					}
					else if (j <= n - 3 || j == 2)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][2];
						Q[Q_index_mn][i*n + j] >>= 2 * n;
						Q[Q_index_mn][i*n + j] <<= j - 2;
					}
					else if (j == n - 2 || j == 3)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][3];
						Q[Q_index_mn][i*n + j] >>= 2 * n;
					}
					else //(j=n-1)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][4];
						Q[Q_index_mn][i*n + j] >>= 2 * n;
					}
			else if (i == 1)
				for (std::vector<boost::dynamic_bitset<>>::size_type j = 0; j < n; ++j)
					if (j == 0)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][0];
						Q[Q_index_mn][i*n + j] >>= n;
					}
					else if (j == 1)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][1];
						Q[Q_index_mn][i*n + j] >>= n;
					}
					else if (j <= n - 3 || j == 2)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][2];
						Q[Q_index_mn][i*n + j] >>= n;
						Q[Q_index_mn][i*n + j] <<= j - 2;
					}
					else if (j == n - 2 || j == 3)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][3];
						Q[Q_index_mn][i*n + j] >>= n;
					}
					else //(j=n-1)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][4];
						Q[Q_index_mn][i*n + j] >>= n;
					}
			else if (i <= m - 3)
				for (std::vector<boost::dynamic_bitset<>>::size_type j = 0; j < n; ++j)
					if (j == 0)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][0];
						Q[Q_index_mn][i*n + j] <<= (i - 2)*n;
					}
					else if (j == 1)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][1];
						Q[Q_index_mn][i*n + j] <<= (i - 2)*n;
					}
					else if (j <= n - 3 || j == 2)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][2];
						Q[Q_index_mn][i*n + j] <<= (i - 2)*n + j - 2;
					}
					else if (j == n - 2 || j == 3)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][3];
						Q[Q_index_mn][i*n + j] <<= (i - 2)*n;
					}
					else //(j=n-1)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][4];
						Q[Q_index_mn][i*n + j] <<= (i - 2)*n;
					}
			else if (i == m - 2)
				for (std::vector<boost::dynamic_bitset<>>::size_type j = 0; j < n; ++j)
					if (j == 0)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][0];
						Q[Q_index_mn][i*n + j] <<= (m - 4)*n;
					}
					else if (j == 1)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][1];
						Q[Q_index_mn][i*n + j] <<= (m - 4)*n;
					}
					else if (j <= n - 3 || j == 2)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][2];
						Q[Q_index_mn][i*n + j] <<= (m - 4)*n + j - 2;
					}
					else if (j == n - 2 || j == 3)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][3];
						Q[Q_index_mn][i*n + j] <<= (m - 4)*n;
					}
					else //(j=n-1)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][4];
						Q[Q_index_mn][i*n + j] <<= (m - 4)*n;
					}
			else//(i=m-1)
				for (std::vector<boost::dynamic_bitset<>>::size_type j = 0; j < n; ++j)
					if (j == 0)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][0];
						Q[Q_index_mn][i*n + j] <<= (m - 3)*n;
					}
					else if (j == 1)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][1];
						Q[Q_index_mn][i*n + j] <<= (m - 3)*n;
					}
					else if (j <= n - 3 || j == 2)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][2];
						Q[Q_index_mn][i*n + j] <<= (m - 3)*n + j - 2;
					}
					else if (j == n - 2 || j == 3)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][3];
						Q[Q_index_mn][i*n + j] <<= (m - 3)*n;
					}
					else //(j=n-1)
					{
						Q[Q_index_mn][i*n + j] = Qa[Q_index_mn][4];
						Q[Q_index_mn][i*n + j] <<= (m - 3)*n;
					}
		}
	}

	//计算行列式
	for (std::vector<boost::dynamic_bitset<>>::size_type i = 0; i < mn; ++i)
	{
		if (!Q[Q_index_mn][i][i]) {
			for (std::vector<boost::dynamic_bitset<>>::size_type j = 1; j <= 2 * n + 2; ++j)
			{
				if (i + j < n*m)
				{
					if (Q[Q_index_mn][i + j][i])
					{
						Q[Q_index_mn][i] ^= Q[Q_index_mn][i + j];
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		if (Q[Q_index_mn][i][i])
		{
			for (std::vector<boost::dynamic_bitset<>>::size_type j = 1; j <= 2 * n + 2; ++j)
			{
				if (i + j < n*m)
				{
					if (Q[Q_index_mn][i + j][i])
					{
						Q[Q_index_mn][i + j] ^= Q[Q_index_mn][i];
					}
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			return 0;
			break;
		}
		if (i == mn - 1)
		{
			if (Q[Q_index_mn][i][i])
			{
				return 1;
			}
		}
	}
	return 0;
}
