#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
string input;
map<string, int> temp;
vector<pair<int, string>> v;

bool cmp(pair<int, string> a, pair<int, string> b) {
	if (a.first == b.first) {
		if (a.second.length() == b.second.length()) 
			return a.second < b.second;
		return a.second.length() > b.second.length();
	}
	return a.first > b.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input.length() < m) continue;
		temp[input]++;
	}

	for (auto now : temp) v.push_back({ now.second, now.first });
	sort(v.begin(), v.end(), cmp);
	for (auto now : v) {
		cout << now.second << "\n";
	}
}