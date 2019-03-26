// population count
// 立っているbitの数を数える
// 後ろから立っているbitを降ろす
int popcount(int x) {
	int ret = 0;
	while (x) {
		x &= x - 1;
		ret++;
	}
	return ret;
}