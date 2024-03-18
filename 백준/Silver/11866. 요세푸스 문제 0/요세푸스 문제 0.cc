#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k; cin >> n >> k;
	vector<int> a;
	for (int i = 1; i <= n; i++) {
		a.push_back(i);
	}
	k = k - 1;
	int idx = k;
	vector<int> ret;
	while (true) {
		ret.push_back(a[idx]);
		a.erase(a.begin() + idx);
		if (a.empty())break;
		idx += k;
		if (idx >= a.size()) idx %= a.size();
	}
	cout << "<";
	for (int i = 0; i < ret.size() - 1; i++) {
		cout << ret[i] << ", ";
	}
	cout << ret[ret.size() - 1] << ">\n";
}