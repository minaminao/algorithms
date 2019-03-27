// n進法
// 0が存在する場合
//   0123456789ABCDEF
//   0,1, ... ,F,10,11, ...
// 0が存在しない場合
//   abcdefghijklmnopqrstuvwxyz
//   a,b, ... ,z,aa,ab, ...
// に気をつける
//
// Verified:
//   https://yukicoder.me/submissions/329288
//   http://arc009.contest.atcoder.jp/submissions/1177495
//   RitsCamp17Day1 D

struct Radix {
	string s;
	int a[128];
	int n;
	Radix(string s = "0123456789ABCDEF") :s(s), n(s.size()) {
		for (int i = 0; i < n; i++)
			a[s[i]] = i;
	}
	// 10進(long long) -> n進(string)
	string format(long long x, int n = -1, int len = 1) {
		if (n == -1)n = this->n;
		if (!x)return string(len, s[0]);
		string ret;
		for (; x || len > 0; x /= n, len--)
			ret += s[x%n];
		reverse(ret.begin(), ret.end());
		return ret;
	}
	// 0が存在しない
	string formatNonZero(long long x, int n = -1) {
		if (n == -1)n = this->n;
		string ret;
		while (x >= 0) {
			ret += s[x%n];
			x = (x / n) - 1;
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
	using It = string::iterator;
	// m進(string) -> n進(string)
	string format(It l, It r, int m, int n, int len = 1) {
		return format(format(l, r, m), n, len);
	}
	// m進(string) -> 10進(long long)
	long long format(It l, It r, int m) {
		long long x = a[*l];
		for (l++; l != r; l++)
			x = x * m + a[*l];
		return x;
	}
};
