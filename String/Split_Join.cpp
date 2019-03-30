// delimiter で区切る
vector<string> split(const string &input, const char &delimiter) {
	vector<string> ret;
	string w;
	for (const char &c : input) {
		if (c == delimiter) {
			ret.emplace_back(w);
			w.clear();
		}
		else w += c;
	}
	if (input.back() == delimiter)ret.emplace_back("");
	else ret.emplace_back(w);
	return ret;
}

// delimiterの連続 と 両脇のdelimiter は無視
vector<string> split(const string &input, const char &delimiter) {
	vector<string> ret;
	string w;
	for (const char &c : input) {
		if (c == delimiter) {
			if (w.size())ret.emplace_back(w);
			w.clear();
		}
		else w += c;
	}
	if (w.size())ret.emplace_back(w);
	return ret;
}

// 結合
string join(const vector<string> &input, const char &separator) {
	string ret = input[0];
	for (int i = 1; i < input.size(); i++) {
		ret += separator;
		ret += input[i];
	}
	return ret;
}