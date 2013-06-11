#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 10001;
const int MAXM = 50001;

int visited[MAXN];
vector<vector<int> > graph;
int nodes[MAXN];

int dfs(int u) {
    int cost = nodes[u];
    visited[u] = 1;
    for(int i=0; i<graph[u].size(); i++) {
        int v = graph[u][i];
        if(visited[v] == -1) {
            cost += dfs(v);
        }
    }

    return cost;
}

int main(void) {

    int cases;
    scanf("%d", &cases);

    while (cases--) {

        int n,m;
        scanf("%d %d", &n, &m);
        
        graph = vector<vector<int> > (n);
        for(int i=0; i<n; i++) {
            visited[i] = -1;
            scanf("%d", &nodes[i]);
        }

        for(int i=0; i<m; i++) {
            int a,b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        bool possible = true;
        for(int i=0; i<n; i++) {
            if(visited[i] == -1) {
                int cost = dfs(i);
                if(cost != 0) {
                    possible = false;
                    break;
                }
            }
        }

        if(possible) {
            printf("POSSIBLE\n");
        }else {
            printf("IMPOSSIBLE\n");
        }

    }

    return 0;
}
