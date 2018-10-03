#include <bits/stdc++.h>
const int maxn = 507;
struct { int next, v; } edge[maxn * maxn << 1];
int dep[maxn * maxn], n, m, up[maxn * maxn][27], tot, q;
int index(int x, int y) { return (x - 1) * m + y; }
namespace graph {
    int head[maxn * maxn], cnt;
    void addedge(int u, int v) {
        edge[++cnt] = {head[u], v};
        head[u] = cnt;
    }
}
void bfs() {
    memset(up, 0xff, sizeof(up));
    std::queue<int> que;
    que.push(1);
    dep[1] = 1;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int i = graph::head[u]; i; i = edge[i].next) {
            int v = edge[i].v;
            if (dep[v] == 0) {
                dep[v] = dep[u] + 1;
                up[v][0] = u;
                que.push(v);
            }
        }
    }
    for (int j = 1; j <= 22; j++) {
        for (int i = 1; i <= n * m; i++) {
            if (~up[i][j - 1]) up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
}
int query(int u, int v) {
    if (dep[u] < dep[v]) std::swap(u, v);
    int tmp = dep[u] - dep[v];
    for (int j = 0; tmp; j++) if (tmp & (1 << j)) tmp ^= (1 << j), u = up[u][j];
    if (u == v) return u;
    for (int j = 22; ~j; j--) if (up[u][j] != up[v][j]) u = up[u][j], v = up[v][j];
    return up[u][0];
}
struct Disjoint {
    int pre[maxn * maxn];
    Disjoint() { for (int i = 0; i < maxn * maxn; i++) pre[i] = i; }
    int find(int x) { return x == pre[x] ? x : pre[x] = find(pre[x]); }
    void merge(int x, int y) { if (x != y) pre[x] = y; }
} disjoint;
struct Edge { int u, v, cost; } edges[maxn * maxn << 1];
int main() {
    scanf("%d%d", &n, &m);
    char ch;
    for (int i = 1, cost; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 2; k++) {
                scanf(" %c%d", &ch, &cost);
                if (ch != 'X') {
                    if (ch == 'R') edges[tot++] = {index(i, j), index(i, j + 1), cost};
                    else edges[tot++] = {index(i, j), index(i + 1, j), cost};
                }
            }
        }
    }
    std::sort(edges, edges + tot, [](Edge x, Edge y) { return x.cost > y.cost; });
    for (int i = 0; i < tot; i++) {
        int u = disjoint.find(edges[i].u), v = disjoint.find(edges[i].v);
        if (u != v) {
            graph::addedge(edges[i].u, edges[i].v);
            graph::addedge(edges[i].v, edges[i].u);
            disjoint.merge(u, v);
        }
    }
    bfs();
    scanf("%d", &q);
    for (int i = 0, x, y, a, b; i < q; i++) {
        scanf("%d%d%d%d", &x, &y, &a, &b);
        int u = index(x, y), v = index(a, b), lca = query(u, v);
        printf("%d\n", dep[u] + dep[v] - 2 * dep[lca]);
    }
    return 0;
}
