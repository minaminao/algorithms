void format() {
	string s; cin >> s;
	char a; int n, k;
	sscanf(s.c_str(), "%c(%d,%d)\n", &a, &n, &k);
}

// 文字列を大文字/小文字に
void stoupper(string& s) { transform(s.begin(), s.end(), s.begin(), ::toupper); }
void stolower(string& s) { transform(s.begin(), s.end(), s.begin(), ::tolower); }