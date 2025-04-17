#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;
    
    int cnt = 0;
    for(int idx = 0; idx < myString.size(); idx++)
    {
        if(myString[idx] == 'x')
        {
            answer.push_back(cnt);
            cnt = 0;
            continue;
        }
        cnt++;
    }
    answer.push_back(cnt);
    
    return answer;
}