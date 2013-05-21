#include <cstdio>
#include <vector>

std::vector<unsigned long> primes;

void genPrimes(int n) {
    std::vector<bool> vis = std::vector<bool>(n+1);

    for(unsigned long i=2; i<n; i++) {
        if(!vis[i]) {
            primes.push_back(i);
            for(int j=2*i; j<=n; j += i) {
                vis[j] = true;
            }
        }
    }
}

int factorize(int n) {
    
    std::vector<std::pair<int,int> > facts = std::vector<std::pair<int,int> >();

    for(int i=0; i<primes.size(); i++) {
        int p = primes[i];

        if(p*p>n) break;

        int alpha = 0;
        while(n % p == 0) {
            alpha++;
            n /= p;
        }

        if(alpha > 0) {
            facts.push_back(std::make_pair(p,alpha));
        }
    }

    if(n>1) {
        facts.push_back(std::make_pair(n,1)); 
    }

    unsigned long num = 1;

    for(int i=0; i<facts.size(); i++) {
        num *= facts[i].second+1;
    }

    return num;

}

int main(void) {
    
    unsigned long n;
    scanf("%lu", &n);

    genPrimes(n);

    unsigned long max = 1;
    unsigned long ans = 1;

    for(unsigned long i=1; i<=n; i++) {
        unsigned long divisors = factorize(i);
        //printf("%lu has %lu divisors\n", i, divisors);
        if(divisors > max) {
            max = divisors;
            ans = i;
        }
    }

    printf("%lu\n", ans);
    
    return 0;
}
