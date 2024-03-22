#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	int n, num; cin >> n;
	int sum = 0;
	int result = -1001;
	for (int i = 0; i < n; i++) {
		cin >> num;
		sum += num;
		result = max(result, sum);
		if (sum < 0)sum = 0;
	}
	cout << result << '\n';
}