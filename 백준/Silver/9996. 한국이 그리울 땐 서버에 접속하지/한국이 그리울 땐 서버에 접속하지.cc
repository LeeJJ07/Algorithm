#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	string o_s;
	cin >> o_s;
	int pos = o_s.find('*');
	string pre = o_s.substr(0, pos);
	string suf = o_s.substr(pos + 1);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (pre.size() + suf.size() > s.size()) cout << "NE\n";
		else {
			if (pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) cout << "DA\n";
			else cout << "NE\n";
		}
	}
}