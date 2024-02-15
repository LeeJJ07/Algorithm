#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		map<string, int> cloth;
		for (int j = 0; j < n; j++) {
			string c, kind;
			cin >> c >> kind;
			cloth[kind]++;
		}
		int result = 1;
		for (auto j = cloth.begin(); j != cloth.end(); j++) {
			result *= (j->second + 1);
		}
		cout << result - 1 << '\n';
	}
}