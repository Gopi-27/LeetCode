

bool validMountainArray(int* arr, int arrSize){
    // checking if the size of the array is >= 3 or not
	if(arrSize<=2){
		return false;
	}
    // finding the index of maximum value in the array
	int maxidx=0;
	for(int i=1; i<arrSize; i++){
		if(arr[maxidx]<arr[i]){
			maxidx=i;
		}
	}
    // Checking if maxidx is 0 or arrSize-1
    if (maxidx==(arrSize-1) || maxidx==0){
        return false;
    }
	int tempmax=arr[maxidx];
	int cnt=0;
	// dividing array into two parts. One part, before the maximum element and another part, after the maximum element

    // Checking is firstpart is strictly decreasing or not  from the index (maxidx-1 to 0)
	for(int i=maxidx-1; i>=0; i--){
		if(arr[i]>=tempmax){
			cnt++;
			break;
		}
		tempmax=arr[i];
	}
    // Checking second part whether it is strictly decresing or not from  index (maxidx+1 to arrSize-1) if and only if first part is strictly decreasing from index (maxidx-1 to 0)
	if(cnt==0){
	for(int i=maxidx+1; i<arrSize; i++ ){
		if(arr[i]>=arr[maxidx]){
			cnt++;
			break;
		}
		arr[maxidx]=arr[i];
	}
    
    }
    if(cnt==0){
	return true;
    }else{
	return false;
}

}
