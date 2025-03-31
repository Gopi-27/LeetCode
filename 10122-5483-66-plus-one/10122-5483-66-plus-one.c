/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* ans = (int*)calloc(digitsSize + 1,sizeof(int));
    int carry = 1;
    for(int i = digitsSize - 1; i >= 0; i--){
        int sum = digits[i] + carry;
        if(sum <= 9){
            ans[i + 1] = sum;
            carry = 0;
        }else{
            ans[i + 1] = 0;
            carry = 1;
        }
    }
    *returnSize = digitsSize;
    if(carry > 0){
        ans[0] = carry;
        (*returnSize)++;
        return ans;
        
    }
    
    return ans + 1;
}