#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int ans = 0;
    int num = order;

    while (num) {
        int digit = num % 10;
        if (digit != 0 && digit % 3 == 0)
            ++ans;
        num /= 10;
    }
    return ans;
}