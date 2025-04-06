/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    bool * Ans = (bool*)malloc(candiesSize * sizeof(bool));
    *returnSize = candiesSize;
    int max = - 1;
    for(int i = 0; i < candiesSize; i++){
        if(max < candies[i])max = candies[i];
    }
    for(int i = 0; i < candiesSize; i++){
        if(candies[i] + extraCandies >= max){
            Ans[i] = true;
        }else{
            Ans[i] = false;
        }
    }
    return Ans;
}