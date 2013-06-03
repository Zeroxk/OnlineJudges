#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

const int MAXN = 5001;
const int MAXK = 1009;

int memo[MAXK][MAXN];
int chopsticks[MAXN];

int main(void) {
    
    int cases;
    scanf("%d", &cases);

    while(cases--) {
        int k,n;
        scanf("%d %d", &k, &n);
        k += 8;

        for(int i=n; i>=1; i--) {
            int cs;
            scanf("%d", &cs);
            chopsticks[i] = cs;
        }

        for(int i=0; i<=k; i++) {
            for(int j=0; j<=n; j++) {
                memo[i][j] = INT_MAX;
            }
        }

        for(int i=0; i<=n; i++) {
            memo[0][i] = 0;
        }

        for(int i=1; i<=k; i++) {
            for(int j=i*3; j<=n; j++) {
                memo[i][j] = min(memo[i][j-1], memo[i-1][j-2] + ( (chopsticks[j-1]-chopsticks[j]) * (chopsticks[j-1]-chopsticks[j]) ));
            }
        }

        printf("%d\n", memo[k][n]);
    }

    return 0;
}
