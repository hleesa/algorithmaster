#include <string.h>
#include <ctype.h>
#include <stdio.h>

int solution2(const char* str) {
    int ans = 0;
    int num = 0;
    size_t len = strlen(str);

    for (size_t i = 0; i <= len; ++i) {
        char c = str[i];

        if (isdigit(c)) {
            num = num * 10 + c - '0';
        } else {
            ans += num;
            num = 0;
        }
    }

    return ans;
}

int solution1(const char* str) {
    int ans = 0;

    for (size_t i = 0; str[i]; ++i) {
        if (!isdigit(str[i])) continue;
        int d_end = i;
        while (str[d_end] != '\0' && isdigit(str[d_end])) ++d_end;
        char buf[1002] = {0,};
        strncpy(buf, str + i, d_end - i);
        int num = 0;
        sscanf(buf, "%d", &num);
        ans += num;
        i += (d_end - i);
    }

    return ans;
}
