#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	map<string, string> mp;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		mp[a] = b;
	}
	for (int i = 0; i < m; i++) {
		string a; cin >> a;
		cout << mp[a] << '\n';
	}
}