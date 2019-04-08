// (N, +)
// オーバーフローする、すなわち演算について閉じていないので厳密には群ではない
struct S {
	using T = int;
	static const T op(const T &a, const T &b) { return a + b; }
	static const T inverse(const T &x) { return -x; }
	static const T I = 0;
};