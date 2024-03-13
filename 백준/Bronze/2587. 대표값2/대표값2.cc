#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int sum = 0;
	vector<int> a(5);
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a.begin(), a.end());
	cout << sum / 5 << '\n' << a[2];
}