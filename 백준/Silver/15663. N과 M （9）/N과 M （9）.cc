#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int n, m;
vector<int> a;
vector<int> result;
int visited[10];
map<string, int> mp;

void dfs() {
	if (result.size() == m) {
		string res = "";
		for (int num : result) {
			res += to_string(num); res += " ";
		}
		if (!mp[res]) {
			cout << res << "\n";
			mp[res]++;
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i])continue;
		result.push_back(a[i]);
		visited[i] = 1;
		dfs();
		visited[i] = 0;
		result.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a.begin(), a.end());
	dfs();
}