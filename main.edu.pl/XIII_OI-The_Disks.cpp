#include <cstdio>
#include <vector>

int main(void) {

    int height, disks;
    scanf("%d %d", &height, &disks);

    std::vector<int> hole = std::vector<int>();
    for(int i=0; i<height; i++) {
        int diaHole;
        scanf("%d", &diaHole);
        hole.push_back(diaHole);
    }

    std::vector<int> disk = std::vector<int>();
    for(int i=0; i<disks; i++) {
        int diaDisk;
        scanf("%d", &diaDisk);
        disk.push_back(diaDisk);
    }

    int ans = 0;
    int ind = hole.size(); 
    for(int i=0; i<disk.size(); i++) {
        for(int j=0; j<ind; j++) {
            if(hole[j] < disk[i]) {
                //printf("Stopped at %d\n", hole[j]);
                //hole.erase(hole.begin()+j, hole.end());
               
                ind = j;

                hole[ind] = -1;
            }

            if(j == ind-1 && hole[ind] != -1) {
                hole[ind] = -1;
                ind--;
            }

            
        }
    }

    printf("%d\n", ind);

    /*for(int i=0; i<disk.size(); i++) {
        
        while(disk[i] >= hole.back()) {
            printf("Passing through hole %d\n", hole.back());
            hole.pop_back();
        }

        if(hole.size() == 0) break;
        
        printf("Disk %d stopped at %d\n", disk[i], hole.back());
        hole[hole.size()-1] = disk[i];
        //hole.pop_back(); 

        printf("Last elem is now %d\n\n", hole.back());

    }*/

    //printf("%d\n", hole.size());


    return 0;
}
