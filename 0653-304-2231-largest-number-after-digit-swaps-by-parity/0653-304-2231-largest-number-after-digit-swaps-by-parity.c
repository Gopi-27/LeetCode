int largestInteger(int num) {
    int dig = log10(num) + 1;
    int arr[dig];
    for(int i = dig - 1; i >= 0; i--){
        arr[i] = num % 10;
        num /= 10;
    }
    for(int i = 0; i < dig; i++){
        int par = arr[i] % 2 ;
        int maxidx = i;
        for(int j = i; j < dig ; j++){
            if(arr[j] % 2 == par && arr[maxidx] < arr[j]){
                maxidx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[maxidx];
        arr[maxidx] = temp;
    }
    num = 0;
    for(int i = 0; i < dig; i++){
        num = (10 * num) + arr[i];
    }
    return num;
}