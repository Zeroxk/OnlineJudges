#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool cmp(pair<int,int> p, pair<int,int> q) {
    if(p.second == q.second) {
        return p.first < q.first;
    }

    return p.second < q.second;
}

int main(void) {
    int n;
    scanf("%d", &n);

    vector<int> tasks;
    vector<pair<int,int> > t;
    while(n--) {
        int d,t2;
        scanf("%d %d", &d, &t2);
        pair<int,int> p = make_pair(d,t2);
        t.push_back(p);
        tasks.push_back(t2-d);
    }

    stable_sort(t.begin(), t.end(), cmp);
    int maks = 0;
    for(int i=0; i<t.size()-1; i++) {
        //printf("(%d, %d)\n", t[i].first, t[i].second);
    }

    printf("Max %d\n", maks);
    
    /*stable_sort(tasks.begin(), tasks.end());
    for(int i=0; i<tasks.size(); i++) {
        printf("%d ", tasks[i]);
    }*/

    return 0;
}
