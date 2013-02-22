#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

typedef struct Node {

    float x,y;

};

typedef struct Edge {

    Node* a;
    Node* b;
    float cost;

};

bool compareX(Node a, Node b) {

   return a.x < b.x; 

}

bool compareY(Node a, Node b) {

    return a.y < b.y;

}

int main(void) {

    int cases;
    scanf("%d\n",&cases);
    for(int t=0;t<cases;t++) {
    
        int freckles;
        scanf("%d",&freckles);
        std::vector<Node> nodes = std::vector<Node>(freckles);
        for(int i=0;i<freckles;i++) {
        
            float a,b;
            scanf("%f %f",&a,&b);
            Node n = {a,b};
            nodes[i] = n;
        }

        /*printf("Unsorted:\n");
        for(int i=0;i<nodes.size();i++) {
            printf("%.2f %.2f\n",nodes[i].x,nodes[i].y);
        }*/

        std::stable_sort(nodes.begin(),nodes.end(),compareX);
        
        /*printf("Sorted by y:\n");
        for(int i=0;i<nodes.size();i++) {
            printf("%.2f %.2f\n",nodes[i].x, nodes[i].y);
        }*/

        //printf("Sorted by x and y:\n");
        std::stable_sort(nodes.begin(),nodes.end(),compareY);

        /*for(int i=0;i<nodes.size();i++) {
            printf("%.2f %.2f\n",nodes[i].x, nodes[i].y);
        }*/

        int marker = 0;
        float sumLen = 0;
        for(int i=0; i<nodes.size()-1;i++) {
        
            Node a = nodes[i];
            Node b = nodes[i+1];

            float c,d;
            c = pow( (a.x - b.x) , 2);
            d = pow( (a.y - b.y) , 2);
            float srA = sqrt( c + d );
            sumLen += srA;

        }

        printf("%.2f\n",sumLen);

    }

    return 0;

}
