class Solution {
    public long maxProfit(int[] prices, int[] strategy, int k) {
        long ans = 0;
        int n = prices.length;
        for(int i = 0; i < n; i++)ans += strategy[i] * prices[i];
        long sum = ans;
        for(int i = 0; i < k/2; i++){
            if(strategy[i] == -1)sum += prices[i];
            else if(strategy[i] == 1)sum -= prices[i];
        }
        for(int i = k/2; i < k; i++){
            if(strategy[i] == -1)sum += prices[i] + prices[i];
            else if(strategy[i] == 0)sum += prices[i];
        }
        int start = 0;
        int mid = k/2;
        ans = Math.max(ans,sum);
        for(int i = k; i < n; i++){
            if(strategy[i] == -1)sum += prices[i] + prices[i];
            else if(strategy[i] == 0)sum += prices[i];

            sum -= prices[mid++];
            sum += strategy[start] * prices[start];
            start++;
            ans = Math.max(ans,sum);
        }
        return ans;
    }
}