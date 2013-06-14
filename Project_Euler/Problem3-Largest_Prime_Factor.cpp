#include <cstdio>
#include <vector>
#include <cmath>
#define ULL unsigned long long

using namespace std;

const ULL n = 600851475143;

vector<ULL> primes;
vector<bool> vis (n+1);

void genPrimes( ULL n) {

    for(ULL i=2; i<n; i++) {
        if(!vis[i]) {
            primes.push_back(i);
            for(ULL j=2*i; j<=n; j+=i) {
                vis[j] = true;
            }
        }
    }
}

vector<pair<ULL,int> > factorize(ULL n) {
    vector<pair<ULL,int> > res;
    for(ULL i=0; i<primes.size(); i++) {
        ULL p = primes[i];
        if(p*p > n) break;

        int alpha = 0;
        while(n % p == 0) {
            alpha++;
            n /= p;
        }

        if(alpha>0) {
            res.push_back(make_pair(p, alpha));
        }
    }

    if(n>1) {
        res.push_back(make_pair(n,1));
    }

    return res;
}

int main(void) {
    
    printf("Generating primes\n");
    genPrimes(sqrt(n));
    printf("Generated primes\n");
    vector<pair<ULL,int> > facts = factorize(n);
    printf("Factorized %llu\n", n);

    printf("Largest prime factor of %llu: %llu\n", n, facts.back().first);

    return 0;
}
