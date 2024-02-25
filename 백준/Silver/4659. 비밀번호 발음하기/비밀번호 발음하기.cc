#include <iostream>

using namespace std;

bool check(string str) {
	bool first = false;
	int mm = 0;
	int jj = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'a' || str[i] == 'o' || str[i] == 'i' || str[i] == 'e' || str[i] == 'u') {
			first = true;
			mm++;
			jj = 0;
			if (mm == 3) {
				return false;
			}
		}
		else {
			mm = 0;
			jj++;
			if (jj == 3)
				return false;
		}
		if (i > 0) {
			if ((str[i] != 'e' && str[i] != 'o') && str[i] == str[i - 1])
				return false;
		}
	}
	return first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string str;
		cin >> str;
		if (str == "end")
			break;
		if (check(str)) {
			cout << "<" << str << "> is acceptable.\n";
		}
		else {
			cout << "<" << str << "> is not acceptable.\n";
		}
	}
}