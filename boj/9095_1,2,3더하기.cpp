#include <iostream>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> dp(13);
    dp[1] = 1;
    dp[2] = dp[1] + 1;
    dp[3] = dp[2] + dp[1] + 1;
    for (int i = 4; i <= 11; ++i) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}