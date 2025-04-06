/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    *returnSize = pricesSize;
    int* Ans = (int*)malloc(pricesSize * sizeof(int));
    int stack[pricesSize + 1];
    int Top = 0;
    stack[Top] = 0;    
    for(int i = pricesSize - 1; i >= 0; i--){
        while(prices[i] < stack[Top])Top--;
        Ans[i] = prices[i] - stack[Top];
        Top++;
        stack[Top] = prices[i];
    }
    return Ans;
}