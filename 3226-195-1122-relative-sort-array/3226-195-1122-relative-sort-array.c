/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    *returnSize = arr1Size;
    int frr[1001] = {0};
    for(int i = 0; i < arr1Size; i++){
        frr[arr1[i]]++;
    }
    int idx = 0;
    for(int i = 0; i < arr2Size; i++){
        for(int j = 0; j < frr[arr2[i]]; j++){
            arr1[idx++] = arr2[i]; 
        }
        frr[arr2[i]] = 0;
    }
    for(int i = 0; i < 1001; i++){
        if(frr[i] > 0){
            for(int j = 0; j < frr[i]; j++){
                arr1[idx++] = i;
            }
        }
    }
    return arr1;
}