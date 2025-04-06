int maxProfit(int* prices, int pricesSize) {
    int Ans = 0;
    int max = prices[pricesSize - 1];
    for(int i = pricesSize - 2; i >= 0; i--){
        if(max > prices[i]){
            if(Ans < (max - prices[i])){
                Ans = max - prices[i];
            }
        }else{
            max = prices[i];
        }
    }
    return Ans;
}