class Solution {
public:
    int maxDepth(string s) {
        stack<pair<char,int>>st;
        st.push({'#',0});
        for(char& ch : s){
            if(ch == '(')st.push({'(',0});
            else if(ch == ')'){
                int len = st.top().second + 1;st.pop();
                st.top().second = max(st.top().second,len);
            }
        }
        return st.top().second;
    }
};