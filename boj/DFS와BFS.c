#include <stdio.h>
#include <stdlib.h>

#define N_MAX 1002

void dfs(int adj[][N_MAX], int* adj_size, int* vis, int v) {
    if (vis[v]) return;
    vis[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < adj_size[v]; ++i) {
        dfs(adj, adj_size, vis, adj[v][i]);
    }
}

void bfs(int adj[][N_MAX], int* adj_size, int v) {
    int q[N_MAX] = {0,};
    int vis[N_MAX] = {0,};
    int q_front = 0, q_back = 0;
    vis[v] = 1;
    q[q_back++] = v;

    while (q_front < q_back) {
        int cur = q[q_front++];
        printf("%d ", cur);
        for (int i = 0; i < adj_size[cur]; ++i) {
            int next = adj[cur][i];
            if (vis[next]) continue;
            vis[next] = 1;
            q[q_back++] = next;
        }
    }
}

int compare(const void* l, const void* r) {
    return *(int*) l - *(int*) r;
}

int main() {
    int adj[N_MAX][N_MAX] = {0,};
    int adj_size[N_MAX] = {0,};
    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);

    for (int i = 0; i < M; ++i) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);

        adj[v1][adj_size[v1]++] = v2;
        adj[v2][adj_size[v2]++] = v1;
    }

    for (int i = 1; i <= N; ++i) {
        qsort(adj[i], adj_size[i], sizeof(int), compare);
    }

    int vis[N_MAX] = {0,};
    dfs(adj, adj_size, vis, V);
    printf("\n");
    bfs(adj, adj_size, V);

    return 0;
}