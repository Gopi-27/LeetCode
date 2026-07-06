class Solution {
public:
    int ans = INT_MAX;
    void rec(int i,vector<int>& A,int maxi,vector<int>& cookies){
        if(i >= cookies.size()){
            ans = min(ans,maxi);
            return ;
        }
        for(int j = 0; j < A.size(); j++){
            A[j] += cookies[i];
            rec(i + 1,A,max(maxi,A[j]),cookies);
            A[j] -= cookies[i];
        }
        return;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>A(k);
        rec(0,A,0,cookies);
        return ans;

        // 8 15 10 20 8
        // 8 8 10 15 20
        // 8 8 15
        // 10 20
    }
};