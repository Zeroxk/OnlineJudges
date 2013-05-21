#include <cstdio> 
#include <vector>

const int MAXP = 50000;

std::vector<unsigned int> primes;

/*int get_powers(int n, int p) {
    int result = 0;
    n /= p;

    do {
        result += n;
        n /= p;
    }while(n > 0);
    return result;
}*/

int get_powers(int n, int p) {
    
    int num = 0;
    for(unsigned long i=p; i<=n; i *= p) {
        num += n/i;
    }
    
    return num;
}

std::vector<std::pair<int,int> > factorize(int m) {
    
    std::vector<std::pair<int,int> > facts = std::vector<std::pair<int,int> >();

    for(int i=0; i<primes.size(); i++) {
        int p = primes[i];
        //printf("Prime is %d\n", p);
        if( (p*p) > m) break;

        int alpha = 0;
        while(m % p == 0) {
            alpha++;
            m /= p;
        }

        if(alpha>0) {
            //printf("Made pair from %d and %d\n", p, alpha);
            facts.push_back(std::make_pair(p, alpha));
        }


    }

    if(m>1) {
        facts.push_back(std::make_pair(m,1));
    }

    return facts;
}

bool factovisor(int n, int m) {
   
    if( m == 0) {
        return false;
    }

    if( (m <= n) ) {
        return true;        
    }

    //Factorize m
    //printf("Factorizing\n");
    std::vector<std::pair<int, int> > facts = factorize(m);

    /*printf("Factors of %d are:\n", m);
    for(int i=0; i<facts.size(); i++) {
        printf("Prime %d power %d\n", facts[i].first, facts[i].second);
    }*/
    

    for(int i=0; i<facts.size(); i++) {
        
        int powers = get_powers(n, facts[i].first);
        //printf("%d! has %d powers in %d\n", n, powers, facts[i].first);

        if(powers < facts[i].second) {
            return false;
        }
    }

    return true;
}

int main(void) {
    
    //Generate primes
    std::vector<bool> vis = std::vector<bool>(MAXP+1);

    for(int i=2; i<MAXP; i++) {
        if(!vis[i]) {
            primes.push_back(i);
            for(int j=2*i; j<=MAXP; j +=i) {
                vis[j] = true;
            }
        }
    }

    unsigned int n,m;
    
    while(scanf("%u %u", &n, &m) != EOF) {

        if(factovisor(n,m)) {
            printf("%u divides %u!\n", m, n);
        }else {
            printf("%u does not divide %u!\n", m, n);
        }

    }

    return 0;
}
