#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

struct Node {

    double x,y;
    Node* parent;
    int rank;
};

struct Edge {

    Node* a;
    Node* b;
    double cost;

};

bool eq (Node* n, Node* m) {
    return n->x == m->x && n->y == m->y;
}

Node* findLeader(Node* n) {
    if( !eq(n, n->parent) ) {
        n->parent = findLeader(n->parent);
    }
    return n->parent;
   
}

bool myUnion (Node* n, Node* m) {

    Node* xL = findLeader(n);
    Node* yL = findLeader(m);

    if( !eq(xL, yL) ) {
        //printf("n coords: %.2f, %.2f \t m coords: %.2f, %.2f\n", n->x, n->y, m->x, m->y);
        //printf("xL coords: %.2f, %.2f \t yL coords: %.2f, %.2f\n", xL->x, xL->y, yL->x, yL->y);
        if (xL->rank < yL->rank) {
            xL->parent = yL;
        }else if(xL->rank > yL->rank) {
            yL->parent = xL;
        }else {
            yL->parent = xL;
            xL->rank = xL->rank + 1;
        }
        //printf("n's parent now has coords; %.2f, %.2f \t xL coords is: %.2f, %.2f\n", n->parent->x, n->parent->y, xL->x, xL->y);
        return true;
    }

    return false;

}

bool cmpEdge(Edge e, Edge f) {

    return e.cost < f.cost;

}

int main(void) {

    int cases;
    scanf("%d\n",&cases);
    for(int t=0;t<cases;t++) {
    
        int freckles;
        scanf("%d",&freckles);
        std::vector<Node> nodes = std::vector<Node>(freckles);
        for(int i=0;i<freckles;i++) {
        
            double a,b;
            scanf("%lf %lf",&a,&b);
            Node n = {a,b};
            nodes[i] = n;
            nodes[i].parent = &nodes[i];
            nodes[i].rank = 0;
        }
        std::vector<Edge> edges = std::vector<Edge>();

        for(int i=0; i<nodes.size(); i++) {
            for(int j=i+1; j<nodes.size(); j++) {
                double c,d,len;
                c = pow(nodes[j].x - nodes[i].x, 2.0);
                d = pow(nodes[j].y - nodes[i].y, 2.0);
                len = sqrt( c+d );
                Edge e = {&nodes[i], &nodes[j], len};
                edges.push_back(e);
            }
        }
        std::stable_sort(edges.begin(), edges.end(), cmpEdge);
        //for(int i=0; i<edges.size(); i++) { printf("Edge cost: %.2f\n", edges[i].cost);}
        double sumLen = 0;
        for(int i=0; i<edges.size();i++) {
            if(nodes.size() == 1) break;
           if(myUnion(edges[i].a, edges[i].b)) {
               //printf("Picked edge with cost: %0.2f\n", edges[i].cost); 
               sumLen += edges[i].cost;
           } 
        }

        printf("%.2f\n",sumLen);
        if(t < (cases-1)) printf("\n");
        nodes.clear();
        edges.clear();

    }

    return 0;

}
