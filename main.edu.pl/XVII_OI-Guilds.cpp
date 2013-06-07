#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;

struct Edge {
    int a,b;
};

int main(void) {
    int n,m;
    scanf("%d %d", &n, &m);

    vector<char> guilds (n);
    vector<Edge> edges;
    fill(guilds.begin(), guilds.end(), 'N');
    for(int i=0; i<m; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        a--; b--;
        Edge e = {a,b};
        edges.push_back(e);
    }

    for(int i=0; i<edges.size(); i++) {
        Edge e = edges[i];
        if(guilds[e.a] == 'N') {
            
            guilds[e.a] = guilds[e.b] == 'K' ? 'S' : 'K';
            
        }

        if(guilds[e.b] == 'N') {
            
            guilds[e.b] = guilds[e.a] == 'K' ? 'S' : 'K';
            
        }
    }

    /*for(int i=0; i<guilds.size(); i++) {
        printf("%c\n", guilds[i]);
    }*/

    bool nie = false;
    for(int i=0; i<guilds.size(); i++) {
        if(guilds[i] == 'N') {
            nie = true;
            break;
        }
    }

    if(nie) {
        printf("NIE\n");
    }else {
        printf("TAK\n");
        for(int i=0; i<guilds.size(); i++) {
            printf("%c\n", guilds[i]);
        }
    }  
    
    return 0;
}
