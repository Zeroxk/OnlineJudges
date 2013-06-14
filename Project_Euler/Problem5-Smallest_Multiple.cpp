#include <cstdio>

int main(void) {
    
    int n = 20;
    unsigned int ans = n;
    
    while(true) {
        bool found = true;
        
        //printf("Testing %u\n", ans);
        for(int i=1; i<=n; i++) {
            if(ans % i != 0) {
                found = false;
                break;
            }
        }

        if(found) break;

        ans += n;
    }

    printf("Smallest multiple of 1-%d is %u\n", n, ans);

    return 0;
}
