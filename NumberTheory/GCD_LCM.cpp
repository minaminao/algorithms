//
// 最大公約数（greatest common divisor）
// 最小公倍数（least common multiple）
//

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int lcm(int x, int y) { return x / gcd(x, y) * y; }

int gcd(const vector<int> &v) {
	int ret = v[0];
	for (int i = 1; i < v.size(); i++)
		ret = gcd(ret, v[i]);
	return ret;
}
int lcm(const vector<int> &v) {
	int ret = v[0];
	for (int i = 1; i < v.size(); i++)
		ret = lcm(ret, v[i]);
	return ret;
}

// 非再帰
// 多倍長整数用
using Int = int;
Int gcd(Int x, Int y) {
	while (true) {
		if (y == 0)
			return x;
		Int t = x;
		x = y;
		y = t % y;
	}
}