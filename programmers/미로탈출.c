#include <string.h>

#define M_MAX 101
#define INF 987654321

typedef struct {
    int y;
    int x;
} Pos;

int bfs(const char* maps[], size_t maps_len, Pos begin, Pos end) {
    const int dy[] = {-1, 1, 0, 0};
    const int dx[] = {0, 0, -1, 1};
    const int y_max = maps_len;
    const int x_max = strlen(maps[0]);

    int dist[M_MAX][M_MAX];
    for (size_t y = 0; y < M_MAX; ++y) {
        for (size_t x = 0; x < M_MAX; ++x) {
            dist[y][x] = INF;
        }
    }

    Pos q[M_MAX * M_MAX];
    size_t q_front = 0, q_back = 0;

    q[q_back++] = begin;
    dist[begin.y][begin.x] = 0;

    while (q_front < q_back) {
        Pos cur = q[q_front++];

        for (int d = 0; d < 4; ++d) {
            int ny = cur.y + dy[d];
            int nx = cur.x + dx[d];

            if (ny < 0 || ny >= y_max || nx < 0 || nx >= x_max) continue;
            if (maps[ny][nx] == 'X') continue;
            if (dist[ny][nx] != INF) continue;

            Pos next = {ny, nx};
            q[q_back++] = next;
            dist[ny][nx] = dist[cur.y][cur.x] + 1;
        }
    }

    return dist[end.y][end.x];
}

int solution(const char* maps[], size_t maps_len) {
    Pos begin = {0}, lever = {0}, end = {0};
    size_t x_len = strlen(maps[0]);

    for (size_t y = 0; y < maps_len; ++y) {
        for (size_t x = 0; x < x_len; ++x) {
            if (maps[y][x] == 'S') {
                begin = (Pos) {y, x};
            }
            else if (maps[y][x] == 'L') {
                lever = (Pos) {y, x};
            }
            else if (maps[y][x] == 'E') {
                end = (Pos) {y, x};
            }
        }
    }

    int dist_to_lever = bfs(maps, maps_len, begin, lever);
    int dist_to_end = bfs(maps, maps_len, lever, end);

    if (dist_to_lever == INF || dist_to_end == INF) {
        return -1;
    }

    return dist_to_lever + dist_to_end;
}