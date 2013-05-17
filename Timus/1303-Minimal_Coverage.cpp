#include <cstdio>
#include <vector>
#include <algorithm>

bool cmp(std::pair<int,int> p, std::pair<int, int> q) {
    if(p.first == q.first) {
        return p.second > q.second;
    }else {
        return p.first < q.first;
    }
}

int main(void) {

    int m;
    scanf("%d", &m);

    std::vector<std::pair<int,int> > lines = std::vector<std::pair<int,int> >();
    while(true) {
        int l,r;
        scanf("%d %d", &l, &r);

        if(l == 0 && r == 0) break;

        
        if(!(l < 0 && r < 0) && !(l > m))  {
            //printf("Made a pair %d %d\n", l, r);
            lines.push_back(std::make_pair(l,r));
        }
    }

    std::stable_sort(lines.begin(), lines.end(), cmp);

    /*printf("Sorted input\n");
    for(int i=0; i<lines.size(); i++) {
        printf("%d,%d", lines[i].first, lines[i].second);
    }
    printf("\n");*/

    std::vector<std::pair<int,int> > minSubSet = std::vector<std::pair<int,int> >();
    
    int covered = 0;
    int ind = 0;
    while(covered < m) {
        int max = -1;
        for(int i=ind; i<lines.size(); i++) {
            if(lines[i].first <= covered && lines[i].second > max) {
                max = lines[i].second;
                ind = i;
            }
        }

        if(max > covered) {
            //printf("Max is %d\n", max);
            minSubSet.push_back(lines[ind]);
            covered = max;
        }else {
            //printf("Breaking\n");
            break;
        }
    } 

    if(minSubSet.size() == 0 || minSubSet[minSubSet.size()-1].second < m) {
        printf("No solution\n");
    }else {
        printf("%d\n", minSubSet.size());
        for(int i=0; i<minSubSet.size(); i++) {
            printf("%d %d\n", minSubSet[i].first, minSubSet[i].second);
        }
    }

    

    return 0;
}
