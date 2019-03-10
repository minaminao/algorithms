// Z algorithm
// 最長共通接辞を求める
// O(S)
struct ZAlgorithm {
	// 戻り値: a[i]: sとs[i:n)の最長共通接頭辞の長さ
	static vector<int> construct(const string &s) {
		int n = s.size();
		vector<int> a(n); a[0] = n;
		int i = 1, j = 0;
		while (i < n) {
			while (i + j < n && s[j] == s[i + j]) ++j;
			a[i] = j;
			if (j == 0) { ++i; continue; }
			int k = 1;
			while (i + k < n && k + a[k] < j) a[i + k] = a[k], ++k;
			i += k; j -= k;
		}
		return a;
	}
	// 戻り値: a[i]: tとs[i:n)の最長共通接頭辞の長さ
	static vector<int> construct(const string &s, const string &t) {
		vector<int> a = construct(t + s);
		a.erase(a.begin(), a.begin() + t.size());
		int T = t.size();
		for (int &e : a)if (e > T)e = T;
		return a;
	}
	// 戻り値: a[i]: tとs(i:0]の最長共通接尾辞の長さ
	static vector<int> constructSuffix(string s, string t) {
		reverse(s.begin(), s.end());
		reverse(t.begin(), t.end());
		vector<int> a = construct(s, t);
		reverse(a.begin(), a.end());
		return a;
	}
};
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2496084