class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int ans = 0;
        int cnt = 0;
        int l = 0;
        for(int r = 0; r < n; r++){
            if(answerKey[r] == 'F')cnt++;
            while(cnt > k){
                if(answerKey[l] == 'F')cnt--;
                l++;
            }
            ans = max(ans,r - l + 1);
        }
        cnt = 0;
        l = 0;
        for(int r = 0; r < n; r++){
            if(answerKey[r] == 'T')cnt++;
            while(cnt > k){
                if(answerKey[l] == 'T')cnt--;
                l++;
            }
            ans = max(ans,r - l + 1);
        }
        return ans;
    }
};