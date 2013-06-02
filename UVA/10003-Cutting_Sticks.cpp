#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

int cuts[51];
int memo[51][51];

int minCut(int start, int end) {
    if(start+1 == end) return 0;
    if(memo[start][end] != -1) return memo[start][end];

    int minimum = INT_MAX;

    for(int i=start+1; i<end; i++) {
        minimum = min(minimum, minCut(start,i)+minCut(i,end)+cuts[end]-cuts[start]);
    }

    memo[start][end] = minimum;
    return minimum;
}

int main(void) {
    
    while(true) {
        int length;
        scanf("%d", &length);
        
        if(length == 0) break;

        int n;
        scanf("%d", &n);

        for(int i=0; i<51; i++) {
            for(int j=0; j<51; j++) {
                memo[i][j] = -1;
            }
        }

        for(int i=1; i<=n; i++) {
            int cut;
            scanf("%d", &cut);
            cuts[i] = cut;
        } 
        
        cuts[0] = 0;
        cuts[n+1] = length;

        int ans = minCut(0, n+1);

        printf("The minimum cutting is %d.\n", ans);

    }

    return 0;
}

