#include <cstdio>
#include <vector>

int main(void) {

    int nodes,edges;
    scanf("%d %d\n",&nodes,&edges);
    std::vector<std::vector<int> > graph;
    if(nodes>edges) {
        printf("NIE\n");
    }else {
    
        graph = std::vector<std::vector<int> >(nodes);
        for(int i=0;i<edges;i++) {
        
            int a,b;
            scanf("%d %d",&a,&b);
            a--;
            b--;
            graph[a].push_back(b);
            graph[b].push_back(a);

        }

    }
    return 0;

}

