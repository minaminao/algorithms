// 順列（zero-based）のソートでの最小交換回数
// Verified: https://yukicoder.me/submissions/335519
int minimumNumbersOfSwaps(const vector<int> &v) {
	int n = v.size();
	vector<bool> vis(n);
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i])continue;
		int p = i;
		int size = 0;
		while (!vis[p]) {
			vis[p] = true;
			size++;
			p = v[p];
		}
		ret += size - 1;
	}
	return ret;
}