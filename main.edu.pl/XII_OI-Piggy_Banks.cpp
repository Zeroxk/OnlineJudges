#include <cstdio>
#include <vector>
const int MAXNODES = 1000000;
int visited [MAXNODES];

void dfs(std::vector<std::vector<int> >, int);
int findAllComponents(std::vector<std::vector<int> >);

int findAllComponents(std::vector<std::vector<int> > graph) {

    int components;
    components = 0;
    for(int i=0;i<graph.size();i++) {
    
        if(visited[i] == -1) {
        
            components++;
            dfs(graph,i);

        }

    }

    return components;

}

void dfs(std::vector<std::vector<int> > graph, int node) {

    visited[node] = 1;
    for(int i=0; i<graph[node].size(); i++) {
    
        int neighbour;
        neighbour = graph[node][i];
        if(visited[neighbour] == -1) {
            dfs(graph,neighbour);
        }
    
    }

}

int main(void) {

    int piggyBanks;
    scanf("%d",&piggyBanks);
    std::vector<std::vector<int> > graph;
    graph = std::vector<std::vector<int> >(piggyBanks);

    for(int i=0;i<piggyBanks;i++) {
    
        int key;
        scanf("%d",&key);
        key--;
        graph[i].push_back(key);
        graph[key].push_back(i);
    }
    
    for(int i=0; i<piggyBanks; i++) {
    
        visited[i] = -1;
    
    }

    int components = findAllComponents(graph);
    printf("%d\n",components);

    return 0;

}
