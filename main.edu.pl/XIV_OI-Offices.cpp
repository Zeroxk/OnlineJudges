#include <cstdio>
#include <vector>

const int MAXNODES = 100000;
std::vector<int> officeSize;
int components;
int visited[MAXNODES];

void makeInverse(std::vector<std::vector<int> >& g) {

    for(int i=0;i<g.size();i++) {
        for(int j=0;j<g[i].size();j++) {
        
               

        }
    
    }

}

int findComponents(std::vector<std::vector<int> >& g) {

    components = 0;
    for(int i;i<g.size(); i++) {
        
            if(visited[i] == -1) {
                dfs(g, i);
                components++;
            }
        
    }

    return 0;

}

void dfs(std::vector<std::vector<int> >& g, int node) {

    for(int i=0;i<g[node].size();i++) {
        
        int neighbour = g[node][i];
        if(visited[neighbour] == -1) {
            dfs(g,neighbour);
            officeSize[components]++;
        }

    }

}

int main(void) {

    int nodes,edges;
    scanf("%d %d\n",&nodes,&edges);
    std::vector<std::vector<int> > graph = std::vector<std::vector<int> >(nodes);
    officeSize = std::vector<int>();

    for(int i=0;i<edges;i++) {
    
        int a,b;
        scanf("%d %d\n",&a,&b);

        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }

    makeInverse(graph);
    int components = findComponents(graph);

    printf("Number of components: %d\n",components);

    return 0;

}
