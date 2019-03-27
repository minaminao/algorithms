// 三分探索
// f が最小になるような最小のxを返す
// Verified: https://yukicoder.me/submissions/329575

auto f = [&](int x) {
	return x > 0;
};
auto ternarySearch = [&](int l, int r) {
	for (int i = 0; i < 70; i++) { // long long なら 70 で十分
		int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
		dump(l, m1, m2, r);
		// min 下に凸 : f(m1) > f(m2)
		// max 上に凸 : f(m1) < f(m2)
		if (f(m1) > f(m2)) {
			l = m1;
		}
		else {
			r = m2;
		}
	}
	// max にするなら変える
	int mini = f(l);
	int ret = l;
	for (int i = l + 1; i <= r; i++) {
		if (mini > f(i)) {
			mini = f(i);
			ret = i;
		}
	}
	return ret;
};

// 実数
auto f = [&](double x) {
	return x > 0;
};
auto ternarySearch = [&](double l, double r) {
	for (int i = 0; i < 200; i++) {
		double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
		// min 下に凸 : f(m1) > f(m2)
		// max 上に凸 : f(m1) < f(m2)
		if (f(m1) > f(m2)) {
			l = m1;
		}
		else {
			r = m2;
		}
	}
	return r;
};