// 経路復元
// 始点から終点までの経路を取得
// 終点から親を再帰的に辿り始点に着くまでの経路を反転している
// 存在しない場合の戻り値: vector<int>()
vector<int> getPath(int s, int g, vector<int> prev) {
	vector<int> path;
	path.emplace_back(g);
	for (int i = g; i != s; ) {
		if (i == -1)
			return vector<int>();
		path.emplace_back(i = prev[i]);
	}
	reverse(path.begin(), path.end());
	return path;
}