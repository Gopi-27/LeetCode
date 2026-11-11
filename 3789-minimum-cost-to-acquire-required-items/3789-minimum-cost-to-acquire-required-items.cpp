class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
        if(cost1 + cost2 >= costBoth){
            if(need1 > need2){
                ans += 1ll * need2 * costBoth;
                int rem = need1 - need2;
                
                if(cost1 > costBoth){
                    ans += 1ll * rem * costBoth;
                }else{
                    ans += 1ll * rem * cost1;
                }                 
            }else{// n2 > n1
                ans += 1ll * need1 * costBoth;
                int rem = need2 - need1;

                if(cost2 > costBoth){
                    ans += 1ll * rem * costBoth;
                }else{
                    ans += 1ll * rem * cost2;
                }
            }  
            
        }else{
            ans += 1ll * need1 * cost1;
            ans += 1ll * need2 * cost2;            
        }
        return ans;
    }
};