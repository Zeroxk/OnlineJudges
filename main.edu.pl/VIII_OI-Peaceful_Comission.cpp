#include <cstdio>
#include <vector>

using namespace std;

int main(void) {

    int n,m;
    scanf("%d %d", &n, &m);

    vector<vector<int> > graph (n);
    for(int i=0; i<m; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    return 0;
}
