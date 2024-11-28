#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<long long>> board;
vector<vector<long long>> dp;

int dy[] = {1, 0};
int dx[] = {0, 1};

long long dfs(int y, int x){
    if (y + 1 == N && x + 1 == N) return 1;
    else if (dp[y][x] != -1) return dp[y][x];

    dp[y][x] = 0;
    for (int i = 0; i < 2; ++i) {
        int ny = y + board[y][x] * dy[i];
        int nx = x + board[y][x] * dx[i];
        if (ny >= N || nx >= N) continue;
        dp[y][x] += dfs(ny, nx);
    }

    return dp[y][x];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    board = vector<vector<long long>>(N, vector<long long>(N));
    dp = vector<vector<long long>>(N, vector<long long>(N, -1));
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> board[y][x];
        }
    }

    cout << dfs(0, 0);
    return 0;
}