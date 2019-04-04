int mex(const set<int> &st) {
	int c = 0;
	for (auto x : st) {
		if (x == c)
			c++;
		else
			break;
	}
	return c;
}