#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int v;
	cin >> v;
	int result = 0;
	for (int i = 0; i < n; i++) if (a[i] == v) result++;
	cout << result << '\n';
}