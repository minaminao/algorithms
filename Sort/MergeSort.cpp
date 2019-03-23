template <class It>
void merge(It l, It m, It r) {
	vector<int> tmp(r - l);
	It it = tmp.begin(), it1 = l, it2 = m;
	while (it1 != m && it2 != r) {
		if (*it1 < *it2)
			*it++ = *it1++;
		else
			*it++ = *it2++;
	}
	while (it1 != m) *it++ = *it1++;
	while (it2 != r) *it++ = *it2++;
	move(tmp.begin(), tmp.end(), l);
};

template <class It>
void mergeSort(It l, It r) {
	if (r - l <= 1)return;
	It m = l + (r - l) / 2;
	mergeSort(l, m);
	mergeSort(m, r);
	merge(l, m, r);
}