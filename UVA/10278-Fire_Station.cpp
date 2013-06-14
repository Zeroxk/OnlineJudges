#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>
#include <climits>

using namespace std;

const int INF = 1000000;

int dist[510][510];

int main(void) {
    int cases;
    scanf("%d\n", &cases);

    while(cases--) {
        int fireStations, intersections;
        scanf("%d %d\n", &fireStations, &intersections);
        //printf("fs: %d, is: %d\n", fireStations, intersections);
        
        vector<int>fs (intersections);
        for(int i=0; i<fireStations; i++) {
            int fsNode;
            scanf("%d\n", &fsNode);
            fsNode--;
            fs[fsNode] = 1;
        }

        for(int i=0; i<intersections; i++) {
            for(int j=0; j<intersections; j++) {
                dist[i][j] = INF;
            }
            dist[i][i] = 0;
        }

        int a,b,len;
        while(scanf("%d %d %d", &a, &b, &len) == 3) {
            a--; b--;
            dist[a][b] = len;
            dist[b][a] = len;
        }
        
        /*printf("Firestations: ");
        for(int i=0; i<fs.size(); i++) {
            printf("%d ", fs[i]);
        }
        printf("\n");*/

        //Start floyd-warshall
        //printf("Starting FW, #%d\n", intersections);
        
        //printf("Compare dist\n");
        for(int k=0; k<intersections; k++) {
            for(int i=0; i<intersections; i++) {
                for(int j=0; j<intersections; j++) {
                    int distIKKJ = dist[i][k] + dist[k][j];
                    //printf("%d\n", distIKKJ);
                    if(distIKKJ < dist[i][j]) {
                        dist[i][j] = distIKKJ;
                    }
                }
            }
        }

        //printf("FW done\n");

        for(int i=0; i<intersections; i++) {
            printf("Paths for node %d: ", i+1);
            for(int j=0; j<intersections; j++) {
                printf("%d ", dist[i][j]);
            }
            printf("\n");
        }



                
        if(cases > 0) {
            printf("\n");
        }
    }

    return 0;
}
