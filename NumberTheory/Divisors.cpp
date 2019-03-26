// 約数
// 未ソート
// O(√n), O(2^(b/2))
vector<int> getDivisors(int x) {
	vector<int> ret;
	int i;
	for (i = 1; i*i < x; i++) {
		if (x%i)continue;
		ret.emplace_back(i);
		ret.emplace_back(x / i);
	}
	if (i*i == x)
		ret.emplace_back(i);
	return ret;
}

// 約数の個数の配列
// 1 から n まで
// O(n log n)
//   n + n / 2 + n / 3 + ... + n / n = n log n
// Verified:
//   https://yukicoder.me/submissions/329249
vector<int> numberOfDivisors(int n) {
	vector<int> num(n + 1);
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i)
			num[j]++;
	return num;
}