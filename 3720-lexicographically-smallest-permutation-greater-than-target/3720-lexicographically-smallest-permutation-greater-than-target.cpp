class Solution {
public:
    int GetKey(vector<int>& frr,int idx){
        for(int i = idx; i < 26; i++){
            if(frr[i]){
                frr[i]--;
                return i;
            }
        }
        return -1;
    }
    void FillRemaining(string & ans,vector<int>& frr){
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < frr[i]; j++){
                ans += (i + 'a');
            }
        }
        return ;
    }
    bool IsThereAnyChance(string& ans,vector<int>& frr){
        int n = ans.size();
        int flag = 1;
        for(int i = n - 1; i >= 0; i--){
            frr[ans[i] - 'a']++;
            int key = GetKey(frr,ans[i] - 'a' + 1);
            ans.pop_back();
            
            if(key != -1){
                flag = 0;
                ans += ('a' + key);
                break;
            }
        }
        if(flag)return 0;
        FillRemaining(ans,frr);
        return 1;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int>frr(26);
        int n = s.size();
        for(int i = 0; i < n; i++)frr[s[i] - 'a']++;
        string ans = "";
        int flag = 0;
        for(int i = 0; i < n; i++){
            if(flag)break;
            int key = GetKey(frr,(target[i] - 'a'));
            if(key == -1){
                if(IsThereAnyChance(ans,frr))return ans;
                return "";
            }
            char ch = 'a' + key;
            if(ch > target[i])flag = 1;
            ans += ch;
        }
        if(target == ans){
            if(IsThereAnyChance(ans,frr))return ans;
            return "";
        }
        FillRemaining(ans,frr);
        return ans;
    }
};