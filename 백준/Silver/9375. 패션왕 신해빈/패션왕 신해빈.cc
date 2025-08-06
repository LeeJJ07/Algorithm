#include <iostream>
#include <map>

using namespace std;

int n, m;
string str1, str2;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n--) {

		map<string, int> c;
		cin >> m;
		while (m--) {
			cin >> str1 >> str2;
			c[str2]++;
		}

		int res = 1;
		for (auto iter = c.begin(); iter != c.end();iter++)
			res *= (iter->second + 1);
		cout << res - 1 << '\n';
	}
}