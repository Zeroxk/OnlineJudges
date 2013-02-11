#include <cstdio>
#include <vector>
const int MAXNODES = 1000000;
int visited [MAXNODES];

typedef struct {

    int elem;
    node* parent;


}Node;

Node find(Node n) {

    if(n.parent == n) {
        return n;
    }else {
        return find(n.parent);
    }

}

void myUnion(Node x, Node y) {

    Node xLeader = find(x);
    Node yLeader = find(y);
    xLeader.parent = yLeader;

}

int main(void) {

    int piggyBanks;
    scanf("%d",&piggyBanks);
    std::vector<node> graph = std::vector<node>();

    for(int i=0;i<piggyBanks;i++) {
    
        int key;
        scanf("%d",&key);
        key--;
        
        Node n;
        n.elem = i;
        n.parent = &n;
        
        Node m;
        m.elem = key;
        m.parent = &n;


    }
    
    return 0;

}
