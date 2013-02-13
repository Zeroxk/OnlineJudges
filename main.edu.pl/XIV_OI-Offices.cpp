#include <cstdio>
#include <vector>

std::vector<int> officeSize;

void makeInverse(std::vector<std::vector<int> >& g) {

    for(int i=0;i<g.size();i++) {
        for(int j=0;j<g[i].size();j++) {
        
               

        }
    
    }

}

int findComponents(std::vector<std::vector<int> >& g) {

    return 0;

}

int main(void) {

    int nodes,edges;
    scanf("%d %d\n",&nodes,&edges);
    std::vector<std::vector<int> > graph = std::vector<std::vector<int> >(nodes);

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
