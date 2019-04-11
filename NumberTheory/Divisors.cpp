// 約数
// 未ソート
// O(√n), O(2^(b/2))
template<typename Int>
vector<Int> getDivisors(Int x) {
	vector<Int> ret;
	Int i;
	for (i = 1; i*i < x; i++) {
		if (x%i)continue;
		ret.push_back(i);
		ret.push_back(x / i);
	}
	if (i*i == x)
		ret.push_back(i);
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