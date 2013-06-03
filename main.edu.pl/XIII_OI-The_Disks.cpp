#include <cstdio>
#include <vector>

int main(void) {

    int height, disks;
    scanf("%d %d", &height, &disks);

    std::vector<int> hole = std::vector<int>(height);
    for(int i=0; i<height; i++) {
        int diaHole;
        scanf("%d", &diaHole);
        hole[i] = diaHole;
    }

    int min = hole[0];
    for(int i=1; i<height; i++) {
        if(min < hole[i]) {
            hole[i] = min;
        }else {
            min = hole[i];
        }
    }

    std::vector<int> disk = std::vector<int>(disks);
    for(int i=0; i<disks; i++) {
        int diaDisk;
        scanf("%d", &diaDisk);
        disk[i] = diaDisk;
    }

    int ind = 0;
    while(hole.size() >= 0 && ind < disk.size()) {

        int d = disk[ind];

        if(d > hole[0]) break;

        ind++;

        while(d > hole.back() && hole.size()>0) {
            //printf("Passing through hole %d\n", hole.back());
            hole.pop_back();
        }

        if(hole.size() == 0) break;

        hole.pop_back();
        
        //printf("Disk %d stopped at %d\n", d, hole.back());
        //hole.pop_back(); 

    }

    if(ind != disk.size()) {
        printf("0\n");
    }else {
        printf("%d\n", hole.size()+1);
    }


    return 0;
}
