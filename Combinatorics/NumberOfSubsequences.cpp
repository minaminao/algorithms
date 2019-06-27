// ret[i][c]: i文字目以降で文字cが最初に現れるindex（現れないならn）
vector<vector<int>> nextCharIndex(const string &s) {
	int n = s.size();
	vector<vector<int>> ret(n + 1, vector<int>(26, n));
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++)
			ret[i][j] = ret[i + 1][j];
		ret[i][s[i] - 'a'] = i;
	}
	return ret;
}

// 文字列の部分列の個数（インデックスごとに数え上げ）
vector<int> numberOfSubsequences(const string &s) {
	int n = s.size();
	auto next = nextCharIndex(s);
	vector<int> dp(n + 1);
	dp[0] = 1;
	rep(i, 0, n) {
		rep(j, 0, 26) {
			if (next[i][j] >= n)continue;
			dp[next[i][j] + 1] += dp[i];
			chmin(dp[next[i][j] + 1], INF);
		}
	}
	return dp;
}

// 文字列の部分列の個数（インデックスと長さごとに数え上げ）
// Verified: http://codeforces.com/contest/1183/submission/56151035
vector<vector<int>> numberOfSubsequences(const string &s) {
	int n = s.size();
	auto next = nextCharIndex(s);
	auto dp = gen_v<int>(n + 1, n + 1);
	dp[0][0] = 1;
	rep(h, 0, n) {
		rep(i, 0, n) {
			rep(j, 0, 26) {
				if (next[i][j] >= n)continue;
				dp[next[i][j] + 1][h + 1] += dp[i][h];
				chmin(dp[next[i][j] + 1][h + 1], INF);
			}
		}
	}
	return dp;
}

