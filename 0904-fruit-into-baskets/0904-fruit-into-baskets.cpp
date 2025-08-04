class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 1;
        int prev = -1;
        int cur = fruits[0];
        int pcnt = 0;
        int ccnt = 1;
        int n = fruits.size();
        for(int i = 1; i < n; i++){
            if(fruits[i] == prev){
                pcnt = pcnt + ccnt;
                ccnt = 1;
                prev = cur;
                cur = fruits[i];
                ans = max(ans,pcnt + ccnt);
            }else if(fruits[i] == cur){
                ccnt++;
                ans = max(ans,ccnt + pcnt);
            }else{
                prev = cur;
                pcnt = ccnt;
                ccnt = 1;
                cur = fruits[i];
                ans = max(ans ,ccnt + pcnt);
            }
        }
        return ans;



    }
};