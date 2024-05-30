#include <stdio.h>
#include <string.h>

#define MAX 16

void addEdge(int u, int v, int adj[MAX][MAX]) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

int bfs(int start, int end, int N, int adj[MAX][MAX], int path[MAX]) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int prev[MAX] = {0};
    memset(prev, -1, sizeof(prev));
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int u = queue[front++];
        for (int v = 1; v <= MAX; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = 1;
                prev[v] = u;
                queue[rear++] = v;
                if (v == end) {
                    int pathIdx = 0;
                    for (int at = end; at != -1; at = prev[at]) {
                        path[pathIdx++] = at;
                    }
                    return pathIdx;
                }
            }
        }
    }
    return 0;
}

int main() {
    int N, X, Z, Y = 0;
    int adj[MAX][MAX] = {0};
    int path1[MAX], path2[MAX];
    
    // Input reading
    if (scanf("%d %d %d", &N, &X, &Z) != 3) {
        printf("NO\n");
        return 0;
    }
    char c = getchar();
    if (c != '\n' && c != EOF) {
        ungetc(c, stdin);
        scanf("%d", &Y);
    }
    
    for (int i = 0; i < N; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v, adj);
    }
    
    // No intermediate city
    if (Y == 0) {
        int pathLen = bfs(X, Z, N, adj, path1);
        if (pathLen) {
            printf("%d\n", pathLen - 1);
            for (int i = pathLen - 1; i >= 0; i--) {
                printf("%d%c", path1[i], i > 0 ? ' ' : '\n');
            }
        } else {
            printf("NO\n");
        }
    } else {
        // With intermediate city Y
        int pathLen1 = bfs(X, Y, N, adj, path1);
        if (pathLen1 == 0) {
            printf("NO\n");
            return 0;
        }
        
        int pathLen2 = bfs(Y, Z, N, adj, path2);
        if (pathLen2 == 0) {
            printf("NO\n");
            return 0;
        }
        
        // Merge paths: path1 (X to Y) and path2 (Y to Z)
        printf("%d\n", pathLen1 + pathLen2 - 2);
        for (int i = pathLen1 - 1; i > 0; i--) {
            printf("%d ", path1[i]);
        }
        for (int i = pathLen2 - 1; i >= 0; i--) {
            printf("%d%c", path2[i], i > 0 ? ' ' : '\n');
        }
    }
    
    return 0;
}
