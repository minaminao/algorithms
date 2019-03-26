// 四則演算パーサー	
/*
式 = 項, { ('+' | '-'),項 };
項 = c, { ('*' | '/'),c };
c = '(', 式, ')' | integer;
*/
struct Parser {
	using Iter = string::const_iterator;
	Iter it;
	Parser(Iter it) :it(it) {}
	void cmp(char expected) {
		if (*it != expected) {
			throw 0;
			cerr << *it << " is not " << expected << endl;
		}
	}
	int a() {
		int ret = b();
		while (true) {
			if (*it == '+') {
				it++;
				ret += b();
			}
			else if (*it == '-') {
				it++;
				ret -= b();
			}
			else break;
		}
		return ret;
	}
	int b() {
		int ret = c();
		while (true) {
			if (*it == '*') {
				it++;
				ret *= c();
			}
			else if (*it == '/') {
				it++;
				ret /= c();
			}
			else break;
		}
		return ret;
	}
	int c() {
		int ret;
		if (*it == '(') {
			it++;
			ret = a();
			cmp(')');
			it++;
		}
		else ret = integer();
		return ret;
	}
	int integer() {
		int ret = 0;
		while (isdigit(*it)) {
			ret *= 10;
			ret += *it - '0';
			it++;
		}
		return ret;
	}
};

// 多項式パーサー
#include "Polynomial.cpp"
struct Parser {
	using Iter = string::const_iterator;
	const char kTerminator = '$';
	string s;
	Iter it;
	Parser(const string &t) :s(t) { s += kTerminator; it = s.begin(); }
	void cmp(char expected) { if (*it != expected)cerr << *it << " is not " << expected << endl; assert(*it == expected); }
	Polynomial a() {
		Polynomial ret = b();
		while (true) {
			if (*it == '+') {
				it++;
				ret += b();
			}
			else if (*it == '-') {
				it++;
				ret -= b();
			}
			else break;
		}
		return ret;
	}
	Polynomial b() {
		int coef = integer();
		int degree = 0;
		if (*it == 'x') {
			coef = max(1, coef);
			it++;
			if (*it == '^') {
				it++;
				degree = integer();
			}
			else
				degree = 1;
		}
		return Polynomial(degree + 1, coef);
	}
	int integer() {
		int ret = 0;
		while (isdigit(*it)) {
			ret *= 10;
			ret += *it - '0';
			it++;
		}
		return ret;
	}
};


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	for (int N, M; cin >> N >> M && N;) {
		rep(i, 0, M) {
			int u, v; string p;
			cin >> u >> v >> p;
			dump(p);
			Parser parser(p);
			Polynomial poly = parser.a();
			dump(poly.n, poly.coefs);
		}
	}

	try {

	}
	catch (...) {

	}
	return 0;
}