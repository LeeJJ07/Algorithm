#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input;
	stack<char> stk;
	int res = 0, count1 = 0, count2 = 0;
	bool finish = false;

	cin >> input;

	for (int idx = 0; idx < input.size(); idx++)
	{
		if (input[idx] == '(' || input[idx] == '[')
		{
			stk.push(input[idx]);
			if (input[idx] == '(') count1++;
			else count2++;
		}
		else
		{
			if (stk.empty() || (input[idx] == ')' && stk.top() == '[') || (input[idx] == ']' && stk.top() == '('))
			{
				finish = true;
				break;
			}
			else if (input[idx] == ')')
			{
				if (input[idx - 1] == '(')
					res += pow(2, count1) * pow(3, count2);
				count1--;
				stk.pop();
			}
			else
			{
				if (input[idx - 1] == '[')
					res += pow(2, count1) * pow(3, count2);
				count2--;
				stk.pop();
			}
		}
	}

	if (finish || stk.size()) cout << 0 << '\n';
	else cout << res << '\n';
	return 0;
}