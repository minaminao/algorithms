// –ñ” –¢ƒ\[ƒg
vector<int> getDivisors(int x) {
	vector<int> ret;
	int i;
	for (i = 1; i*i < x; i++) {
		if (x%i)continue;
		ret.emplace_back(i);
		ret.emplace_back(x / i);
	}
	if (i*i == x)
		ret.emplace_back(i);
	return ret;
}