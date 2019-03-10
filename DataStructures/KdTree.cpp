/*
k-d tree
k次元ユークリッド空間の点を空間分割するデータ構造

クエリ
領域内探索
最近傍探索
k-最近傍探索
半径内探索
*/

//静的 2-d tree
//領域内の点を返す
using Point = pair<int, int>;
#define x first
#define y second
//struct Point {
//	int x, y;
//	Point() {}
//	Point(int x, int y) :x(x), y(y) {}
//};
bool base_y(const Point &p1, const Point &p2) { return p1.y == p2.y ? p1.x < p2.x : p1.y < p2.y; }

struct StaticKdTree {
	using It = vector<Point>::iterator;
	int n;
	vector<Point> ps;
	vector<Point> tree;
	StaticKdTree(const vector<Point> &ps) :n(ps.size()), ps(ps), tree(n) {
		build(0, n, true);
	}
	//平均 O(nlogn)
	void build(int l, int r, bool is_x_base) {
		if (l >= r)return;
		int m = (l + r) / 2;
		It first = ps.begin() + l,
			nth = ps.begin() + m,
			last = ps.begin() + r;
		//平均 O(r-l)
		if (is_x_base)
			nth_element(first, nth, last);
		else
			nth_element(first, nth, last, base_y);
		tree[m] = *nth;
		build(l, m, !is_x_base);
		build(m + 1, r, !is_x_base);
	}
	bool inrange(const Point &p, int sx, int sy, int tx, int ty) {
		return sx <= p.x&&p.x <= tx && sy <= p.y&&p.y <= ty;
	}
	void query(int sx, int sy, int tx, int ty, vector<Point> &ret) {
		query(0, n, true, sx, sy, tx, ty, ret);
	}
	void query(int l, int r, bool is_x_base, int sx, int sy, int tx, int ty, vector<Point> &ret) {
		dump(l, r, is_x_base, sx, sy, tx, ty);
		if (l >= r)return;
		int m = (l + r) / 2;
		Point p = tree[m];
		dump(p);
		if (is_x_base) {
			if (tx < p.x) {
				query(l, m, !is_x_base, sx, sy, tx, ty, ret);
			}
			else if (p.x < sx) {
				query(m + 1, r, !is_x_base, sx, sy, tx, ty, ret);
			}
			else {
				if (inrange(p, sx, sy, tx, ty))ret.emplace_back(p);
				query(l, m, !is_x_base, sx, sy, tx, ty, ret);
				query(m + 1, r, !is_x_base, sx, sy, tx, ty, ret);
			}
		}
		else {
			if (ty < p.y) {
				query(l, m, !is_x_base, sx, sy, tx, ty, ret);
			}
			else if (p.y < sy) {
				query(m + 1, r, !is_x_base, sx, sy, tx, ty, ret);
			}
			else {
				if (inrange(p, sx, sy, tx, ty))ret.emplace_back(p);
				query(l, m, !is_x_base, sx, sy, tx, ty, ret);
				query(m + 1, r, !is_x_base, sx, sy, tx, ty, ret);
			}
		}
	}
};

//http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2237631
//静的 2-d tree
//領域内の点のインデックスを返す
//高速化したい
namespace _ {
	using Point = pair<int, int>;
#define x first
#define y second
	struct Node {
		Point p;
		int idx;
		Node() {}
		Node(const Point &p, int idx) :p(p), idx(idx) {}
	};
	bool base_x(const Node &n1, const Node &n2) {
		const Point &p1 = n1.p, &p2 = n2.p;
		return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
	}
	bool base_y(const Node &n1, const Node &n2) {
		const Point &p1 = n1.p, &p2 = n2.p;
		return p1.y == p2.y ? p1.x < p2.x : p1.y < p2.y;
	}

	struct StaticKdTree {
		int n;
		vector<Node> nodes;
		using It = vector<Node>::iterator;
		vector<Node> tree;
		StaticKdTree(const vector<Point> &ps) :n(ps.size()), nodes(n), tree(n) {
			rep(i, 0, n) {
				nodes[i].p = ps[i];
				nodes[i].idx = i;
			}
			build(0, n, true);
		}
		//平均 O(nlogn)
		void build(int l, int r, bool is_x_base) {
			if (l >= r)return;
			int m = (l + r) / 2;
			It first = nodes.begin() + l,
				nth = nodes.begin() + m,
				last = nodes.begin() + r;
			//平均 O(r-l)
			if (is_x_base)
				nth_element(first, nth, last, base_x);
			else
				nth_element(first, nth, last, base_y);
			tree[m] = *nth;
			build(l, m, !is_x_base);
			build(m + 1, r, !is_x_base);
		}
		bool inrange(const Point &p, int sx, int sy, int tx, int ty) {
			return sx <= p.x&&p.x <= tx && sy <= p.y&&p.y <= ty;
		}
		void query(int sx, int sy, int tx, int ty, vector<int> &idxs) {
			query(0, n, true, sx, sy, tx, ty, idxs);
		}
		void query(int l, int r, bool is_x_base, int sx, int sy, int tx, int ty, vector<int> &idxs) {
			dump(l, r, is_x_base, sx, sy, tx, ty);
			if (l >= r)return;
			int m = (l + r) / 2;
			Node node = tree[m];
			Point p = node.p;
			dump(p);
			if (is_x_base) {
				if (tx < p.x) {
					query(l, m, !is_x_base, sx, sy, tx, ty, idxs);
				}
				else if (p.x < sx) {
					query(m + 1, r, !is_x_base, sx, sy, tx, ty, idxs);
				}
				else {
					if (inrange(p, sx, sy, tx, ty))idxs.emplace_back(node.idx);
					query(l, m, !is_x_base, sx, sy, tx, ty, idxs);
					query(m + 1, r, !is_x_base, sx, sy, tx, ty, idxs);
				}
			}
			else {
				if (ty < p.y) {
					query(l, m, !is_x_base, sx, sy, tx, ty, idxs);
				}
				else if (p.y < sy) {
					query(m + 1, r, !is_x_base, sx, sy, tx, ty, idxs);
				}
				else {
					if (inrange(p, sx, sy, tx, ty))idxs.emplace_back(node.idx);
					query(l, m, !is_x_base, sx, sy, tx, ty, idxs);
					query(m + 1, r, !is_x_base, sx, sy, tx, ty, idxs);
				}
			}
		}
	};
}