// ヒストグラムの最大長方形 O(N)
int largestRectangleInAHistogram(const vector<int> &h) {
	int n = h.size();
	using P = pair<int, int>;
	stack<P> st;
	st.emplace(-1, -1);
	int area = 0;
	for (int i = 0; i < n; i++) {
		if (st.top().first == h[i])
			continue;
		int pos = i;
		while (st.top().first >= h[i]) {
			chmax(area, st.top().first*(i - st.top().second));
			pos = st.top().second;
			st.pop();
		}
		st.emplace(h[i], pos);
	}
	while (st.size()) {
		chmax(area, st.top().first*(n - st.top().second));
		st.pop();
	}
	return area;
}

// 0-1二次元配列上の最大長方形 O(H*W)
// ヒストグラムの最大長方形を求めるのと同様
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2236876
int largestRectangle(vector<vector<int>> v) {
	int H = v.size(), W = v.front().size();
	rep(i, 0, H - 1)rep(j, 0, W) {
		if (v[i + 1][j] == 0)continue;
		v[i + 1][j] += v[i][j];
	}
	int area = 0;
	rep(i, 0, H)
		chmax(area, largestRectangleInAHistogram(v[i]));
	return area;
}