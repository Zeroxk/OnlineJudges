#include <cstdio>
#include <vector>
int components;

typedef struct Node Node;
struct Node {

    int elem;
    Node *parent;


};

Node* find(Node* n) {

    if(n->parent == n) {
        return n;
    }else {
        return find(n->parent);
    }

}


void myUnion(Node* x, Node* y) {

    Node* xLeader = find(x);
    Node* yLeader = find(y);
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
       printf("n's parent is: %p\n", n.parent);

    }

    for(int i=0; i<graph.size();i++) {
        printf("i's parent and elem: %d %p %d\n",i,graph[i].parent,graph[i].elem);
    }

    for(int i=0;i<piggyBanks;i++) {
    
        int key;
        scanf("%d",&key);
        key--;
       
        if(key != i) {
        
            myUnion(&graph[i], &graph[key]);
        
        }

    }

    printf("Number of components: %d\n",components);
    
    return 0;

}
