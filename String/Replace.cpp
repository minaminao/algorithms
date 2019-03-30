// inputに含まれるsearchを全てformatに置き換え 破壊的
void replace_all(string& input, const string& search, const string& format) {
	string::size_type pos = input.find(search);
	while (pos != string::npos) {
		input.replace(pos, search.size(), format);
		pos = input.find(search, pos + format.size());
	}
}

// inputに含まれるsearchを全てformatに置き換え 非破壊的
string replace_all_copy(string input, const string& search, const string& format) {
	string::size_type pos = input.find(search);
	while (pos != string::npos) {
		input.replace(pos, search.size(), format);
		pos = input.find(search, pos + format.size());
	}
	return input;
}
