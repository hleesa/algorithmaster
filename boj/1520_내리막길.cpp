#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> dp;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int dfs(int y, int x){
    if (y + 1 == N && x + 1 == M) return 1;
    else if (dp[y][x] != -1) return dp[y][x];
    dp[y][x] = 0;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        else if (map[ny][nx] >= map[y][x]) continue;
        dp[y][x] += dfs(ny, nx);
    }
    return dp[y][x];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    map = vector<vector<int>>(N, vector<int>(M));
    dp = vector<vector<int>>(N, vector<int>(M, -1));
    for (int y = 0; y < N; ++y){
        for (int x = 0; x < M; ++x) {
            cin >> map[y][x];
        }
    }

    cout << dfs(0, 0);
    return 0;
}