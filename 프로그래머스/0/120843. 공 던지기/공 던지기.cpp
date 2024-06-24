#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k)
{
    int answer = 0;
    while(--k){
        
        answer+=2;
        if(answer >=numbers.size())
            answer-=numbers.size();
    }
    
    return numbers[answer];
}