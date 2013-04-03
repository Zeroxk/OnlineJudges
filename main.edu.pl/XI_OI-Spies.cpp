#include <cstdio>
#include <vector>

int main(void) {

    int spies;
    scanf("%d", &spies);
    std::vector<std::vector<int > > graph = std::vector<std::vector<int > >(spies);

    for(int i=0; i<spies; i++) {
    
        int shadows;
        scanf("%d", &shadows);
        shadows--;
        graph[i].push_back(shadows);
    
    }

    return 0;

}
