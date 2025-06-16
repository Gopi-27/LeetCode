int buyChoco(int* prices, int pricesSize, int money) {
    int first_min = prices[0];
    int second_min = prices[1];
    if(second_min < first_min){
        first_min = first_min ^ second_min;
        second_min = first_min ^ second_min;
        first_min = first_min ^ second_min;
    }
    for(int i = 2; i < pricesSize; i++){
        if(prices[i] > second_min)continue;
        else if(prices[i] > first_min){
            second_min = prices[i];
        }else{
            second_min = first_min;
            first_min = prices[i];
        }
    }
    if(first_min + second_min <= money)return money - first_min - second_min;
    return money;
}