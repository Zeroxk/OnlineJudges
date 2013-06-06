#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

const int MAXNODES = 100001;

std::vector<int> officeSize;
int components;
int visited[MAXNODES];

void dfs(std::vector<std::vector<int> > &g, int node) {

    visited[node] = 1;
    for(int i=0;i<g[node].size();i++) {
        
        int isEdge = g[node][i];
        if(isEdge == 1) {
            if(visited[i] == -1) {
                dfs(g,i);
                officeSize[components]++;
            }
        }
        

    }

}

void makeInverse(std::vector<std::vector<int> > &g) {

    for(int i=0;i<g.size();i++) {
        for(int j=0;j<g[i].size();j++) {
        
           g[i][j] = g[i][j] == 1 ? 0:1; 

        }
    
    }

}


void findComponents(std::vector<std::vector<int> > &g) {

    for(int i=0;i<g.size(); i++) {
            if(visited[i] == -1) {
                //printf("Exploring %d\n", i+1); 
                officeSize.push_back(1);
                dfs(g, i);
                components++;
            }
        
    }

}

int main(void) {

    int nodes,edges;
    scanf("%d %d\n",&nodes,&edges);
    std::vector<std::vector<int> > graph = std::vector<std::vector<int> >(nodes);
    officeSize = std::vector<int>();

    for(int i=0; i<nodes; i++) {
        graph[i] = std::vector<int>(nodes,0);
    }

    for(int i=0;i<edges;i++) {
    
        int a,b;
        scanf("%d %d",&a,&b);
        a--; b--;

        graph[a][b] = 1;
        graph[b][a] = 1;

    }

    makeInverse(graph);
    //printf("Made inverse\n");
    
    /*for(int i=0; i<graph.size(); i++) {
        printf("Node %d: ", i+1);
        for(int j=0; j<graph[i].size(); j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }*/
   
    memset(visited, -1, sizeof(visited));
    findComponents(graph);

    printf("%d\n",components);
    std::stable_sort(officeSize.begin(), officeSize.end());
    for(int i=0; i<officeSize.size(); i++) {
        if(i != officeSize.size()-1) {
            printf("%d ", officeSize[i]);
        }else {
            printf("%d\n", officeSize[i]);
        }
    }
    return 0;

}
