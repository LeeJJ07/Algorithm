#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    sort(num_list.begin(), num_list.end());
    
    for(int index = 5; index < num_list.size(); index++)
        answer.push_back(num_list[index]);
    
    return answer;
}