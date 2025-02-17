bool checkIfExist(int* arr, int arrSize) {

    for(int i=0; i<arrSize-1; i++){
        for(int j=i+1; j<arrSize; j++){
            if(arr[i]==(2*arr[j]) || (arr[i]==(arr[j]/2) && arr[j]%2==0)){
                return true;
            }
        }
    }
    return false;
    
}