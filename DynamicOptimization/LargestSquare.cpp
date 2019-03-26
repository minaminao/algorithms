// 最大正方形 O(HW)
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2236860
void largestSquare() {
	int H, W; cin >> H >> W;
	vector<vector<int>> dp(H + 1, vector<int>(W + 1));
	rep(i, 0, H) rep(j, 0, W) {
		int x; cin >> x;
		dp[i + 1][j + 1] = !x;
	}
	int ans = 0;
	rep(i, 1, H + 1)rep(j, 1, W + 1) {
		if (dp[i][j] == 0)continue;
		dp[i][j] = min({
			dp[i - 1][j],
			dp[i][j - 1],
			dp[i - 1][j - 1]
			}) + 1;
		chmax(ans, dp[i][j]);
	}
	cout << ans * ans << endl;
}