// デバッグ出力をしたいときに読み込む
// オブジェクト名を出力したくない場合は素直にcerrする

using namespace std;
#define dump(...) { cerr << #__VA_ARGS__ << ": "; _dump(__VA_ARGS__); cerr << endl; }

template <typename T1, typename T2>
ostream &operator<<(ostream &, const pair<T1, T2> &);
template <typename ...T>
ostream &operator<<(ostream &, const tuple<T...> &);
template <typename T, size_t N>
ostream &operator<<(ostream &, const array<T, N> &);
#define __DECLARE__(C)    \
    template <typename T> \
    ostream &operator<<(ostream &, const C<T> &);
#define __DECLAREM__(C)               \
    template <typename T1, typename T2> \
    ostream &operator<<(ostream &, const C<T1, T2> &);
__DECLARE__(deque)
__DECLAREM__(map)
__DECLARE__(set)
__DECLARE__(stack)
__DECLARE__(queue)
__DECLARE__(priority_queue)
__DECLARE__(unordered_set)
__DECLAREM__(unordered_map)
__DECLARE__(vector)

// function to print a tuple of any size
template <class Tuple, size_t N>
struct TuplePrinter {
	static void print(ostream &os, const Tuple &t) {
		TuplePrinter<Tuple, N - 1>::print(os, t);
		os << ", " << get<N - 1>(t);
	}
};

template <class Tuple>
struct TuplePrinter<Tuple, 1> {
	static void print(ostream &os, const Tuple &t) { os << get<0>(t); }
};

template <typename ...T>
ostream &operator<<(ostream &os, const tuple<T...> &t) {
	os << '(';
	TuplePrinter<decltype(t), sizeof...(T)>::print(os, t);
	os << ')';
	return os;
}
// end

// function to print a pair
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
	return (os << '(' << p.first << ", " << p.second << ')');
}
// end

// function to print a container
#define __INNER__ \
    os << '['; \
    for (auto it = begin(c); it != end(c); it++) \
		os << (it != begin(c) ? ", " : "") << *it; \
    return os << ']' << endl;

template <typename T, size_t N>
ostream &operator<<(ostream &os, const array<T, N> &c) {
	__INNER__
}

#define __DEFINE__(C) \
    template <typename T> \
    ostream &operator<<(ostream &os, const C<T> &c) { \
        __INNER__ \
    }

#define __DEFINEM__(C) \
    template <typename T1, typename T2> \
    ostream &operator<<(ostream &os, const C<T1, T2> &c) { \
        __INNER__ \
    }

#define __DEFINEW__(C, M1, M2) \
    template <typename T> \
    ostream &operator<<(ostream &os, const C<T> &c) { \
        deque<T> v; \
        for (auto d = c; !d.empty(); d.pop()) v.M1(d.M2()); \
        return os << v; \
    }

__DEFINE__(deque)
__DEFINEM__(map)
__DEFINEW__(priority_queue, emplace_front, top)
__DEFINEW__(queue, emplace_back, front)
__DEFINE__(set)
__DEFINEW__(stack, emplace_front, top)
__DEFINEM__(unordered_map)
__DEFINE__(unordered_set)
__DEFINE__(vector)
// end

// vector<bool>
ostream &operator<<(ostream &os, const vector<bool> &v) {
	for (auto e : v)
		os << e;
	return os;
}

void _dump() {}

void _dump(const char *s) {}

template<typename T>
void _dump(T a) {
	cerr << a;
}

template<class T, size_t N>
void _dump(T(&a)[N]) {
	cerr << '[';
	for (auto i = 0; i < N; i++) {
		cerr << (i ? ", " : "");
		_dump(a[i]);
	}
	cerr << "]" << endl;
}

template<typename T1, typename T2, typename ...Tail>
void _dump(T1 a, T2 b, Tail... tail) {
	cerr << a << ", ";
	_dump(b, tail...);
}
