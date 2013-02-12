#include <cstdio>
#include <vector>
int components;

typedef struct Node Node;
struct Node {

    int elem;
    Node *parent;


};

Node* find(Node* n) {

    printf("n's address: %p\n",n);
    if(n->parent == n) {
        return n;
    }else {
        return find(n->parent);
    }

}


void myUnion(Node* x, Node* y) {

    printf("Trying to find x\n");
    Node* xLeader = find(x);
    printf("Found x!\n");
    printf("Trying to find y\n");
    Node* yLeader = find(y);
    printf("Found y!\n");
    printf("xLeader elem: %d\n",xLeader->elem);
    printf("xLeader parent: %p\n\n", xLeader->parent);
    printf("yLeader elem: %d\n",yLeader->elem);
    printf("yLeader parent: %p\n", yLeader->parent);
    if(xLeader != yLeader) {
        xLeader->parent = yLeader;
        components--;
    }

}

int main(void) {

    int piggyBanks;
    scanf("%d",&piggyBanks);
    components = piggyBanks;
    std::vector<Node> graph = std::vector<Node>();

    for(int i=0;i<piggyBanks;i++) {
    
        Node n = {i, &n};
        graph.push_back(n);
       graph[i].parent = &graph[i]; 

    }
    
    for(int i=0; i<graph.size();i++) {
        printf("i's address parent and elem: %p %p %d\n",&graph[i],graph[i].parent,graph[i].elem);
    }

    for(int i=0;i<piggyBanks;i++) {
    
        int key;
        scanf("%d",&key);
        key--;
        
        if(key != i) {
        
            Node* a = &graph[i];
            printf("A's address, parent and elem: %p %p %d\n",a,a->parent, a->elem);
            Node* b = &graph[key];
            printf("B's address, parent and elem: %p %p %d\n",b,b->parent, b->elem);
            myUnion(a, b);
        
        }

    }

    printf("Number of components: %d\n",components);
    
    return 0;

}
