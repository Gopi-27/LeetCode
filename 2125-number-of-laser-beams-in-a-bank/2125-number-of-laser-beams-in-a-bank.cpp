class Solution {
public:
    int GetOnes(string str){
        int cnt = 0;
        for(int i = 0; str[i] != '\0'; i++)if(str[i] == '1')cnt++;
        return cnt;        
    }
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int i = 0;
        int n = bank.size();
        int ans = 0;
        while(prev != 0 && i < n)prev = GetOnes(bank[i++]);
        while(i < n){
            int cur = GetOnes(bank[i]);
            if(cur > 0){
                ans += prev * cur;
                prev = cur;
            }
            i++;
        }
        return ans;

    }
};