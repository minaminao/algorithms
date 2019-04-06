// Max Binary Heap
// priority_queue の5倍くらい早い
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2467391
using Val = tuple<int, int>;
const int MAX_N = 2000010;
Val heap[MAX_N];
int sz = 0;
void push(Val x) {
	int v = sz++;
	while (v > 0) {
		int p = (v - 1) / 2;
		if (heap[p] >= x)break;
		heap[v] = heap[p];
		v = p;
	}
	heap[v] = x;
}
const Val pop() {
	Val ret = heap[0];
	Val back = heap[--sz];
	int v = 0;
	while (v * 2 + 1 < sz) {
		// l と r のうち小さいほうと交換したい
		int l = v * 2 + 1, r = v * 2 + 2;
		int u = (r >= sz || heap[l] > heap[r]) ? l : r;
		// もう逆転していない
		if (heap[u] <= back)break;
		heap[v] = heap[u];
		v = u;
	}
	heap[v] = back;
	return ret;
}
const Val top() {
	return heap[0];
}