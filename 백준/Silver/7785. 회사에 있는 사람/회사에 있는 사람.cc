#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin >> n;
	set<string> s;
	while (n--) {
		string name, sta;
		cin >> name >> sta;
		if (sta == "enter") s.insert(name);
		else s.erase(name);
	}
	vector<string> ret;
	for (auto name : s) {
		ret.push_back(name);
	}
	sort(ret.begin(), ret.end(), cmp);
	for (string name : ret) cout << name << '\n';
}