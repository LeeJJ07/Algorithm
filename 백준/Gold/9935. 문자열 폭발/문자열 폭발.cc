#include <iostream>
using namespace std;

string str, c, ret;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> str >> c;
	for (char a : str) {
		ret += a;
		if (ret.size() >= c.size() && ret.substr(ret.size() - c.size(), c.size()) == c) {
			ret.erase(ret.end() - c.size(), ret.end());
		}
	}
	if (ret.size()) cout << ret << '\n';
	else cout << "FRULA\n";
}