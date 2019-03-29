#include "ModInt.cpp"

// スターリング数
vector<vector<mint>> stirlingNumbers(int n) {
	vector<vector<mint>> S(n + 1, vector<mint>(n + 1, 0));
	S[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			S[i + 1][j] += S[i][j] * j;
			S[i + 1][j + 1] += S[i][j];
		}
	}
	return S;
}