class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        for(int i = 0; i < n; i++){
            int cur = asteroids[i];
            while(!st.empty() && st.top() > 0 && cur < 0){
                if(st.top() == -cur){
                    st.pop();
                    cur = 0;
                }else if(st.top() > -cur)cur = 0;
                else st.pop(); 
            }
            if(cur)st.push(cur);
        }
        int m = st.size();
        vector<int>ans(m);
        for(int i = m - 1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};