// 文字埋め 破壊的
void fill(string& s, int length, char c = '0') {
	string prefix = "";
	for (int i = s.size(); i < length; i++)prefix += c;
	s = prefix + s;
}

// 文字埋め
string fill(const string &s, int length, char c = '0') {
	string prefix = "";
	for (int i = s.size(); i < length; i++)prefix += c;
	return prefix + s;
}