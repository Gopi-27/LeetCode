


typedef struct {
    int Big;
    int Medium;
    int Small
} ParkingSystem;


ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
    ParkingSystem* nn = (ParkingSystem *)malloc(sizeof(ParkingSystem));
    nn->Big = big;
    nn->Medium = medium;
    nn->Small = small;
    return nn;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
    if(carType == 1){
        if(obj->Big > 0){
            obj->Big--;
            return true;
        }
        return false;
    }
    if(carType == 2){
        if(obj->Medium > 0){
            obj->Medium--;
            return true;
        }
        return false;
    }
        if(obj->Small > 0){
            obj->Small--;
            return true;
        }
        return false;

}

void parkingSystemFree(ParkingSystem* obj) {
    free(obj);
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);
 
 * parkingSystemFree(obj);
*/