class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>st;
        int n = heights.size();
        vector<int>Ans(n);
        for(int i = n - 1; i >= 0; i--){
            int cnt = 0;
            while(!st.empty() && st.top() < heights[i]){
                cnt++;
                st.pop();
            }
            if(!st.empty())cnt++;
            Ans[i] = cnt;
            st.push(heights[i]);
        }
        return Ans;
    }
};