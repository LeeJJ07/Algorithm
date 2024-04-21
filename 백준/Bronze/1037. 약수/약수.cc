#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, i, m;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n; m = n;
	while (n--) { cin >> i; v.push_back(i); }
	sort(v.begin(), v.end());
	cout << v[0] * v[m - 1];
}