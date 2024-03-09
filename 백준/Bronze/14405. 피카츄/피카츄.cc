#include <iostream>
using namespace std;

string s[] = { "pi", "ka", "chu" };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;
	int i;
	for (i = 0; i < str.size();) {
		int j;
		for (j = 0; j < 3; j++) {
			if (s[j] == str.substr(i, s[j].size())) {
				i += s[j].size();
				break;
			}
		}
		if (j == 3) break;
	}
	if (i == str.size()) cout << "YES";
	else cout<< "NO";
}