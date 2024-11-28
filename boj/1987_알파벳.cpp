#include <iostream>
#include <vector>

using namespace std;

int R, C;
vector<vector<char>> board;
vector<int> vis;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int dfs(int y, int x, int cnt) {
    if (y < 0 || y >= R || x < 0 || x >= C || vis[board[y][x]] ) return cnt;

    vis[board[y][x]] = true;
    int ret = 0;
    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        ret = max(dfs(ny, nx, cnt + 1), ret);
    }
    vis[board[y][x]] = false;

    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    board = vector<vector<char>>(R, vector<char>(C));
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> board[r][c];
        }
    }
    vis = vector<int>(256, false);

    cout << dfs(0, 0, 0);
    return 0;
}

/*
int R, C;
vector<vector<char>> board;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int maxCnt = 0;

void dfs(int y, int x, int vis, int cnt) {
    maxCnt = max(cnt, maxCnt);

    for (int i = 0; i < 4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        int next = board[ny][nx] - 'A';
        if (vis & (1 << next)) continue;
        dfs(ny, nx, vis | (1 << next), cnt + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    board = vector<vector<char>>(R, vector<char>(C));
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> board[r][c];
        }
    }

    dfs(0, 0, 1 << (board[0][0] - 'A'), 1);
    cout << maxCnt;
    return 0;
}
*/