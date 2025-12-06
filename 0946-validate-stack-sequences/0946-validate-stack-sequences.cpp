class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int n = pushed.size();
        int j = 0;
        for(int i = 0; i < n; i++){
            st.push(pushed[i]);
            while(j < n && !st.empty() && st.top() == popped[j]){
                j++;
                st.pop();
            }
        }
        return (st.empty() && j == n);
    }
};