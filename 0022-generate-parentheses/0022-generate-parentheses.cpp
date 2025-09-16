class Solution {
public:
    void Fun(int open,int close,string& s,int n,vector<string>&Ans){
        if(open == 0 && close == 0){
            Ans.push_back(s);
            return ;
        }
        
        if(open){
            s += '(';
            Fun(open - 1,close,s,n,Ans);
            s.pop_back();
        }

        if(close && (n - open) > (n - close)){
            s += ')';
            Fun(open,close - 1,s,n,Ans);
            s.pop_back();
        }
        return;

    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string>Ans;
        Fun(n,n,s,n,Ans);
        return Ans;
    }
};