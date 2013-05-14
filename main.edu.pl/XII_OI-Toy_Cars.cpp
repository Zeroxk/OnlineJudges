#include <cstdio>
#include <vector>

//std::vector<int> myfloor;
int myfloor[100001];
int cars[100001];

bool onFloor(int car, int floorCars) {
    for(int i=0; i<floorCars; i++) {
        if(myfloor[i] == car) {
            return true;
        }
    }
    return false;
}

//-2 means will not appear for rest of sequence
int findCar(int car, std::vector<int> seq, int start) {
    for(int i=start; i<seq.size(); i++) {
        if(seq[i] == car) {
            return i;
            break;
        }
    }
    return -2;
}

int main(void) {

    int totCars, maxFloor, lenSeq;
    scanf("%d %d %d", &totCars, &maxFloor, &lenSeq);

    std::vector<int> seq = std::vector<int>();
    for(int i=0; i<lenSeq; i++) {
        int a;
        scanf("%d", &a);
        a--;
        seq.push_back(a);
    }
    
    

    for(int i=0; i<totCars; i++) {
        cars[i] = -1;
    }

    //myfloor = std::vector<int>();
    int floorSize = 0;
    int shelf = 0;
    for(int i=0; i<seq.size(); i++) {
        int car = seq[i];
        
        if(onFloor(car, maxFloor)) continue;
        
        if(floorSize < maxFloor && !onFloor(car, floorSize)) {
            printf("Floor has space left\n");
            //myfloor.push_back(car);
            //printf("size: %d\n", myfloor.size());
            floorSize++;
            shelf++;
            continue;
        }
        
        //Car not on floor and full floor
        int max = 0;
        int ind = -1;
        for(int j=0; j<maxFloor; j++) {
            printf("On the floor now: ");
            for(int k=0; k<maxFloor; k++) {printf("%d ", myfloor[k]+1);} printf("\n");
            int car2 = myfloor[j];

            if(cars[car2] == -2) {
                max = cars[car2];
                ind = j;
                printf("%d does not appear again\n", car2+1);
                break;
            }

            if(cars[car2] < i) {
                cars[car2] = findCar(car2, seq, i);
            }


                printf("Next occurence of %d is %d\n", car2+1, cars[car2]);
            if(cars[car2] > max) {
                max = cars[car2];
                ind = j;
            }
        }
        printf("Max: %d, ind: %d\n", max, ind);
        myfloor[ind] = car;
        //myfloor.erase(myfloor.begin()+ind, myfloor.begin()+ind+1);
        //myfloor.push_back(car);
        shelf++;

    }

    printf("Mommy has to take minimum this # of cars: %d\n", shelf);

    return 0;
}
