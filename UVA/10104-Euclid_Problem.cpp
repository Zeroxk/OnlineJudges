#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

pair<long long,long long> eea(long long a, long long b) {
    
    if(a<b) {
        pair<long long, long long> r = eea(b,a);
        return make_pair(r.second, r.first);
    }

    if(b == 0) return make_pair(1,0);

    pair<long long, long long> r = eea(b, a % b);
    pair<long long, long long> res = make_pair(r.second, (r.first-r.second*(a/b)));

    /*if(res.first >= b) {
        res.second += a*(r.first/b);
        res.first -= b*(r.first/b);
    }

    if(res.first < 0) {
        res.second += a*(-1+r.first/b);
        res.first -= b*(-1+r.first/b);
    }*/

    return res;
}

int main(void) {
   long long a,b;
   
   while(scanf("%lld %lld", &a, &b) != EOF) {
        pair<long long,long long> XY = eea(a,b);
        long long d = (a*XY.first)+(b*XY.second);

        printf("%lld %lld %lld\n", XY.first, XY.second, d); 

   }

   return 0;

}
