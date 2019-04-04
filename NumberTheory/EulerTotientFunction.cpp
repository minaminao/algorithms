// オイラーのトーシェント関数（Euler's totient function）
// nと互いに素な数[1,n]の個数
// Verified: https://yukicoder.me/submissions/335332
int eulerTotient(int n) {
	int ret = n;
	for (int x = 2; x*x <= n; x++) {
		if (n%x)continue;
		ret -= ret / x;
		while (n%x == 0)
			n /= x;
	}
	if (n != 1)
		ret -= ret / n;
	return ret;
}