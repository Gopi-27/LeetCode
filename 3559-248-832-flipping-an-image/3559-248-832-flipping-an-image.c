/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 void Reverse(int* arr,int n){
    for(int i = 0; i  < n / 2; i++){
        int temp = arr[n - i - 1];
        arr[n - 1 - i] = arr[i];
        arr[i] = temp;
    }
    return;
 }
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    for(int i = 0; i < imageSize; i++){
        Reverse(image[i],imageSize);
    }
    for(int i = 0; i < imageSize; i++){
        for(int j = 0; j < imageSize; j++){
            if(image[i][j] == 0)image[i][j] = 1;
            else image[i][j] = 0;
        }
    }
    *returnSize = imageSize;
    *returnColumnSizes = (int*)calloc(imageSize,sizeof(int));
    for(int i = 0; i < imageSize; i++){
        (*returnColumnSizes)[i]= imageSize;
    }
    return image;
}