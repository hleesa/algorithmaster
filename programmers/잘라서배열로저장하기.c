#include <stdlib.h>
#include <string.h>

char** solution(const char* my_str, int n) {
    size_t str_len = strlen(my_str);
    size_t num_chunks = (str_len + n - 1) / n;
    char** ans = (char**) malloc(num_chunks * sizeof(char*));

    for (size_t i = 0; i < num_chunks; ++i) {
        ans[i] = (char*) malloc((n + 1) * sizeof(char));
        strncpy(ans[i], &my_str[n * i], n);
        ans[i][n] = '\0';
    }

    return ans;
}