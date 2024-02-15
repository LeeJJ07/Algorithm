#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	map<string, int> a;
	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		a[name]++;
	}
	for (int i = 0; i < M; i++) {
		string name;
		cin >> name;
		a[name]++;
	}
	set<string>result;
	int count = 0;
	for (auto iter = a.begin(); iter != a.end(); iter++) {
		if (iter->second == 2) {
			count++;
			result.insert(iter->first);
		}
	}
	cout << count << '\n';
	for (string name : result)
		cout << name << '\n';
}