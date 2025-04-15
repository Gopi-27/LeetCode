bool threeConsecutiveOdds(int* arr, int arrSize) {
    int cnt = 0;
    for(int i = 0; i < arrSize; i++){
        if(arr[i] % 2 == 1){
            cnt++;
            if(cnt >= 3)return true;
        }else{
            cnt = 0;
        }
    }
    return false;
}