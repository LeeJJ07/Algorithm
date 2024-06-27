#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list)
{
    int answer = 1;
    if (num_list.size() > 10) {
        for (int i : num_list)
            answer += i;
        answer--;
    }
    else
        for (int i : num_list)
            answer *= i;
    return answer;
}