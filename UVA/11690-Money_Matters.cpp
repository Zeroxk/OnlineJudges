#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 10001;
const int MAXM = 50001;

int visited[MAXN];

struct Node {
    int owes, index;
    Node* parent;
};

Node* findLeader(Node* n) {
    if(n->parent == n) return n;

    return findLeader(n->parent);
}

void myUnion(Node* x, Node* y) {
    Node* xL = findLeader(x);
    Node* yL = findLeader(y);

    //printf("xL %d yL %d\n", xL->index, yL->index);
    if(xL != yL) {
        y->parent->owes += x->parent->owes;
        x->parent = y->parent;
        //printf("%d is component leader and owes %d\n", x->parent->index, x->parent->owes);
    }
}

int main(void) {

    int cases;
    scanf("%d", &cases);

    while (cases--) {

        int n,m;
        scanf("%d %d", &n, &m);
        
        vector<Node> nodes (n);
        for(int i=0; i<n; i++) {
            visited[i] = -1;
            int a;
            scanf("%d", &a);
            Node n = {a};
            nodes[i] = n;
            nodes[i].parent = &nodes[i];
            nodes[i].index = i;
        }

        for(int i=0; i<m; i++) {
            int a,b;
            scanf("%d %d", &a, &b);
            myUnion(&nodes[a],&nodes[b]);
        }

        bool possible = true;
        for(int i=0; i<n; i++) {
            Node* leader = findLeader(&nodes[i]);
            if(visited[leader->index] == -1) {
                if(leader->owes != 0) {
                    //printf("Leader is %d, component owes %d\n", leader->index, leader->owes);
                    possible = false;
                    break;
                }
                
                visited[leader->index] = 1;
                
            }
        }

        if(possible) {
            printf("POSSIBLE\n");
        }else {
            printf("IMPOSSIBLE\n");
        }

    }

    return 0;
}
