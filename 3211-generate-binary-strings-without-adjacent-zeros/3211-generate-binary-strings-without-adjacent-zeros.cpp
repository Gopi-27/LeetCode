class Solution {
public:
    void Recur(vector<string>& Ans,string &prev,int n){
        // base case
        if(prev.size() == n){
            Ans.push_back(prev);
            return;
        }

        if(prev.back() == '0'){
            prev.push_back('1');
            Recur(Ans,prev,n);
            prev.pop_back();
            return;
        }
        //
        prev.push_back('0');
        Recur(Ans,prev,n);
        prev.pop_back();

        //

        prev.push_back('1');
        Recur(Ans,prev,n);
        prev.pop_back();  

        return;
        
    }
    vector<string> validStrings(int n) {
        string prev = "0";
        vector<string>Ans;
        Recur(Ans,prev,n);
        prev = "1";
        Recur(Ans,prev,n);        
        return Ans;
    }
};