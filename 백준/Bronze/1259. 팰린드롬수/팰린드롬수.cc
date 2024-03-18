#include <iostream>
#include <algorithm>
using namespace std;

bool pl(string str) {
	string sstr = str;
	reverse(str.begin(),str.end());
	if (str == sstr) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while (true) {
		string str; cin >> str;
		if (str == "0") break;
		if (pl(str)) cout << "yes\n";
		else cout << "no\n";
	}
}