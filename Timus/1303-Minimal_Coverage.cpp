#include <cstdio>
#include <vector>
#include <algorithm>

bool cmp(std::pair<int,int> p, std::pair<int, int> q) {
    if(p.first == q.first) {
        return p.second < q.second;
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

        lines.push_back(std::make_pair(l,r));
    }

    std::stable_sort(lines.begin(), lines.end(), cmp);

    std::vector<std::pair<int,int> > minSubSet = std::vector<std::pair<int,int> >();
    for(int i=0; i<lines.size(); i++) {
        std:: pair<int,int> p = lines[i];

        if(p.first < 0 && p.second < 0) continue;
        if(p.first > m) break;
        
        if(p.first >= 0) {
            minSubSet.push_back(p);
        }

    }

    for(int i=0; i<minSubSet.size(); i++) {
        printf("%d %d\n", minSubSet[i].first, minSubSet[i].second);
    }

    return 0;
}
