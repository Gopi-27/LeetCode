class Solution {
public:
    void rec(int i,string str,string& digits,vector<string>& Ans,vector<string>& Adj){
        if(i == digits.size()){
            Ans.push_back(str);
            return;
        }
        for(char& ch : Adj[digits[i] - '0']){
            rec(i + 1,str + ch,digits,Ans,Adj);
        }
    }
    vector<string> letterCombinations(string digits) {
       vector<string>Adj(10),Ans;
       Adj[2] = "abc";Adj[3] = "def";Adj[4] = "ghi";Adj[5] = "jkl";
       Adj[6] = "mno";Adj[7] = "pqrs";Adj[8] = "tuv";Adj[9] = "wxyz";
       rec(0,"",digits,Ans,Adj);
       return Ans;
    }
};