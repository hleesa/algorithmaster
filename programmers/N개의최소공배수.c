#include <stdio.h>


//v2
int gcd2(int a, int b){
    int c;
    while(b){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b){
    return a * (b / gcd2(a,b));
}

int solution2(int arr[], size_t arr_len) {
    int ans = arr[0];
    for(size_t i = 1; i < arr_len; ++i){
        ans = lcm(ans, arr[i]);
    }
    return ans;
}


//v1
int gcd(int a, int b) {
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int solution(int arr[], size_t arr_len) {
    int ans = arr[0];
    for (size_t i = 1; i < arr_len; ++i) {
        ans = ans * (arr[i] / gcd(ans, arr[i]));
    }

    return ans;
}