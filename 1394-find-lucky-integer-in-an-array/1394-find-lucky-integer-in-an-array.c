int findLucky(int* arr, int arrSize) {
    int frr[501] = {0};
    for(int i = 0; i < arrSize; i++){
        frr[arr[i]]++;
    }
    for(int i = 500; i >= 1; i--){
        if(frr[i] == i)return i;
    }
    return -1;
}