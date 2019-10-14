// 包除原理
// O(2^n)

#include "GCD_LCM.cpp"
#include "PopCount.cpp"

// 1以上n以下の整数のうち、集合aの少なくとも1つの要素の倍数である（割り切れるもの）の個数
// Verified: https://yukicoder.me/submissions/329371
int numberOfMultiples(int n, vector<int> a) {
	int ret = 0;
	int m = a.size();
	for (int i = 1; i < (1 << m); i++) {
		int lcm = 1;
		for (int j = 0; j < m; j++) {
			if (i >> j & 1) {
				lcm = lcm / gcd(lcm, a[j])*a[j];
				if (lcm > n)break; // lcm>n => n/lcm==0 よりオーバーフローする前にbreak
			}
		}
		if (popcount(i) & 1)
			ret += n / lcm;
		else
			ret -= n / lcm;
	}
	return ret;
}