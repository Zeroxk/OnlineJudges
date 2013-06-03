#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int main(void) {

    int n;
    scanf("%d", &n);

    vector<int> buildings(n);
    for(int i=0; i<n; i++) {
        int l,h;
        scanf("%d %d", &l, &h);
        //buildings.push(h);
        buildings[i] = h;
    }

    //int top = buildings.top();
    //buildings.pop();
    int ans = buildings.size();
    int top = buildings[0];
    /*while(buildings.size() > 0) {
        if(buildings.top() < top) ans++;
        buildings.pop();
    }*/

    for(int i=1; i<n; i++) {
        if(buildings[i] < top) ans--;
    }
    
    printf("%d\n", ans);

    return 0;
}
