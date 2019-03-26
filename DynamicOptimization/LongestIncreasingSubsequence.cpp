// 最長増加部分列 O(n log n)
// v[i] < v[i+1]
// 戻り値: 長さ
int longestIncreasingSubsequence(const vector<int> &v) {
	int n = v.size();
	vector<int> dp(n, INF);
	for (int i = 0; i < n; i++)
		*lower_bound(dp.begin(), dp.end(), v[i]) = v[i];
	return find(dp.begin(), dp.end(), INF) - dp.begin();
}

// 最長増加部分列 O(n log n)
// 戻り値: 最長増加部分列（元配列でのインデックス）
vector<int> longestIncreasingSubsequence(const vector<int> &v) {
	int n = v.size();
	vector<int> dp(n, INF);
	vector<int> idx(n, -1);
	vector<int> prev(n, -1);
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(dp.begin(), dp.end(), v[i]);
		int j = it - dp.begin();
		*it = v[i];
		idx[j] = i;
		if (j > 0)
			prev[i] = idx[j - 1];
	}
	int length = find(dp.begin(), dp.end(), INF) - dp.begin();
	vector<int> lis;
	for (int s = idx[length - 1]; s != -1; s = prev[s])
		lis.push_back(s);
	reverse(lis.begin(), lis.end());
	return lis;
}