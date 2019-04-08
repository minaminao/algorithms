// (int, min)
struct S {
	using T = int;
	static const T op(const T &a, const T &b) { return min(a, b); }
	static const T I = INT_MAX;
};