#include <cstdio>
#include <stack>

using namespace std;

int main(void) {

    int n;
    scanf("%d", &n);

    stack<int> buildings;
    int ans = 0;
    for(int i=0; i<n; i++) {
        int l,h;
        scanf("%d %d", &l, &h);
        
        while(!buildings.empty() && buildings.top() > h) {
            //printf("Popping %d\n", buildings.top());
            buildings.pop();
        }

        if(buildings.empty() || buildings.top() < h) {
            //printf("Pushing %d\n", h);
            buildings.push(h);
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
