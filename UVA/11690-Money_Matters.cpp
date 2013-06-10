#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 10001;
const int MAXM = 50001;

int visited[MAXN];
int nodes[MAXN];

struct Node {
    int owes;
    Node* parent;
};

int dfs(vector<vector<int> > graph, int u) {
    int cost = nodes[u];
    visited[u] = 1;
    
    //printf("Visiting node %d\n", u);
    for(int i=0; i<graph[u].size(); i++) {
        int v = graph[u][i];

        if(visited[v] == -1) {
            cost += dfs(graph, v);
        }
    }
    
    //printf("Cost is %d\n", cost);
    return cost;
}

int main(void) {

    int cases;
    scanf("%d", &cases);

    while (cases--) {

        int n,m;
        scanf("%d %d", &n, &m);
        
        for(int i=0; i<n; i++) {
            visited[i] = -1;
            scanf("%d", &nodes[i]);
        }

        vector<vector<int> > graph (n);
        for(int i=0; i<m; i++) {
            int a,b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        bool possible = true;
        for(int i=0; i<n; i++) {
            if(visited[i] == -1) {
                //printf("Visiting new component\n");
                int cost = dfs(graph, i);

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
