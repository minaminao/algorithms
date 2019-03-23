// 転倒数（inversion number）
// O(n log n)
// a[i] > a[j] かつ i < j である組の数
//
// Verified:
//   http://arc075.contest.atcoder.jp/submissions/1481787

template <class It>
long long merge(It l, It m, It r) {
	long long cnt = 0;
	vector<int> tmp(r - l);
	It it = tmp.begin(), it1 = l, it2 = m;
	while (it1 != m && it2 != r) {
		if (*it1 < *it2)
			*it++ = *it1++;
		else
			*it++ = *it2++, cnt += m - it1;
	}
	while (it1 != m) *it++ = *it1++;
	while (it2 != r) *it++ = *it2++;
	move(tmp.begin(), tmp.end(), l);
	return cnt;
};

template <class It>
long long mergeSort(It l, It r) {
	if (r - l <= 1)return 0;
	long long cnt = 0;
	It m = l + (r - l) / 2;
	cnt += mergeSort(l, m);
	cnt += mergeSort(m, r);
	cnt += merge(l, m, r);
	return cnt;
}

// a から b に変えるための最小 swap 回数
// b をソート済みの順列とみなして転倒数を求めればいい
// not verified
template <class T>
long long minSwapCost(vector<T> a, vector<T> b) {
	int n = a.size();
	unordered_map<T, int> mp;
	rep(i, 0, n)mp[b[i]] = i;
	vector<int> v(n);
	rep(i, 0, n)
		v[i] = mp[a[i]];
	return mergeSort(v.begin(), v.end());
}
