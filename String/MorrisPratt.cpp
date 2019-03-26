// Morris-Pratt algorithm (MP)
// 一致する位置を全て取得するのは向いていない 最悪 O(n(n+m))
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2495566#1
struct MorrisPratt {
	// a[i]: 文字列S[0,i)の接頭辞と接尾辞のうち一致している最大文字数
	// O(m)
	static vector<int> construct(const string &pattern) {
		int m = pattern.size();
		vector<int> a(m + 1);
		a[0] = -1;
		int j = -1;
		for (int i = 0; i < m; i++) {
			while (j >= 0 && pattern[i] != pattern[j])
				j = a[j];
			a[i + 1] = ++j;
		}
		return a;
	}
	// s に含まれる pattern の位置を返す
	// ない場合は -1
	// O(n+m)
	static int search(const string &s, const string &pattern) {
		int n = s.size(), m = pattern.size();
		vector<int> a = construct(pattern);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i + j] != pattern[j]) {
					i += a[j + 1];
					break;
				}
				if (j == m - 1)
					return i;
			}
		}
		return -1;
	}
};