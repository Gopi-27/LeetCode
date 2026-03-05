class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        //(2/7) 5;
        int ans = 0;
        for(int i = 0; i < n; i++)if(num[i] != '0')ans++;
        int i = n - 1;
        while(i >= 0 && num[i] != '5')i--;i--;
        while(i >= 0 && num[i] != '2' && num[i] != '7')i--;
        if(i >= 0)ans = min(ans,n - i - 2);
        cout << ans << " ";
        i = n - 1;
        while(i >= 0 && num[i] != '0')i--;i--;
        while(i >= 0 && num[i] != '0' && num[i] != '5')i--;
        if(i >= 0)ans = min(ans,n - i - 2);
        cout << ans << " ";
        return ans;
    }
};