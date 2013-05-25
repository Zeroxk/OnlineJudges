#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
    
    int n;
    scanf("%d", &n);

    vector<pair<int,int> > rabbits = vector<pair<int,int> >();
    while(n--) {
        int x,y;
        scanf("%d %d", &x, &y);

        rabbits.push_back(make_pair(x,y));
    }

    int max = 2;
    for(int i=0; i<rabbits.size(); i++) {
        pair<int,int> a = rabbits[i];
        for(int j=i+1; j<rabbits.size(); j++) {
            pair<int,int> b = rabbits[j]; 
            int count = 2;

            for(int k=j+1; k<rabbits.size(); k++) {
                pair<int,int> c = rabbits[k];
                
                int prod1 = (a.first-c.first)*(b.second-a.second);
                int prod2 = (a.first-b.first)*(c.second-a.second);

                if(prod1 - prod2 == 0) count++;
            }
            if(max < count) max = count;
        } 
    }

    printf("%d\n", max);

    return 0;
}
