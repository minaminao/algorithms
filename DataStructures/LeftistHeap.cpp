// Leftist Heap (min)
// Verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3461949
template<class T>
struct LeftistHeap {
	struct Node {
		Node *l, *r;
		int d;
		T val;
		Node(const T &val) :l(NULL), r(NULL), d(0), val(val) {}
	};
	Node *root;
	int sz;
	LeftistHeap() :root(NULL), sz(0) {}

	Node *meld(Node *a, Node *b) {
		if (!a)return b;
		if (!b)return a;
		// a < b にして a.r (> a) と b (> a) を meld
		if (a->val > b->val)swap(a, b);
		a->r = meld(a->r, b);
		// 左の子の最も近い葉までの距離 > 右の子の最も近い葉までの距離 にする
		if (!a->l || a->l->d < a->r->d)swap(a->l, a->r);
		a->d = (a->r ? a->r->d : 0) + 1;
		return a;
	}
	void meld(LeftistHeap &h) {
		root = meld(root, h.root);
		sz += h.size();
		h.root = NULL;
		h.sz = 0;
	}
	void push(const T &x) {
		root = meld(new Node(x), root);
		sz++;
	}
	void pop() {
		root = meld(root->l, root->r);
		sz--;
	}
	T top() {
		assert(root);
		return root->val;
	}
	int size()const {
		return sz;
	}
};
