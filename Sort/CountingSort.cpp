// 計数ソート
// O(n+k)
// 制約: 0 <= v[i] <= k
void countingSort(vector<int> &v) {
	int n = v.size(), k = *max_element(v.begin(), v.end());
	vector<int> cnt(k + 1), tmp(v);
	cnt[0]--;
	for (int x : v)cnt[x]++;
	for (int i = 0; i < k; i++)cnt[i + 1] += cnt[i];
	for (int i = n - 1; i >= 0; i--) {
		v[cnt[tmp[i]]] = tmp[i];
		cnt[tmp[i]]--;
	}
}