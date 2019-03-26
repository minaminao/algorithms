// 座標圧縮
template<typename T>
vector<T> compress(vector<T> v) {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	return v;
}

template<typename T>
int index(const vector<T> &zip, T i) { return lower_bound(zip.begin(), zip.end(), i) - zip.begin(); }

void solve() {
	vector<int> v;
	vector<int> zip = compress(v);
	int idx = index(zip, INF);
}

// 座標圧縮(map)
// 戻り値: zip[圧縮前の座標]:圧縮後の座標 (zip.size()<=10^5なら高速に動作)
template<typename T>
map<T, T> compress(vector<T> v) {
	map<T, T> zip;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (T i = 0; i < v.size(); i++) zip[v[i]] = i;
	return zip;
}