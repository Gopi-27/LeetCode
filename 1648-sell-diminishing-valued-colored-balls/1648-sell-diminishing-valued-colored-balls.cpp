class Solution {
public:
    int mod = 1e9 + 7;
    int maxProfit(vector<int>& inventory, int orders) {
        inventory.push_back(0);
        sort(inventory.begin(),inventory.end(),greater<int>());
        int n = inventory.size();
        long long ans = 0;
        for(int i = 0; i < n - 1; i++){
            int cnt = i + 1;
            int layers = inventory[i] - inventory[i + 1];
            if(!layers)continue;
            
            if(1ll * cnt * layers <= orders){
                // pick all
                long long l = inventory[i];
                long long a = inventory[i] - layers + 1;
                ans = (ans + 1ll * cnt * (1ll * layers * (a + l))/2) % mod;
                orders -= cnt * layers;
            }else{
                int k = orders/cnt; // layers
                long long l = inventory[i];
                long long a = inventory[i] - k + 1;
                ans = (ans + 1ll * cnt * (1ll * k * (a + l))/2) % mod;
                ans = (ans + (a - 1) * (orders % cnt)) % mod;
                break;
            }
        }
        return ans;
    }
};