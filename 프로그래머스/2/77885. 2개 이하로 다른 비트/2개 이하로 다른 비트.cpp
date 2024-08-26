#include <string>
#include <vector>

using namespace std;

long long GetRes(long long num){
    long long i = 0;
    while(1&(num>>i)) ++i;
        
    if(i==0)
        return (num|1L);
    
    num |= (1L<<i);
    num -= (1L << (i-1L));
    
    return num;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer(numbers.size());
    
    for(int i = 0;i<numbers.size();i++){
        
        answer[i] = GetRes(numbers[i]);
            
    }
    
    return answer;
}