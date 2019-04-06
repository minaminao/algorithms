using Weight = int;
struct Edge {
	int s, d; Weight w;
	Edge() {};
	Edge(int s, int d, Weight w) : s(s), d(d), w(w) {};
};
bool operator<(const Edge &e1, const Edge &e2) { return e1.w == e2.w ? (e1.s == e2.s ? e1.d < e2.d : e1.s < e2.s) : e1.w < e2.w; }
bool operator>(const Edge &e1, const Edge &e2) { return e2 < e1; }
inline ostream &operator<<(ostream &os, const Edge &e) { return (os << '(' << e.s << ", " << e.d << ", " << e.w << ')'); }

using Edges = vector<Edge>;
using Graph = vector<Edges>;
using Array = vector<Weight>;
using Matrix = vector<Array>;

void addArc(Graph &g, int s, int d, Weight w = 1) {
	g[s].emplace_back(s, d, w);
}
void addEdge(Graph &g, int a, int b, Weight w = 1) {
	addArc(g, a, b, w);
	addArc(g, b, a, w);
}

auto getEdges = [](const Graph &g) {
	Edges ret;
	for (auto &es : g)
		for (auto &e : es)
			ret.emplace_back(e);
	return ret;
};