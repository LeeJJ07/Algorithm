#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<pair<int,int>> num_count;
vector<int>num;
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	num_count.resize(8004, {0, 0});
	int mx = -4001;
	int mn = 4001;
	double sum = 0, avg = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		num.push_back(a);
		num_count[a + 4000].first++;
		num_count[a + 4000].second = a;
		sum += a;
		mx = max(mx, a);
		mn = min(mn, a);
	}
	avg = round(sum/n);
	if (avg == -0)avg = 0;
	cout << avg << '\n';
	sort(num.begin(), num.end());
	cout << num[n / 2] << '\n';
	sort(num_count.begin(), num_count.end(), cmp);
	if (n > 1 && num_count[0].first == num_count[1].first) {
		cout << num_count[1].second << '\n';
	}
	else {
		cout << num_count[0].second << '\n';
	}
	cout << mx - mn << '\n';
}