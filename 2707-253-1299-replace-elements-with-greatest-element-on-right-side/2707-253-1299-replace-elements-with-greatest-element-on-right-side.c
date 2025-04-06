/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize) {
    int curmax = - 1;
    int prevmax = -1;
    *returnSize = arrSize;
    for(int i = arrSize - 1; i >= 0; i--){
        if(arr[i] > curmax){
            curmax = arr[i];
        }
        arr[i] = prevmax;
        prevmax = curmax;
    }
    return arr;
}