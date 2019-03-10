// n := s.size()
// m := pattern.size()
// 構築 O(n log^2 n)
// 検索 O(m log n) LCP を使うと O(m + log n) でできる
struct SuffixArray {
	int n, k;
	string s;
	vector<int> ord, tmp, left;
	SuffixArray(const string &s) :s(s), n(s.size()), ord(n + 1), tmp(n + 1), left(n + 1) {
		for (int i = 0; i <= n; i++) {
			left[i] = i;
			ord[i] = i < n ? s[i] : -1;
		}
		auto compare = [&](int i, int j) {
			if (ord[i] != ord[j])return ord[i] < ord[j];
			else {
				int ri = i + k <= n ? ord[i + k] : -1;
				int rj = j + k <= n ? ord[j + k] : -1;
				return ri < rj;
			}
		};
		for (k = 1; k <= n; k *= 2) {
			sort(left.begin(), left.end(), compare);
			tmp[left[0]] = 0;
			for (int i = 1; i <= n; i++) {
				tmp[left[i]] = tmp[left[i - 1]] + (compare(left[i - 1], left[i]) ? 1 : 0);
			}
			ord = tmp;
		}
	}
	int lowerBound(const string &pattern) {
		int ng = 0, ok = n + 1;
		while (ng + 1 < ok) {
			int m = (ng + ok) / 2;
			if (s.compare(left[m], pattern.size(), pattern) >= 0)
				ok = m;
			else
				ng = m;
		}
		return ok;
	}
	int search(const string &pattern) {
		int ok = lowerBound(pattern);
		if (ok == n + 1)
			return -1;
		else
			return s.compare(left[ok], pattern.size(), pattern) == 0 ? ok : -1;
	}
};
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2496034
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2406804