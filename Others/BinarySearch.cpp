// 二分探索
// false  ... false [true] ...  true
// [true]のインデックスを返す
//
// true ... (true) false ... false
// (true)が欲しいなら条件を反転して
// false ... (false) [true] ... true
// [true]のインデックスから1を引く

template<class F>
int binarySearch(int l, int r, F f) {
	if (f(l))return l; // f(l): true
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (f(m))
			r = m;
		else
			l = m;
	}
	return r; // f(l):false, f(r):true
}

template<class F>
double binarySearch(double l, double r, F f) {
	if (f(l))return l; // f(l): true
	for (int i = 0; i < 60; i++) { // ループの回数は2進数での精度
		double m = (l + r) / 2;
		if (f(m))
			r = m;
		else
			l = m;
	}
	return r; // f(l):false, f(r):true
}

// ng と ok は具体的な定数にする
// INF を設定してオーバーフローした場合、#define int long long で対処しても
// INF が long long 版になるのでオーバーフローする
auto f = [&](int x) {
	return x > 0;
};
auto binarySearch = [&](int ng, int ok) {
	if (f(ng))return ng;
	while (ng + 1 < ok) {
		int m = (ng + ok) / 2;
		if (f(m))
			ok = m;
		else
			ng = m;
	}
	return ok;
};