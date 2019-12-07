#include "stdafx.h"
#include "det_structure_q_5.h"
#include <boost/dynamic_bitset.hpp>
int det_structure_q_5(const int m, const int n, const int Pm[][5])
{
	//构造五等对角分块矩阵

//构造ABCDE的一行
	boost::dynamic_bitset<> q_a_1(n*m);
	boost::dynamic_bitset<> q_a_2(n*m);
	boost::dynamic_bitset<> q_a(n*m);
	boost::dynamic_bitset<> q_a_n_1(n*m);
	boost::dynamic_bitset<> q_a_n(n*m);
	boost::dynamic_bitset<> q_a_15(5 * n);
	boost::dynamic_bitset<> q_a_25(5 * n);
	boost::dynamic_bitset<> q_a5(5 * n);
	boost::dynamic_bitset<> q_a_n5(5 * n);
	boost::dynamic_bitset<> q_a_n_15(5 * n);
	std::vector<boost::dynamic_bitset<>> Q(m*n, boost::dynamic_bitset<>(m*n));

	if (m <= 4) {
		switch (n) {
		case 1:
			q_a_15[0] = Pm[0][2];
			q_a_15[n] = Pm[1][2];
			q_a_15[2 * n] = Pm[2][2];
			q_a_15[3 * n] = Pm[3][2];
			q_a_15[4 * n] = Pm[4][2];

			break;
		case 2:

			q_a_15[0] = Pm[0][2]; q_a_15[1] = Pm[0][3];
			q_a_15[n] = Pm[1][2]; q_a_15[n + 1] = Pm[1][3];
			q_a_15[2 * n] = Pm[2][2]; q_a_15[2 * n + 1] = Pm[2][3];
			q_a_15[3 * n] = Pm[3][2]; q_a_15[3 * n + 1] = Pm[3][3];
			q_a_15[4 * n] = Pm[4][2]; q_a_15[4 * n + 1] = Pm[4][3];

			q_a_25[0] = Pm[0][1]; q_a_25[1] = Pm[0][2];
			q_a_25[n] = Pm[1][1]; q_a_25[n + 1] = Pm[1][2];
			q_a_25[2 * n] = Pm[2][1]; q_a_25[2 * n + 1] = Pm[2][2];
			q_a_25[3 * n] = Pm[3][1]; q_a_25[3 * n + 1] = Pm[3][2];
			q_a_25[4 * n] = Pm[4][1]; q_a_25[4 * n + 1] = Pm[4][2];

			break;
		case 3:

			q_a_15[0] = Pm[0][2]; q_a_15[1] = Pm[0][3]; q_a_15[2] = Pm[0][4];
			q_a_15[n] = Pm[1][2]; q_a_15[n + 1] = Pm[1][3]; q_a_15[n + 2] = Pm[1][4];
			q_a_15[2 * n] = Pm[2][2]; q_a_15[2 * n + 1] = Pm[2][3]; q_a_15[2 * n + 2] = Pm[2][4];
			q_a_15[3 * n] = Pm[3][2]; q_a_15[3 * n + 1] = Pm[3][3]; q_a_15[3 * n + 2] = Pm[3][4];
			q_a_15[4 * n] = Pm[4][2]; q_a_15[4 * n + 1] = Pm[4][3]; q_a_15[4 * n + 2] = Pm[4][4];

			q_a_25[0] = Pm[0][1]; q_a_25[1] = Pm[0][2]; q_a_25[2] = Pm[0][3];
			q_a_25[n] = Pm[1][1]; q_a_25[n + 1] = Pm[1][2]; q_a_25[n + 2] = Pm[1][3];
			q_a_25[2 * n] = Pm[2][1]; q_a_25[2 * n + 1] = Pm[2][2]; q_a_25[2 * n + 2] = Pm[2][3];
			q_a_25[3 * n] = Pm[3][1]; q_a_25[3 * n + 1] = Pm[3][2]; q_a_25[3 * n + 2] = Pm[3][3];
			q_a_25[4 * n] = Pm[4][1]; q_a_25[4 * n + 1] = Pm[4][2]; q_a_25[4 * n + 2] = Pm[4][3];

			q_a5[0] = Pm[0][0]; q_a5[1] = Pm[0][1]; q_a5[2] = Pm[0][2];
			q_a5[n] = Pm[1][0]; q_a5[n + 1] = Pm[1][1]; q_a5[n + 2] = Pm[1][2];
			q_a5[2 * n] = Pm[2][0]; q_a5[2 * n + 1] = Pm[2][1]; q_a5[2 * n + 2] = Pm[2][2];
			q_a5[3 * n] = Pm[3][0]; q_a5[3 * n + 1] = Pm[3][1]; q_a5[3 * n + 2] = Pm[3][2];
			q_a5[4 * n] = Pm[4][0]; q_a5[4 * n + 1] = Pm[4][1]; q_a5[4 * n + 2] = Pm[4][2];
			break;
		case 4:
			q_a_15[0] = Pm[0][2]; q_a_15[1] = Pm[0][3]; q_a_15[2] = Pm[0][4];
			q_a_15[n] = Pm[1][2]; q_a_15[n + 1] = Pm[1][3]; q_a_15[n + 2] = Pm[1][4];
			q_a_15[2 * n] = Pm[2][2]; q_a_15[2 * n + 1] = Pm[2][3]; q_a_15[2 * n + 2] = Pm[2][4];
			q_a_15[3 * n] = Pm[3][2]; q_a_15[3 * n + 1] = Pm[3][3]; q_a_15[3 * n + 2] = Pm[3][4];
			q_a_15[4 * n] = Pm[4][2]; q_a_15[4 * n + 1] = Pm[4][3]; q_a_15[4 * n + 2] = Pm[4][4];

			q_a_25[0] = Pm[0][1]; q_a_25[1] = Pm[0][2]; q_a_25[2] = Pm[0][3]; q_a_25[3] = Pm[0][4];
			q_a_25[n] = Pm[1][1]; q_a_25[n + 1] = Pm[1][2]; q_a_25[n + 2] = Pm[1][3]; q_a_25[n + 3] = Pm[1][4];
			q_a_25[2 * n] = Pm[2][1]; q_a_25[2 * n + 1] = Pm[2][2]; q_a_25[2 * n + 2] = Pm[2][3]; q_a_25[2 * n + 3] = Pm[2][4];
			q_a_25[3 * n] = Pm[3][1]; q_a_25[3 * n + 1] = Pm[3][2]; q_a_25[3 * n + 2] = Pm[3][3]; q_a_25[3 * n + 3] = Pm[3][4];
			q_a_25[4 * n] = Pm[4][1]; q_a_25[4 * n + 1] = Pm[4][2]; q_a_25[4 * n + 2] = Pm[4][3]; q_a_25[4 * n + 3] = Pm[4][4];

			q_a5[0] = Pm[0][0]; q_a5[1] = Pm[0][1]; q_a5[2] = Pm[0][2]; q_a5[3] = Pm[0][3];
			q_a5[n] = Pm[1][0]; q_a5[n + 1] = Pm[1][1]; q_a5[n + 2] = Pm[1][2]; q_a5[n + 3] = Pm[1][3];
			q_a5[2 * n] = Pm[2][0]; q_a5[2 * n + 1] = Pm[2][1]; q_a5[2 * n + 2] = Pm[2][2]; q_a5[2 * n + 3] = Pm[2][3];
			q_a5[3 * n] = Pm[3][0]; q_a5[3 * n + 1] = Pm[3][1]; q_a5[3 * n + 2] = Pm[3][2]; q_a5[3 * n + 3] = Pm[3][3];
			q_a5[4 * n] = Pm[4][0]; q_a5[4 * n + 1] = Pm[4][1]; q_a5[4 * n + 2] = Pm[4][2]; q_a5[4 * n + 3] = Pm[4][3];

			q_a_n_15[n - 3] = Pm[0][0]; q_a_n_15[n - 2] = Pm[0][1]; q_a_n_15[n - 1] = Pm[0][2];
			q_a_n_15[2 * n - 3] = Pm[1][0]; q_a_n_15[2 * n - 2] = Pm[1][1]; q_a_n_15[2 * n - 1] = Pm[1][2];
			q_a_n_15[3 * n - 3] = Pm[2][0]; q_a_n_15[3 * n - 2] = Pm[2][1]; q_a_n_15[3 * n - 1] = Pm[2][2];
			q_a_n_15[4 * n - 3] = Pm[3][0]; q_a_n_15[4 * n - 2] = Pm[3][1]; q_a_n_15[4 * n - 1] = Pm[3][2];
			q_a_n_15[5 * n - 3] = Pm[4][0]; q_a_n_15[5 * n - 2] = Pm[4][1]; q_a_n_15[5 * n - 1] = Pm[4][2];
			break;
		default:
			q_a_15[0] = Pm[0][2]; q_a_15[1] = Pm[0][3]; q_a_15[2] = Pm[0][4];
			q_a_15[n] = Pm[1][2]; q_a_15[n + 1] = Pm[1][3]; q_a_15[n + 2] = Pm[1][4];
			q_a_15[2 * n] = Pm[2][2]; q_a_15[2 * n + 1] = Pm[2][3]; q_a_15[2 * n + 2] = Pm[2][4];
			q_a_15[3 * n] = Pm[3][2]; q_a_15[3 * n + 1] = Pm[3][3]; q_a_15[3 * n + 2] = Pm[3][4];
			q_a_15[4 * n] = Pm[4][2]; q_a_15[4 * n + 1] = Pm[4][3]; q_a_15[4 * n + 2] = Pm[4][4];

			q_a_25[0] = Pm[0][1]; q_a_25[1] = Pm[0][2]; q_a_25[2] = Pm[0][3]; q_a_25[3] = Pm[0][4];
			q_a_25[n] = Pm[1][1]; q_a_25[n + 1] = Pm[1][2]; q_a_25[n + 2] = Pm[1][3]; q_a_25[n + 3] = Pm[1][4];
			q_a_25[2 * n] = Pm[2][1]; q_a_25[2 * n + 1] = Pm[2][2]; q_a_25[2 * n + 2] = Pm[2][3]; q_a_25[2 * n + 3] = Pm[2][4];
			q_a_25[3 * n] = Pm[3][1]; q_a_25[3 * n + 1] = Pm[3][2]; q_a_25[3 * n + 2] = Pm[3][3]; q_a_25[3 * n + 3] = Pm[3][4];
			q_a_25[4 * n] = Pm[4][1]; q_a_25[4 * n + 1] = Pm[4][2]; q_a_25[4 * n + 2] = Pm[4][3]; q_a_25[4 * n + 3] = Pm[4][4];

			q_a5[0] = Pm[0][0]; q_a5[1] = Pm[0][1]; q_a5[2] = Pm[0][2]; q_a5[3] = Pm[0][3]; q_a5[4] = Pm[0][4];
			q_a5[n] = Pm[1][0]; q_a5[n + 1] = Pm[1][1]; q_a5[n + 2] = Pm[1][2]; q_a5[n + 3] = Pm[1][3]; q_a5[n + 4] = Pm[1][4];
			q_a5[2 * n] = Pm[2][0]; q_a5[2 * n + 1] = Pm[2][1]; q_a5[2 * n + 2] = Pm[2][2]; q_a5[2 * n + 3] = Pm[2][3]; q_a5[2 * n + 4] = Pm[2][4];
			q_a5[3 * n] = Pm[3][0]; q_a5[3 * n + 1] = Pm[3][1]; q_a5[3 * n + 2] = Pm[3][2]; q_a5[3 * n + 3] = Pm[3][3]; q_a5[3 * n + 4] = Pm[3][4];
			q_a5[4 * n] = Pm[4][0]; q_a5[4 * n + 1] = Pm[4][1]; q_a5[4 * n + 2] = Pm[4][2]; q_a5[4 * n + 3] = Pm[4][3]; q_a5[4 * n + 4] = Pm[4][4];

			q_a_n_15[n - 4] = Pm[0][0]; q_a_n_15[n - 3] = Pm[0][1]; q_a_n_15[n - 2] = Pm[0][2]; q_a_n_15[n - 1] = Pm[0][3];
			q_a_n_15[2 * n - 4] = Pm[1][0]; q_a_n_15[2 * n - 3] = Pm[1][1]; q_a_n_15[2 * n - 2] = Pm[1][2]; q_a_n_15[2 * n - 1] = Pm[1][3];
			q_a_n_15[3 * n - 4] = Pm[2][0]; q_a_n_15[3 * n - 3] = Pm[2][1]; q_a_n_15[3 * n - 2] = Pm[2][2]; q_a_n_15[3 * n - 1] = Pm[2][3];
			q_a_n_15[4 * n - 4] = Pm[3][0]; q_a_n_15[4 * n - 3] = Pm[3][1]; q_a_n_15[4 * n - 2] = Pm[3][2]; q_a_n_15[4 * n - 1] = Pm[3][3];
			q_a_n_15[5 * n - 4] = Pm[4][0]; q_a_n_15[5 * n - 3] = Pm[4][1]; q_a_n_15[5 * n - 2] = Pm[4][2]; q_a_n_15[5 * n - 1] = Pm[4][3];

			q_a_n5[n - 3] = Pm[0][0]; q_a_n5[n - 2] = Pm[0][1]; q_a_n5[n - 1] = Pm[0][2];
			q_a_n5[2 * n - 3] = Pm[1][0]; q_a_n5[2 * n - 2] = Pm[1][1]; q_a_n5[2 * n - 1] = Pm[1][2];
			q_a_n5[3 * n - 3] = Pm[2][0]; q_a_n5[3 * n - 2] = Pm[2][1]; q_a_n5[3 * n - 1] = Pm[2][2];
			q_a_n5[4 * n - 3] = Pm[3][0]; q_a_n5[4 * n - 2] = Pm[3][1]; q_a_n5[4 * n - 1] = Pm[3][2];
			q_a_n5[5 * n - 3] = Pm[4][0]; q_a_n5[5 * n - 2] = Pm[4][1]; q_a_n5[5 * n - 1] = Pm[4][2];
			break;
		}
	}
	else {
		switch (n) {
		case 1:
			q_a_1[0] = Pm[0][2];
			q_a_1[n] = Pm[1][2];
			q_a_1[2 * n] = Pm[2][2];
			q_a_1[3 * n] = Pm[3][2];
			q_a_1[4 * n] = Pm[4][2];

			break;
		case 2:

			q_a_1[0] = Pm[0][2]; q_a_1[1] = Pm[0][3];
			q_a_1[n] = Pm[1][2]; q_a_1[n + 1] = Pm[1][3];
			q_a_1[2 * n] = Pm[2][2]; q_a_1[2 * n + 1] = Pm[2][3];
			q_a_1[3 * n] = Pm[3][2]; q_a_1[3 * n + 1] = Pm[3][3];
			q_a_1[4 * n] = Pm[4][2]; q_a_1[4 * n + 1] = Pm[4][3];

			q_a_2[0] = Pm[0][1]; q_a_2[1] = Pm[0][2];
			q_a_2[n] = Pm[1][1]; q_a_2[n + 1] = Pm[1][2];
			q_a_2[2 * n] = Pm[2][1]; q_a_2[2 * n + 1] = Pm[2][2];
			q_a_2[3 * n] = Pm[3][1]; q_a_2[3 * n + 1] = Pm[3][2];
			q_a_2[4 * n] = Pm[4][1]; q_a_2[4 * n + 1] = Pm[4][2];

			break;
		case 3:

			q_a_1[0] = Pm[0][2]; q_a_1[1] = Pm[0][3]; q_a_1[2] = Pm[0][4];
			q_a_1[n] = Pm[1][2]; q_a_1[n + 1] = Pm[1][3]; q_a_1[n + 2] = Pm[1][4];
			q_a_1[2 * n] = Pm[2][2]; q_a_1[2 * n + 1] = Pm[2][3]; q_a_1[2 * n + 2] = Pm[2][4];
			q_a_1[3 * n] = Pm[3][2]; q_a_1[3 * n + 1] = Pm[3][3]; q_a_1[3 * n + 2] = Pm[3][4];
			q_a_1[4 * n] = Pm[4][2]; q_a_1[4 * n + 1] = Pm[4][3]; q_a_1[4 * n + 2] = Pm[4][4];

			q_a_2[0] = Pm[0][1]; q_a_2[1] = Pm[0][2]; q_a_2[2] = Pm[0][3];
			q_a_2[n] = Pm[1][1]; q_a_2[n + 1] = Pm[1][2]; q_a_2[n + 2] = Pm[1][3];
			q_a_2[2 * n] = Pm[2][1]; q_a_2[2 * n + 1] = Pm[2][2]; q_a_2[2 * n + 2] = Pm[2][3];
			q_a_2[3 * n] = Pm[3][1]; q_a_2[3 * n + 1] = Pm[3][2]; q_a_2[3 * n + 2] = Pm[3][3];
			q_a_2[4 * n] = Pm[4][1]; q_a_2[4 * n + 1] = Pm[4][2]; q_a_2[4 * n + 2] = Pm[4][3];

			q_a[0] = Pm[0][0]; q_a[1] = Pm[0][1]; q_a[2] = Pm[0][2];
			q_a[n] = Pm[1][0]; q_a[n + 1] = Pm[1][1]; q_a[n + 2] = Pm[1][2];
			q_a[2 * n] = Pm[2][0]; q_a[2 * n + 1] = Pm[2][1]; q_a[2 * n + 2] = Pm[2][2];
			q_a[3 * n] = Pm[3][0]; q_a[3 * n + 1] = Pm[3][1]; q_a[3 * n + 2] = Pm[3][2];
			q_a[4 * n] = Pm[4][0]; q_a[4 * n + 1] = Pm[4][1]; q_a[4 * n + 2] = Pm[4][2];
			break;
		case 4:
			q_a_1[0] = Pm[0][2]; q_a_1[1] = Pm[0][3]; q_a_1[2] = Pm[0][4];
			q_a_1[n] = Pm[1][2]; q_a_1[n + 1] = Pm[1][3]; q_a_1[n + 2] = Pm[1][4];
			q_a_1[2 * n] = Pm[2][2]; q_a_1[2 * n + 1] = Pm[2][3]; q_a_1[2 * n + 2] = Pm[2][4];
			q_a_1[3 * n] = Pm[3][2]; q_a_1[3 * n + 1] = Pm[3][3]; q_a_1[3 * n + 2] = Pm[3][4];
			q_a_1[4 * n] = Pm[4][2]; q_a_1[4 * n + 1] = Pm[4][3]; q_a_1[4 * n + 2] = Pm[4][4];

			q_a_2[0] = Pm[0][1]; q_a_2[1] = Pm[0][2]; q_a_2[2] = Pm[0][3]; q_a_2[3] = Pm[0][4];
			q_a_2[n] = Pm[1][1]; q_a_2[n + 1] = Pm[1][2]; q_a_2[n + 2] = Pm[1][3]; q_a_2[n + 3] = Pm[1][4];
			q_a_2[2 * n] = Pm[2][1]; q_a_2[2 * n + 1] = Pm[2][2]; q_a_2[2 * n + 2] = Pm[2][3]; q_a_2[2 * n + 3] = Pm[2][4];
			q_a_2[3 * n] = Pm[3][1]; q_a_2[3 * n + 1] = Pm[3][2]; q_a_2[3 * n + 2] = Pm[3][3]; q_a_2[3 * n + 3] = Pm[3][4];
			q_a_2[4 * n] = Pm[4][1]; q_a_2[4 * n + 1] = Pm[4][2]; q_a_2[4 * n + 2] = Pm[4][3]; q_a_2[4 * n + 3] = Pm[4][4];

			q_a[0] = Pm[0][0]; q_a[1] = Pm[0][1]; q_a[2] = Pm[0][2]; q_a[3] = Pm[0][3];
			q_a[n] = Pm[1][0]; q_a[n + 1] = Pm[1][1]; q_a[n + 2] = Pm[1][2]; q_a[n + 3] = Pm[1][3];
			q_a[2 * n] = Pm[2][0]; q_a[2 * n + 1] = Pm[2][1]; q_a[2 * n + 2] = Pm[2][2]; q_a[2 * n + 3] = Pm[2][3];
			q_a[3 * n] = Pm[3][0]; q_a[3 * n + 1] = Pm[3][1]; q_a[3 * n + 2] = Pm[3][2]; q_a[3 * n + 3] = Pm[3][3];
			q_a[4 * n] = Pm[4][0]; q_a[4 * n + 1] = Pm[4][1]; q_a[4 * n + 2] = Pm[4][2]; q_a[4 * n + 3] = Pm[4][3];

			q_a_n_1[n - 3] = Pm[0][0]; q_a_n_1[n - 2] = Pm[0][1]; q_a_n_1[n - 1] = Pm[0][2];
			q_a_n_1[2 * n - 3] = Pm[1][0]; q_a_n_1[2 * n - 2] = Pm[1][1]; q_a_n_1[2 * n - 1] = Pm[1][2];
			q_a_n_1[3 * n - 3] = Pm[2][0]; q_a_n_1[3 * n - 2] = Pm[2][1]; q_a_n_1[3 * n - 1] = Pm[2][2];
			q_a_n_1[4 * n - 3] = Pm[3][0]; q_a_n_1[4 * n - 2] = Pm[3][1]; q_a_n_1[4 * n - 1] = Pm[3][2];
			q_a_n_1[5 * n - 3] = Pm[4][0]; q_a_n_1[5 * n - 2] = Pm[4][1]; q_a_n_1[5 * n - 1] = Pm[4][2];

			break;
		default:
			q_a_1[0] = Pm[0][2]; q_a_1[1] = Pm[0][3]; q_a_1[2] = Pm[0][4];
			q_a_1[n] = Pm[1][2]; q_a_1[n + 1] = Pm[1][3]; q_a_1[n + 2] = Pm[1][4];
			q_a_1[2 * n] = Pm[2][2]; q_a_1[2 * n + 1] = Pm[2][3]; q_a_1[2 * n + 2] = Pm[2][4];
			q_a_1[3 * n] = Pm[3][2]; q_a_1[3 * n + 1] = Pm[3][3]; q_a_1[3 * n + 2] = Pm[3][4];
			q_a_1[4 * n] = Pm[4][2]; q_a_1[4 * n + 1] = Pm[4][3]; q_a_1[4 * n + 2] = Pm[4][4];

			q_a_2[0] = Pm[0][1]; q_a_2[1] = Pm[0][2]; q_a_2[2] = Pm[0][3]; q_a_2[3] = Pm[0][4];
			q_a_2[n] = Pm[1][1]; q_a_2[n + 1] = Pm[1][2]; q_a_2[n + 2] = Pm[1][3]; q_a_2[n + 3] = Pm[1][4];
			q_a_2[2 * n] = Pm[2][1]; q_a_2[2 * n + 1] = Pm[2][2]; q_a_2[2 * n + 2] = Pm[2][3]; q_a_2[2 * n + 3] = Pm[2][4];
			q_a_2[3 * n] = Pm[3][1]; q_a_2[3 * n + 1] = Pm[3][2]; q_a_2[3 * n + 2] = Pm[3][3]; q_a_2[3 * n + 3] = Pm[3][4];
			q_a_2[4 * n] = Pm[4][1]; q_a_2[4 * n + 1] = Pm[4][2]; q_a_2[4 * n + 2] = Pm[4][3]; q_a_2[4 * n + 3] = Pm[4][4];

			q_a[0] = Pm[0][0]; q_a[1] = Pm[0][1]; q_a[2] = Pm[0][2]; q_a[3] = Pm[0][3]; q_a[4] = Pm[0][4];
			q_a[n] = Pm[1][0]; q_a[n + 1] = Pm[1][1]; q_a[n + 2] = Pm[1][2]; q_a[n + 3] = Pm[1][3]; q_a[n + 4] = Pm[1][4];
			q_a[2 * n] = Pm[2][0]; q_a[2 * n + 1] = Pm[2][1]; q_a[2 * n + 2] = Pm[2][2]; q_a[2 * n + 3] = Pm[2][3]; q_a[2 * n + 4] = Pm[2][4];
			q_a[3 * n] = Pm[3][0]; q_a[3 * n + 1] = Pm[3][1]; q_a[3 * n + 2] = Pm[3][2]; q_a[3 * n + 3] = Pm[3][3]; q_a[3 * n + 4] = Pm[3][4];
			q_a[4 * n] = Pm[4][0]; q_a[4 * n + 1] = Pm[4][1]; q_a[4 * n + 2] = Pm[4][2]; q_a[4 * n + 3] = Pm[4][3]; q_a[4 * n + 4] = Pm[4][4];

			q_a_n_1[n - 4] = Pm[0][0]; q_a_n_1[n - 3] = Pm[0][1]; q_a_n_1[n - 2] = Pm[0][2]; q_a_n_1[n - 1] = Pm[0][3];
			q_a_n_1[2 * n - 4] = Pm[1][0]; q_a_n_1[2 * n - 3] = Pm[1][1]; q_a_n_1[2 * n - 2] = Pm[1][2]; q_a_n_1[2 * n - 1] = Pm[1][3];
			q_a_n_1[3 * n - 4] = Pm[2][0]; q_a_n_1[3 * n - 3] = Pm[2][1]; q_a_n_1[3 * n - 2] = Pm[2][2]; q_a_n_1[3 * n - 1] = Pm[2][3];
			q_a_n_1[4 * n - 4] = Pm[3][0]; q_a_n_1[4 * n - 3] = Pm[3][1]; q_a_n_1[4 * n - 2] = Pm[3][2]; q_a_n_1[4 * n - 1] = Pm[3][3];
			q_a_n_1[5 * n - 4] = Pm[4][0]; q_a_n_1[5 * n - 3] = Pm[4][1]; q_a_n_1[5 * n - 2] = Pm[4][2]; q_a_n_1[5 * n - 1] = Pm[4][3];

			q_a_n[n - 3] = Pm[0][0]; q_a_n[n - 2] = Pm[0][1]; q_a_n[n - 1] = Pm[0][2];
			q_a_n[2 * n - 3] = Pm[1][0]; q_a_n[2 * n - 2] = Pm[1][1]; q_a_n[2 * n - 1] = Pm[1][2];
			q_a_n[3 * n - 3] = Pm[2][0]; q_a_n[3 * n - 2] = Pm[2][1]; q_a_n[3 * n - 1] = Pm[2][2];
			q_a_n[4 * n - 3] = Pm[3][0]; q_a_n[4 * n - 2] = Pm[3][1]; q_a_n[4 * n - 1] = Pm[3][2];
			q_a_n[5 * n - 3] = Pm[4][0]; q_a_n[5 * n - 2] = Pm[4][1]; q_a_n[5 * n - 1] = Pm[4][2];
			break;
		}
	}

	if (m <= 4) {
		for (std::vector<boost::dynamic_bitset<>>::size_type i = 0; i < m; i++) {
			if (i == 0)
				for (std::vector<boost::dynamic_bitset<>>::size_type j = 0; j < n; j++)
					if (j == 0)
						Q[i*n + j] = q_a_15 >> 2 * n;
					else if (j == 1)
						Q[i*n + j] = q_a_25 >> 2 * n;
					else if (j <= n - 3 || j == 2)
						Q[i*n + j] = (q_a5 >> 2 * n) << j - 2;
					else if (j == n - 2 || j == 3)
						Q[i*n + j] = q_a_n_15 >> 2 * n;
					else //(j=n-1)
						Q[i*n + j] = q_a_n5 >> 2 * n;
			else if (i == 1)
				for (std::vector<boost::dynamic_bitset<>>::size_type j = 0; j < n; j++)
					if (j == 0)
						Q[i*n + j] = q_a_15 >> n;
					else if (j == 1)
						Q[i*n + j] = q_a_25 >> n;
					else if (j <= n - 3 || j == 2)
						Q[i*n + j] = (q_a5 >> n) << j - 2;
					else if (j == n - 2 || j == 3)
						Q[i*n + j] = q_a_n_15 >> n;
					else //(j=n-1)
						Q[i*n + j] = q_a_n5 >> n;
			else if ( i == 2)
				for (std::vector<boost::dynamic_bitset<>>::size_type j = 0; j < n; j++)
					if (j == 0)
						Q[i*n + j] = q_a_15 << (i - 2)*n;
					else if (j == 1)
						Q[i*n + j] = q_a_25 << (i - 2)*n;
					else if (j <= n - 3 || j == 2)
						Q[i*n + j] = q_a5 << (i - 2)*n + j - 2;
					else if (j == n - 2 || j == 3)
						Q[i*n + j] = q_a_n_15 << (i - 2)*n;
					else //(j=n-1)
						Q[i*n + j] = q_a_n5 << (i - 2)*n;
			else if ( i == 3)
				for (std::vector<boost::dynamic_bitset<>>::size_type j = 0; j < n; j++)
					if (j == 0)
						Q[i*n + j] = q_a_15 << n;
					else if (j == 1)
						Q[i*n + j] = q_a_25 << n;
					else if (j <= n - 3 || j == 2)
						Q[i*n + j] = q_a5 << n + j - 2;
					else if (j == n - 2 || j == 3)
						Q[i*n + j] = q_a_n_15 << n;
					else //(j=n-1)
						Q[i*n + j] = q_a_n5 << n;
		}

	}
	else {

#pragma endregion

		for (std::vector<boost::dynamic_bitset<>>::size_type i = 0; i < m; i++) {
			if (i == 0)
				for (std::vector<boost::dynamic_bitset<>>::size_type j = 0; j < n; j++)
					if (j == 0)
						Q[i*n + j] = q_a_1 >> 2 * n;
					else if (j == 1)
						Q[i*n + j] = q_a_2 >> 2 * n;
					else if (j <= n - 3 || j == 2)
						Q[i*n + j] = (q_a >> 2 * n) << j - 2;
					else if (j == n - 2 || j == 3)
						Q[i*n + j] = q_a_n_1 >> 2 * n;
					else //(j=n-1)
						Q[i*n + j] = q_a_n >> 2 * n;
			else if (i == 1)
				for (std::vector<boost::dynamic_bitset<>>::size_type j = 0; j < n; j++)
					if (j == 0)
						Q[i*n + j] = q_a_1 >> n;
					else if (j == 1)
						Q[i*n + j] = q_a_2 >> n;
					else if (j <= n - 3 || j == 2)
						Q[i*n + j] = (q_a >> n) << j - 2;
					else if (j == n - 2 || j == 3)
						Q[i*n + j] = q_a_n_1 >> n;
					else //(j=n-1)
						Q[i*n + j] = q_a_n >> n;
			else if (i <= m - 3)
				for (std::vector<boost::dynamic_bitset<>>::size_type j = 0; j < n; j++)
					if (j == 0)
						Q[i*n + j] = q_a_1 << (i - 2)*n;
					else if (j == 1)
						Q[i*n + j] = q_a_2 << (i - 2)*n;
					else if (j <= n - 3 || j == 2)
						Q[i*n + j] = q_a << (i - 2)*n + j - 2;
					else if (j == n - 2 || j == 3)
						Q[i*n + j] = q_a_n_1 << (i - 2)*n;
					else //(j=n-1)
						Q[i*n + j] = q_a_n << (i - 2)*n;
			else if (i == m - 2)
				for (std::vector<boost::dynamic_bitset<>>::size_type j = 0; j < n; j++)
					if (j == 0)
						Q[i*n + j] = q_a_1 << (m - 4)*n;
					else if (j == 1)
						Q[i*n + j] = q_a_2 << (m - 4)*n;
					else if (j <= n - 3 || j == 2)
						Q[i*n + j] = q_a << (m - 4)*n + j - 2;
					else if (j == n - 2 || j == 3)
						Q[i*n + j] = q_a_n_1 << (m - 4)*n;
					else //(j=n-1)
						Q[i*n + j] = q_a_n << (m - 4)*n;
			else//(i=m-1)
				for (std::vector<boost::dynamic_bitset<>>::size_type j = 0; j < n; j++)
					if (j == 0)
						Q[i*n + j] = q_a_1 << (m - 3)*n;
					else if (j == 1)
						Q[i*n + j] = q_a_2 << (m - 3)*n;
					else if (j <= n - 3 || j == 2)
						Q[i*n + j] = q_a << (m - 3)*n + j - 2;
					else if (j == n - 2 || j == 3)
						Q[i*n + j] = q_a_n_1 << (m - 3)*n;
					else //(j=n-1)
						Q[i*n + j] = q_a_n << (m - 3)*n;
		}
	}

	//计算行列式
	for (std::vector<boost::dynamic_bitset<>>::size_type i = 0; i < m*n; i++)
	{
		if (!Q[i][i]) {
			for (std::vector<boost::dynamic_bitset<>>::size_type j = 1; j <= 2 * n + 2; j++)
			{
				if (i + j < n*m)
				{
					if (Q[i + j][i])
					{
						Q[i] = Q[i] ^ Q[i + j];
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		if (Q[i][i])
		{
			for (std::vector<boost::dynamic_bitset<>>::size_type j = 1; j <= 2 * n + 2; j++)
			{
				if (i + j < n*m)
				{
					if (Q[i + j][i])
					{
						Q[i + j] = Q[i] ^ Q[i + j];
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
		if (i == n*m - 1)
		{
			if (Q[i][i])
			{
				return 1;
			}
		}
	}


	return 0;
}

