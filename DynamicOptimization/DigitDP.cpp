//S以下の非負整数
void keta1() {
	//i桁目
	//S未満確定か
	int dp[10][2] = {};
	string S; cin >> S;
	dp[0][0] = 1;
	rep(i, 0, S.size()) rep(j, 0, 2) {
		int lim = j ? 9 : S[i] - '0';
		rep(d, 0, lim + 1) {
			//すでに未満確定||未満確定
			(dp[i + 1][j || d != lim] += dp[i][j]) %= MOD;
		}
	}
	int ans = dp[S.size()][0] + dp[S.size()][1];
	ans %= MOD;
	cout << ans << endl;
}

//S以下の非負整数 かつ 3が付く
void keta2() {
	//i桁目
	//S未満確定か
	//3が付くか 
	int dp[10][2][2] = {};
	string S; cin >> S;
	dp[0][0][0] = 1;
	rep(i, 0, S.size()) rep(j, 0, 2) rep(k, 0, 2) {
		int lim = j ? 9 : S[i] - '0';
		rep(d, 0, lim + 1) {
			(dp[i + 1][j || d < lim][k || d == 3] += dp[i][j][k]) %= MOD;
		}
	}
	int ans = dp[S.size()][0][1] + dp[S.size()][1][1];
	ans %= MOD;
	cout << ans << endl;
}

//S以下の非負整数 かつ 1が付く個数
void keta2a() {
	//i桁目
	//S未満確定か
	//1が付く個数
	int dp[15][2][15] = {};
	string S; cin >> S;
	dp[0][0][0] = 1;
	rep(i, 0, S.size()) rep(j, 0, 2) rep(k, 0, 14) {
		int lim = j ? 9 : S[i] - '0';
		rep(d, 0, lim + 1) {
			dp[i + 1][j || d < lim][k + (d == 1)] += dp[i][j][k];
		}
	}
	int ans = 0;
	rep(k, 1, 15) {
		ans += (dp[S.size()][0][k] + dp[S.size()][1][k])*k;
	}
	cout << ans << endl;
}

//S以下の非負整数 かつ (3が付く または 3の倍数)
void keta3() {
	//i桁目
	//S未満確定か
	//3が付くか
	//mod3
	int dp[10][2][2][3] = {};
	string S; cin >> S;
	dp[0][0][0][0] = 1;
	rep(i, 0, S.size()) rep(j, 0, 2) rep(k, 0, 2)rep(l, 0, 3) {
		int lim = j ? 9 : S[i] - '0';
		rep(d, 0, lim + 1) {
			(dp[i + 1][j || d < lim][k || d == 3][(d + l) % 3] += dp[i][j][k][l]) %= MOD;
		}
	}
	int ans = 0;
	rep(j, 0, 2)rep(k, 0, 2)rep(l, 0, 3) {
		if (k || l == 0)
			(ans += dp[S.size()][j][j][l]) %= MOD;
	}
	cout << ans << endl;
}

//S以下の非負整数 かつ (3が付く または 3の倍数) かつ 8の倍数でない
void keta4() {
	//i桁目
	//S未満確定か
	//3が付くか
	//mod3
	//mod8
	int dp[10][2][2][3][8] = {};
	string S; cin >> S;
	dp[0][0][0][0][0] = 1;
	rep(i, 0, S.size()) rep(j, 0, 2) rep(k, 0, 2)rep(l, 0, 3)rep(m, 0, 8) {
		int lim = j ? 9 : S[i] - '0';
		rep(d, 0, lim + 1) {
			(dp[i + 1][j || d < lim][k || d == 3][(d + l) % 3][(m * 10 + d) % 8] += dp[i][j][k][l][m]) %= MOD;
		}
	}
	int ans = 0;
	rep(j, 0, 2)rep(k, 0, 2)rep(l, 0, 3)rep(m, 1, 8) {
		if (k || l == 0)
			(ans += dp[S.size()][j][j][l][m]) %= MOD;
	}
	cout << ans << endl;
}

//S以下の非負整数 かつ 4が付くかつ 9が付く
int keta5(string S) {
	//i桁目
	//S未満確定か
	//4が付くか 
	//9が付くか 
	int dp[20][2][2][2] = {};
	dp[0][0][0][0] = 1;
	rep(i, 0, S.size()) rep(j, 0, 2) rep(k, 0, 2)rep(l, 0, 2) {
		int lim = j ? 9 : S[i] - '0';
		rep(d, 0, lim + 1) {
			dp[i + 1][j || d < lim][k || d == 4][l || d == 9] += dp[i][j][k][l];
		}
	}
	int ret = dp[S.size()][1][1][0] + dp[S.size()][1][0][1] + dp[S.size()][1][1][1] + dp[S.size()][0][1][0] + dp[S.size()][0][0][1] + dp[S.size()][0][1][1];
	return ret;
}

signed main_keta5() {
	int A, B; cin >> A >> B;
	cout << keta5(to_string(B)) - keta5(to_string(A - 1)) << endl;
	return 0;
}