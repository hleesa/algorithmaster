#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// v2
char* toBinaryStr(int n) {
    if (n == 0) {
        return strdup("0");
    }

    char buff[65] = {0};
    int idx = 0;

    while (n) {
        buff[idx++] = n % 2 + '0';
        n /= 2;
    }

    for (int i = 0; i < idx / 2; ++i) {
        int t = buff[i];
        buff[i] = buff[idx - i - 1];
        buff[idx - i - 1] = t;
    }

    return strdup(buff);
}

char* solution2(const char* bin1, const char* bin2) {
    long num1 = strtol(bin1, NULL, 2);
    long num2 = strtol(bin2, NULL, 2);

    char* ans = toBinaryStr(num1 + num2);
    return ans;
}


// v1

long long toDecimal(char* b) {
    long long dec = 0;
    size_t len = strlen(b);
    for (size_t i = 0; i < len; ++i) {
        if (b[i] == '1') {
            dec += (1 << (len - i - 1));
        }
    }
    return dec;
}

long long toBinary(int d) {
    long long bi = 0;
    int begin = 10;
    for (int i = begin; i >= 0; --i) {
        bi = bi * 10;
        if (d >= (1 << i)) {
            d -= (1 << i);
            bi += 1;
        }
    }
    return bi;
}

char* solution(const char* bin1, const char* bin2) {
    long long sum = toBinary(toDecimal(bin1) + toDecimal(bin2));
    char buff[22] = {0};
    sprintf(buff, "%lld", sum);
    size_t len = strlen(buff);
    char* ans = (char*) malloc((len + 1) * sizeof(char));
    memcpy(ans, buff, len + 1);
    return ans;
}
