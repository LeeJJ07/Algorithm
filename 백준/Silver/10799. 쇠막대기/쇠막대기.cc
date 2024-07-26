#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	stack<char> stk;
	string input;
	cin >> input;

	int res = 0, count = 0;

	for (int idx = 0; idx < input.size(); idx++)
	{
		if (input[idx] == '(')
		{
			stk.push(input[idx]);
			count++;
		}
		else
		{
			stk.pop();
			count--;
			if (input[idx - 1] == '(')
				res += count;
			else res += 1;
		}
	}

	cout << res << '\n';

	return 0;
}