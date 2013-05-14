#include <cstdio>
#include <vector>

std::vector<int> myfloor;
int cars[100001];

bool onFloor(int car, int totCars) {
    if(myfloor.size() == 0) return false;
    for(int i=0; i<totCars; i++) {
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

    myfloor = std::vector<int>();
    int floorSize = 0;
    int shelf = 0;
    for(int i=0; i<seq.size(); i++) {
        int car = seq[i];
        
        if(onFloor(car, totCars)) continue;
        
        if(floorSize < maxFloor && !onFloor(car, totCars)) {
            printf("Floor has space left\n");
            myfloor.push_back(car);
            printf("size: %d\n", myfloor.size());
            floorSize++;
            shelf++;
            continue;
        }
        
        //Car not on floor and full floor
        int max = 0;
        for(int j=0; j<myfloor.size(); j++) {
            int car2 = myfloor[j];

            if(cars[car2] == -2) {
                max = j;
                break;
            }

            if(cars[car2] < i) {
                cars[car2] = findCar(car2, seq, i);
            }

            if(cars[car2] > max) {
                max = j;
            }
        }
        printf("Max is: %d\n", myfloor[max]);
        myfloor.erase(myfloor.begin()+max, myfloor.begin()+max+1);
        myfloor.push_back(car);
        shelf++;

    }

    printf("Mommy has to take minimum this # of cars: %d\n", shelf);

    return 0;
}
