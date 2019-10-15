// Verified: https://codeforces.com/contest/689/submission/62583075
struct SparseTable {
	int n;
	int lg_n;
	vector<int> a;
	vector<vector<int>> mini;
	vector<int> lg;
	// O(n log n)
	SparseTable(const vector<int> &a) :a(a), n(a.size()), lg(n + 1), lg_n(log2(n) + 1), mini(lg_n, vector<int>(n)) {
		for (int i = 2; i <= n; i++)
			lg[i] = lg[i >> 1] + 1;

		for (int i = 0; i < n; i++)
			mini[0][i] = a[i];

		for (int k = 0; k + 1 < lg_n; k++)
			for (int i = 0; i + (1 << k) < n; i++)
				mini[k + 1][i] = min(mini[k][i], mini[k][i + (1 << k)]);
	}
	// O(1) [l,r)
	int query(int l, int r) {
		if (r - l <= 0)return INF;
		int k = lg[r - l];
		return min(mini[k][l], mini[k][r - (1 << k)]);
	}
};
