#include <iostream>
#include <deque>
using namespace std;

int n, m, input, temp[100004];
deque<int> arr;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> temp[i];
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (!temp[i]) arr.push_back(input);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> input; 
		arr.push_front(input);
		cout << arr.back() << " ";
		arr.pop_back();
	}
}