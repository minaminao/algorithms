#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

// Manacher's algorithm
// 奇数長の最長回文を求める
// O(N)
// 戻り値: r[i]: s[i]を中心とする最長の回文の半径 := (全長 + 1) / 2
// 偶数長の回文を求めたい場合はダミー文字を入れる
vector<int> manacher(const string &s) {
	int n = s.size();
	vector<int> r(n);
	int i = 0, j = 0;
	while (i < n) {
		while (i - j >= 0 && i + j < n && s[i - j] == s[i + j]) ++j;
		r[i] = j;
		int k = 1;
		while (i - k >= 0 && i + k < n && k + r[i - k] < j) r[i + k] = r[i - k], ++k;
		i += k; j -= k;
	}
	return r;
}

// ダミー文字挿入
// abc -> a$b$c
string insertDummyChar(const string &s, char dummy = '$') {
	int n = s.size();
	string ret(2 * n - 1, dummy);
	for (int i = 0; i < n; i++)
		ret[i * 2] = s[i];
	return ret;
}

// 偶数長の最長回文を求める
// ret[i] := s[i] と s[i+1] の間を中心とする最長の回文の半径 := 全長 / 2
vector<int> manacherEven(const string &s) {
	int n = s.size();
	vector<int> ret(n - 1);
	vector<int> m = manacher(insertDummyChar(s));
	for (int i = 0; i < n - 1; i++)
		ret[i] = m[i * 2 + 1] / 2;
	return ret;
}

int main() {
	string S = "aababcbabaab";

	dump(manacher(S));
	dump(manacherEven(S));
	return 0;
}