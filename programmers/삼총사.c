#include <stdio.h>

//v2
int solution2(int number[], size_t number_len) {
    int ans = 0;
    for (size_t i = 0; i + 2 < number_len; ++i) {
        for (size_t j = i + 1; j + 1 < number_len; ++j) {
            for (int k = j + 1; k < number_len; ++k) {
                if (number[i] + number[j] + number[k] == 0) {
                    ++ans;
                }
            }
        }
    }
    return ans;
}


//v1
int threeCounter(int idx, int cnt, int sum, int number[], size_t number_len) {
    if (cnt == 3) {
        if (sum == 0)
            return 1;
        return 0;
    }
    if (idx == number_len)
        return 0;
    int ret = 0;
    ret += threeCounter(idx + 1, cnt, sum, number, number_len);
    ret += threeCounter(idx + 1, cnt + 1, sum + number[idx], number, number_len);
    return ret;
}

int solution(int number[], size_t number_len) {
    int ans = threeCounter(0, 0, 0, number, number_len);
    return ans;
}