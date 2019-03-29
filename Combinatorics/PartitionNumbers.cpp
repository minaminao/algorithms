#include "ModInt.cpp"

// 分割数（partition numbers）
vector<vector<mint>> partitionNumbers(int n, int m) {
	vector<vector<mint>> P(n + 1, vector<mint>(m + 1, 0));
	for (int i = 0; i <= n; i++)
		P[i][1] = 1;
	for (int i = 1; i <= m; i++)
		P[0][i] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (j - 1 >= 1 && i - j >= 0)
				P[i][j] = P[i][j - 1] + P[i - j][j];
			else if (j - 1 >= 1)
				P[i][j] = P[i][j - 1];
		}
	}
	return P;
}