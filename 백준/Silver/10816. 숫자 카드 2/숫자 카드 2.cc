#include <iostream>
#include <map>
using namespace std;

int n, m, num;
map<int, int> my;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num; my[num]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num; cout << my[num] << ' ';
	}
}