//v2
int getDivisor2(int n) {
    int divs = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i == n / i)
                ++divs;
            else
                divs += 2;
        }
    }
    return divs;
}

//v1
int getDivisor(int n) {
    int divs = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0)
            ++divs;
    }
    return divs;
}

int solution(int left, int right) {
    int ans = 0;
    for (int i = left; i <= right; ++i) {
        int divs = getDivisor(i);
        if (divs % 2 == 0) {
            ans += i;
        }
        else {
            ans -= i;
        }
    }

    return ans;
}