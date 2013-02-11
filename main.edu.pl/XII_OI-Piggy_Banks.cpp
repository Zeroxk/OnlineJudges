#include <cstdio>
#include <vector>
const int MAXNODES = 1000000;

typedef struct {

    int elem;
    Node *parent;


}Node;

Node find(Node* n) {

    if(&n.parent == n) {
        return n;
    }else {
        return find(&n.parent);
    }

}


void myUnion(Node* x, Node* y) {

    Node xLeader = find(&x);
    Node yLeader = find(&y);
    if(xLeader != yLeader) {
        xLeader->parent = yLeader;
    }

}

int main(void) {

    int piggyBanks,components;
    scanf("%d",&piggyBanks);
    components = piggyBanks;
    std::vector<Node> graph = std::vector<Node>();

    for(int i=0;i<piggyBanks;i++) {
    
        Node n = {i,&n};
        graph.push_back(n);
    
    }

    for(int i=0;i<piggyBanks;i++) {
    
        int key;
        scanf("%d",&key);
        key--;
       
        if(key != i) {
        
            myUnion(graph[i], graph[key]);
            components--;
        
        }

    }
    
    return 0;

}
