// マイナスn進数
// 下の桁から確定させていく
// x = 0 なら {0} を返す
// Verified: https://atcoder.jp/contests/abc105/submissions/4782908
vector<int> negativeRadix(int x, int base) {
	if (x == 0)return vector<int>(1);
	vector<int> digits;
	while (x != 0) {
		int r = x % base;
		x /= base;
		if (r < 0) {
			r += -base;
			x++;
		}
		digits.push_back(r);
	}
	reverse(digits.begin(), digits.end());
	return digits;
}