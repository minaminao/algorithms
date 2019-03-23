// 配列の i 番目をタプルとして結びつけてソート
//
// vector<int> v(N), idx(N);
// iota(idx.begin(), idx.end(), 0);
// tiedSort(v, idx);
// のように使うと便利
template<class T, class ...Tail>
void tiedSort(vector<T> &a, vector<Tail>&... tail) {
	int n = a.size();
	using S = tuple<T, Tail...>;
	vector<S> s(n);
	for (int i = 0; i < n; i++)
		s[i] = make_tuple(a[i], tail[i]...);
	sort(s.begin(), s.end());
	for (int i = 0; i < n; i++)
		tie(a[i], tail[i]...) = s[i];
}