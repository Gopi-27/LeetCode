/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    int frr[101] = {0};
    for(int i = 0; i < numsSize; i++)frr[nums[i]]++;
    int sum_idx = 0;
    for(int i = 0; i < target; i++)sum_idx += frr[i];
    int * ans = (int *)calloc(frr[target],sizeof(int));
    int i = 0;
    *returnSize = frr[target];
    while(frr[target]--){
        ans[i++] = sum_idx++;
    }
    return ans;

}