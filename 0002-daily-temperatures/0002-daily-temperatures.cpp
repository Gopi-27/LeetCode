class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>>st;
        int n = temp.size();
        vector<int>ans(n);
        for(int i = n - 1; i >= 0; i--){
            if(st.empty()){
                st.push({temp[i],i});
                ans[i] = 0;
            }else{
                while(!st.empty() && temp[i] >= st.top().first)st.pop();
                if(st.empty()){
                    st.push({temp[i],i});
                    ans[i] = 0;
                }else{
                    ans[i] = st.top().second - i;
                    st.push({temp[i],i});
                }
            }
        }
        return ans;
    }
};