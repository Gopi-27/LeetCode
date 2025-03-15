int maximum69Number (int num) {
    int arr[4] = {0};
    int i = 0;
    while(num > 0){
        arr[i++] = num % 10;
        num /= 10;
    }
    for( i = 3; i >= 0; i--){
        if(arr[i] == 6){
            arr[i] = 9;
            break;
        }
    }
    int rn = 0;
    for( i = 3; i >= 0; i--){
        rn = (rn * 10) + arr[i];
    }
    return rn;

}