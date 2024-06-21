#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());
    stack<pair<int, int>> s;
    for (int i = 0; i < prices.size(); i++)
    {
        while (s.size() && s.top().second > prices[i])
        {
            answer[s.top().first] = i - s.top().first;
            s.pop();
        }
        s.push({ i, prices[i] });
    }
    while (s.size())
    {
        answer[s.top().first] = prices.size() - 1 - s.top().first;
        s.pop();
    }
    return answer;
}