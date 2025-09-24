class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int>st;
        vector<int>last_idx(26);
        for(int i = 0; i < n; i++){
            last_idx[s[i] - 'a'] = i;
        }
        st.push_back(last_idx[s[0] - 'a']);
        for(int i = 0; i < n; i++){
            int top = st.back();
            if(i <= top){

                if(last_idx[s[i] - 'a'] > top){
                    st[st.size() - 1] = last_idx[s[i] - 'a'];
                }

            }else{
                st.push_back(last_idx[s[i] - 'a']);
            }
        }
        int len = st.size();
        for(int i = len - 1; i > 0; i--){
            st[i] = st[i] - st[i - 1];
        }
        st[0]++;
        return st;

    }
};