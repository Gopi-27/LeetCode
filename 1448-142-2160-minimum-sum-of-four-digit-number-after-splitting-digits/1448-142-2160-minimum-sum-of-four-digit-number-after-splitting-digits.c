int minimumSum(int num) {
    int arr[4];
    int i=0;
    while(num>0){
        arr[i]=num%10;
        num=num/10;
        i++;
    }
    for(int i=0; i<3; i++){
        for(int j=1; j<4; j++){
            if(arr[j-1]>arr[j]){
                int temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    return (arr[0]*10)+arr[3]+(arr[1]*10)+arr[2];
}