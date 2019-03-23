// Quick Sort
// v[i] <= x <= v[j] にする (i<=j) 
// O(N) 
// [l,r]
// STL にある
// partition(v.begin(), v.end(), [x](int i) {return i <= x; }); のように使う。

template<typename T>
int partition(vector<T> &v, int l, int r, T x) {
	int i = l - 1;
	for (int j = l; j < r; j++) {
		if (v[j] <= x) {
			i++;
			swap(v[i], v[j]);
		}
	}
	swap(v[i + 1], v[r]);
	return i + 1;
}

// 平均 O(NlogN) 
// 最悪 O(N^2)
// [l,r]
template<typename T>
void quickSort(vector<T> &v, int l, int r) {
	if (l < r) {
		int k = partition(v, l, r, v[r]);
		quickSort(v, l, k - 1);
		quickSort(v, k + 1, r);
	}
}