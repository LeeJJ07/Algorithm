#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer1 = 0, answer2 = 0;
    for(int i = 0 ; i<num_list.size();i++){
        if(i&1)answer1 += num_list[i];
        else answer2+=num_list[i];
    }
    return answer1>answer2?answer1:answer2;
}