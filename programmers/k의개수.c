#include <stdio.h>
#include <string.h>

int digitCounter(int n, char k) {
    char num[7] = {0};
    sprintf(num, "%d", n);
    int ret = 0;

    for (size_t i = 0; i < strlen(num); ++i) {
        if (num[i] == k) {
            ++ret;
        }
    }

    return ret;
}

int solution(int i, int j, int k) {
    int ans = 0;
    for (int n = i; n <= j; ++n) {
        ans += digitCounter(n, k + '0');
    }

    return ans;
}

/*
 * sprintf
 */