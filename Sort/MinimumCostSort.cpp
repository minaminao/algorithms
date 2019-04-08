// 最小コストソート
// コスト v[i]+v[j] の交換を用いてソートする場合の最小コスト
// ループ中の最小の要素を用いてソートする
// オーバーフローに注意
// v[i] != v[j] が成り立たないとダメ
// Verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2188323
template<class T>
T minimumCostSort(const vector<T> &v) {
	int n = v.size();
	T total_cost = 0;
	vector<pair<T, int>> sorted(n);
	for (int i = 0; i < n; i++)sorted[i] = make_pair(v[i], i);
	sort(sorted.begin(), sorted.end());
	T mini = sorted[0].first;
	vector<bool> is_sorted(n);
	for (int i = 0; i < n; i++) {
		if (is_sorted[sorted[i].second])continue;
		T loop_cost = 0;
		T loop_sum = 0;
		T loop_mini = sorted[i].first;
		T loop_n = 0;
		for (int j = i;;) {
			T cost = sorted[j].first;
			int dst = sorted[j].second;
			is_sorted[j] = true;
			chmin(loop_mini, cost);
			loop_sum += cost;
			loop_n++;
			j = dst;
			if (is_sorted[dst])break;
		}
		total_cost += min(
			loop_sum + (loop_n - 2)*loop_mini,
			loop_sum + loop_mini + (loop_n + 1)*mini
		);
	}
	return total_cost;
}