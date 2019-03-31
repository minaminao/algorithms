// 記数法
// 基本的に以下の3つの関数を使えばいい
// format(x, n)
// format(s.begin(), s.end(), m)
// format(s.begin(), s.end(), m, n)
struct Radix {
	using It = string::iterator;
	string num;
	int id[128];
	int max_base;

	Radix(string num = "0123456789ABCDEF") :num(num), max_base(num.size()) {
		for (int i = 0; i < max_base; i++)
			id[num[i]] = i;
	}

	// 10進数(long long) -> n進数の桁配列に変換（マイナスも可能）
	// 下の桁から確定させていく
	// 戻り値:
	//   123 なら {1,2,3}
	//   0 なら {0} を返す
	// Verified:
	//   https://atcoder.jp/contests/abc105/submissions/4782908
	static vector<int> convertBase(long long x, int base) {
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

	// 10進数(long long) -> n進数(string)
	// Verified:
	//   http://arc009.contest.atcoder.jp/submissions/1177495
	//   https://yukicoder.me/submissions/330999
	//   https://yukicoder.me/submissions/331000
	string format(long long x, int base = -1, int len = 1) {
		if (base == -1)base = this->max_base;
		vector<int> res = convertBase(x, base);
		string ret;
		for (auto x : res)
			ret += num[x];
		return ret;
	}

	// 10進数(long long) -> 0が存在しない場合のn進数(string)
	// 123456789: 1,2, ... ,9,11,12, ...
	// abcde...z: a,b, ... ,z,aa,ab, ...
	// Verified:
	//   https://yukicoder.me/submissions/329288
	//   RitsCamp17Day1 D
	string formatNonZero(long long x, int base = -1) {
		if (base == -1)base = this->max_base;
		string ret;
		while (x >= 0) {
			ret += num[x%base];
			x = (x / base) - 1;
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}

	// m進数(string) -> n進数(string)
	string format(It l, It r, int m, int n, int len = 1) {
		return format(format(l, r, m), n, len);
	}
	// m進数(string) -> 10進数(long long)
	long long format(It l, It r, int m) {
		long long x = id[*l];
		for (l++; l != r; l++)
			x = x * m + id[*l];
		return x;
	}
};