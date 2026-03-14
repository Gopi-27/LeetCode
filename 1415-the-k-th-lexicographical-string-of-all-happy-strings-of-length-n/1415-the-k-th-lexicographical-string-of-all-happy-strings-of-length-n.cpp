class Solution {
public:
    void rec(int i,string& cur,int n, int k,vector<string>& ans){
        if(ans.size() >= k)return;
        if(i == n){
            ans.push_back(cur);
            return;
        }
        for(char ch = 'a'; ch <= 'c'; ch++){
            if(ch != cur[i - 1]){
                cur += ch;
                rec(i + 1,cur,n,k,ans);
                cur.pop_back();
            }
        }
        return ;
    }
    string getHappyString(int n, int k) {
        vector<string>ans;
        for(char ch = 'a'; ch <= 'c'; ch++){
            string cur = "";
            cur += ch;
            rec(1,cur,n,k,ans);
        }
        if(ans.size() < k)return "";
        return ans[k - 1];
    }
};