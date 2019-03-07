//素集合データ構造
struct UnionFind {
	vector<int> parent;
	int size;
	UnionFind(int n) :parent(n, -1), size(n) {}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y)return false;
		if (sizeOf(x) < sizeOf(y))swap(x, y);
		parent[x] += parent[y]; parent[y] = x; size--;
		return true;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
	int sizeOf(int x) { return -parent[root(x)]; }
};

//素集合データ構造 + 集合内の最小値を求める機能
struct UnionFind_ {
	vector<int> parent;
	vector<int> mini;
	int size;
	UnionFind_(int n) :parent(n, -1), size(n), mini(n) {}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y)return false;
		if (sizeOf(x) < sizeOf(y))swap(x, y);
		parent[x] += parent[y]; parent[y] = x; size--;
		mini[x] = min(mini[x], mini[y]);
		return true;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
	int sizeOf(int x) { return -parent[root(x)]; }
	int minOf(int x) { return mini[root(x)]; }
};

//連結成分にインデックスを割り当てる
struct UnionFind_ {
	vector<int> parent;
	vector<int> idx;
	int size;
	UnionFind_(int n) :parent(n, -1), size(n), idx(n) {
		iota(all(idx), 0);
	}
	bool unite(int x, int y, int i) {
		x = root(x); y = root(y);
		if (x == y)return false;
		if (sizeOf(x) < sizeOf(y))swap(x, y);
		parent[x] += parent[y]; parent[y] = x; size--;
		idx[x] = idx[y] = i;
		return true;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
	int sizeOf(int x) { return -parent[root(x)]; }
	int getIdx(int x) { return idx[root(x)]; }
};

//無向グラフの閉路の検出
//根を連結成分の id として見ると都合がいい
struct UnionFind {
	vector<int> parent;
	vector<bool> cycle;
	int size;
	UnionFind(int n) :parent(n, -1), size(n), cycle(n) {}
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) {
			cycle[x] = true;
			return false;
		}
		if (cycle[x] || cycle[y])cycle[x] = cycle[y] = true;
		if (size_of(x) < size_of(y))swap(x, y);
		parent[x] += parent[y]; parent[y] = x; size--;
		return true;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
	int size_of(int x) { return -parent[root(x)]; }
	bool has_cycle(int x) { return cycle[root(x)]; }
};