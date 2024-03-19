#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string str; cin >> str;
	set<string> st;
	for (int L = 0; L < str.length(); L++) {
		int s = 0, e = L;
		while (e < str.length()) {
			st.insert(str.substr(s, e - s + 1));
			s++; e++;
		}
	}
	cout << st.size() << '\n';
}