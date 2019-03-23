// 挿入ソート
// O(n^2)
template<typename T>
void insertionSort(vector<T> v) {
	int n = v.size();
	for (int i = 1; i < n; i++) {
		int x = v[i];
		int j = i - 1;
		for (; j >= 0 && v[j] > x; j--)
			v[j + 1] = v[j];
		v[j + 1] = x;
	}
}