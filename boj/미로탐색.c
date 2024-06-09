#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 101
#define INF INT_MAX

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

typedef struct {
    int y;
    int x;
} Dot;

int bfs(int maze[][MAX_SIZE], const int Y_MAX, const int X_MAX) {
    int dist[MAX_SIZE][MAX_SIZE] = {0};
    for (int y = 0; y < Y_MAX; ++y) {
        for (int x = 0; x < X_MAX; ++x) {
            dist[y][x] = INF;
        }
    }
    Dot q[MAX_SIZE * MAX_SIZE];
    int q_front = 0, q_back = 0;

    q[q_back++] = (Dot) {0, 0};
    dist[0][0] = 1;

    while (q_front < q_back) {
        Dot cur = q[q_front++];
        for (int d = 0; d < 4; ++d) {
            int ny = cur.y + dy[d];
            int nx = cur.x + dx[d];
            if (ny < 0 || ny >= Y_MAX || nx < 0 || nx >= X_MAX) {
                continue;
            }
            else if (maze[ny][nx] != 1) {
                continue;
            }
            else if (dist[ny][nx] != INF) {
                continue;
            }

            dist[ny][nx] = dist[cur.y][cur.x] + 1;
            Dot next = {ny, nx};
            q[q_back++] = next;
        }
    }
    return dist[Y_MAX - 1][X_MAX - 1];
}

void dfs(Dot pos, int maze[][MAX_SIZE], int dist[][MAX_SIZE], const int Y_MAX, const int X_MAX, int cost) {
    dist[pos.y][pos.x] = cost;

    if (pos.y == Y_MAX - 1 && pos.x == X_MAX - 1) {
        return;
    }

    for (int d = 0; d < 4; ++d) {
        int ny = pos.y + dy[d];
        int nx = pos.x + dx[d];
        if (ny < 0 || ny >= Y_MAX || nx < 0 || nx >= X_MAX) {
            continue;
        }
        else if (maze[ny][nx] != 1) {
            continue;
        }
        else if (cost + 1 >= dist[ny][nx]) {
            continue;
        }
        Dot next = {ny, nx};
        dfs(next, maze, dist, Y_MAX, X_MAX, cost + 1);
    }
}

int main() {
    int N, M;
    int maze[MAX_SIZE][MAX_SIZE] = {0};

    scanf("%d %d", &N, &M);
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            scanf("%1d", &maze[y][x]);
        }
    }

//    int dist[MAX_SIZE][MAX_SIZE];
//    for (int y = 0; y < N; ++y) {
//        for (int x = 0; x < M; ++x) {
//            dist[y][x] = INF;
//        }
//    }
//    Dot begin = {0, 0};
//    dfs(begin, maze, dist, N, M, 1);
//    int ans = dist[N - 1][M - 1];

    int ans = bfs(maze, N, M);
    printf("%d\n", ans);
    return 0;
}