// Matrix chain multiplication
// O(n^3)
// Verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3472954
int R[101], C[101];
int dp[101][101];
int f(int l, int r) {
	if (dp[l][r] != INF)return dp[l][r];
	if (l >= r - 1)return 0;
	rep(m, l + 1, r) {
		chmin(dp[l][r], f(l, m) + f(m, r) + R[l] * R[m] * C[r - 1]);
	}
	return dp[l][r];
}
