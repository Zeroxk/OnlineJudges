#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

const int MAXN = 201;

int capacities[MAXN][MAXN];
int flows[MAXN][MAXN];
int path[MAXN]; //Path in reverse found by bfs
int pathCapacity[MAXN]; //Max flow to node in path found by bfs

int bfs(vector<vector<int> > &graph, int start, int dest) {

    //printf("BFS is running\n");
    memset(path, -1, sizeof(path));
    memset(pathCapacity, 0, sizeof(pathCapacity));

    queue<int> q;
    q.push(start);

    path[start] = start;
    pathCapacity[start] = INT_MAX;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int i=0; i<graph[u].size(); i++) {
            int v = graph[u][i];

            if(path[v] == -1) {
                if(capacities[u][v] - flows[u][v] > 0) {
                    path[v] = u;

                    int resCap = capacities[u][v] - flows[u][v];
                    pathCapacity[v] = min(pathCapacity[u], resCap);

                    if(v == dest) {
                        //printf("Found path to sink\n");
                        return pathCapacity[dest];
                    }
                    q.push(v);
                }
            }
        }
    }

    return 0;

}

int edmondsKarp(vector<vector<int> > &graph, int source, int sink) {
    
    int maxFlow = 0;

    while(true) {
        int flow = bfs(graph, source, sink);

        if(flow == 0) break;

        maxFlow += flow;
        int currNode = sink;

        while(currNode != source) {
            int prevNode = path[currNode];
            flows[prevNode][currNode] += flow;
            flows[currNode][prevNode] -= flow;

            currNode = prevNode;
        }
    }

    return maxFlow;
}

int main(void) {

    int n;
    scanf("%d", &n);

    vector<vector<int> > graph(n);

    for(int i=0; i<n-1; i++) {
        int num;
        scanf("%d", &num);

        for(int j=0; j<num; j++) {
            int a;
            scanf("%d", &a);
            a--;
            capacities[i][a] = 1;
            graph[i].push_back(a);
            //graph[a].push_back(i);
        }
    }

    int ans = edmondsKarp(graph, 0, n-1);

    printf("%d\n", ans);

    return 0;

}
