#include <cstdio>
#include <vector>
#include <algorithm>

bool cmp(std::pair<double, int> p, std::pair<double, int> q) {
    return p.first < q.first;
}

int main(void) {

    int cases;
    scanf("%d\n\n", &cases);

    while(cases > 0) {
        int n;
        scanf("%d",&n);
        std::vector<std::pair<double, int> > vec = std::vector<std::pair<double, int> >();
        for(int i=0; i<n;i++) {    
            int time,fine;
            scanf("%d %d", &time, &fine);
            double ratio = (double)time/(double)fine;
            vec.push_back(std::make_pair(ratio, i+1));
        }

        std::sort(vec.begin(),vec.end(),cmp);
        /*for(int i=0; i<vec.size(); i++) {
            printf("Ratio: %f Job: %d\n", vec[i].first, vec[i].second);
        }*/

        for(int i=0; i<vec.size(); i++) {
            printf("%d ",vec[i].second);
        }
        printf("\n");
       
        cases--;
    
    }
    
    return 0;
}
