#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len) {
    int start = -1, end = -1;
    for(int i = 0;i<arr_len; i++){
        if(arr[i]==2){
            if(start==-1){
                start = i, end = i;
            }else{
                end = i;
            }
        }
    }
    if(start==-1) {
        int* answer = (int*)malloc(sizeof(int));
        answer[0] = -1;
        return answer;
    }
    int* answer = (int*)malloc((end-start+1) * sizeof(int));
    for(int i = start; i<=end; i++){
        answer[i - start] = arr[i];
    }
    return answer;
}