#include <cstdio>
#include <vector>

int components;

int main(void) {

    int piggyBanks;
    scanf("%d",&piggyBanks);
    components = piggyBanks;
    std::vector<int> graph = std::vector<int>();

    for(int i=0;i<piggyBanks;i++) {
        graph.push_back(i);
    }

    for(int i=0;i<piggyBanks;i++) {
    
        int key;
        scanf("%d",&key);
        key--;

        if(key != i) {
        
            int a = i;
            int b = key;
            while(graph[a] != a) {
                a = graph[a];
            }
            while(graph[b] != b) {
                b = graph[b];
            }
            if(a != b) {
                graph[i] = b;
                components--;
            }
        }
    }

    printf("%d\n",components);

    return 0;

}
