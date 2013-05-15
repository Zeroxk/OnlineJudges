#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

int dist[101][101];

int main(void) {

    int scenario = 1;
    while(true) {
        int cities, roads;
        scanf("%d %d", &cities, &roads);

        if(cities == 0 || roads == 0) break;
        
        for(int i=0; i<cities; i++) {
            for(int j=0; j<cities; j++) {
                dist[i][j] = -1;
            }
            dist[i][i] = 0;
        }

        for(int r=0; r<roads; r++) {
            int a,b,len;
            scanf("%d %d %d", &a,&b, &len);
            a--; b--;

            dist[a][b] = len;
            dist[b][a] = len;
            
        }

        int source, dest, pass;
        scanf("%d %d %d", &source, &dest, &pass);
        
        if(source == dest) {
            printf("Scenario #%d\n", scenario++);
            printf("Minimum Number of Trips = %d\n\n", 1);
            continue;
        }

        source--; dest--;

        //Start Floyd Warshall
        
        for(int k=0; k<cities; k++) {
            for(int i=0; i<cities; i++) {
                for(int j=0; j<cities; j++) {
                    dist[i][j] = std::max(dist[i][j], std::min(dist[i][k], dist[k][j])); 
                }
            }
        }

        /*for(int i=0; i<cities; i++) {
            printf("Shortest paths for node %d:", i+1);
            for(int j=0; j<cities; j++) {
                printf("%d ", dist[i][j]);
            }
            printf("\n");
        }*/

        //printf("Bottleneck from src to dst has weight: %d\n", dist[source][dest]);
        printf("Scenario #%d\n", scenario++);
        printf("Minimum Number of Trips = %d\n\n", (int)std::ceil((double)pass/(dist[source][dest]-1)));

    }

    return 0;
}
