#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, num; 
	cin >> n >> m;
	set<int> a;
	for (int i = 0; i < n + m; i++) {
		cin >> num; a.insert(num);
	}
	cout << 2 * a.size() - (n + m);
}