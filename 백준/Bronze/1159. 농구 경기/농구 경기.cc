#include <vector>
#include <iostream>

using namespace std;

int n;
vector<int> num(26);
string str;

string Result() {
	string res = "";
	for (int idx = 0;idx < 26;idx++) {
		if (num[idx] < 5) continue;
		res += (idx + 'a');
	}

	if (res == "")
		res = "PREDAJA";

	return res;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n--)
	{
		cin >> str;
		num[str[0] - 'a']++;
	}

	cout << Result();
}