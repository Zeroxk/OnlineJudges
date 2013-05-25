#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
    unsigned long n = 2000000;
    //unsigned long n = 10;

    unsigned long long primeSum = 0;

    vector<bool> vis = vector<bool>(n+1);
    for(unsigned long i=2; i<n; i++) {
        if(!vis[i]) {
            primeSum += i;
            for(unsigned long j=2*i; j<=n; j+=i) {
                vis[j] = true;
            }
        }
    }

    printf("Sum of all primes below %ld is %lld\n", n, primeSum);

    return 0;
}
