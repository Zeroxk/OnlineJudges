#include <cstdio>
#include <vector>

struct Edge {
    int a,b,len;
};

int main(void) {

    while(true) {
        int cities, roads;
        scanf("%d %d\n", &cities, roads);

        if(cities == 0 && roads == 0) break;

        for(int r=0; r<roads; r++) {
            int a,b,c;
            scanf("%d %d %d\n", &a,&b, &c);
            Edge e = {a,b,c};
            edgeList.push_back(e);
            
        }

    }

    return 0;
}
