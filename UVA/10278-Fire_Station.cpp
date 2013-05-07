#include <cstdio>
#include <vector>

struct Edge {
    int a,b;
    int len;
}

void dijkstra() {

}

int main(void) {
    int cases;
    scanf("%d\n", &cases);

    while(cases > 0) {
        int fireStations, intersections;
        scanf("%d %d", &fireStations, &intersections);

        std::vector<int> fs = std::vector<int>();

        for(int i=0; i<fireStations; i++) {
            int fsNode;
            scanf("%d", &fsNode);
            fsNode--;
            fs.push_back(fsNode);
        }

        std::vector<Edge> edgeList = std::vector<Edge>();

        for(int i=0; i<intersections; i++) {
            int a,b,len;
            scanf("%d %d %d", &a, &b, &len);
            Edge e = {a,b,len};
            edgeList.push_back(e);
        }

        cases--;
        
    }

    return 0;
}
