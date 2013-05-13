#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>

struct Edge {
    int a,b;
    int len;
};

int dist[501][501];
int intersections;
std::vector<int> fs;

int solve1() {
    int node = -1;
    int minDist = 1000000;
    for(int i=0; i<intersections; i++) {
        int max = 0;
        for(int j=0; j<intersections; j++) {
            if(dist[i][j] > max) {
                max = dist[i][j];
            }
        }
        if(max < minDist) {
            minDist = max;
            node = i;
        }
    }
    
    return node;
}

int solveN() {
    int node = -1;
    int maxDist = -1;
    for(int i=0; i<intersections; i++) {
        if(fs[i] == 1) continue;
        int min = 1000000;
        for(int j=0; j<fs.size(); j++) {
            if(fs[j] == 0) continue;
            if(dist[i][j] < min) {
                min = dist[i][j];
            }
        }
        //printf("i : %d, Min: %d, Max: %d\n", i+1, min, maxDist);
        if(min > maxDist) {
            maxDist = min;
            node = i;
        } 
    }
    
    return node;
}

int main(void) {
    int cases;
    scanf("%d\n", &cases);

    while(cases > 0) {
        int fireStations;
        scanf("%d %d\n", &fireStations, &intersections);
        //printf("fs: %d, is: %d\n", fireStations, intersections);
        
        
            fs = std::vector<int>(intersections);
        

        for(int i=0; i<fireStations; i++) {
            int fsNode;
            scanf("%d\n", &fsNode);
            fsNode--;
            fs[fsNode] = 1;
        }
        
        /*printf("Firestations: ");
        for(int i=0; i<fs.size(); i++) {
            printf("%d ", fs[i]);
        }
        printf("\n");*/

        std::vector<Edge> edgeList = std::vector<Edge>();

        std::string line;
        while(getline(std::cin, line)) {
//printf("I'm in\n");
            if(line == "" || std::cin.eof()) break;

            int vals[3];
            int index=0;

            for(int i=0; i<line.length(); i++) {
                std::string str = "";
                while(line[i] != ' ') {
                    str += line[i];
                    i++;
                }
                vals[index++] = std::atoi(str.c_str());

            }
            vals[0]--;
            vals[1]--;
            Edge e = {vals[0], vals[1], vals[2]};
            //printf("%d %d %d\n", e.a, e.b, e.len);
            edgeList.push_back(e);
            line = "";
        }

        //Start floyd-warshall
        //printf("Starting FW, #%d\n", intersections);
        for(int i=0; i<intersections; i++) {
            for(int j=0; j<intersections; j++) {
                dist[i][j] = 1000000;
            }
        }

        //printf("Init dist[i][i]\n");
        for(int i=0; i<intersections; i++) {
            dist[i][i] = 0;
        }

        //printf("Putting edge weights in dist array\n");
        for(int i=0; i<edgeList.size(); i++) {
            Edge e = edgeList[i];
            dist[e.a][e.b] = e.len;
            dist[e.b][e.a] = e.len;
        }

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

        /*for(int i=0; i<intersections; i++) {
            printf("Paths for node %d: ", i+1);
            for(int j=0; j<intersections; j++) {
                printf("%d ", dist[i][j]);
            }
            printf("\n");
        }*/

        int putFs = -1;
        if(fireStations == 0) {
            //printf("Solving for no FS\n");
            putFs = solve1();
        }else {
            //printf("Solving for 1 or more FS\n");
            putFs = solveN();
        }
        putFs++;

        //printf("Put fs here: %d", putFs);
        printf("%d\n", putFs);
        for(int i=0; i<intersections; i++) {
            for(int j=0; j<intersections; j++) {
                dist[i][j] = 0;
            }
        }
        
        intersections = 0;
        edgeList.clear();
        fs.clear();
        
        cases--;
        if(cases > 0) {
            printf("\n");
        }
    }

    return 0;
}
