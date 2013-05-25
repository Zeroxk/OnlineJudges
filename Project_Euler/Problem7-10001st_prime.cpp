#include <cstdio>
#include <vector>

using namespace std;

bool isPrime(unsigned long long n) {
    unsigned long root = (unsigned long) sqrt(n);
    for(unsigned long i=2; i<=root; i++) {
        if(n % i == 0) {
            //printf("%d is not prime\n", n);
            return false;
        }
    }
    return true;
}

int main(void) {

    vector<unsigned long long> primes = vector<unsigned long long>();
    int target = 10001;

    unsigned long long n = 3;
    primes.push_back(2);
    while(true) {
        if(isPrime(n)) {
            primes.push_back(n);
            if(primes.size() == target) break;
        }
        n++;
    }

    printf("The %d'th prime is %d\n", target, primes.back()); 

    return 0;

}
