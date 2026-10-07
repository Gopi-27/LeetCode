class Solution {
public:
    unordered_set<string>st;
    int rec(int i,int open,string& s,string& temp){
        if(open < 0)return 1e9;
        if(i >= s.size()){
            if(open)return 1e9;
            st.insert(temp);
            return 0;
        }

        int ans = 1e9;
        if(s[i] == '('){
            ans = min(ans,1 + rec(i + 1,open,s,temp));
            temp += '(';
            ans = min(ans,rec(i + 1,open + 1,s,temp));
            temp.pop_back();
            
        }else if(s[i] == ')'){
            ans = min(ans,1 + rec(i + 1,open,s,temp));
            temp += ')';
            ans = min(ans,rec(i + 1,open - 1,s,temp));
            temp.pop_back();
        }else{
            temp += s[i];
            ans = min(ans,rec(i + 1,open,s,temp));
            temp.pop_back();
        }

        return ans;
    }
    vector<string> removeInvalidParentheses(string s) {
        string temp = "";
        int n = s.size() - rec(0,0,s,temp);
        vector<string>Ans;
        for(auto& str : st)if(str.size() == n)Ans.push_back(str);
        return Ans;
    }
};