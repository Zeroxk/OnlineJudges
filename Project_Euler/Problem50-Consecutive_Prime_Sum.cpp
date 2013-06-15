#include <cstdio>
#include <vector>

#define uint unsigned int

using namespace std;

vector<uint> primes;

void genPrimes(uint n) {
    vector<bool> vis (n+1);

    for(uint i=2; i<n; i++) {
        if(!vis[i]) {
            primes.push_back(i);
            for(uint j=2*i; j<=n; j+=i) {
                vis[j] = true;
            }
        }
    }
}

bool isPrime(uint n) {
    for(uint i=2; i<n; i++) {
        if(n % i == 0) {
            return false;
        }
    }

    return true;
}

int main(void) {
    
    uint n = 100;
    genPrimes(n);

    uint ans = 2;
    uint sum = 0;
    int terms = 0;

    for(int i=0; i<primes.size(); i++) {
        sum = primes[i];
        terms = 0;
        printf("Sum is %u\n", sum);
        for(int j=i+1; j<primes.size(); j++) {
            sum += primes[j];
            if(sum < n && isPrime(sum)) {
                ans = max(ans, sum);
                terms = j;
            }else if(sum >= n){
                break;
            }
        }

    }
    
    printf("# of terms %d\n", terms);
    printf("Longest sum is %u\n", ans);

    return 0;
}
