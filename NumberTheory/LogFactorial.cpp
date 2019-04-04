// 階乗の対数表現
// スターリングの近似を用いて
// ln n! を O(log()の計算量) で近似して計算できる
// 整数部 x と小数部 y に分けると、n! = y e^x として表せる
// ただしそれを計算しようとすると容易にオーバーフローする
// n が小さければ愚直に計算する
const double PI = acos(-1);
double logFactorial(long long n) {
	if (n < 100) {
		double ret = 0;
		for (long long i = 1; i <= n; i++)
			ret += log(i);
		return ret;
	}
	return n * log(n) - n + log(2.0 * PI * n) / 2.0 + 1.0 / (12.0 * n);
}