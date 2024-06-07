#include <stdio.h>
#include <stdlib.h>

//v2
int solution2(int n) {
    int ans = 0;
    int num = n;

    while(num){
        ans = ans * 3 + num % 3;
        num /= 3;
    }

    return ans;
}


// v1
int solution(int n) {
    char three[40] = {0};
    int num = n;
    int idx = 0;

    while(num){
        three[idx++] = num % 3 + '0';
        num /= 3;
    }

    int ans = strtol(three, NULL, 3);
    return ans;
}